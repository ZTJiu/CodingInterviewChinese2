#include <iostream>
#include <string>

int NumberOf1InBinary(int n) {
  int count = 0;
  while (n != 0) {
    ++count;
    n = n & (n - 1);
  }
  return count;
}

int main(int argc, char *argv[]) {
  int n = std::stoi(argv[1]);
  std::cout << NumberOf1InBinary(n) << std::endl;
  return 0;
}