/*
 * @lc app=leetcode id=3034 lang=cpp
 *
 * [3034] Number of Subarrays That Match a Pattern I
 */

#include <memory>
#include <utility>
#include <unordered_map>
#include <optional>
#include <vector>
#include <iostream>

using namespace std;


// @lc code=start
struct TrieNode {
    bool is_end;
    std::unordered_map<int, std::unique_ptr<TrieNode>> childern;
    TrieNode(): is_end(false), childern() {}
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
    }
private:
    std::optional<std::unique_ptr<TrieNode>> buildTrie(vector<int> & arr){
        try{
            auto root = std::make_unique<TrieNode>();


            return root;
        } catch (const std::exception & err) {
            cout << err.what() << endl;
            return std::nullopt;
        }
    }
};
// @lc code=end

