class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
            int a = 0;
        int b= 0;
        int c = 0;
        for(int v: bills){
            if(v == 5){ a++;
            } else if(v== 10){
                a--;
                b++;
            } else {
                if(b>0){
                    b--;
                    a--;
                } else {
                    a -= 3;
                }
            }
            if(a<0 || b<0) return false;
        }
        if(a>=0 && b>=0 && c>=0) return true;
        return false;
    }
};