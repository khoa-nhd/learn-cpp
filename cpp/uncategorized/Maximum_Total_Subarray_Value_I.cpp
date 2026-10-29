class Solution {
public:
    typedef long long ll;
    long long maxTotalValue(vector<int>& nums, int k) {
        ll ma = -1e18;
        ll mi = 1e18;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            ma = max(ma, (ll)nums[i]);
            mi = min(mi, (ll)nums[i]);
        }
        return (ma - mi) * k;
    }
};