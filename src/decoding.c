#include <stdio.h>
#include <string.h>
#include "../include/decoding.h"

void reverseString1(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;
    
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int toInt1(char str[])
{
    int ans = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i]=='1')
        {
            ans = ans * 2 + 1;
        }
        else{
            ans = ans * 2;
        }
    }
    return ans;
}

void toBinary1(int a, char bin[])
{
    int k = 0;
    while(a!=0)
    {
        int rem = a % 2;
        bin[k++] = rem + '0';
        a = a / 2;
    }
    bin[k] = '\0';
    reverseString1(bin);
    char temp[7];
    for(int i = 0; i < 6-k; i++)
    {
        temp[i] = '0';
    }
    temp[6-k] = '\0';
    strcat(temp, bin);
    strcpy(bin, temp);
}

void decoder(char str[])
{
    int equal = 0;
    int ascii = -1;
    char bin[7];
    char ans[1000] = "";
    if(strlen(str) < 4)
    {
        printf("Invalid base64 encoded string");
        return;
    }
    if(str[strlen(str) - 2]=='=' && str[strlen(str) - 1]!='=')
    {
        printf("Invalid base64 encoded string");
        return;
    }
    for(int i = 0; i < strlen(str) - 2; i++)
    {
        char curr = str[i];
        if(curr=='=')
        {
            printf("Invalid base64 encoded string");
            return;
        }
    }
    for(int i = 0; i < strlen(str); i++)
    {
        char curr = str[i];
        int temp = -1;
        if(curr >= 'A' && curr <='Z')
        {
            temp = curr - 'A';
        }
        else if(curr >= 'a' && curr <= 'z')
        {
            temp = curr - 'a' + 26;
        }
        else if(curr >= '0' && curr <= '9')
        {
            temp = curr - '0' + 52;
        }
        else if(curr=='+')
        {
            temp = 62;
        }
        else if(curr=='/')
        {
            temp = 63;
        }
        else if(curr=='='){
            equal++;
        }
        else{
            printf("Invalid base64 encoded string");
            return;
        }
        if(temp >= 0)
        {
            toBinary1(temp, bin);
            strcat(ans, bin);
        }
    }
    
    ans[strlen(ans) - (equal * 2)] = '\0';
    if(strlen(ans)%8!=0)
    {
        printf("Invalid base64 encoded string");
        return;
    }
    for(int i = 0; i < strlen(ans)/8; i++)
    {
        int index = 0;
        char temp[9] = "";
        for(int j = i * 8; j < 8 * (i + 1); j++)
        {
            temp[index++] = ans[j];
        }
        temp[8] = '\0';
        int a = toInt1(temp);
        if(a > 127)
        {
            printf("Invalid base64 encoded string");
            return;
        }
        printf("%c", a);
    }
}