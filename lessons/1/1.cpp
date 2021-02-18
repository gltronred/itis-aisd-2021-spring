
// Компиляция:
// g++ -Wall -Wextra -o bin1 1.cpp

// Подключение библиотек
#include <iostream>

// std - пространство имён
// если надоело писать std::
using namespace std;

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

  // код возврата (0 - нет ошибки)
  return 0;
}
