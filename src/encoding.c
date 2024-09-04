#include <stdio.h>
#include <string.h>
#include "../include/encoding.h"

void reverseString(char *str) {
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

void toBinary(int a, char bin[])
{
    int k = 0;
    while(a!=0)
    {
        int rem = a % 2;
        bin[k++] = rem + '0';
        a = a / 2;
    }
    bin[k] = '\0';
    reverseString(bin);
    char temp[9];
    for(int i = 0; i < 8-k; i++)
    {
        temp[i] = '0';
    }
    temp[8-k] = '\0';
    strcat(temp, bin);
    strcpy(bin, temp);
}

int toInt(char str[])
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

char base(int b)
{
    if(b >= 0 && b <= 25)
    {
        return b + 'A';
    }
    else if(b >= 26 && b<=51)
    {
        return b + 'a' - 26;
    }
    else if(b >= 52 && b<=61)
    {
        return b + '0' - 52;
    }
    else if(b==62)
    {
        return '+';
    }
    else{
        return '/';
    }
}

void encoder(char str[])
{
    int n = strlen(str);
    char bin[1000] = "";
    for(int i = 0; i < n; i++)
    {
        char temp[9];
        int a = str[i];
        toBinary(a, temp);
        strcat(bin, temp);
    }
    n = strlen(bin);
    int state = 0;
    if(n%6==4)
    {
        bin[n++] = '0';
        bin[n++] = '0';
        bin[n] = '\0';
        state = 1;
    }
    else if(n%6==2)
    {
        bin[n++] = '0';
        bin[n++] = '0';
        bin[n++] = '0';
        bin[n++] = '0';
        bin[n] = '\0';
        state = 2;
    }
    char ans[1000] = "";
    strcpy(str, ans);
    int l = 0;
    for(int i = 0; i < n/6; i++)
    {
        char temp1[7] = "";
        int index = 0;
        for(int j = i * 6; j < 6 * (i + 1); j++)
        {
            temp1[index++] = bin[j];
        }
        temp1[index] = '\0';
        int b = toInt(temp1);
        str[l++] = base(b);
    }
    if(state==1)
    {
        str[l++] = '=';
    }
    if(state==2)
    {
        str[l++] = '=';
        str[l++] = '=';
    }
    str[l] = '\0';
}