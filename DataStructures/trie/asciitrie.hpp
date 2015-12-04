#ifndef ASCIITRIE_HPP
#define ASCIITRIE_HPP

#include <string>

//forward declare
class TrieNode;

class LowerCaseTrie
{
private:
    TrieNode *root;
public:
    LowerCaseTrie();
    ~LowerCaseTrie();
    void add(const std::string&);
    bool contains(const std::string&);
    void print();
};

#endif
