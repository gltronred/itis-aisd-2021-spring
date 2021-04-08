#include <iostream>

using std::cout;
using std::endl;

int count;
int* parent;
int* rank;

void init(int n) {
  count = n;
  parent = new int[n];
  rank = new int[n];
  for (int i=0; i<n; i++) {
    parent[i]=i;
    rank[i]=0;
  }
}

void destroy() {
  delete[] parent;
  delete[] rank;
  count = 0;
}

int find(int x) {
  if (parent[x] == x)
    return x;
  else {
    int y = find(parent[x]);
    parent[x] = y;
    return y;
  }
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

void debug_print() {
  cout << "-------------------" << endl;
  for (int i=0; i<count; i++)
    cout << i << "\t";
  cout << endl;
  for (int i=0; i<count; i++)
    cout << parent[i] << "\t";
  cout << endl;
  for (int i=0; i<count; i++)
    cout << rank[i] << "\t";
  cout << endl;
}

int main() {
  init(5);
  debug_print();
  join(1,2);
  debug_print();
  join(3,4);
  debug_print();
  join(2,3);
  debug_print();
  cout << find(4) << endl;
  debug_print();
  destroy();

  init(8);
  for (int i=0; i<5; i++) {
    join(2*i, 2*i+1);
  }
  join(0,2);
  join(4,6);
  join(0,4);
  debug_print();
  return 0;
}
