#pragma once
#include "Interface.h"
#include "RouteEntry.h"
#include "Trie.h"
#include <unordered_map>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
enum class EventType{InterfaceUp,InterfaceDown};
struct Event{EventType type; std::string iface;};
class Router{
 std::unordered_map<std::string,Interface> ifs;
 std::vector<RouteEntry> routes;
 Trie trie; std::string cfg;
 std::queue<Event> q; std::mutex m,qm; std::condition_variable cv; bool run=true; std::thread worker;
public:
 Router(const std::string&); ~Router();
 void reload();
 void showInterfaces();
 void showRoutes();
 void explain(const std::string& ip);
 void enqueue(Event);
};
