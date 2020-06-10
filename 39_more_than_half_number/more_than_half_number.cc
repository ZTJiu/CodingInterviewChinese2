#include <iostream>
#include <vector>

bool ValidInput(const std::vector<int>& nums, int num) {
  int count = 0;
  for (int elem : nums) {
    if (elem == num) ++count;
  }
  return count > (nums.size() >> 1);
}

int MoreThanHalfNumber(const std::vector<int>& nums) {
  if (nums.empty()) throw std::invalid_argument("empty input");
  int times = 1;
  int current = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    if (times > 0) {
      if (nums[i] == current) {
        ++times;
      } else {
        --times;
      }
    } else {
      times = 1;
      current = nums[i];
    }
  }
  if (!ValidInput(nums, current)) throw std::invalid_argument("invalid inputs");
  return current;
}

int main(int argc, char* argv[]) {
  // std::vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
  std::vector<int> nums = {};
  std::cout << MoreThanHalfNumber(nums) << std::endl;
  return 0;
}