#include "ConfigLoader.h"
#include "Utils.h"
#include <fstream>
#include <regex>
static std::string readf(const std::string&p){std::ifstream f(p); return {std::istreambuf_iterator<char>(f),{}};}
std::vector<Interface> ConfigLoader::loadInterfaces(const std::string& d){
 std::vector<Interface> v; auto s=readf(d+"/interfaces.json");
 std::regex r(R"(\{"name":"([^"]+)","ip":"([^"]+)","prefix":(\d+)\})");
 for(auto i=std::sregex_iterator(s.begin(),s.end(),r);i!=std::sregex_iterator();++i) v.push_back({(*i)[1],(*i)[2],std::stoi((*i)[3])});
 return v;
}
std::vector<RouteEntry> ConfigLoader::loadRoutes(const std::string& d){
 std::vector<RouteEntry> v; auto s=readf(d+"/static_routes.json");
 std::regex r(R"(\{"network":"([^"]+)","prefix":(\d+),"nextHop":"([^"]+)","interface":"([^"]+)"\})");
 for(auto i=std::sregex_iterator(s.begin(),s.end(),r);i!=std::sregex_iterator();++i) v.push_back({ipToInt((*i)[1]),std::stoi((*i)[2]),(*i)[3],(*i)[4]});
 return v;
}
