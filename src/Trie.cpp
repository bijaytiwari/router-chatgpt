#include "Trie.h"
Trie::Trie(){root=new Node();}
void Trie::destroy(Node*n){if(!n)return; destroy(n->c[0]); destroy(n->c[1]); delete n;}
Trie::~Trie(){destroy(root);}
void Trie::insert(RouteEntry*r){Node*cur=root; for(int i=31;i>=32-r->prefix;--i){int b=(r->network>>i)&1; if(!cur->c[b])cur->c[b]=new Node(); cur=cur->c[b];} cur->route=r;}
RouteEntry* Trie::lookup(uint32_t ip,std::vector<RouteEntry*>* m) const{Node*cur=root; RouteEntry*best=root->route; for(int i=31;i>=0&&cur;--i){ if(cur->route&&cur->route->active){best=cur->route; if(m)m->push_back(best);} cur=cur->c[(ip>>i)&1]; } return best;}
