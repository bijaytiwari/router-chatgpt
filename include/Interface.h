#pragma once
#include <string>
struct Interface { std::string name, ip; int prefix{}; bool up{true}; uint64_t rxPackets{},txPackets{},rxBytes{},txBytes{}; };
