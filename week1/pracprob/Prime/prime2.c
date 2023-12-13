#include <cs50.h>
#include <stdio.h>

int main()
{
    int num, temp = 0;
    printf("Enter any number to check for Prime: ");
    scanf("%d", &num);

    int i = 2;
    while(i <= num / 2)
    {
        if(num % i == 0)
        {
            temp++;
            break;
        }
        i++;
    }
    if(temp == 0 && num != 1)
    {
        printf("%d is a Prime Number \n", num);
    }
    else
    {
        printf("%d is NOT a Prime Number \n", num);
    }
    return 0;
}