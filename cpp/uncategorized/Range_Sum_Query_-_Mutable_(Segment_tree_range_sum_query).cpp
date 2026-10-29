class NumArray {
public:
    #define maxN 120005
    int segTre[maxN] = {};
    int n;

    void build(vector<int>& nums, int l, int r, int node){
        if(l == r){
            segTre[node] = nums[l];
        } else{
            int mid = (l + r) / 2;
            build(nums, l, mid, node*2);
            build(nums, mid+1, r, node*2+1);
            segTre[node] = segTre[node*2] + segTre[node*2+1];
        }
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        build(nums, 0, n-1, 1);
    }

    void up(int idx, int v, int l, int r, int node){
        if(l == r){
            segTre[node] = v;
        } else{
            int mid = (l + r) / 2;
            if(l <= idx && mid >= idx) up(idx, v, l, mid, node*2);
            else up(idx, v, mid+1, r, node*2+1);
            segTre[node] = segTre[node*2] + segTre[node*2+1];
        }
    }
    
    void update(int index, int val) {
        up(index, val, 0, n-1, 1);
    }

    int query(int node, int l, int r, int u, int v){
        if(r < u || l > v) return 0;
        if(l >= u && r <= v) return segTre[node];
        int mid = (l + r) / 2;
        return query(node*2, l, mid, u, v) + query(node*2+1, mid+1, r, u, v);
    }
    
    int sumRange(int left, int right) {
        return query(1, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */