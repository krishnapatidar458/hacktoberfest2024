#include <stdio.h>

int main()
{
    double num1, num2;
    char opr;
    char choice;

    while (true)
    {
        printf("Enter first number: ");
        scanf("%lf", &num1);

        printf("Enter second number: ");
        scanf("%lf", &num2);

        printf("Enter an operator (+, -, *, /): ");
        scanf(" %c", &opr);
        printf("\n");

        switch (opr)
        {
        case '+':
            printf("%.2lf + %.2lf = %.2lf", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("%.2lf / %.2lf = %.2lf", num1, num2, num1 / num2);
            else
                printf("Error: Division by zero!");
            break;
        default:
            printf("Error: Invalid operator!");
        }

        printf("\n\nEnter 'c' to continue, Enter 'q' to exit\n");
        scanf(" %c", &choice);
        if (choice == 'q')
        {
            break;
        }
    }

    return 0;
}
