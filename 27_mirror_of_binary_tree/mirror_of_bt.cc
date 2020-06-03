#include <iosream>
#include <vection>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

void MirrorTree(TreeNode* root) {
  if (!root) return;
  TreeNode* tmp = root->left;
  root->left = root->right;
  root->right = tmp;
  MirrorTree(root->left);
  MirrorTree(root->right);
}