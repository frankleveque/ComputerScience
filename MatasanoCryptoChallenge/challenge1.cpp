#include <string>
#include <iostream>
#include "b64converter.hpp"
#include "hexconverter.hpp"

int main()
{
    const std::string originalHex =
    "49276d206b696c6c696e6720796f757220627261696e206c"
    "696b65206120706f69736f6e6f7573206d757368726f6f6d";

    HexConverter hex;
    Base64Converter b64;
    std::cout << "Original Hex: " << std::endl << originalHex << std::endl << std::endl;
    std::cout << "As Text:" << std::endl << hex.decodeFromHex(originalHex) << std::endl << std::endl;
    std::cout << "As Base64:" << std::endl << b64.encodeIntoBase64(hex.decodeFromHex(originalHex));

    //safe way to pause to observe output
    std::cin.get();
}
