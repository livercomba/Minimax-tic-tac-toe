#ifndef NODE_H
#define NODE_H

#include <vector>

class Node {
public:
    int val;
    std::vector<Node> *childNodes;
    Node() : val(0), childNodes(nullptr) {}
    Node(int x) : val(x), childNodes(nullptr) {}
    Node(int x, std::vector<Node> *c) : val(x), childNodes(c) {}
};
#endif
