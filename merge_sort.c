#include<stdio.h>
#include <stdlib.h>

void mergeSort(int *arr,int low,int mid,int high)
{

    int i,m,k,l,temp[50];

    l = low;
    i = low;
    m = mid+1;

    while((l <= mid)&&(m <= high))
        {

         if(arr[l] <= arr[m])
        {
             temp[i] = arr[l];
             l++;
         }
         else{
             temp[i] = arr[m];
             m++;
         }
         i++;
    }

    if(l > mid)
    {
         for(k = m; k <= high; k++)
        {
             temp[i] = arr[k];
             i++;
         }
    }
    else
    {
         for(k = l; k <= mid; k++)
        {
             temp[i] = arr[k];
             i++;
        }
    }

    for(k = low; k <= high; k++)
    {
         arr[k] = temp[k];
    }
}

void dividing(int *arr,int low,int high)
{

    int mid;
    if(low < high)
    {
         mid = (low+high)/2;
         dividing(arr, low, mid);
         dividing(arr, mid+1, high);
         mergeSort(arr, low, mid, high);
    }
}

int main()
{

    int m[50],i;
    printf ("Before sorting:\n");

    for ( i = 0; i < 50; i ++)
    {
    m[i] = rand()%100;
    printf ("%d ",m[i]);
    }
    printf ("\n");
    dividing(m,0,49);

    printf("After sorting:\n");
    for(i = 0; i < 50; i++)
    {
         printf("%d ",m[i]);
    }

   return 0;
}
