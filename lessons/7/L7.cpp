#include <iostream>

int* parent;
int* rank;

void init(int n) {
  parent = new int[n];
  rank = new int[n];
  for (int i=0; i<n; i++) {
    parent[i]=i;
    rank[i]=0;
  }
}

int find(int x) {
  if (parent[x] == x)
    return x;
  else
    return find(parent[x]);
}

void join(int x, int y) {
  int i = find(x);
  int j = find(y);
  if (i == j) return;
  if (rank[i] < rank[j]) {
    parent[i] = j;
  } else {
    parent[j] = i;
    if (rank[i] == rank[j])
      rank[i]++;
  }
}

int main() {
  return 0;
}
