#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX 100

void sortStrings(char arr[][MAX], int n)
{
    char temp[100];

    // Sorting strings using bubble sort
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = j + 1; i < n; i++)
        {
            if (strcmp(arr[j], arr[i]) > 0)
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[i]);
                strcpy(arr[i], temp);
            }
        }
    }
}

int main()
{
    char arr[][MAX] = {"Makefile", "LICENSE.md", "README.md ","inc","libmx", "a.out",};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortStrings(arr, n);

    for (int i = 0; i < n; i++)
        printf("%s      ", arr[i]);
    return 0;
}