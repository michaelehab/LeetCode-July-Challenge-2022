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
        ListNode* ans = head;
        int i = 1;
        while(i < left - 1){
            ans = ans->next;
            i++;
        }
        ListNode* tmp = ans;
        tmp = tmp->next;
        i++;
        stack<ListNode*> st;
        while(tmp && i <= right){
            st.push(tmp);
            tmp = tmp->next;
            i++;
        }
        
        while(!st.empty()){
            ans->next = st.top();
            ans = ans->next;
            st.pop();
        }
        
        ans->next = tmp;
        
        return head;
    }
};