/*
客户端，需要有效连接，需要创建RcfServer，并调用RcfServer::createCallbackConnection()
*/

#include <iostream>
using namespace std;

#include <RCF/RCF.hpp>

RCF_BEGIN(I_HelloWorld, "I_HelloWorld")
RCF_METHOD_V1(void, Print, const string &)
RCF_END(I_HelloWorld)

RCF_BEGIN(I_IdentifyClient, "I_IdentifyClient")
RCF_METHOD_V1(void, SetClientName, const string &)
RCF_END(I_IdentifyClient)

class HelloWorld {
public:
    void Print(const string &s)
    {
        cout << s << endl;
    }
};

class IdentifyClient {
public:
    void SetClientName(const string &s)
    {
        cout << s << endl;
    }
};

int main()
{
    RCF::init();
    try {
        RCF::RcfServer callbackServer((RCF::TcpEndpoint(50004))); // 为什么需要空的 加两层括号是为了与c兼容，因为编译器解释RCF::TcpEndpoint()为函数调用
        IdentifyClient identifyClient;
        callbackServer.bind<I_IdentifyClient>(identifyClient);
        callbackServer.start();

        RcfClient<I_IdentifyClient> client(RCF::TcpEndpoint(50004));
        // 创建回调
        client.SetClientName("wangh");
        RCF::createCallbackConnection(client, callbackServer);
        cout << "任意键退出..." << endl;
        cin.get();
    } catch (RCF::Exception &e) {
        cout << e.getErrorString() << endl;
        cout << "任意键退出..." << endl;
        cin.get();
    }
    return 0;
}