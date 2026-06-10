# Cisco G10 Virtual Router

Build:
    make

Run:
    ./router --config-dir sample

Features:
- IPv4 Binary Trie LPM
- Connected + Static routes
- Interactive CLI
- Event queue (producer/consumer)
- reload-config
- interface-up / interface-down
- explain-lookup
- No third-party libraries

NOTE:
This project includes a minimal JSON reader tailored to the provided schema.
