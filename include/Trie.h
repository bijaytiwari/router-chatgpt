#pragma once
#include "RouteEntry.h"
#include <vector>
class Trie {
    struct Node { Node* c[2]{}; RouteEntry* route{}; };
    Node* root;
    void destroy(Node* n);
public:
    Trie(); ~Trie();
    void insert(RouteEntry* r);
    RouteEntry* lookup(uint32_t ip,std::vector<RouteEntry*>* matched=nullptr) const;
};
