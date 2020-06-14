#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* CreateList(int n) {
  ListNode* head = nullptr;
  for (int i = n; i > 0; --i) {
    ListNode* tmp = new ListNode(i);
    if (head) {
      tmp->next = head;
      head = tmp;
    } else {
      head = tmp;
    }
  }
  return head;
}

void PrintList(ListNode* head) {
  while (head) {
    std::cout << head->val << "\t";
    head = head->next;
  }
  std::cout << std::endl;
}

ListNode* ReverseList(ListNode* head) {
  ListNode* cur = head;
  ListNode* pre = nullptr;
  while (cur) {
    ListNode* tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }
  return pre;
}

int main(int argc, char* argv[]) {
  int n = std::stoi(argv[1]);
  ListNode* head = CreateList(n);
  PrintList(head);
  head = ReverseList(head);
  PrintList(head);
  return 0;
}