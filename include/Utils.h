#pragma once
#include <arpa/inet.h>
#include <string>
inline uint32_t ipToInt(const std::string& ip){ in_addr a{}; inet_pton(AF_INET,ip.c_str(),&a); return ntohl(a.s_addr);}
