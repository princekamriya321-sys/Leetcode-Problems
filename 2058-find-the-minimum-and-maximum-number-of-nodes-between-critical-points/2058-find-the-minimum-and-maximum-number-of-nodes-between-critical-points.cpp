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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return {-1,-1};
        vector<int> arr;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        int ct = 1;
        while(temp != nullptr){
            if(prev != nullptr && temp->next != nullptr){
             if(prev->val > temp->val && temp->val < temp->next->val){
                arr.push_back(ct);
             } else if(prev->val < temp->val && temp->val > temp->next->val){
                arr.push_back(ct);
             }
            }
            ct++;
            prev = temp;
            temp = temp->next;
        }
        int mindiff = INT_MAX;
        if(arr.size() < 2) return {-1,-1};
        sort(arr.begin(),arr.end());
        int maxdiff = arr[arr.size()-1] - arr[0];
        for(int i =1; i<arr.size(); i++){
            mindiff = min(arr[i] - arr[i-1],mindiff);
        }
        return {mindiff,maxdiff};
    }
};