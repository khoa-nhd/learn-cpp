class Solution {
public:
    int dem(vector<int>& nums){
        int n = nums.size();
        int idx0 = -1;
        for(int i = 0; i < n; ++i){
            if(!nums[i]){
                idx0 = i;
                break;
            }
        }
        if(idx0 != 0 && idx0 != n-1 && (nums[idx0 - 1] != n-1 || nums[idx0 + 1] != 1)) return -1;
        for(int i = 1; i < idx0; ++i){
            if(nums[i] - 1 != nums[i-1]) return -1;
        }
        for(int i = idx0+2; i < nums.size(); ++i){
            if(nums[i] - 1 != nums[i-1]) return -1;
        }
        return min(idx0, n - idx0 + 2);
    }
    int dem2(vector<int>& nums){
        int n = nums.size();
        int idx0 = -1;
        for(int i = 0; i < n; ++i){
            if(!nums[i]){
                idx0 = i;
                break;
            }
        }
        if(idx0 != 0 && idx0 != n-1 && (nums[idx0 - 1] != 1 || nums[idx0 + 1] != n-1)) return -1;
        for(int i = 1; i < idx0; ++i){
            if(nums[i] + 1 != nums[i-1]) return -1;
        }
        for(int i = idx0+2; i < nums.size(); ++i){
            if(nums[i] + 1 != nums[i-1]) return -1;
        }
        return min(n - idx0, idx0 + 2);
    }
    int minOperations(vector<int>& nums) {
        int res = dem(nums);
        if(res == -1){
            res = dem2(nums);
        }
        return res;
    }
};