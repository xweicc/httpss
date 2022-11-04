#ifndef __HOSTTOIP_H__
#define __HOSTTOIP_H__

unsigned int hostToIp(const char *host);
unsigned int __host_to_ip(const char *host, unsigned int *ips, int size);

#endif
