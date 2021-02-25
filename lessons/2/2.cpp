#include <iostream>

struct elem {
  int val;
  elem* next;
};

elem* add(elem* head, int x) {
  elem* p = new elem;
  // ОШИБКА! Компилятор посоветует p->val
  // p.val = x;
  (*p).val = x; // То же, что p->val = x;
  p->next = head;
  return p;
}

elem* empty_list() {
  return NULL;
}

void print_list(elem* head) {
}

int main() {
  elem* head = empty_list();
  head = add(head, 1);
  head = add(head, 3);
  head = add(head, -123);
  print_list(head);
  return 0;
}
