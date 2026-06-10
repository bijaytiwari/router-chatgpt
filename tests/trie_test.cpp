#include "Trie.h"
#include "Utils.h"

#include <cassert>
#include <iostream>
#include <vector>

void validate(
    Trie& trie,
    const std::string& ip,
    uint32_t expectedPrefix)
{
    auto* route =
        trie.lookup(ipToUint32(ip));

    assert(route != nullptr);

    assert(route->prefixLength ==
           expectedPrefix);

    std::cout
        << "PASS "
        << ip
        << " -> /"
        << expectedPrefix
        << '\n';
}

int main()
{
    std::vector<RouteEntry> routes;

    routes.push_back(
    {
        .network = ipToUint32("10.0.0.0"),
        .prefixLength = 8
    });

    routes.push_back({
        .network = ipToUint32("10.64.0.0"),
        .prefixLength = 10
    });

    routes.push_back({
        .network = ipToUint32("10.80.0.0"),
        .prefixLength = 12
    });

    routes.push_back({
        .network = ipToUint32("10.80.16.0"),
        .prefixLength = 20
    });

    routes.push_back({
        .network = ipToUint32("10.80.16.128"),
        .prefixLength = 25
    });

    routes.push_back({
        .network = ipToUint32("10.80.16.192"),
        .prefixLength = 26
    });

    routes.push_back({
        .network = ipToUint32("10.80.16.224"),
        .prefixLength = 27
    });

    routes.push_back({
        .network = ipToUint32("10.80.16.240"),
        .prefixLength = 28
    });

    routes.push_back({
        .network = ipToUint32("10.80.16.248"),
        .prefixLength = 29
    });

    routes.push_back({
        .network = ipToUint32("10.80.16.252"),
        .prefixLength = 30
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

    validate(trie, "10.1.1.1", 8);
    validate(trie, "10.64.1.1", 10);
    validate(trie, "10.80.1.1", 12);
    validate(trie, "10.80.16.1", 20);
    validate(trie, "10.80.16.130", 25);
    validate(trie, "10.80.16.194", 26);
    validate(trie, "10.80.16.225", 27);
    validate(trie, "10.80.16.241", 28);
    validate(trie, "10.80.16.249", 29);
    validate(trie, "10.80.16.253", 30);
    return 0;
}
