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
        if(head == nullptr) return nullptr;
        ListNode* s = head;
        ListNode* f = head;
        while(f->next != nullptr && f->next->next != nullptr){
            s = s->next;
            f = f->next->next;
            if(s == f){
                 s = head;
        while(s != f){
            s = s->next;
            f = f->next;
        }
        return s;
            }
        }
       return nullptr;
    }
};