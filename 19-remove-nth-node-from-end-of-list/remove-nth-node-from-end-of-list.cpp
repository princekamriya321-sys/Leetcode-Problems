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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            int ct = 0;
      ListNode* temp = head;
      while(temp != nullptr){
          ct++;
          temp = temp->next;
      }
        int idx = ct-n;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        if(idx <= 0){
            if(head->next != nullptr){
                head = head->next;
                return head;
            } else {
                return nullptr;
            }
        }
        while(curr != nullptr && idx != 0){
            prev = curr;
            curr = curr->next;
            idx--;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
        return head;
    }
};