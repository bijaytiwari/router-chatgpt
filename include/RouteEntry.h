#pragma once

#include <cstdint>
#include <string>

enum class RouteType
{
    Connected,
    Static
};

struct RouteEntry
{
    uint32_t network{0};
    uint32_t prefixLength{0};

    std::string nextHop;
    std::string interfaceName;

    RouteType type{RouteType::Static};

    bool active{true};
};