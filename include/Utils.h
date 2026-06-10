#pragma once

#include <arpa/inet.h>
#include <cstdint>
#include <stdexcept>
#include <string>

inline uint32_t ipToUint32(const std::string& ip)
{
    in_addr addr{};

    if (inet_pton(AF_INET, ip.c_str(), &addr) != 1)
    {
        throw std::runtime_error("Invalid IPv4 address: " + ip);
    }

    return ntohl(addr.s_addr);
}