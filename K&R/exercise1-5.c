/* Modify the temperature conversion program to print the table
 * in reverse order, that is, from 300 degrees to 0 */

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
    fahr = upper;

    printf("fahr  celsius\n");
    while(fahr >= lower){
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr - step;
    }
}


