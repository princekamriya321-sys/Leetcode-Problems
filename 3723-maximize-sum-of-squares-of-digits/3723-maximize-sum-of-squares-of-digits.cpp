class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum <= 9){
            string s = to_string(sum);
            num--;
            while(num > 0){
                s += ("0");
                num--;
            }
            return s;
        }
string s = "";
while(sum>9 && num > 0){
s += ("9");
sum -= 9;
num--;
}
if(sum <= 9 && num >0){
    s += to_string(sum);
    num--;
    while(num > 0){
    s += ('0');
    num--;
    }
} else {
    return "";
}
return s;
    }
};