#include "trienode.hpp"
#include <iostream>

TrieNode::TrieNode()
{
    children.reserve(255);
    for(int i=0; i<256; ++i){
        children.push_back(nullptr);
    }
}

TrieNode::~TrieNode()
{
    while(!children.empty()){
    delete children.back();
    children.pop_back();
    }
}

TrieNode* TrieNode::operator[](const char c)
{
    return children[c];
}

void TrieNode::add(const std::string& str)
{
    int index = (int) str[0];

    if(children[index] == NULL)
        children[index] = new TrieNode();

    std::string sub = str.substr(1);
    if(sub.size() > 0)
        children[index]->add(sub);

    /*} else{
        printf("Invalid character: %c ", str[0]);
    }*/
}


bool TrieNode::contains(const std::string& str)
{
    int index = (int) str[0];
    //index-= 97;

   // if(index < 0 || index > 25)
    //    return false;

    if(children[index] == NULL)
        return false;

    std::string sub = str.substr(1);
    if(sub.size() > 0)
        children[index]->contains(sub);
    if(sub.size() == 0)
        return true;

}


void TrieNode::print()
{
    for(int i=0; i<children.size(); ++i) {
        if(children[i] != NULL) {
            std::cout << char(i);// << "";
            children[i]->print();
        }
    }
}
