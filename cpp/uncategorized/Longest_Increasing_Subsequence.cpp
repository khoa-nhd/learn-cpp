class Solution {
public:
    #define maxN 2505
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; ++i){
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if(it != res.end()) *it = nums[i];
            else res.push_back(nums[i]);
        }
        return res.size();
        /*int dp[maxN] = {};
        for(int i = 0; i < n; ++i){
            int maxx = 0;
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]) maxx = max(maxx, dp[j]);
            }
            dp[i] = maxx + 1;
        }
        int res = 0;
        for(int i = 0; i < n; ++i){
            res = max(res, dp[i]);
        }
        return res;*/
    }
};