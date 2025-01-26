
class Solution {
public:
    ListNode *reverse(ListNode *head){
        ListNode *next=nullptr;
        ListNode *prev=nullptr;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *nextHalf = reverse(slow);
        while(nextHalf){
            if(head->val != nextHalf->val) return false;
            head = head->next;
            nextHalf = nextHalf->next;
        }
        return true;
    }
};