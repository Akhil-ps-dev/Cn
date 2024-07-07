#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

void main() {

int sockdec, w=0;
struct sockaddr_in server_addr;
char sermsg[500],clmsg[500],c;
FILE *fp1;

 bzero(sermsg,sizeof(sermsg));
 bzero(clmsg,sizeof(clmsg));

 sockdec=socket(AF_INET,SOCK_STREAM,0);
 printf("socket is created \n");
 server_addr.sin_family=AF_INET;
 server_addr.sin_port=htons(1500);
 server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
 
 connect(sockdec,(struct sockaddr*)&server_addr,sizeof(server_addr));
 fp1=fopen("input.txt","r");
 while((c=fgetc(fp1))!=EOF) {
      w++;
   }
   sprintf(clmsg,"%d",w);
   send(sockdec,clmsg,sizeof(clmsg),0);
   rewind(fp1);
   
 while((c=fgetc(fp1))!=EOF) {
      send(sockdec,&c,sizeof(char),0);
   }
   
   close(sockdec);
   
  }
