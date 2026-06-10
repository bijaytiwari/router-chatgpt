#include "Router.h"
#include <iostream>
#include <sstream>
int main(int argc,char**argv){
 std::string dir="sample"; for(int i=1;i<argc;i++) if(std::string(argv[i])=="--config-dir"&&i+1<argc) dir=argv[++i];
 Router r(dir); std::string line;
 while(std::cout<<"router> ",std::getline(std::cin,line)){
  if(line=="exit") break;
  if(line=="show-interfaces") r.showInterfaces();
  else if(line=="show-routes") r.showRoutes();
  else if(line=="reload-config") r.reload();
  else if(line.rfind("explain-lookup ",0)==0) r.explain(line.substr(15));
  else if(line.rfind("interface-up ",0)==0) r.enqueue({EventType::InterfaceUp,line.substr(13)});
  else if(line.rfind("interface-down ",0)==0) r.enqueue({EventType::InterfaceDown,line.substr(15)});
 }
}
