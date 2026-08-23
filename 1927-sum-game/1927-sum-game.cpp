class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sum1 = 0;
        int ct1 = 0;
        for(int i =0; i<n/2; i++){
            if(num[i] == '?') ct1++; 
            else 
            sum1 = sum1 + (num[i]-'0');
        }
        int ct2 = 0;
        int sum2 = 0;
        for(int j =n/2; j<n; j++){
            if(num[j] == '?') ct2++;
             else
            sum2 = sum2 + (num[j]-'0');
        }
        if(ct1 == 0 && ct2 == 0){
            if(sum1 == sum2) return false; 
            return true;
        } else if(ct1 != 0 && ct2 == 0){
            if(sum1 > sum2) return true;
            if(ct1%2 != 0){
             return true;
             }
             sum1 += 4.5*ct1;
             if(sum1 == sum2) return false;
             return true;
        } else if(ct1 == 0 && ct2 != 0){
             if(sum1 < sum2) return true;
             if(ct2 % 2 != 0) {
                return true;
             }
              sum2 += 4.5*ct2;
             if(sum1 == sum2) return false;
             return true;
        } else {
          int sum = ct1 + ct2;
          if(sum%2 != 0)return true;
           sum1 += 4.5*ct1;
           sum2 += 4.5*ct2;
           if(sum1 == sum2) return false;
           return true;
    }
    }
};