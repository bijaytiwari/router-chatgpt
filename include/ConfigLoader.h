#pragma once
#include "Interface.h"
#include "RouteEntry.h"
#include <vector>
#include <string>
class ConfigLoader{
public:
 static std::vector<Interface> loadInterfaces(const std::string& dir);
 static std::vector<RouteEntry> loadRoutes(const std::string& dir);
};
