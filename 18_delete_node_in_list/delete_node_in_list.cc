#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* CreateList(int n) {
  if (n <= 0) return nullptr;
  ListNode* head = nullptr;
  for (int i = n; i > 0; --i) {
    for (int j = 1; j <= i; ++j) {
      ListNode* node = new ListNode(i);
      if (head) {
        node->next = head;
        head = node;
      } else {
        head = node;
      }
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

ListNode* FindNode(ListNode* head, int val) {
  while (head) {
    if (head->val == val) return head;
    head = head->next;
  }
  return nullptr;
}

void DeleteListNode(ListNode** head, ListNode* node_to_delete) {
  if (!head || !(*head) || !node_to_delete) return;
  if (node_to_delete->next) {
    ListNode* tmp = node_to_delete->next;
    node_to_delete->val = tmp->val;
    node_to_delete->next = tmp->next;
    delete tmp;
  } else if (*head == node_to_delete) {
    *head = nullptr;
    delete node_to_delete;
  } else {
    ListNode* cur = *head;
    while (cur && cur->next != node_to_delete) {
      cur = cur->next;
    }
    if (!cur) throw std::logic_error("node to delete is not in list");
    cur->next = nullptr;
    delete node_to_delete;
  }
}

void DeleteDuplicatedNode(ListNode* head) {
  if (!head || head->next == nullptr) return;
  ListNode* cur = head;
  ListNode* next = head->next;
  while (next && cur) {
    while (next && cur->val == next->val) {
      ListNode* tmp = next;
      next = next->next;
      cur->next = next;
      delete tmp;
    }
    if (next) {
      cur = next;
      next = next->next;
    }
  }
}

int main(int argc, char* argv[]) {
  ListNode* head = CreateList(10);
  PrintList(head);

  DeleteDuplicatedNode(head);
  PrintList(head);

  /*std::cout << "delete last node" << std::endl;
  ListNode* last_node = FindNode(head, 10);
  DeleteListNode(&head, last_node);
  PrintList(head);

  std::cout << "delete 5th node" << std::endl;
  ListNode* fifth_node = FindNode(head, 5);
  DeleteListNode(&head, fifth_node);
  PrintList(head);

  std::cout << "detete head" << std::endl;
  while (head->next) {
    ListNode* tmp = head->next;
    head->next = tmp->next;
    delete tmp;
  }
  PrintList(head);
  DeleteListNode(&head, head);
  std::cout << ((head == nullptr) ? "Yes, it's nullptr"
                                  : "No, it's not nullptr")
            << std::endl;*/
  return 0;
}