#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long seed = LONG_MAX;



void reseed(){

    seed+=(time(NULL)+seed)*3+time(NULL);

}



char getFirstLetter()
{
    reseed();
    srand(seed);
    int chance = rand() % 106;
    if(chance < 12)
        return 'A';
    else if(chance < 17)
        return 'B';
    else if(chance < 21)
        return 'C';
    else if(chance < 24)
        return 'D';
    else if(chance < 26)
        return 'E';
    else if(chance < 30)
        return 'F';
    else if(chance < 32)
        return 'G';
    else if(chance < 39)
        return 'H';
    else if(chance < 45)
        return 'I';
    else if(chance < 46)
        return 'J';
    else if(chance < 47)
        return 'K';
    else if(chance < 50)
        return 'L';
    else if(chance < 54)
        return 'M';
    else if(chance < 56)
        return 'N';
    else if(chance < 62)
        return 'O';
    else if(chance < 65)
        return 'P';
    else if(chance < 66)
        return 'Q';
    else if(chance < 68)
        return 'R';
    else if(chance < 76)
        return 'S';
    else if(chance < 93)
        return 'T';
    else if(chance < 94)
        return 'U';
    else if(chance < 95)
        return 'V';
    else if(chance < 102)
        return 'W';
    else if(chance < 103)
        return 'X';
    else if(chance < 105)
        return 'Y';
    else if(chance < 106)
        return 'Z';
    else 
        return ' ';
}

char getLetter()
{
    reseed();
    srand(seed);
    int chance = rand() % 104;
    if(chance < 14)
        return 'e';
    else if(chance < 22)
        return 'a';
    else if(chance < 23)
        return 'b';
    else if(chance < 24)
        return 'c';
    else if(chance < 29)
        return 'd';
    else if(chance < 31)
        return 'f';
    else if(chance < 33)
        return 'g';
    else if(chance < 39)
        return 'h';
    else if(chance < 46)
        return 'i';
    else if(chance < 47)
        return 'j';
    else if(chance < 48)
        return 'k';
    else if(chance < 52)
        return 'l';
    else if(chance < 53)
        return 'm';
    else if(chance < 61)
        return 'n';
    else if(chance < 69)
        return 'o';
    else if(chance < 71)
        return 'p';
    else if(chance < 72)
        return 'q';
    else if(chance < 78)
        return 'r';
    else if(chance < 84)
        return 's';
    else if(chance < 93)
        return 't';
    else if(chance < 96)
        return 'u';
    else if(chance < 97)
        return 'v';
    else if(chance < 100)
        return 'w';
    else if(chance < 101)
        return 'x';
    else if(chance < 103)
        return 'y';
    else if(chance < 104)
        return 'z';
    else
        return ' ';
}

int main()
{


    time_t old = time(NULL);

    while(1){

        reseed();
        srand(seed);
        int letters = (rand() % 6) + 2;
        char finalName[100] = {0};

        int i=0;
        while(i < letters){
            if(i==0){
                finalName[0] = getFirstLetter();
            }else{
                char temp[2] = {0};
                sprintf(temp,"%c",getLetter());
                strcat(finalName, temp);
            }
            i++;
        }


        while(difftime(time(NULL), old) < 1){
        
        }
        printf("%s\n",finalName);
        old = time(NULL);
    }

    return 0;
}





