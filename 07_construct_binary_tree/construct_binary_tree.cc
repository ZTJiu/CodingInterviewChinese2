#include <iostream>
#include <queue>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val_) : val(val_), left(nullptr), right(nullptr) {}
};

void createTreeCore(TreeNode* root, int num) {
  int l = root->val * 2 + 1;
  int r = root->val * 2 + 2;
  if (l < num) {
    TreeNode* l_node = new TreeNode(l);
    root->left = l_node;
    createTreeCore(l_node, num);
  }
  if (r < num) {
    TreeNode* r_node = new TreeNode(r);
    root->right = r_node;
    createTreeCore(r_node, num);
  }
}

TreeNode* createTree(int num) {
  TreeNode* root = new TreeNode(0);
  createTreeCore(root, num);
  return root;
}

void levelOrderPrintTree(TreeNode* root) {
  if (!root) return;
  std::queue<TreeNode*> queue;
  queue.push(root);
  int curr_num = 1;
  while (!queue.empty()) {
    int next_num = 0;
    for (int i = 0; i < curr_num; ++i) {
      TreeNode* tmp = queue.front();
      queue.pop();
      std::cout << tmp->val << "\t";
      if (tmp->left) {
        queue.push(tmp->left);
        ++next_num;
      }
      if (tmp->right) {
        queue.push(tmp->right);
        ++next_num;
      }
    }
    curr_num = next_num;
    std::cout << std::endl;
  }
}

TreeNode* constructBinaryTreeCore(const std::vector<int>& pre_order,
                                  int pre_beg, int pre_end,
                                  const std::vector<int>& in_order, int in_beg,
                                  int in_end) {
  if (pre_beg >= pre_end) return nullptr;
  int in_root_index = in_beg;
  while (in_root_index < in_end) {
    if (in_order[in_root_index] == pre_order[pre_beg]) break;
    ++in_root_index;
  }
  int l_len = in_root_index - in_beg;
  TreeNode* root = new TreeNode(pre_order[pre_beg]);
  root->left =
      constructBinaryTreeCore(pre_order, pre_beg + 1, pre_beg + 1 + l_len,
                              in_order, in_beg, in_root_index);
  root->right = constructBinaryTreeCore(pre_order, pre_beg + 1 + l_len, pre_end,
                                        in_order, in_root_index + 1, in_end);
  return root;
}

TreeNode* constructBinaryTree(const std::vector<int>& pre_order,
                              const std::vector<int>& in_order) {
  if (pre_order.empty() || in_order.empty() ||
      pre_order.size() != in_order.size())
    return nullptr;
  return constructBinaryTreeCore(pre_order, 0, pre_order.size(), in_order, 0,
                                 in_order.size());
}

int main(int argc, char* argv[]) {
  // TreeNode* root = createTree(10);
  std::vector<int> pre_order = {1, 2, 4, 7, 3, 5, 6, 8};
  std::vector<int> in_order = {4, 7, 2, 1, 5, 3, 8, 6};
  TreeNode* root = constructBinaryTree(pre_order, in_order);
  levelOrderPrintTree(root);
  return 0;
}