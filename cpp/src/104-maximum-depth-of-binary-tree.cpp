/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
    int maxDepth(TreeNode *root) {
        int max = 0;

        return foo(root, 0);
    }
private:
    int foo(TreeNode *root, int curr){
        if (root == nullptr){
            return curr;
        } else {
            return std::max(foo(root->left, curr+1), foo(root->right, curr+1));
        }
    }
};
// @lc code=end
