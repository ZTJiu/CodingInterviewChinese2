#include <iostream>
#include <vector>

bool findInPartiallySortedMatrix(const std::vector<std::vector<int>>& matrix,
                                 int num) {
  int max_row = matrix.size();
  int max_col = matrix.front().size();
  int row = 0;
  int col = max_col - 1;
  if (matrix.empty() || matrix.front().empty()) return false;
  while (row < max_row && col >= 0) {
    int tmp = matrix[row][col];
    if (tmp != num) {
      if (tmp > num) {
        --col;
      } else {
        ++row;
      }
    } else {
      return true;
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> matrix = {
      {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
  std::cout << findInPartiallySortedMatrix(matrix, 1) << std::endl;
  std::cout << findInPartiallySortedMatrix(matrix, 6) << std::endl;
  std::cout << findInPartiallySortedMatrix(matrix, 7) << std::endl;
  std::cout << findInPartiallySortedMatrix(matrix, 11) << std::endl;
  std::cout << findInPartiallySortedMatrix(matrix, 15) << std::endl;
  std::cout << findInPartiallySortedMatrix(matrix, 20) << std::endl;
  return 0;
}