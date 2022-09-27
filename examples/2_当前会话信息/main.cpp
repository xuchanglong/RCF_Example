/*
    RcfSession 可以获取当前客户端连接的信息
*/

#include <iostream>
#include <RCF/RCF.hpp>

RCF_BEGIN(I_HelloWorld, "I_HelloWorld")
RCF_METHOD_V1(void, Print, const std::string &)
RCF_END(I_HelloWorld)

class MySessionObj {
public:
    MySessionObj() { count++; }
    static int count;
};
int MySessionObj::count = 0;

class HelloWorld {
public:
    void Print(const std::string &s)
    {
        std::cout << "Print服务器: " << s << std::endl;
        // 获取当前连接的会话
        RCF::RcfSession &session = RCF::getCurrentRcfSession();
        // 传输协议
        RCF::TransportType transportType = session.getTransportType();
        // 客户端地址:端口
        const RCF::RemoteAddress &clientAddr = session.getClientAddress();
        std::cout << "ip:port : " << clientAddr.string() << std::endl;
        // 请求
        RCF::RemoteCallInfo request = session.getRemoteCallRequest();
        // 自定义的请求附加数据
        std::string customRequestData = session.getRequestUserData();
        // 创建，取得，删除会话对象
        session.createSessionObject<MySessionObj>();
        MySessionObj *pObj = session.querySessionObject<MySessionObj>();
        MySessionObj &obj = session.getSessionObject<MySessionObj>(); // 如果不存在则会抛出异常，可指定构造函数 为true
        std::cout << "link count : " << obj.count << std::endl;
        session.deleteSessionObject<MySessionObj>();
        // 客户端的连接成功的时间点（ms)
        time_t connectedAt = session.getConnectedAtTime();
        std::cout << "connect success time : " << connectedAt << std::endl;
        // 客户端连接的时长(S)，从客户端调用接口开始计算
        //RCF::sleepMs(2500);
        size_t connectedDurationS = session.getConnectionDuration();
        std::cout << "connect all time : " << connectedDurationS << std::endl;
        // 客户端的调用次数
        size_t callCount = session.getRemoteCallCount();
        std::cout << "clinet call count : " << callCount << std::endl;
        // 发送和收到的字节数
        uint64_t totalBytesReceived = session.getTotalBytesReceived();
        std::cout << "receive byte count : " << totalBytesReceived << std::endl;
        uint64_t totalBytesSent = session.getTotalBytesSent();
        std::cout << "send bype count : " << totalBytesSent << std::endl
                  << std::endl;
    }
};

void close()
{
    std::cout << "任意键退出..." << std::endl;
    std::cin.get();
}

int main()
{
    try {
        RCF::init();
        HelloWorld helloWorld;

        RCF::RcfServer server(RCF::TcpEndpoint(50001));
        server.bind<I_HelloWorld>(helloWorld);
        server.start();

        RcfClient<I_HelloWorld> client(RCF::TcpEndpoint(50001));

        client.Print("client");
        client.Print("client");

        close();
    } catch (RCF::Exception &e) {
        std::cout << e.getErrorString() << std::endl;
        close();
    }

    return 0;
}