#
# @lc app=leetcode id=1137 lang=python3
#
# [1137] N-th Tribonacci Number
#

# @lc code=start
from functools import cache

class Solution:
    @cache
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        return self.tribonacci(n-1) + self.tribonacci(n-2) + self.tribonacci(n-3)
# @lc code=end

