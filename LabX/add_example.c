#include <stdio.h>
#include <stdlib.h>


int add(int *num1, int *num2, int *num3) {
    return *num1 + *num2 + *num3;
}


int main(void){
    int num1 = 2;
    int num2 = 3;
    int num3 = 5;

    int add_num = add(&num1, &num2, &num3);

    printf("Addition: %d + %d + %d = %d \n", num1, num2, num3, add_num);

    return 0;
}

