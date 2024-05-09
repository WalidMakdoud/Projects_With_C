#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Number1;
    float Number2;
    float result;
    char op;

    printf("Enter a number : ");
    scanf("%f", &Number1);

    printf("Enter an operator : ");
    scanf(" %c", &op);

    printf("Enter another number : ");
    scanf("%f", &Number2);

    if (op == '/'){
        result = Number1 / Number2;
        printf("The result is : %f\n", result);


    } else if (op == '*') {
        result = Number1 * Number2;
        printf("The result is : %f\n", result);


    } else if (op == '+') {
        result = Number1 + Number2;
        printf("The result is : %f\n", result);


    } else if (op == '-') {
        float result = Number1 - Number2;
        printf("The result is : %f\n", result);


    } else {
        printf("Error\n");

    }





    return 0;
}
