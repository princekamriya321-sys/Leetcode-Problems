class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
       unordered_map<char,int> freq;
       int j =0;
       queue<int> q;
        while(j<n){
            freq[s[j]]++;
            q.push(j);
            j++;
        }
        while(q.size() > 0){
if(freq[s[q.front()]] == 1) return q.front();
q.pop();
        }
        return -1;
    }
};