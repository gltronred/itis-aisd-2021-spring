#include <cstring>
#include <iostream>
#include <string>

using namespace std;

struct elem {
  int val;
  elem* next;
};

// & - чтобы можно было менять аргумент
// (передача по ссылке)
void push(elem*& head, int n) {
  elem *p = new elem;
  p->val = n;
  p->next = head;
  head = p;
}

int pop(elem*& head) {
  elem *p = head;
  head = head->next;
  int n = p->val;
  delete p;
  return n;
}

bool empty(elem* head) {
  return head == NULL;
}

int compute(int n, const char* const expr) {
  elem* head = NULL;
  for (int i=0; i<n; i++) {
    int a,b;
    switch(expr[i]) {
      case '+':
        a = pop(head);
        b = pop(head);
        push(head, b+a);
        break;
      case '-':
        a = pop(head);
        b = pop(head);
        push(head, b-a);
        break;
      case '*':
        a = pop(head);
        b = pop(head);
        push(head, b*a);
        break;
      case ' ':
        break;
      default:
        a = expr[i] - '0';
        push(head, a);
    }
  }
  return pop(head);
}

int main() {
  string s;
  getline(cin,s);
  int n = strlen(s.c_str());
  cout << compute(n, s.c_str()) << endl;
  return 0;
}
