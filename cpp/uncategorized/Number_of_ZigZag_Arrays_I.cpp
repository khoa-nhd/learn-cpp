class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l;
        vector<int> dp(m, 1);
        int mod = 1e9 + 7;
        for(int i = 0; i < n; ++i){
            reverse(dp.begin(), dp.end());
            for(int i = 1; i < m; ++i){
                dp[i] += dp[i-1];
                dp[i] %= mod;
            }
        }
        return dp[m-1] * 2 % mod;
    }
};