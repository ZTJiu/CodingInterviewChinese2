#include <iostream>
#include <string>

void Print1ToNCore(std::string& str, int pos) {
  if (pos == str.size()) {
    bool found_first_pos = false;
    for (auto c : str) {
      if (c != '0') {
        found_first_pos = true;
      }
      if (found_first_pos) std::cout << c;
    }
    if (!found_first_pos) std::cout << '0';
    std::cout << std::endl;
    return;
  }
  for (int i = 0; i < 10; ++i) {
    str[pos] = '0' + i;
    Print1ToNCore(str, pos + 1);
  }
}

void Print1ToN(int n) {
  if (n <= 0) return;
  std::string str(n, '0');
  Print1ToNCore(str, 0);
}

int main(int argc, char* argv[]) {
  int n = std::stoi(argv[1]);
  Print1ToN(n);
  return 0;
}