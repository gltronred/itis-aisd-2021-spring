#include <iostream>

using namespace std;

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
  elem* p = head;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}

// Возвращает сумму элементов списка
int sum_list(elem* head) {
  int s = 0;
  elem* p = head;
  // NULL == 0, а 0 считается false в условиях
  // поэтому (p != NULL) эквивалентно (p)
  while (p) {
    s += p->val;
    p = p->next;
  }
  return s;
}

// Вернуть список, из которого удалены все чётные
// элементы
// Не забудьте вызвать delete
elem* filter_odd(elem* head) {
  while (head && head->val % 2 == 0) {
    elem* q = head;
    head = head->next;
    delete q;
  }
  elem* p = head;
  while (p) {
    // while - чтобы удалить все четные элементы,
    // идущие подряд
    // Можно написать if и сдвигаться дальше только
    // если мы не удаляли элемент
    while (p->next && p->next->val % 2 == 0) {
      elem* q = p->next;
      p->next = p->next->next;
      delete q;
    }
    p = p->next;
  }
  return head;
}

int main() {
  elem* head = empty_list();
  head = add(head, 1);
  head = add(head, 2);
  head = add(head, 2);
  head = add(head, 3);
  head = add(head, -124);
  head = add(head, -126);
  print_list(head);
  cout << sum_list(head) << endl;
  head = filter_odd(head);
  print_list(head);
  return 0;
}
