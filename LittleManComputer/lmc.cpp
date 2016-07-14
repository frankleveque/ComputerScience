#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>


std::string prefix = "The little man";


enum class LMStates{
    Start,

};



int main(int argc, char* argv[]) 
{
    if(argc < 2){
        std::cout << prefix << "needs instructions. Pass in a \"compiled\" instruction file as argument.";
        return EXIT_FAILURE;
    } else if(argc >= 2){
        std::cout << "reading " << argv[1] << std::endl;
    } 
    if(argc > 2){
        std::cout << "Ignoring other files";
    }

    std::ifstream file(argv[1]);

    if(!file.good()){
        std::cout << "invalid file: " << argv[1] << std::endl;
        return EXIT_FAILURE;
    } 


    LMStates lState = LMStates::Start;
    int32_t accumulator = 0;
    uint8_t programCounter = 0;
    uint16_t mailboxes[100];

    std::string str; 
    int counter = 0;
    while(std::getline(file, str)){
        if(counter < 100)
            mailboxes[counter] = std::stoi(str);
        else
            std::cout << "Ignoring extra instructions" << std::endl;
        ++counter;
    }

    //read value at box
    int inside = mailboxes[programCounter];
    while(true){

        std::cout << std::endl;
        int address = inside % 100;

//---------------------------------------------------------------------------------------------------------
        if(inside >= 900){
            if(address == 1){
                printf("%.3u - %s %s \n",inside,prefix.c_str(),"uses the inbox to get information...");
                std::string val = ""; 
                while(true){
                    std::cout << "      Enter Value from 0 to 999: ";
                    std::cin >> val;
                    try{
                        int temp = std::stoi(val);
                        if(temp > 999 || temp < 0)
                            continue;
                        printf("      %s %s %u\n", prefix.c_str(), "changes the working value to", temp); 
                        accumulator += temp;
                        break;
                    }catch(std::exception &e) {
                        continue;
                    }
                }
            }
            else if(address == 2){
                printf("%.3u - %s %s \n",inside,prefix.c_str(),"puts the working value in the outbox");
                std::cout << "      Outbox: " << std::setfill('0') << std::setw(3) << accumulator << std::endl;
            }
        }
//---------------------------------------------------------------------------------------------------------
        else if(inside >= 800){
            printf("%.3u - %s %s \n",inside,prefix.c_str(),"checks if working value is positive...");
            if(accumulator > 0){
                printf("      %s %s %s %u\n", "It is.", prefix.c_str(), "jumps to mailbox", address); 
                programCounter = address;
                inside = mailboxes[programCounter];
                continue;
            }
            printf("      %s \n", "It's not"); 
        }

        else if(inside == 0){
            printf("%.3u - %s %s \n",inside,prefix.c_str(),"goes on an indefinite coffee break.");
            printf("      %s \n","Program Halted");
            break;    
        }
        else
            printf("%.3u - %s %s \n",inside,prefix.c_str(),"doesn't know what to do yet");

        inside = mailboxes[++programCounter];


    }


    return 0;


}
