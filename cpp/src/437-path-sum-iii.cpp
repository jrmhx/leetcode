/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
class Solution {
public:
    int pathSum(TreeNode *root, int targetSum) {
        int ans = 0;

        unordered_map<long long, int> lookUpTable; // key: rootSum, val: freq
        lookUpTable[0] = 1; // init a fake rootSum 

        dfs(root, 0, targetSum, lookUpTable, ans);

        return ans;
    }

    void dfs(TreeNode* root, long long parentsRootSum, const int target, unordered_map<long long, int> & lookUpTable, int & ans){
        if (!root) return;
        
        long long currRootSum = parentsRootSum + root->val;
        long long ancestorRootSum = currRootSum - target;
        ans+= lookUpTable[ancestorRootSum];
        lookUpTable[currRootSum]++;

        dfs(root->left, currRootSum, target, lookUpTable, ans);
        dfs(root->right, currRootSum, target, lookUpTable, ans);
        lookUpTable[currRootSum]--;
    }
};
// @lc code=end
