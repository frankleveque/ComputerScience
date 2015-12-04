#include "asciitrie.hpp"
#include "trienode.hpp"

LowerCaseTrie::LowerCaseTrie()
{
    root = new TrieNode();
}

LowerCaseTrie::~LowerCaseTrie()
{
    delete root;
}

void LowerCaseTrie::add(const std::string& str)
{
    root->add(str);
}

bool LowerCaseTrie::contains(const std::string& str)
{
    return root->contains(str);
}

void LowerCaseTrie::print()
{
    root->print();
}


