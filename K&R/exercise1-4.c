/* Write a program to print the corresponding Celsius to Fahrenheit table */

#include <stdio.h>

int main()
{
    float fahr;
    float celsius;
    int lower;
    int upper;
    int step;

    lower = 0;
    upper = 300;
    step = 20;
    celsius = lower;
    
    printf("celsius   fahr\n");
    while(celsius <= upper){
        fahr = (celsius * (9.0/5.0)) + 32;
        printf("%3.0f %9.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
