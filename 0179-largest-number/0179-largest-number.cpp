class Solution {
public:
static bool cmp(int a, int b) {
    return to_string(a) + to_string(b) >
           to_string(b) + to_string(a);
}
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0) return "0";
        string s = "";
        for(int v: nums){
            s += to_string(v);
        }
        return s;
    }
};