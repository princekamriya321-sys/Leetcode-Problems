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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr1;
        vector<int> arr2;
        int ct = 1;
        while(temp != nullptr){
            if(ct%2 != 0){
                arr1.push_back(temp->val);
            } else {
                arr2.push_back(temp->val);
            }
            ct++;
            temp = temp->next;
        }
        temp = head;
        int n = arr1.size();
        int m = arr2.size();
        int i = 0,j = 0;
        while(i<n){
            temp->val = arr1[i];
            i++;
            temp = temp->next;
        }
        while(j<m){
            temp->val = arr2[j];
            j++;
            temp = temp->next;
        }
        return head;
    }
};