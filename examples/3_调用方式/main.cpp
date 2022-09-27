/*
客户端详细：
每个客户端由RCF::ClientStub控制与服务器对的连接    client.getClientStub()
客户端与服务器的响应方式有	Oneway - 服务器不应答
						Twoway - 客户端需等待服务器应答（默认）（可使用异步请求方式，解决应答阻塞）
*/

#include <iostream>
#include <time.h>
#include <RCF/RCF.hpp>

RCF_BEGIN(I_HelloWorld, "I_HelloWorld")
RCF_METHOD_V1(void, Print, const std::string &)
RCF_END(I_HelloWorld)

int main()
{
    RCF::init();
    std::cout << "调用服务器端的 Print 函数" << std::endl;
    try {
        RcfClient<I_HelloWorld> client(RCF::TcpEndpoint(50001));

        // 获取客户端代理
        RCF::ClientStub &clientStub = client.getClientStub();

        clock_t start = clock();
        // 远程调用
        client.Print("我是Twoway");
        clock_t end = clock();
        std::cout << "Twoway耗时:" << end - start << "ms" << std::endl;

        // 设置远程调用方式
        // 或者直接在调用时指定
        clientStub.setRemoteCallMode(RCF::Oneway);
        start = clock();
        client.Print("我是Oneway");
        end = clock();
        std::cout << "Oneway耗时:" << end - start << "ms" << std::endl;

        //如果有大量调用，则可以使用 批Oneway 方案（如果设置为Oneway，每一个调用都会发给server，如果有大量调用，则耗时）
        clientStub.enableBatching(); // 激活Oneway批调用
        clientStub.setMaxBatchMessageLength(1025 * 50); // 达到50K的消息自动发送
        for (size_t i = 0; i < 10; ++i) {
            client.Print("我是");
        }
        clientStub.flushBatch(); // 手动发送

        client.Print(RCF::Oneway, "我是Oneway");
    } catch (RCF::Exception &e) {
        std::cout << "ErrorId: " << e.getErrorId() << std::endl; // 错误码
        std::cout << "Error: " << e.getErrorString() << std::endl; // 错误信息
    }

    std::cin.get();
    return 0;
}