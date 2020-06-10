#include <functional>
#include <iostream>
#include <vector>

void ReorderArray(std::vector<int>& arr, std::function<bool(int)> judger) {
  if (arr.empty()) return;
  int l = 0;
  int r = arr.size() - 1;
  while (l < r) {
    while (l < r && judger(arr[l])) ++l;
    while (r > l && !judger(arr[r])) --r;
    int tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> arr = {1, 2, 3, 4, 5, 6};
  for (auto& num : arr) std::cout << num << "\t";
  std::cout << std::endl;
  ReorderArray(arr, [](int num) { return num & 0x01; });
  for (auto& num : arr) std::cout << num << "\t";
  std::cout << std::endl;
  return 0;
}