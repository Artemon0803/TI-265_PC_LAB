// TI-265 Pcela Artiom LAB 2 var. 9
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    const int MAX_SIZE = 10;

    float mass[MAX_SIZE];
    float max_abs = 0.0f;
    float sum = 0;
    bool f = false;
    int i;

    //Input
    for (i = 0; i < MAX_SIZE; i++)
    {
        printf("mass[%d] = ", i);
        scanf("%f", &mass[i]);
    }

    //Max abs element
    for(i = 0; i < MAX_SIZE; i++){
        if(fabsf(mass[i]) > fabsf(max_abs)) max_abs = fabsf(mass[i]);
    }

    printf("\nMax abs element: %.2f", max_abs);

    //Sum between positive
    for(i = 0; i < MAX_SIZE; i++){
        if(!f && mass[i] > 0 ){
            f = true;
            continue;
        }

        if(f && mass[i] > 0) break;

        if(f) sum += mass[i];
    }

    printf("\nSum between positive: %.2f", sum);

    //Move 0 to the right
    for(i = 0; i < MAX_SIZE; i++){
        for(int j = i+1; j < MAX_SIZE; j++){
            if(mass[i] == 0 && mass[j] !=0){
                mass[i] = mass[j];
                mass[j] = 0;
            }
        }
    }

    printf("\n0 sorted:");
    for(i = 0; i < MAX_SIZE; i++) printf("\nmass[%d] = %.2f", i, mass[i]);

    return 0;
}