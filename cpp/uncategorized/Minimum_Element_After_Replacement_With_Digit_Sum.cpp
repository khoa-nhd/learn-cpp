class Solution {
public:
    int cnt(int x){
         int res = 0;
         while(x > 0){
            res += x % 10;
            x /= 10;
         }
         return res;
    }
    int minElement(vector<int>& nums) {
        int res = 1e9;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            res = min(res, cnt(nums[i]));
        }
        return res;
    }
};