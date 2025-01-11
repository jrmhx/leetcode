/*
 * @lc app=leetcode id=2266 lang=cpp
 *
 * [2266] Count Number of Texts
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int countTexts(string nums) {
        int mod = 1e9+7;
        int n = nums.length();
        vector<int> parse(n+10, 0);

        // 7 and 9 -> 4 
        // others -> 3

        int sum = 1;
        parse[n-1] = 1;
        char prev = nums[n-1]; // the previous key alice pressed
        int counter = 1; // the freq of curr key
        bool canComb = false;
        for (int i = n - 2; i >= 0; i--){
            char k = nums[i];
            if (k==prev) {
                counter ++;
            } else {
                counter = 1;
                prev = k;
            }
            sum = 0;
            int keyLen = (k == '7' || k == '9') ? 4 : 3; // how many letters are there on phone key k
            int rep = min(counter, keyLen); // the max number of k we can use curr

            for(int j = 1; j <= rep; j++){
                sum += parse[i+j] != 0 ? parse[i+j] : 1;
                sum = sum % mod;
            }

            parse[i] = sum;
        }
        
        return sum;
    }
};
// @lc code=end

