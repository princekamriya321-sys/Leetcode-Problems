class Solution {
public:
    int countCommas(int n) {
    string s = to_string(n);
    int m = s.size();
    if(m<=3) return 0;
    if(m == 4){
        return n - 1000 + 1;
    } else if(m == 5){
        return (n-1000+1);
    } else if(m == 6){
    return (n-1000+1);
    } else if(m == 7){
        return (n-1000+1);
    }
    return 0;
    }
};