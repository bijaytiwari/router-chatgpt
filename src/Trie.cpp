#include "Trie.h"

void Trie::insert(RouteEntry* route)
{
    Node* current = &root_;

    for (int bit = 31;
         bit >= static_cast<int>(32 - route->prefixLength);
         --bit)
    {
        int value = (route->network >> bit) & 0x1;

        if (!current->children[value])
        {
            current->children[value] =
                std::make_unique<Node>();
        }

        current = current->children[value].get();
    }

    current->route = route;
}

RouteEntry* Trie::lookup(
    uint32_t ip,
    std::vector<RouteEntry*>* matchedRoutes) const
{
    const Node* current = &root_;

    RouteEntry* bestMatch = nullptr;

    if (root_.route && root_.route->active)
    {
        bestMatch = root_.route;

        if (matchedRoutes)
        {
            matchedRoutes->push_back(bestMatch);
        }
    }

    for (int bit = 31; bit >= 0; --bit)
    {
        int value = (ip >> bit) & 0x1;

        if (!current->children[value])
        {
            break;
        }

        current = current->children[value].get();

        if (current->route &&
            current->route->active)
        {
            bestMatch = current->route;

            if (matchedRoutes)
            {
                matchedRoutes->push_back(bestMatch);
            }
        }
    }

    return bestMatch;
}