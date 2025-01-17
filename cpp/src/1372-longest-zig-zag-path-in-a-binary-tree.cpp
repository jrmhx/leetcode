/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

class Solution
{
public:
    int longestZigZag(TreeNode *root)
    {
        if (!root) return 0;
        int maxLen = 0;
        dfs(root->left, true, 1, maxLen);
        dfs(root->right, false, 1, maxLen);

        return maxLen;
    }

private:
    void dfs(TreeNode* root, bool isLeftKid, int currLen, int &maxLen){
        if (!root) return;

        maxLen = max(maxLen, currLen);

        if (isLeftKid){ // last dir is left
            dfs(root->left, true, 1, maxLen);
            dfs(root->right, false, currLen + 1, maxLen);
        } else {
            dfs(root->left, true, currLen + 1, maxLen);
            dfs(root->right, false, 1, maxLen);
        }
    }
};
// @lc code=end
