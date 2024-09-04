#include "../include/searching.h"

int linearSearch(int arr[], int target, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int target, int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while(s<=e)
    {
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}