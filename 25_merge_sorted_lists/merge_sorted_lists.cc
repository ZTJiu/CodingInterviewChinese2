#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* CreateList(int beg, int end) {
  if (beg > end) return nullptr;
  ListNode* head = nullptr;
  for (int i = end; i >= beg; --i) {
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

ListNode* MergeSortedList(ListNode* head1, ListNode* head2) {
  if (!head1) return head2;
  if (!head2) return head1;
  ListNode* head = nullptr;
  ListNode* tail = nullptr;
  while (head1 && head2) {
    ListNode* tmp = nullptr;
    if (head1->val > head2->val) {
      tmp = head2;
      head2 = head2->next;
    } else {
      tmp = head1;
      head1 = head1->next;
    }
    tmp->next = nullptr;
    if (head) {
      tail->next = tmp;
      tail = tmp;
    } else {
      head = tmp;
      tail = tmp;
    }
  }
  if (head1) {
    tail->next = head1;
  }
  if (head2) tail->next = head2;
  return head;
}

int main(int argc, char* argv[]) {
  if (argc < 5) {
    std::cout << argv[0] << " beg1 end1 beg2 end2" << std::endl;
    return -1;
  }
  int beg1 = std::stoi(argv[1]);
  int end1 = std::stoi(argv[2]);
  int beg2 = std::stoi(argv[3]);
  int end2 = std::stoi(argv[4]);
  ListNode* head1 = CreateList(beg1, end1);
  ListNode* head2 = CreateList(beg2, end2);
  PrintList(head1);
  PrintList(head2);
  ListNode* head = MergeSortedList(head1, head2);
  PrintList(head);
  return 0;
}