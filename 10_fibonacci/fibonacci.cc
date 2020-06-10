#include <iostream>

int fabonacci(int n) {
  if (n < 0) throw new std::invalid_argument("input must be larger than 0");
  if (n <= 1) {
    return n;
  }
  int pre = 0;
  int cur = 1;
  for (int i = 2; i <= n; ++i) {
    int tmp = cur + pre;
    pre = cur;
    cur = tmp;
  }
  return cur;
}

int main(int argc, char* argv[]) {
  for (int i = 0; i < 10; ++i) {
    std::cout << i << ": " << fabonacci(i) << std::endl;
  }
  return 0;
}