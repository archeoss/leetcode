/*
  36. Valid Sudoku

  Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
  validated according to the following rules: Each row must contain
  the digits 1-9 without repetition. Each column must contain the
  digits 1-9 without repetition. Each of the nine 3 x 3 sub-boxes of the grid
  must contain the digits 1-9 without repetition. Note: A Sudoku board
  (partially filled) could be valid but is not necessarily solvable. Only the
  filled cells need to be validated according to the mentioned rules.

  Input: board =
  [["5","3",".",".","7",".",".",".","."]
  ,["6",".",".","1","9","5",".",".","."]
  ,[".","9","8",".",".",".",".","6","."]
  ,["8",".",".",".","6",".",".",".","3"]
  ,["4",".",".","8",".","3",".",".","1"]
  ,["7",".",".",".","2",".",".",".","6"]
  ,[".","6",".",".",".",".","2","8","."]
  ,[".",".",".","4","1","9",".",".","5"]
  ,[".",".",".",".","8",".",".","7","9"]]
  Output: true

  Input: board =
  [["8","3",".",".","7",".",".",".","."]
  ,["6",".",".","1","9","5",".",".","."]
  ,[".","9","8",".",".",".",".","6","."]
  ,["8",".",".",".","6",".",".",".","3"]
  ,["4",".",".","8",".","3",".",".","1"]
  ,["7",".",".",".","2",".",".",".","6"]
  ,[".","6",".",".",".",".","2","8","."]
  ,[".",".",".","4","1","9",".",".","5"]
  ,[".",".",".",".","8",".",".","7","9"]]
  Output: false
  Explanation: Same as Example 1, except with the 5 in the top left corner being
  modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is
  invalid.
  */

class Solution {
  int BOARD_SIZE;

public:
  bool isValidSudoku(vector<vector<char>> &board) {
    BOARD_SIZE = board.size();
    bool res = true;
    for (int i = 0; res && i < BOARD_SIZE; i++) {
      res = isValidRow(board[i]);
    }
    for (int i = 0; res && i < BOARD_SIZE; i++) {
      res = isValidRow(formRowFromCol(board, i));
    }
    for (int i = 0; res && i < BOARD_SIZE; i++) {
      res = isValidRow(formRowFromSquare(board, i));
    }

    return res;
  }

  bool isValidRow(vector<char> vec) {
    set<char> nums;
    for (char c : vec) {
      if (c == '.')
        continue;

      if (nums.count(c))
        return false;

      nums.insert(c);
    }

    return true;
  }

  vector<char> formRowFromCol(vector<vector<char>> &board, int &col) {
    vector<char> res;
    for (int row = 0; row < BOARD_SIZE; row++) {
      res.push_back(board[row][col]);
    }

    return res;
  }

  vector<char> formRowFromSquare(vector<vector<char>> &board, int &square) {
    vector<char> res;
    int OFFSET_ROW = (square / 3) * 3;
    int OFFSET_COL = (square % 3) * 3;
    for (int row = OFFSET_ROW; row < 3 + OFFSET_ROW; row++) {
      for (int col = OFFSET_COL; col < 3 + OFFSET_COL; col++) {
        res.push_back(board[row][col]);
      }
    }

    return res;
  }
};
