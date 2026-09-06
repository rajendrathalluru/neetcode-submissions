class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // save next node
            curr->next = prev;               // reverse the link
            prev = curr;                     // move prev forward
            curr = nextNode;                 // move curr forward
        }

        return prev;
    }
};