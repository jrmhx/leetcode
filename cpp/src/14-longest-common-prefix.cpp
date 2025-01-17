/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <optional>
#include <iostream>

using namespace std;

// @lc code=start

struct TrieNode {
    bool is_end;
    unordered_map<char, unique_ptr<TrieNode>> childern;
};

optional<unique_ptr<TrieNode>> buildTrie(vector<string>& strs) {
    try {
        auto root = std::make_unique<TrieNode>();
        for (auto str : strs) { // start from first word
            auto curr = root.get();
            for (auto c : str) { // start from first letter of the word
                if (curr->childern.find(c) == curr->childern.end()){
                    curr->childern[c] = std::make_unique<TrieNode>();
                }
                curr = curr->childern[c].get();
            }
            // end of the word
            curr->is_end = true;
        }
        return root;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return std::nullopt;
    }
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto opt = buildTrie(strs);
        string ans = "";
        if (opt) {
            auto root = opt.value().get();
            while (root && root->childern.size() == 1 && !root->is_end){
                auto it = root->childern.begin();
                ans += it->first;
                root = it->second.get();
            }
        }
        return ans;
    }
};
// @lc code=end

