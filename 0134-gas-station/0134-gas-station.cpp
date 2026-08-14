class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalgas = 0;
        int totalcost = 0;
        for(int i =0; i<n; i++){
            totalgas += gas[i];
            totalcost += cost[i];
        }
        if(totalcost > totalgas){
            return -1;
        }
        int start =0;
        int currfuel = 0;
    for(int i =0; i<n; i++){
     currfuel += gas[i]- cost[i];
     if(currfuel < 0){
        start = i+1;
        currfuel = 0;
     }
    }
    return start;
    }
};