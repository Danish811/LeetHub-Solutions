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
    ListNode* middleNode(ListNode* head) {
        ListNode *Slow = head;
        ListNode *Fast= head;
        while(Fast && Fast->next){
            Slow = Slow->next;
            Fast = Fast->next->next;
        }
        if(Fast->next) return Slow->next;
        return Slow;
    }
};
