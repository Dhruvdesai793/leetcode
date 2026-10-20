/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && slow && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow){
                slow = head;
                break;
                
            }
            
        }
        if(!fast || !fast->next) return nullptr; // no cycle case;

        while(fast!=slow){
            slow = slow->next;
            fast = fast->next;

            if (fast == slow){
                break;
            }
        }
        return fast; //start of the loop is returned;
    }
};