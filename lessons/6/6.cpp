#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main() {
  int n;
  cin >> n;

  list<int> a[n];
  for (int i=0; i<n; i++) {
    int m;
    cin >> m;
    for (int j=0; j<m; j++) {
      int x;
      cin >> x;
      a[i].push_back(x-1);
    }
  }

  // a[i] - список вершин, связанных с i-й
  // ваше решение тут
  bool f=false;
  int visited[n];
  for (int i=0; i<n; i++) visited[i]=0;
  queue<int> q;
  int k=0;
  do {
    q.push(k);
    visited[k]=1;

    while (!q.empty()) {
      k=q.front();
      q.pop();
      for (auto it=a[k].begin(); it!=a[k].end(); ++it) {
        int x = *it;
        f |= (visited[x] == visited[k]);
        if (visited[x]==0) {
          q.push(x);
          visited[x]=3-visited[k];
        }
      }
    }

    k=0;
    while(k<n && visited[k]!=0) k++;
  } while (!f && k<n);

  if (!f) {
    cout << "YES" << endl;
    for (int d=1; d<3; d++) {
      for (int i=0; i<n; i++)
        if (visited[i]==d)
          cout << (i+1) << " ";
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
