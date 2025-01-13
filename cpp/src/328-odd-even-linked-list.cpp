/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
class Solution {
public:
    ListNode *oddEvenList(ListNode *head){
        if(!head || !head->next || !head->next->next) return head;

        ListNode* odd = head; // 1
        ListNode* even = head->next; // 2
         ListNode* oddHead = head; // 1
        ListNode* evenHead = head->next; // 2
        ListNode* scanner = head->next->next; // 3
        int idx = 3;

        while (scanner) {
            if (idx % 2 == 1){
                odd->next = scanner;
                odd = odd->next;
                
            } else {
                even->next = scanner;
                even = even->next;
            }
            scanner = scanner->next;
            idx++;
        }

        odd->next = evenHead;

        even->next = nullptr;

        return head;
    }
};
// @lc code=end

// in place op
// 1-idx 

