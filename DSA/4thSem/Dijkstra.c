#include <stdio.h>
#define size 10
#define INF 9999
int n, dist[size];

void dijk(int s, int cos[size][size]) {
  int pred[size], vis[size], count, min, u, i, j;
  for (i = 1; i <= n; i++) {
    dist[i] = cos[s][i];
    vis[i] = 0;
    pred[i] = s;
  }
  dist[s] = 0;
  vis[s] = 1;
  count = 2;
  while (count <= n) {
    min = INF;
    for (i = 1; i <= n; i++) {
      if (dist[i] < min && !vis[i]) {
        min = dist[i];
        u = i;
      }
    }
    vis[u] = 1;
    for (i = 1; i <= n; i++) {
      if (dist[u] + cos[u][i] < dist[i] && !vis[i]) {
        dist[i] = dist[u] + cos[u][i];
        pred[i] = u;
      }
    }
    count++;
  }
}

int main() {
  int s, i, j, cos[size][size];
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  printf("Enter the adjacency matrix: ");
  for (i = 1; i <=n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", &cos[i][j]);
      if (cos[i][j] == 0) cos[i][j] = INF;
    }
  }
  printf("Enter the source vertex: ");
  scanf("%d", &s);
  dijk(s, cos);
  printf("Shortest distance from source to vertex: ");
  for (i = 1; i <= n; i++) {
    if (i != s) {
      printf("%d ---> %d (cost = %d)\n", s, i, dist[i]);
    }
  }
  return 0;
}