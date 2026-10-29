class Solution {
public:
    typedef long long ll;
    #define maxN 200005
    int seg[maxN] = {};
    int seg2[maxN] = {};
    void build(int l, int r, int node, vector<int>& nums){
        if(l == r){
            seg[node] = nums[l];
            seg2[node] = nums[l];
        }
        else{
            int mid = (l + r) / 2;
            build(l, mid, node*2, nums);
            build(mid+1, r, node*2+1, nums);
            seg[node] = min(seg[node*2], seg[node*2+1]);
            seg2[node] = max(seg2[node*2], seg2[node*2+1]);
        }
    }
    pair<int, int> query(int l, int r, int node, int u, int v, vector<int>& nums){
        if(l >= u && r <= v) return {seg[node], seg2[node]};
        else if (r < u || l > v) return {(int)2e9, (int)-2e9};
        int mid = (l + r) / 2;
        pair<int, int> ll = query(l, mid, node*2, u, v, nums);
        pair<int, int> rr = query(mid+1, r, node*2+1, u, v, nums);
        return {min(ll.first, rr.first),
                max(ll.second, rr.second)};
    }
    struct ht{
        int l, r, val;
    };
    struct cmp{
        bool operator() (const ht x, const ht y){
            return x.val < y.val;
        }
    };
    long long maxTotalValue(vector<int>& nums, int k) {
        ll res = 0;
        int n = nums.size();
        build(0, n-1, 1, nums);
        priority_queue<ht, vector<ht>, cmp> pq;
        ht v;
        pair<int, int> p;
        for(int i = 0; i < n; ++i){
            p = query(0, n-1, 1, i, n-1, nums);
            v.val = p.second - p.first;
            v.l = i; 
            v.r = n-1;
            pq.push(v);
        }
        while(k--){
            v = pq.top();
            res += v.val;
            pq.pop();
            if(v.l <= v.r-1){
                v.r -= 1;
                p = query(0, n-1, 1, v.l, v.r, nums);
                v.val = p.second - p.first;
                pq.push(v);
                v.r += 1;
            }
        }
        return res;
    }
};