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
ListNode* func(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while(curr != nullptr){
        ListNode* currnext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = currnext;
    }
    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 != nullptr) return l2;
        if(l1 != nullptr && l2 == nullptr) return l1;
        if(l1 == nullptr && l2 == nullptr) return nullptr;
     int carry = 0;
     int sum = 0;
     ListNode* ans = nullptr;
     while(l1 != nullptr || l2 != nullptr || carry){
             sum = carry;
     if(l1 != nullptr){
        sum += l1->val;
        l1 = l1->next;
     }
     if(l2 != nullptr){
        sum += l2->val;
        l2 = l2->next;
     } 
     carry = sum/10;
     ListNode* node = new ListNode(sum%10);
     node->next = ans;
     ans = node;
     }
     ans = func(ans);
     return ans;
    }
};