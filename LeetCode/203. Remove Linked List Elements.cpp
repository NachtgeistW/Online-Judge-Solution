//https://leetcode.cn/problems/remove-linked-list-elements/submissions/
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode* pre = head;
        while (cur != nullptr)
        {
            if (cur->val == val)
            {
                if (cur == head)
                {
                    cur = head->next;
                    delete pre;
                    pre = cur;
                    head = cur;
                }
                else
                {
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                }
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
