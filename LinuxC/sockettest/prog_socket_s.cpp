#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <unistd.h>

#define UNIX_DOMAIN "/tmp/UNIX.domain"
#define MAXClIENT 10
#define DATELEN 1024 //TDC 和 GUI 进程间通信数据长度

int main(int argc, char *argv[])
{
	int iRet = -1;
	int iRecvLen = 0;
	unsigned int iCltAddrLen = 0;
	int TdcServer_fd = -1;
	int GuiClient_fd = -1;
	char TdcRecvBuf[DATELEN] = {0}; 
	char TdcSendBuf[DATELEN] = {0}; 
	struct sockaddr_un CltAddr;
	struct sockaddr_un SrvAddr;
	//struct sockaddr_in CltAddr;
	//struct sockaddr_in SrvAddr;

	unlink(UNIX_DOMAIN); //保证没有已经存在的文件

	//creat server socket 
	TdcServer_fd = socket(PF_UNIX, SOCK_STREAM, 0);
	//TdcServer_fd = socket(AF_INET, SOCK_STREAM, 0);
	printf(" === TdcServer_fd = %d\n", TdcServer_fd);
	if (TdcServer_fd < 0)
	{
		perror("TDC cannot create communication socket");
		return 1;
	}  

	//set server addr_param
	SrvAddr.sun_family = AF_UNIX;//IPV4
	strncpy(SrvAddr.sun_path, UNIX_DOMAIN, sizeof(SrvAddr.sun_path) - 1);
	//memset(&SrvAddr,0,sizeof(SrvAddr));
	//SrvAddr.sin_family = AF_INET;
	//SrvAddr.sin_port = htons(5050);  //这里输入服务器端口号
	//SrvAddr.sin_addr.s_addr = htonl(INADDR_ANY); //INADDR_ANY表示本机IP

	//bind sockfd & addr
	iRet = bind(TdcServer_fd, (struct sockaddr*)&SrvAddr, sizeof(SrvAddr));
	if (-1 == iRet)
	{
		perror("cannot bind server socket");
		close(TdcServer_fd);
		unlink(UNIX_DOMAIN);
		return 1;
	}

	//listen sockfd 
	iRet = listen(TdcServer_fd, MAXClIENT);
	if (-1 == iRet)
	{
		perror("cannot listen the client connect request");
		close(TdcServer_fd);
		unlink(UNIX_DOMAIN);
		return 1;
	}

	//have connect request use accept
	iCltAddrLen = sizeof(CltAddr);

	while(1)
	{
		GuiClient_fd = accept(TdcServer_fd, (struct sockaddr*)&CltAddr, &iCltAddrLen);
		printf("============== GuiClient_fd = %d\n", GuiClient_fd);
		if(GuiClient_fd < 0)
		{
			perror("cannot accept client connect request");
			close(TdcServer_fd);
			unlink(UNIX_DOMAIN);
			return 1;
		}

		//read and printf sent client info
		memset(TdcSendBuf, 0, DATELEN);
		strcpy(TdcSendBuf, "you have connected to TDC succeed, NOW Receive msg from server\n");
		//write(GuiClient_fd, TdcSendBuf, sizeof(TdcSendBuf));
		printf("== GuiClient_fd = %d\n", GuiClient_fd);
		send(GuiClient_fd, TdcSendBuf, strlen(TdcSendBuf), 0);
		memset(TdcRecvBuf, 0, DATELEN);
		//iRecvLen = read(GuiClient_fd, TdcRecvBuf, sizeof(TdcRecvBuf));
		printf("receiveing .....\n");

		//while (1)
		{
			iRecvLen = recv(GuiClient_fd, TdcRecvBuf, DATELEN, 0);
			printf("Message from client (%d)) :%s/n", iRecvLen, TdcRecvBuf);
		}
	}

	close(GuiClient_fd);
	close(TdcServer_fd);
	unlink(UNIX_DOMAIN);

	return 0;
}