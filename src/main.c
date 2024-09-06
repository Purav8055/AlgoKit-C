#include<stdio.h>
#include<string.h>
#include "../include/searching.h"
#include "../include/sorting.h"
#include "../include/math.h"
#include "../include/encoding.h"
#include "../include/decoding.h"

int main()
{
    int arr[] = {1,2,3,4,5};
    printf("Searching library:-\n");
    printf("%d\n", linearSearch(arr, 5, 5));
    printf("%d\n", binarySearch(arr, 5, 5));

    int arr1[] = {5,2,7,4,7};
    sort(arr1, 5);
    printf("Sorting library:-\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Math library:-\n");
    int num = 5;
    printf("Factorial of %d is %d\n", num, factorial(num));

    double base = 2.0;
    int exp = 3;
    printf("%.2f raised to the power of %d is %.2f\n", base, exp, power(base, exp));

    int value = -10;
    printf("Absolute value of %d is %d\n", value, absolute(value));

    printf("Encoding:-\n");
    char str[1000];
    printf("Enter the string to be encoded: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';
    encoder(str);
    for(int i = 0; i < strlen(str); i++)
    {
        printf("%c", str[i]);
    }

    printf("\nDecoding:-\n");
    char str1[1000];
    printf("Enter the string to be decoded: ");
    fgets(str1, sizeof(str), stdin);
    str1[strlen(str1)-1] = '\0';
    decoder(str1);
    printf("\n");
    return 0;
}
