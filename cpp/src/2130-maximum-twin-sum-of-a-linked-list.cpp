/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        int ans = 0;
        vector<int> twin;

        ListNode dummy(0, head);

        ListNode* f = &dummy;
        ListNode* s = f;

        while (f && f->next){
            s = s->next;
            f = f->next->next;

            twin.push_back(s->val);
        }

        s = s->next;
        int idx = twin.size()-1;

        while(s){
            ans = std::max(twin[idx--]+s->val, ans);
            s = s->next;
        }

        return ans;
    }
};
// @lc code=end
// list -> array