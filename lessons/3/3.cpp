#include <iostream>

using namespace std;

struct elem {
  int val;
  elem* next;
};

elem* add(elem* head, int x) {
  elem* p = new elem;
  p->val = x;
  p->next = head;
  return p;
}

void print_list(elem* head) {
  elem* p = head;
  while (p != NULL) {
    cout << p->val << " " << endl;
    p = p->next;
  }
  cout << endl;
}


int main() {
  int k,n;
  cin >> k >> n;
  elem* head = NULL;
  head = add(head,0);
  elem* p = head;
  for (int i=1; i<n; i++) {
    head = add(head, i);
  }
  p->next = head;
  for (int i=0; i<k; i++) {
    head = add(head, i+n);
  }

  print_list(head);
  return 0;
}