#pragma once
#include <string>
#include <cstdint>
struct RouteEntry { uint32_t network{}; int prefix{}; std::string nextHop, iface; bool active{true}; };
