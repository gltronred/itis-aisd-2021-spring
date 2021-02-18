
// Компиляция:
// g++ -Wall -Wextra -o bin1 1.cpp

// Подключение библиотек
#include <iostream>

// std - пространство имён
// если надоело писать std::
using namespace std;

// Структуры
struct intpair {
  int first;
  int second;
};

struct phone {
  int price;
  double weight;
  double screen;
};

void workStr() {
  intpair ip;
  ip.first = 3;
  ip.second = 4;

  cout << ip.first << " " << ip.second << endl;

  phone p;
  p.price = 19999;
  p.weight = 123.45;
  p.screen = 6.3;

  cout << p.price << " " << p.weight << " " << p.screen << endl;
}

// Функции
int sum2(int n) {
  int s = 0;
  // циклы - for, while, do-while
  for (int i=0; i<n; i++) {
    // условия - if, switch-case
    if (i % 2 == 1) {
      s += i*i;
    }
  }
  return s;
}

void print() {
  cout << "Hello!" << endl;
}

// Является ли число простым?
// 1 - не простое
// отрицательные - не простые
// примеры простых: 2, 3, 5, 7, 11, 13, 17, 19
bool isPrime(int n) {
  if (n<2) return false;
  for (int i=2; i*i<=n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

// Массивы
void workArr(int n) {
  // на стеке
  bool b[8];
  // в куче
  int* a = new int[n];
  // работа с массивами
  for (int i=0; i<n; i++) {
    a[i] = 2*i;
  }
  for (int i=0; i<8; i++) {
    b[i] = false;
    int x = (1 << i); // сдвиг влево на i битов
    for (int j=0; j<n; j++) {
      b[i] |= (a[j] & x) > 0;
    }
  }
  for (int i=0; i<8; i++) {
    // вместо b[i] можно писать *(b+i)
    if (*(b+i))
      cout << i << " ";
  }
  cout << endl;

  // освобождение памяти
  delete[] a;
}

// точка входа
int main() {
  // объявление переменной и инициализация
  int x = 0;
  // объявление без инициализации
  int y;
  // присваивания, арифметика
  y = (x+1) * 2 % 3;

  // ввод-вывод
  int n;
  cin >> n;
  cout << sum2(n+2) << " " << isPrime(n) << endl;
  print();
  cout << x << " " << y << endl;

  workArr(12);

  workStr();

  // код возврата (0 - нет ошибки)
  return 0;
}
