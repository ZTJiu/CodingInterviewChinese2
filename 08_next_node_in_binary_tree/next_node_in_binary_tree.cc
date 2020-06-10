#include <iostream>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
  struct TreeNode* parent;
};

TreeNode inOrderNextNode(TreeNode* root) {
  if (!root) return nullptr;
  TreeNode* next = nullptr;
  if (root->right) {
    next = root->right;
    while (next->left) {
      next = next->left;
    }
  } else if (root->parent) {
    TreeNode* current = root;
    TreeNode* parent = current->parent;
    while (parent && current != parent->left) {
      current = parent;
      parent = parent->parent;
    }
    next = parent;
  }
  return next;
}