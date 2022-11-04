#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#if 1
unsigned int __host_to_ip(const char *host, unsigned int *ips, int size)
{
	struct hostent *he;

	he = gethostbyname(host);
	if(!he){
		return 0;
	}
	if(he->h_addrtype == AF_INET){
		*ips=*((unsigned int *)he->h_addr);
		return 1;
	}else{
		return 0;
	}
}
#else
unsigned int __host_to_ip(const char *host, unsigned int *ips, int size)
{
	int i=0;
	struct addrinfo *res=NULL,*ai=NULL;

	if(getaddrinfo(host, NULL, NULL, &res)){
		return 0;
	}

	ai=res;
	while(ai){
		if(ai->ai_family==AF_INET){
			ips[i++]=((struct sockaddr_in *)ai->ai_addr)->sin_addr.s_addr;
			if(i>=size){
				break;
			}
		}
		ai=ai->ai_next;
	}
	if(res){
		freeaddrinfo(res);
	}
	return 0;
}
#endif

unsigned int hostToIp(const char *host)
{
	unsigned int ip=0;
	__host_to_ip(host, &ip, 1);
	return ip;
}

#if 0
int main(int argc, char **argv)
{
	unsigned int ip=0;
	unsigned char *ip_dot=(unsigned char *)&ip;
	if(argc<2){
		exit(1);
	}
	ip=hostToIp(argv[1]);

	printf("%d.%d.%d.%d\n",ip_dot[0],ip_dot[1],ip_dot[2],ip_dot[3]);
	
	return 0;
}
#endif

