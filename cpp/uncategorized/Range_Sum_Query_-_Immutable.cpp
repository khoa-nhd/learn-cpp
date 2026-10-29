class NumArray {
public:
    int pre[10005] = {};
    NumArray(vector<int>& nums) {
        for(int i = 1; i <= nums.size(); ++i){
            pre[i] = pre[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return pre[right+1] - pre[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */