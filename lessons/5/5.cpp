#include <iostream>

using namespace std;

const int N=10000;
bool a[N][N];
bool b[N];
int c[N];
int d;

int main() {
  int n;
  cin >> n;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      int x;
      cin >> x;
      a[i][j]=(x>0);
    }
  }
  int cnt = 0;
  // посчитайте количество
  // компонент связности
  for (int i=0; i<n; i++)
    b[i]=false;
  d = 0;
  // есть ли ещё
  // не пройденные вершины
  bool f = true;
  do {
    f = true;
    int k=0;
    while (k<n && f) {
      f &= b[k];
      k++;
    }
    if (!f) {
      // кладу в стэк
      //cout << "ST: " << k << endl;
      c[d]=k;
      d++;
      // помечаю вершину как пройденную
      b[k]=true;
      // пока стэк не пуст
      while (d>0) {
        // вытаскиваю вершину
        --d;
        k=c[d];
        // cout << "CUR:" << k << endl;
        // добавляю все связанные
        // вершины, где я не был
        for (int i=0;i<n;i++)
          if(a[k][i]==1 && !b[i]) {
            c[d++]=i;
            b[i]=true;
          }
      }
      // увеличиваю количество
      // компонент связности
      cnt++;
    }
  } while (!f);
  // вывод
  cout << cnt << endl;
  return 0;
}
