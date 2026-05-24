#include <stdio.h>
#include <stdlib.h>
int x[20], count = 0;

int Place(int k, int i)
{
  int j;
  for (j = 1; j <= k - 1; j++)
  {
    if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
    {
      return 0; 
    }
  }
  return 1; 
}

void N_Queen(int k, int n)
{
  int i, j, l;
  for (i = 1; i <= n; i++)
  {
    if (Place(k, i))
    {
      x[k] = i;

      if (k == n)
      {
        count++;
        for (j = 1; j <= n; j++)
        {
          printf("%d ", x[j]);
        }
        printf("\n");

        for (j = 1; j <= n; j++)
        {
          printf("\n");
          for (l = 1; l <= n; l++)
          {
            if (l == x[j])
            {
              printf("Q "); 
            }
            else
            {
              printf("_ ");
            }
          }
        }
        printf("\n-------------------\n");
      }
      else
      {
        N_Queen(k + 1, n);
      }
    }
  }
}

int main()
{
  int n;
  printf("Enter the number of queens: ");
  scanf("%d", &n);

  printf("Solutions for %d-Queens:\n\n", n);
  N_Queen(1, n);

  if (count == 0) printf("Cannot place %d queens in the correct order.");
  else  printf("Can be done in %d wasy", count);
  return 0;
}