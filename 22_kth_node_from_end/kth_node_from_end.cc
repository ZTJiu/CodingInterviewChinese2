#include <iostream>
#include <string>

struct ListNode {
  int val;
  struct ListNode* next;
  ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* FindKthNodeFromEnd(ListNode* head, int k) {
  if (!head || k < 1) return nullptr;
  ListNode* first = head;
  ListNode* second = head;
  for (int i = 0; i < k; ++i) {
    if (!second) return nullptr;
    second = second->next;
  }
  while (second) {
    head = head->next;
    second = second->next;
  }
  return head;
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cout << "Usage: " << argv[0] << " number1 number2" << std::endl;
    return -1;
  }
  int m = std::stoi(argv[1]);
  int n = std::stoi(argv[2]);
  ListNode* head = nullptr;
  for (int i = m; i > 0; --i) {
    ListNode* node = new ListNode(i);
    if (head) {
      node->next = head;
      head = node;
    } else {
      head = node;
    }
  }
  ListNode* tmp = head;
  while (tmp) {
    std::cout << tmp->val << "\t";
    tmp = tmp->next;
  }
  std::cout << std::endl;

  ListNode* node = FindKthNodeFromEnd(head, n);
  if (node) {
    std::cout << n << "th node from end is " << node->val << std::endl;
  } else {
    std::cout << n << "th node from end is not found" << std::endl;
  }
  return 0;
}