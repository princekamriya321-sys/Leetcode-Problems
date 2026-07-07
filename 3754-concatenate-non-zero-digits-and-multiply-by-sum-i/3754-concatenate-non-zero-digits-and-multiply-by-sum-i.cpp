class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        string num = "";
        while(n > 0){
            if(n%10 != 0){
                num += to_string(n%10);
            }
      sum += n%10;
      n = n/10;
        }
        int number = 0;
        if(num == ""){
            number = 0;
        } else {
            reverse(num.begin(),num.end());
           number = stoi(num);
        }
        long long target = sum*number;
        return target;
    }
};