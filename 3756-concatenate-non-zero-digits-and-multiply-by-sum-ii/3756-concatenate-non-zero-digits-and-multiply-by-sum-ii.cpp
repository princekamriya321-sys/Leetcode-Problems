class Solution {
public:
typedef long long ll;
int mod = 1e9+7;
vector<long long> func1(string s){
    int n = s.size();
   int sum = 0;
    vector<long long> ans(n);
    for(int i =0; i<n; i++){
        sum = (sum + s[i]-'0');
        ans[i] = sum;
    }
    return ans;
}
vector<long long> func2(string s)
{
    int n = s.size();

    vector<long long> ans(n);

    if(s[0] == '0')
        ans[0] = 0;
    else
        ans[0] = s[0] - '0';

    for(int i = 1; i < n; i++)
    {
        if(s[i] != '0')
        {
            ans[i] = (1LL * ans[i-1] * 10 + (s[i] - '0'))%mod;
        }
        else
        {
            ans[i] = ans[i-1];
        }
    }

    return ans;
}
vector<int> func3(string s){
    vector<int> ans(s.size());
    if(s[0] != '0'){
        ans[0] = 1;
    }  else {
        ans[0] = 0;
    }
    int n = s.size();
    for(int i = 1; i<n; i++){
      if(s[i] != '0'){
        ans[i] = ans[i-1]+1;
      } else {
        ans[i] = ans[i-1];
      }
    }
    return ans;
}
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
      vector<long long> prefixsum = func1(s);
      vector<long long> num = func2(s);
      vector<int> nonzerodigit = func3(s);
      vector<int> ans(queries.size());
      vector<long long> power10(n + 1);
            power10[0] = 1;

        for(int i = 1; i <= n; i++)
        {
            power10[i] = (power10[i-1] * 10) % mod;
        }
      for(int i = 0; i<queries.size(); i++){
        int l = queries[i][0];
        int r = queries[i][1];
        ll sum = prefixsum[r] - ((l == 0)? 0 : prefixsum[l-1]);
        long long numbefore = ((l == 0)? 0 : num[l-1]);
        int k = nonzerodigit[r] - ((l == 0) ? 0 : nonzerodigit[l-1]);
        ll x = (num[r] - (numbefore*power10[k]%mod) + mod)%mod;
        ans[i] = (int)((x*sum)%mod);
      }
      return ans;
    }
};