
// Компиляция:
// g++ -Wall -Wextra -o bin1 1.cpp

// Подключение библиотек
#include <iostream>

// std - пространство имён
// если надоело писать std::
using namespace std;

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
  cout << x << " " << y << " " << n << endl;

  // код возврата (0 - нет ошибки)
  return 0;
}
