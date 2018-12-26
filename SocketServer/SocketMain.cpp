

//#include"iostream"
#include"cmdline.h"
#include"thread"
#include"SocketServer.h"
//#include "string"
//#include <stdlib.h>

//using namespace std;

ServerNet serverNet1;
ServerNet serverNet2;
ServerNet serverNet3;
ServerNet serverNet4;
ServerNet serverNet5;
ServerNet serverNet6;
ServerNet serverNet7;
ServerNet serverNet8;
ServerNet serverNet9;
ServerNet serverNet10;

int ServerPort = 0;
const char* ServerAddr = "127.0.0.1";

void ServerRun1()
{
	serverNet1.ServerRun();
}

void ServerRun2()
{
	serverNet2.ServerRun();
}

void ServerRun3()
{
	serverNet3.ServerRun();
}

void ServerRun4()
{
	serverNet4.ServerRun();
}

void ServerRun5()
{
	serverNet5.ServerRun();
}

void ServerRun6()
{
	serverNet6.ServerRun();
}

void ServerRun7()
{
	serverNet7.ServerRun();
}

void ServerRun8()
{
	serverNet8.ServerRun();
}

void ServerRun9()
{
	serverNet9.ServerRun();
}

void ServerRun10()
{
	serverNet10.ServerRun();
}

int main(int argc, char* argv[])
{
	

	cmdline::parser args;

	//ClientParam
	args.add<UINT>("serverport", 's', "ServerPort", false, 8001, cmdline::range(0, 65535));
	args.add<std::string>("ssar", '\0', "ServerAddress", false, "127.0.0.1");

	args.parse_check(argc, argv);

	//input serverport from cmdline
	if (args.exist("serverport"))
	{
		//int ServerPort;
		ServerPort = args.get<UINT>("serverport");
	}
	//input serveraddr from cmdline
	if (args.exist("ssar"))
	{
		ServerAddr = args.get<std::string>("ssar").data();
	}

	printf("ServerPort:%d\n", ServerPort);

	printf("ServerAddr:%s\n", ServerAddr);



	int iRlt = serverNet1.ServerInit(ServerAddr, ServerPort);

	iRlt = serverNet2.ServerInit(ServerAddr, ServerPort + 1);
	

	iRlt = serverNet3.ServerInit(ServerAddr, ServerPort + 2);

	iRlt = serverNet4.ServerInit(ServerAddr, ServerPort + 3);

	iRlt = serverNet5.ServerInit(ServerAddr, ServerPort + 4);

	iRlt = serverNet6.ServerInit(ServerAddr, ServerPort + 5);

	iRlt = serverNet7.ServerInit(ServerAddr, ServerPort + 6);

	iRlt = serverNet8.ServerInit(ServerAddr, ServerPort + 7);

	iRlt = serverNet9.ServerInit(ServerAddr, ServerPort + 8);

	iRlt = serverNet10.ServerInit(ServerAddr, ServerPort + 9);

	if (iRlt == 0)

	{

		printf("server init successful.\n");

		std::thread th1(ServerRun1);
		std::thread th2(ServerRun2);
		std::thread th3(ServerRun3);
		std::thread th4(ServerRun4);
		std::thread th5(ServerRun5);
		std::thread th6(ServerRun6);
		std::thread th7(ServerRun7);
		std::thread th8(ServerRun8);
		std::thread th9(ServerRun9);
		std::thread th10(ServerRun10);


		th1.join();
		th2.join();
		th3.join();
		th4.join();
		th5.join();
		th6.join();
		th7.join();
		th8.join();
		th9.join();
		th10.join();

		//serverNet1.ServerRun();
		//serverNet2.ServerRun();

	}

	else

		printf("server init failed with error: %d\n", iRlt);

	//system("pause");

	return 0;
}
