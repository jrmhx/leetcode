/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) {
            head = nullptr;
            return head;
        }

        ListNode* f = head;
        ListNode* s = head;
        ListNode* sprev = nullptr;

        while (f && f->next){
            sprev = s;
            f = f->next->next;
            s = s->next;
        }

        // slow ptr node is the one we need to delete

        if(sprev) sprev->next = s->next;

        delete s;

        return head;
    }
};
// @lc code=end

// fast and slow ptr
// fptr travel 2x faster than sptr
// curr
// size 
// if size % 2 == 0 move ptrs