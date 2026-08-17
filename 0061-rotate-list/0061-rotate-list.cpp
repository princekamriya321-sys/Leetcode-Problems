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
ListNode* reverse(ListNode* head,int rem){
ListNode* temp = head;
while(temp != nullptr && rem != 1){
    temp = temp->next;
    rem--;
};
ListNode* curr = temp->next;
temp->next = nullptr;
head = curr;
return head;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k ==0) return head;
        int len = 1;
        ListNode* temp = head;
        while(temp->next != nullptr){
            len++;
            temp = temp->next;
        }
        k = k%len;
        if(k == 0) return head;
        temp->next = head;
    head = reverse(head,len-k);
    return head;
    }
};