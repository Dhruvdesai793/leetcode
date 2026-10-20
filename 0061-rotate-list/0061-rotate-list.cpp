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
    ListNode* rotateRight(ListNode* head, int k) {
        // silly err, using fast instead fast->next in while
        // that caused for fast to get out of bounds.
        if(!head) return head;
        int len = 1, modLen; 

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next) fast = fast->next, len++;
        fast = head;

        modLen = k % len;
        if(modLen==0) return head;

        while(modLen--){
            
            fast = fast->next;
        }

        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode * dummy = new ListNode(0);
        dummy->next = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return dummy->next;
    }
};