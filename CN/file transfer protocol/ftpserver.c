#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

void main()
{
 char sermsg[500],clmsg[500],cl;
 int socdec,clsock,clsize,c;
 struct sockaddr_in server_addr,client_addr;
 FILE *fp2;
 
 fp2=fopen("output.txt","w");
 bzero(sermsg,sizeof(sermsg));
 bzero(clmsg,sizeof(clmsg));
 
 socdec=socket(AF_INET,SOCK_STREAM,0);
 printf("socket is created \n");
 server_addr.sin_family=AF_INET;
 server_addr.sin_port=htons(1500);
 server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
 
 bind(socdec,(struct sockaddr*)&server_addr,sizeof(server_addr));
 printf("binding is done \n");
 
 listen(socdec,10);
 printf("listening...\n");
 
 clsize=sizeof(client_addr);
 clsock=accept(socdec,(struct sockaddr*)&client_addr,&clsize);
 
 recv(clsock,clmsg,sizeof(clmsg),0);
 c=atoi(clmsg);
 
 for(int i=0;i<c;i++) {
     recv(clsock,&cl,sizeof(char),0);
     fprintf(fp2,"%c",cl);
       }
     
 close(clsock);
 close(socdec);
 }
