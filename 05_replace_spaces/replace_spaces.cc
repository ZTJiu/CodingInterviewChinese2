#include <iostream>
#include <string>

void ReplaceSpaces(std::string& str) {
  int space_num = 0;
  for (const auto& c : str) {
    if (c == ' ') ++space_num;
  }
  if (space_num == 0) return;
  int origin_len = str.size();
  str.resize(origin_len + space_num * 2);
  int l = origin_len - 1;
  int r = str.size() - 1;
  while (l < r) {
    if (str[l] == ' ') {
      str[r--] = '0';
      str[r--] = '2';
      str[r--] = '%';
      --l;
    } else {
      str[r--] = str[l--];
    }
  }
}

int main(int argc, char* argv[]) {
  std::string str = "We are happy";
  ReplaceSpaces(str);
  std::cout << str << std::endl;
  return 0;
}