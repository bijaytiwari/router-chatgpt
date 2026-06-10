#include "Trie.h"
#include "Utils.h"

#include <cassert>
#include <iostream>
#include <vector>

int main()
{
    std::vector<RouteEntry> routes;

    routes.push_back({
        ipToUint32("10.0.0.0"),
        8
    });

    routes.push_back({
        ipToUint32("10.64.0.0"),
        10
    });

    routes.push_back({
        ipToUint32("10.80.0.0"),
        12
    });

    routes.push_back({
        ipToUint32("10.80.16.0"),
        20
    });

    routes.push_back({
        ipToUint32("10.80.16.128"),
        25
    });

    routes.push_back({
        ipToUint32("10.80.16.192"),
        26
    });

    routes.push_back({
        ipToUint32("10.80.16.224"),
        27
    });

    routes.push_back({
        ipToUint32("10.80.16.240"),
        28
    });

    routes.push_back({
        ipToUint32("10.80.16.248"),
        29
    });

    routes.push_back({
        ipToUint32("10.80.16.252"),
        30
    });

    Trie trie;

    for (auto& route : routes)
    {
        trie.insert(&route);
    }

    auto* result =
        trie.lookup(ipToUint32("10.80.16.253"));

    assert(result != nullptr);

    assert(result->prefixLength == 30);

    std::cout
        << "PASS: Longest Prefix Match /30 selected\n";

    return 0;
}