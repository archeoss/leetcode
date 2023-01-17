/*
  74. Search a 2D Matrix

  You are given an m x n integer matrix matrix with the following two
  properties:

  Each row is sorted in non-decreasing order.
  The first integer of each row is greater than the last integer of the previous
  row.

  Given an integer target, return true if target is in matrix or false
  otherwise.

  You must write a solution in O(log(m * n)) time complexity.

  Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
  Output: true

  Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
  Output: false
*/
class Solution {
  int ROWS, COLS;

public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    ROWS = matrix.size(), COLS = matrix[0].size();
    int begin = 0, end = ROWS * COLS;
    int mid, num;
    bool res = false;
    while (begin < end) {
      mid = (begin + end) / 2;
      num = matrix[mid / COLS][mid % COLS];

      if (target == num) {
        res = true;
        break;
      }
      if (target < num) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }

    return res;
  }
};
