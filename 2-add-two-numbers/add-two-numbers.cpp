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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp = l1;
        int extra=0;
        while(l1 && l2){
            l1->val += l2->val;
            l2 = l2->next;
            if(!l1->next) break; 
            l1 = l1->next;
        }
        while(l2){
            l1->next = l2;
            l2 = l2->next;
            l1 = l1->next;
        }
        l1 = temp;
        while(l1){
            if(extra>0) l1->val += extra--;
            if(l1->val > 9){
                extra += l1->val/10;
                l1->val %= 10;
            }
            if(l1->next == NULL) break;
            l1 = l1->next;
        }
        if(extra){
            l1->next = new ListNode(extra);
        }
        return temp;
    }
};