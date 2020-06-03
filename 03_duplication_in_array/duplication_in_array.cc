#include <iostream>
#include <vector>

bool hasDuplication(std::vector<int>& nums, int* duplicated_num) {
  if (nums.empty()) return false;
  for (int num : nums) {
    if (num >= nums.size() || num < 0) return false;
  }
  for (int i = 0; i < nums.size(); ++i) {
    while (nums[i] != i) {
      if (nums[i] == nums[nums[i]]) {
        *duplicated_num = nums[i];
        return true;
      }
      int tmp = nums[nums[i]];
      nums[nums[i]] = nums[i];
      nums[i] = tmp;
    }
  }
  return false;
}

bool hasDuplication2(const std::vector<int>& nums, int* dup_num) {
  if (nums.empty()) return false;
  for (int num : nums) {
    if (num < 0 || num >= nums.size()) return false;
  }
  std::vector<int> new_nums(nums.size(), -1);
  for (int i = 0; i < nums.size(); ++i) {
    if (new_nums[nums[i]] == -1) {
      new_nums[nums[i]] = nums[i];
    } else {
      *dup_num = nums[i];
      return true;
    }
  }
  return false;
}

bool hasDuplication3(const std::vector<int>& nums, int* dup_num) {
  if (nums.empty()) return false;
  for (int num : nums) {
    if (num < 0 || num >= nums.size()) return false;
  }
  int l = 0;
  int r = nums.size();
  while (l < r) {
    int mid = l + (r - l) / 2;
    int count = 0;
    for (int num : nums) {
      if (num >= l && num < mid) {
        ++count;
      }
    }
    if (count > mid - l) {
      if (mid - l == 1) {
        *dup_num = l;
        return true;
      }
      r = mid;
    } else {
      if (r - mid == 1) {
        *dup_num = mid;
        return true;
      }
      l = mid;
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
  int dup_num = -1;
  // if (hasDuplication(nums, &dup_num)) {
  // if (hasDuplication2(nums, &dup_num)) {
  if (hasDuplication3(nums, &dup_num)) {
    std::cout << "dup_num: " << dup_num << std::endl;
  } else {
    std::cout << "no dup_num" << std::endl;
  }
  return 0;
}