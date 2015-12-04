#ifndef TRIENODE_HPP
#define TRIENODE_HPP

#include <vector>
#include <cstdint>
#include <string>


class TrieNode
{
    std::vector<TrieNode*> children;

public:
    TrieNode();
    ~TrieNode();

    TrieNode* operator[](const char);
    void add(const std::string&);
    bool contains(const std::string&);
    void print();
};

#endif
