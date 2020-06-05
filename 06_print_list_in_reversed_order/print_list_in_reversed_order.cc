#include <iostream>

struct List {
  int val;
  struct List* next;
};

List* createList(int num) {
  List* head = nullptr;
  for (int i = num - 1; i >= 0; --i) {
    List* tmp = new List();
    tmp->val = i;
    tmp->next = head;
    head = tmp;
  }
  return head;
}

void printList(List* head) {
  while (head) {
    std::cout << head->val << "\t";
    head = head->next;
  }
  std::cout << std::endl;
}

List* reverseList(List* head) {
  List* pre = nullptr;
  List* cur = head;
  while (cur) {
    List* next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }
  return pre;
}

void printListInReversedOrder(List* head) {
  if (!head) return;
  List* new_head = reverseList(head);
  List* cur = new_head;
  while (cur) {
    std::cout << cur->val << "\t";
    cur = cur->next;
  }
  std::cout << std::endl;
  reverseList(new_head);
}

int main(int argc, char* argv[]) {
  List* head = createList(10);
  printList(head);
  printListInReversedOrder(head);
  printList(head);
  return 0;
}