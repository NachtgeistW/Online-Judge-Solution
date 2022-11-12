/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr)
            return nullptr;

        auto pre = head, cur = head->next;
        pre->next = nullptr;
        while (cur != nullptr)
        {
            //save node
            auto cur2 = cur, next = cur->next;
            //reverse
            cur2->next = pre;
            //move
            pre = cur; 
            cur = next;
        }
        return pre;
    }
};
