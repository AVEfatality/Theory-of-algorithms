#include<stdio.h>
#include <time.h>

// Prints a maximum set of activities that can be done by a single
// person, one at a time.
//  n   -->  Total number of activities
//  s[] -->  An array that contains start time of all activities
//  f[] -->  An array that contains finish time of all activities
void printMaxActivities(int *s, int *f, int n)
{
    int i, j;

    printf ("Selected activities:\n");

    // The first activity always gets selected
    i = 0;
    printf("%d ", i);

    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (s[j] >= f[i])
      {
          printf ("%d ", j);
          i = j;
      }
    }
}

// driver program to test above function
int main()
{
    int s[50],f[50];
    int k;
    srand(time(NULL));
    printf ("Start time:\n");
    for ( k = 0; k < 50; k ++)
    {
    s[k] = rand()%100;
    printf ("%d ",s[k]);
    }
    printf ("\n");
    printf ("Finish time:\n");
    for ( k = 0; k < 50; k ++)
    {
    f[k] = rand()%100;
    printf ("%d ",f[k]);
    }
    printf ("\n");

    printMaxActivities(s, f, 50);
    getchar();
    return 0;
}
