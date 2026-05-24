#include <stdio.h>
#include <stdlib.h>

int n;
int vis[100];
int G[100][100];

void DFS(int v)
{
  int j;
  printf("%d\t", v);
  vis[v] = 1;

  for (j = 1; j <= n; j++)
  {
    if (!vis[j] && G[v][j] == 1)
    {
      DFS(j);
    }
  }
}

int main()
{
  int s, i, j;

  printf("Enter the no of vertices:");
  if (scanf("%d", &n) != 1)
    return 1;

  printf("Enter the adjacency matrix:\n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      if (scanf("%d", &G[i][j]) != 1)
        return 1;
    }
  }

  for (i = 1; i <= n; i++)
  {
    vis[i] = 0;
  }

  printf("Enter the source vertex(1 to %d):", n);
  if (scanf("%d", &s) != 1)
    return 1;

  printf("\nThe DFS Traversal is:\n");

  DFS(s);

  printf("\n");
  return 0;
}