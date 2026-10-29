class Solution {
public:
    typedef long long ll;
    #define maxN 200005
    int seg[4*maxN] = {};
    void update(int l, int r, int idx, int node){
        if(l == r) seg[node] += 1;
        else{
            int mid = (l + r) / 2;
            if(l <= idx && mid >= idx){
                update(l, mid, idx, node*2);
            } else{
                update(mid+1, r, idx, node*2+1);
            }
            seg[node] = seg[node*2] + seg[node*2+1];
        }
    }
    ll query(int l, int r, int idx, int node){
        if(l >= idx) return 0;
        if(r < idx) return seg[node];
        int mid = (l + r) / 2;
        return query(l, mid, idx, node*2) + query(mid+1, r, idx, node*2+1);
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre(n, 0);
        for(int i = 0; i < n; ++i){
            if(nums[i] == target) pre[i] = 1;
            else pre[i] = -1;
        }
        for(int i = 1; i < n; ++i) pre[i] += pre[i-1];
        ll res = 0;
        update(0, maxN, (int)1e5, 1);
        for(int i = 0; i < n; ++i){
            res += query(0, maxN, pre[i]+1e5, 1);
            update(0, maxN, pre[i] + 1e5, 1);
        }
        return res;
    }
};