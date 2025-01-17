/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 */

#include <bits/stdc++.h>

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
    int goodNodes(TreeNode *root)
    {
        if (!root) return 0;
        int ans = 0;
        int pathMax = root->val;

        find(root, ans, pathMax);

        return ans;
    }
private: 
    void find(TreeNode *root, int & ans, int pathMax){
        if (!root) return;

        if(root->val >= pathMax) ans++;

        pathMax = std::max(pathMax, root->val);

        find(root->left, ans, pathMax);
        find(root->right, ans, pathMax);
    }
};
// @lc code=end
