#include "Router.h"
#include "ConfigLoader.h"
#include "Utils.h"
#include <iostream>
Router::Router(const std::string& c):cfg(c){
 reload();
 worker=std::thread([this]{while(run){std::unique_lock lk(qm);cv.wait(lk,[&]{return !q.empty()||!run;}); if(!run)break; auto e=q.front(); q.pop(); lk.unlock(); std::lock_guard g(m); if(ifs.count(e.iface)){ifs[e.iface].up=(e.type==EventType::InterfaceUp); for(auto&r:routes) if(r.iface==e.iface) r.active=ifs[e.iface].up;}}});
}
Router::~Router(){run=false;cv.notify_all(); if(worker.joinable())worker.join();}
void Router::reload(){std::lock_guard g(m); ifs.clear(); routes=ConfigLoader::loadRoutes(cfg); for(auto&i:ConfigLoader::loadInterfaces(cfg)) ifs[i.name]=i; trie=Trie(); for(auto&r:routes) trie.insert(&r);}
void Router::showInterfaces(){std::lock_guard g(m); for(auto&[n,i]:ifs) std::cout<<n<<" "<<(i.up?"UP":"DOWN")<<" RX:"<<i.rxPackets<<" TX:"<<i.txPackets<<"\n";}
void Router::showRoutes(){for(auto&r:routes) std::cout<<"/"<<r.prefix<<" via "<<r.iface<<" active="<<r.active<<"\n";}
void Router::explain(const std::string& ip){std::vector<RouteEntry*> m; auto*r=trie.lookup(ipToInt(ip),&m); std::cout<<"Matched:\n"; for(auto*x:m) std::cout<<"/"<<x->prefix<<"\n"; if(r) std::cout<<"Selected /"<<r->prefix<<" via "<<r->iface<<"\n";}
void Router::enqueue(Event e){std::lock_guard lk(qm); q.push(e); cv.notify_one();}
