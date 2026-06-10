#pragma once

#include "RouteEntry.h"

#include <memory>
#include <vector>

class Trie
{
public:

    Trie() = default;
    ~Trie() = default;

    void insert(RouteEntry* route);

    RouteEntry* lookup(
        uint32_t ip,
        std::vector<RouteEntry*>* matchedRoutes = nullptr
    ) const;

private:

    struct Node
    {
        std::unique_ptr<Node> children[2];

        RouteEntry* route{nullptr};
    };

    Node root_;
};