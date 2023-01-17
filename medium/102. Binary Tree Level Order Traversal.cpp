/*
  102. Binary Tree Level Order Traversal

  Given the root of a binary tree, return the level order traversal of its
  nodes' values. (i.e., from left to right, level by level).

  Input: root = [3,9,20,null,null,15,7]
  Output: [[3],[9,20],[15,7]]
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root)
      return {};
    vector<vector<int>> res;
    queue<TreeNode *> level, newLevel;
    level.push(root);
    while (!level.empty()) {
      vector<int> tmp;
      while (!level.empty()) {
        auto node = level.front();
        level.pop();
        if (node->left)
          newLevel.push(node->left);
        if (node->right)
          newLevel.push(node->right);
        tmp.push_back(node->val);
      }
      res.push_back(tmp);
      tmp = {};
      level = newLevel;
      newLevel = {};
    }

    return res;
  }
};
