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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevPtr = head;

        if (head == nullptr || head->next == nullptr) {
            return head;
        };

        if (head->next->next == nullptr) {
            head = head->next;
            head->next = prevPtr;
            prevPtr->next = nullptr;

            prevPtr = nullptr;
            return head;
        }

        ListNode* currPtr = head->next;
        ListNode* nextPtr = head->next->next;
        prevPtr->next = nullptr;

        while (nextPtr != nullptr) {
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
            nextPtr = nextPtr->next;
        }

        currPtr->next = prevPtr;
        head = currPtr;

        prevPtr = currPtr = nextPtr = nullptr;
        return head;
    }
};
