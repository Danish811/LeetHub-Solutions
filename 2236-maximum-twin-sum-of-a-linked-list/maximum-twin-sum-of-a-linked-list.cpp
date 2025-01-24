class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    long long pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow);

        long long maxi = 0;
        ListNode* firstHalf = head;
        while (secondHalf) {
            maxi = max(maxi, (long long)(firstHalf->val + secondHalf->val));
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return maxi;
    }
};
