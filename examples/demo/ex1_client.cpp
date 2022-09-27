#include <iostream>
#include <RCF/RCF.hpp>

RCF_BEGIN(I_HelloWorld, "I_HelloWorld") //RCF接口定义
RCF_METHOD_V1(void, Print, const std::string &) //RCF_METHOD_通用前缀，V表示返回值void， //1表示一个参数
RCF_END(I_HelloWorld)

int main(int argc, char **argv)
{
    try {
        RCF::RcfInit rcfInit; //初始化RCF
        std::cout << "Calling the I_HelloWorld Print() method. " << std::endl;
        RcfClient<I_HelloWorld> client(RCF::TcpEndpoint(50001)); //创建客户端并连接

        for (int i = 0; i < 3; i++) //循环调用远程函数
        {
            client.Print("Hello World");
            std::cout << i << std::endl;
        }
        std::cin.get();
    } catch (const RCF::Exception &e) {
        std::cout << "Error: " << e.getErrorMessage() << std::endl;
    }

    return 0;
}
