#pragma once
#include <string>
#include <cstdint>
enum class RouteType{Connected,Static};
struct RouteEntry{
 uint32_t network{};
 int prefix{};
 std::string nextHop;
 std::string iface;
 bool active{true};
 RouteType type{RouteType::Static};
};
