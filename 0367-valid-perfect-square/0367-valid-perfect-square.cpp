class Solution {
public:
    bool isPerfectSquare(int num) {
        long long limit = sqrt(num);
        if((limit+1)*(limit+1) <= num){
            limit++;
           
        } 
        if(limit*limit == num) return true;
        return false;
    }
};