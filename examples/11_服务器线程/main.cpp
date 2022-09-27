/*
        默认RCF服务器端线程为单线程，可配置为多线程  RcfServer::setThreadPool()
*/

#include <iostream>
using namespace std;

#include <RCF/RCF.hpp>

RCF_BEGIN(I_HelloWorld, "I_HelloWorld")
RCF_METHOD_V1(void, Print, const string &)
RCF_END(I_HelloWorld)

class HelloWorld {
public:
    void Print(const string &s)
    {
        cout << "服务器: " << s << endl;
        // 废掉该线程，用于判断线程池是否起到作用。
        while (1) {
            sleep(1);
        }
    }
};

int main()
{
    try {
        RCF::init();

        RCF::RcfServer server(RCF::TcpEndpoint(50001));
        RCF::ThreadPoolPtr tpPtr(new RCF::ThreadPool(5)); // 固定线程数
        // RCF::ThreadPoolPtr tpPtr(new RCF::ThreadPool(1, 25)); // 弹性线程数
        server.setThreadPool(tpPtr); // 此种方式设置的线程对所有传输方式有效

        // 可单独为某种方式定义线程
        // 	RCF::ServerTransport &udpTransport =
        // server.addEndpoint(RCF::UdpEndpoint(50001)); 	RCF::ServerTransport
        // &pipeTransport =
        // server.addEndpoint(RCF::Win32NamedPipeEndpoint(_T("PIPE")));
        // 	RCF::ThreadPoolPtr udpTpPtr(new RCF::ThreadPool(1, 5));
        // 	udpTransport.setThreadPool(udpTpPtr);
        // 	RCF::ThreadPoolPtr pipeTpPtr(new RCF::ThreadPool(1));
        // 	pipeTransport.setThreadPool(pipeTpPtr);

        HelloWorld helloWorld;
        server.bind<I_HelloWorld>(helloWorld);
        server.start();

        cout << "调用服务器端的 Print 函数" << endl;
        cout << "任意键退出..." << endl;
        cin.get();

        // 起多于5个的终端，分别执行 demo 下的 client，
        // 线程池生效的特征是终端只能打印5个“服务器: Hello World“
    } catch (RCF::Exception &e) {
        cout << e.getErrorString() << endl;
    }

    return 0;
}