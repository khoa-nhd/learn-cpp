class RangeFreqQuery {
public:
    #define maxN 400005
    unordered_map<int, int> seg[maxN];
    int n;

    void build(vector<int>& arr, int l, int r, int node){
        if(l == r) seg[node][arr[l]] += 1;
        else{
            int mid = (l + r) / 2;
            build(arr, l, mid, node*2);
            build(arr, mid+1, r, node*2+1);
            for(auto x : seg[node*2]) seg[node][x.first] += x.second;
            for(auto x : seg[node*2+1]) seg[node][x.first] += x.second;
        }
    }

    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        build(arr, 0, arr.size() - 1, 1);
    }

    int q(int l, int r, int node, int val, int u, int v){
        if(r < u || l > v) return 0;
        if(l >= u && r <= v) return seg[node][val];
        else{
            int mid = (l + r) / 2;
            return q(l, mid, node*2, val, u, v) + q(mid+1, r, node*2+1, val, u, v);
        }
    }
    
    int query(int left, int right, int value) {
        return q(0, n-1, 1, value, left, right);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */