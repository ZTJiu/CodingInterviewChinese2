#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* FindMeetingNode(ListNode* head) {
  if (!head || head->next == nullptr) return nullptr;
  ListNode* first = head;
  ListNode* second = head->next->next;
  while (second) {
    if (first == second) return second;
    if (second->next == nullptr) return nullptr;
    first = first->next;
    second = second->next->next;
  }
  return second;
}

ListNode* FindEntryNode(ListNode* head) {
  ListNode* meeting_node = FindMeetingNode(head);
  if (!meeting_node) return nullptr;
  int loop_size = 1;
  ListNode* tmp = meeting_node->next;
  while (tmp != meeting_node) {
    ++loop_size;
    tmp = tmp->next;
  }
  for (int i = 0; i < loop_size; ++i) head = head->next;
  while (head != meeting_node) {
    meeting_node = meeting_node->nex;
    head = head->next;
  }
  return head;
}