class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int score = 0;
        vector<int> vec;
        for(int i =0; i<n; i++){
            if(s[i] == '('){
                vec.push_back(score);
                score = 0;
            } else {
                if(s[i-1] == '('){
                    score = vec.back() + 1;
                } else {
                    score = vec.back() + (score*2);
                }
            vec.pop_back();
            }
        }
        return score;
    }
};