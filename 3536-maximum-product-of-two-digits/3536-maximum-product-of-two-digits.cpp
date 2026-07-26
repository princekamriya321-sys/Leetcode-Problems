class Solution {
public:
    int maxProduct(int n) {
       int pr = 1;
       int r = n;
       vector<int>freq(10,0);
       while(r > 0){
        int digit = r%10;
        freq[digit]++;
        r = r/10;
       } 
       int count = 0;
       for(int i = 9; i>=0; i--){
        if(freq[i] > 0){
            int ct = freq[i];
            if(ct>=2 && count == 0){
            pr = pr*i*i;
            break;
            } else if(ct>=2 && count ==1){
                pr = pr*i;
                break;
            }
            pr = pr*i;
            count++;
        }
        if(count == 2) break;
       }
       return pr;
    }
};