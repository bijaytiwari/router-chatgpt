#pragma once
#include <string>
#include <cstdint>
struct Interface{
 std::string name;
 std::string ip;
 int prefix{};
 bool up{true};
 uint64_t rxPackets{};
 uint64_t txPackets{};
 uint64_t rxBytes{};
 uint64_t txBytes{};
};
