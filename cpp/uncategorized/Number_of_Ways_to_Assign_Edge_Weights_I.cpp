class Solution {
public:
    #define maxN 100005
    int mod = 1e9 + 7;
    typedef long long ll;
    int mu(int base, int power){
        if(power == 0) return 1;
        ll temp = mu(base, power / 2);
        temp *= temp;
        temp %= mod;
        if(power % 2 == 0) return temp;
        return (temp * base) % mod;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        bool vis[maxN] = {};
        vector<vector<int>> adj(n+1);
        for(const auto &x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<pair<int, int>> q;
        q.push({1, 0});
        vis[1] = true;
        int maxd = 0;
        while(!q.empty()){
            auto [node, depth] = q.front();
            q.pop();
            maxd = max(maxd, depth);
            for(int neighbor : adj[node]){
                if(!vis[neighbor]){
                    vis[neighbor] = true;
                    q.push({neighbor, depth + 1});
                }
            }
        }
        return mu(2, maxd-1);
    }
};