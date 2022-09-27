#include <iostream>
#include <RCF/RCF.hpp>

RCF_BEGIN(I_HelloWorld, "I_HelloWorld") //RCF接口定义
RCF_METHOD_V1(void, Print, const std::string &) //RCF_METHOD_通用前缀，V表示返回值void， //1表示一个参数
RCF_END(I_HelloWorld)

class CHelloWorld {
public:
    void Print(const std::string &s)
    {
        std::cout << "I_HelloWorld service: " << s << std::endl;
    }
};

int main(int argc, char **argv)
{
    try {
        RCF::RcfInit rcfInit; //初始化RCF
        RCF::RcfServer server(RCF::TcpEndpoint(50001)); //建立RCF远程服务，设定IP和端口

        CHelloWorld helloWorldObj;
        server.bind<I_HelloWorld>(helloWorldObj); //绑定接口函数

        server.start(); //启动服务，不会阻塞当前线程
        std::cout << "Press Enter to exit..." << std::endl;
        std::cin.get();
    } catch (const RCF::Exception &e) {
        std::cout << "Error: " << e.getErrorMessage() << std::endl;
    }

    return 0;
}
