/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr){
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
        }

        return prev;

    }
};
// @lc code=end
//        1  2  3  4  5  null
// null   
//    p c
//
// 
