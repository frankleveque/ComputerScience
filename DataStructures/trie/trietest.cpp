#include "asciitrie.hpp"
#include <iostream>

int main()
{

    std::cout << "Testing ASCII Trie: " << std::endl;

    LowerCaseTrie t;
    t.add("dog");
    t.add("cat");
    t.add("bat");
    t.add("   ");
    t.add("CAT");
    t.add("1234");
    t.add("12567");
    t.add("-/?(*");

    std::cout << t.contains("dog") << " dog " << std::endl;
    std::cout << t.contains("cat") << " cat " << std::endl;
    std::cout << t.contains("bat") << " bat " << std::endl;
    std::cout << t.contains("CAT") << " CAT " << std::endl;
    std::cout << t.contains("1234") << " 1234 " << std::endl;
    std::cout << t.contains("12567") << " 12567 " << std::endl;
    std::cout << t.contains("-/?(*") << " -/?(* " << std::endl;

    std::cout << std::endl << "Contents: \"";
    t.print();
    std::cout << "\"";


    return 0;
}
