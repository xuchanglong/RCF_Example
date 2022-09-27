#include <iostream>
#include <RCF/RCF.hpp>

RCF_BEGIN(I_PrintService, "I_PrintService") //RCF接口
RCF_METHOD_V1(void, Print, const std::string &)
RCF_END(I_PrintService)

int main(int argc, char **argv)
{
    try {
        RCF::RcfInit rcfInit; //初始化RCF
        std::cout << "Calling the I_PrintService Print() method. " << std::endl;
        RcfClient<I_PrintService> client(RCF::TcpEndpoint("127.0.0.1", 59005)); //创建客户端并连接

        for (int i = 0; i < 10000; i++) //循环调用远程函数
        {
            client.Print("Hello World");
            std::cout << i << std::endl;
        }
    } catch (const RCF::Exception &e) {
        std::cout << "Error: " << e.getErrorMessage() << std::endl;
    }

    return 0;
}
