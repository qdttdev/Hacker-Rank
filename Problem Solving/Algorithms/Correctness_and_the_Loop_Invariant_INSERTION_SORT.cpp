#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(int N, int arr[]) 
{
    int i,j;
    int temp;

    for(i = 1; i < N; i++) // Starts from 2nd index, i = current index
    {
        temp = arr[i];
        j = i - 1; // j = previous index

        while(j >= 0 && temp < arr[j]) // current < previous
        {
            arr[j+1] = arr[j]; // current = previous
            j--; // decrement previous
        }
        
        arr[j+1] = temp;
    }

    for(j=0;j<N;j++)
    {
        printf("%d",arr[j]);
        printf(" ");
    }
}
int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(N, arr);

    return 0;
}
