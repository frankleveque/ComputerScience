/* modify the temperature conversion program to print 
 * a heading above the table */

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
    fahr = lower;

    printf("fahr  celsius\n");
    while(fahr <= upper){
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

