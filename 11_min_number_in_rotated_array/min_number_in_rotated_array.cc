#include <iostream>
#include <vector>

int Min(const std::vector<int>& nums, int num) {
  int beg = 0;
  int end = nums.size() - 1;
  int mid = beg + ((end - beg + 1) >> 1);
  while (nums[beg] >= nums[end]) {
    if (end - beg == 1) {
      mid = end;
      break;
    }
    if (nums[beg] == nums[end] && nums[beg] == nums[mid]) {
      mid = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < nums[mid]) mid = i;
      }
      break;
    }
    if (nums[mid] >= nums[beg]) {
      beg = mid;
    } else if (nums[mid] <= nums[end]) {
      end = mid;
    }
    mid = beg + ((end - beg + 1) >> 1);
  }
  return nums[mid];
}

int main(int argc, char* argv[]) {
  // std::vector<int> nums = {5, 6, 7, 8, 1, 2, 3, 4};
  std::vector<int> nums = {1, 0, 1, 1, 1};
  std::cout << Min(nums, 0) << std::endl;
  return 0;
}