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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode(0);
        ListNode* tmp1 = l1;
        ListNode* l2 = new ListNode(0);
        ListNode* tmp2 = l2;
        while(head){
            if(head->val < x){
                tmp1->next = new ListNode(head->val);
                tmp1 = tmp1->next;
            }
            else{
                tmp2->next = new ListNode(head->val);
                tmp2 = tmp2->next;
            }
            head = head->next;
        }
        tmp1->next = l2->next;
        return l1->next;
    }
};