#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int compute(int n, const char* const expr) {
  return 0;
}

int main() {
  string s;
  getline(cin,s);
  int n = strlen(s.c_str());
  cout << compute(n, s.c_str()) << endl;
  return 0;
}
