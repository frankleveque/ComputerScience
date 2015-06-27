/**
 * @file
 * @author Frank Leveque
 * @brief Morse Code Generator
 * @details Takes a string input and outputs the morse code equivalent
 * if it is valid then loops or exits.
 * Valid input contains only alphanumeric characters (i.e. A-Z, a-z and 0-9).
 *
 */

#include <map>
#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>

int main()
{
    std::map<char, std::string> morseMap;

    //add morse symbols to map for each character
    morseMap['A'] = ".-";
    morseMap['B'] = "-...";
    morseMap['C'] = "-.-.";
    morseMap['D'] = "-..";
    morseMap['E'] = ".";
    morseMap['F'] = "..-.";
    morseMap['G'] = "--.";
    morseMap['H'] = "....";
    morseMap['I'] = "..";
    morseMap['J'] = ".---";
    morseMap['K'] = "-.-";
    morseMap['L'] = ".-..";
    morseMap['M'] = "--";
    morseMap['N'] = "-.";
    morseMap['O'] = "---";
    morseMap['P'] = ".--.";
    morseMap['Q'] = "--.-";
    morseMap['R'] = ".-.";
    morseMap['S'] = "...";
    morseMap['T'] = "-";
    morseMap['U'] = "..-";
    morseMap['V'] = "...-";
    morseMap['W'] = ".--";
    morseMap['X'] = "-..-";
    morseMap['Y'] = "-.--";
    morseMap['Z'] = "--..";
    morseMap['1'] = ".----";
    morseMap['2'] = "..---";
    morseMap['3'] = "...--";
    morseMap['4'] = "....-";
    morseMap['5'] = ".....";
    morseMap['6'] = "-....";
    morseMap['7'] = "--...";
    morseMap['8'] = "---..";
    morseMap['9'] = "----.";
    morseMap['0'] = "-----";

    std::cout << "Welcome to the International (ITU) Morse Code Generator" << std::endl;
    std::cout << "=======================================================" << std::endl;

    bool isRunning = true;
    bool isValid = true;
    std::string input;
    std::string output;

    //loop
    while(isRunning) {
        input = "";
        output = "";
        isValid = true;

        std::cout << "String Input (\"%\" to exit): ";
        std::getline(std::cin, input);

        //exit test
        if(input == "%") {
            isRunning = false;
            break;
        }

        for(int i=0; i<input.length(); ++i) {
            //count() checks if char exists in map
            if(morseMap.count(toupper(input[i])) > 0) {
                output.append(morseMap.find(toupper(input[i]))->second);
                output.append(" ");
            } else if(input[i] == ' ')
                output.append(" ");
            else {
                std::cout << "Invalid character found - ignoring input" <<
                    std::endl << "(only A-Z, a-z, and 0-9 work in this generator)" <<
                    std::endl << std::endl;
                isValid = false;
                break;
            }
        }

        if(isValid) {
            std::cout << "Morse Output: " <<  output << std::endl << std::endl;
        }
    }
    return EXIT_SUCCESS;
}
