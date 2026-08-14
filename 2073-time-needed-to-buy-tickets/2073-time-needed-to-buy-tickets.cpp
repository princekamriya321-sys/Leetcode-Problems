class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        if(k>= n) return 0;
        int t = 0;
      int i =0;
      while(true){
        if(i >= tickets.size()) i = 0;
        t++;
        tickets[i] = tickets[i]-1;
        if(i == k && tickets[k] == 0) break;
        if(tickets[i] == 0){
            tickets.erase(tickets.begin() + i);
            if(i < k){
            k--;
            }
            continue;
        }
        i++;
      }
      return t;
    }
};