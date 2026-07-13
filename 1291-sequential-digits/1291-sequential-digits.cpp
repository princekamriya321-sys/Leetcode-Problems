class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
       vector<int> ans;
       string s = to_string(low);
        for(int i =1; i<s.size(); i++){
            char c1 = s[i-1];
            s[i] = char((c1-'0') + 1);
        }
        int num = stoi(s);
     while(num<=high){
        if(num >= low){
        ans.push_back(num);
        }
        string t = to_string(num);
        int n = t.size();
        if(t[n-1] == '9'){
            n = n+1;
            int i = 1;
            int x = 0;
            while(i<=n){
             x = x*10 + i;
             i++;
            }
            num = x;
            continue;
        }
        string x = "";
        for(int i = 0; i<n; i++){
          x += "1";
        }
        int number = stoi(x);
        num += number;
     }
    return ans;
    }
};