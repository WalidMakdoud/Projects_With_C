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
    printf("Enter another number : ");
    scanf("%f", &Number2);
    printf("Enter an operator : ");
    scanf(" %c", &op);

    if (op == '/'){
        result = Number1 / Number2;
        printf("The result is : %f", result);


    } else if (op == '*') {
        result = Number1 * Number2;
        printf("The result is : %f", result);


    } else if (op == '+') {
        result = Number1 + Number2;
        printf("The result is : %f", result);


    } else if (op == '-') {
        float result = Number1 - Number2;
        printf("The result is : %d", result);


    } else {
        printf("Error");

    }





    return 0;
}
