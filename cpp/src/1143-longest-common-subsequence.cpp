/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; i++){
            char t1 = text1[i-1];
            for (int j = 1; j <= m; j++){
                char t2 = text2[j-1];
                if (t2 == t1){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};


// @lc code=end
int main(){
    string str1 = "bsbininm", str2 = "jmjkbkjkv";

    Solution sol;

    cout << sol.longestCommonSubsequence(str1, str2) << endl;
    return 0;
}
// subseq NOT substr

// how the sub problem overlap

// text1 = "abcedex", text2 = "dace" 
// p1 = -1, p2 = -1; the current lsq ptr for t1 and t2

// lcs (long common seq)

// def the problem:
// t1 size n;
// t2 size m;
// lcs(i, j) meams the length of longest common seq for t1[::i] and t2[::j]

// so i and j are independent

// bounds of i and j:
// i -> [1, n]
// j -> [1, m]


// recurrence relation:
// lcs(i, j) = max(add_t1 + lcs(i-1, j), add_t2 + lcs(i, j-1))

//   b s b i n i n m
// j 0 0 0 0 0 0 0 0
// m 0 0 0 0 0 0 0 1
// j 0 0 0 0 0 0 0 1
// k 0 0 0 0 0 0 0 1
// b 1 1 1 1 1 1 1 1
// k 1 1 1 1 1 1 1 1 
// j 1 1 1 1 1 1 1 1
// k 1 1 1 1 1 1 1 1 
// v 1 1 1 1 1 1 1 1