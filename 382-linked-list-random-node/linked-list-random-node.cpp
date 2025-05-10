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
    int n;
    ListNode *root;
    Solution(ListNode* head) {
        n = 1;
        root = head;
        ListNode *temp = head;
        while(temp) {
            temp = temp->next;
            n++;
        }
    }
    
    int getRandom() {
        int steps = 1 + (rand()%(n-1));
        ListNode*temp = root;
        int pos= 1;
        while(pos<steps){
            temp=temp->next;
            pos++;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */