#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(void)
{
 char sermsg[200],clmsg[200];
 int sockdec;
 struct sockaddr_in server_addr;
 
 bzero(sermsg,sizeof(sermsg));
 bzero(clmsg,sizeof(clmsg));
 
 sockdec=socket(AF_INET,SOCK_STREAM,0);
 printf("socket is created \n");
 server_addr.sin_family=AF_INET;
 server_addr.sin_port=htons(1500);
 server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
 
 connect(sockdec,(struct sockaddr*)&server_addr,sizeof(server_addr));
 
 printf("enter the message:\n");
 gets(clmsg);
 
 send(sockdec,clmsg,strlen(clmsg),0);
 recv(sockdec,sermsg,sizeof(sermsg),0);
 printf("servermsg is %s\n",sermsg);
 close(sockdec);
 return 0;
 }
