/*
    118. Pascal's Triangle

    Given an integer numRows, return the first numRows of Pascal's triangle.
    In Pascal's triangle, each number is the sum of the two numbers directly
   above it as shown:
*/

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    res.push_back({1});
    for (int i = 1; i < numRows; i++) {
      vector<int> newRow{1};
      for (int j = 0; j < i - 1; j++) {
        newRow.push_back(res[i - 1][j] + res[i - 1][j + 1]);
      }
      newRow.push_back(1);
      res.push_back(newRow);
    }

    return res;
  }
};
