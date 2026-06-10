# Cisco G10 Virtual Router
Build: make
Run: ./router --config-dir sample
Commands: show-interfaces, show-routes, explain-lookup <ip>, reload-config, interface-up <if>, interface-down <if>, exit
Architecture: Binary Trie LPM, Producer/Consumer event queue, user-space only, no third-party libraries.
