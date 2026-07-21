class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int activeCount = count(s.begin(),s.end(),'1');
        vector<int> inactiveBlocks;
        int i =0;
        int n = s.size();
        while(i<n){
            if(s[i] == '0'){
                int start = i;
                while(i<n && s[i] == '0'){i++;}
                inactiveBlocks.push_back(i-start);
            } else {
                i++;
            }
        }
        int maxPairSum= 0;
        for(int j = 1; j<inactiveBlocks.size(); j++){
          maxPairSum = max(maxPairSum,inactiveBlocks[j] + inactiveBlocks[j-1]);
        }
        return maxPairSum + activeCount;
    }
};