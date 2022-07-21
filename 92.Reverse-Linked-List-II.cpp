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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ans = new ListNode(0);
        ListNode* tmp = ans;
        int i = 1;
        while(i < left){
            tmp->next = new ListNode(head->val);
            head = head->next;
            tmp = tmp->next;
            i++;
        }
        
        stack<ListNode*> st;
        while(i <= right){
            st.push(head);
            head = head->next;
            i++;
        }
        
        while(!st.empty()){
            tmp->next = new ListNode(st.top()->val);
            tmp = tmp->next;
            st.pop();
        }
        
        while(head){
            tmp->next = new ListNode(head->val);
            tmp = tmp->next;
            head = head->next;
        }
        
        return ans->next;
    }
};