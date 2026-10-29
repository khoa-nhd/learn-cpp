class Solution {
public:
    #define maxN 100005
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        bool visit[maxN] = {};
        unordered_map<int, vector<int>> um;
        for(int i = 0; i < n; ++i) um[arr[i]].push_back(i);
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(q.size() > 0){
            pair<int, int> now = q.front();
            int i = now.first;
            int move = now.second;
            if(i == n-1) return move;
            q.pop();
            if(i > 0 && !visit[i-1]){
                visit[i-1] = true;
                q.push({i-1, move + 1});
            }
            if(i < n-1 && !visit[i+1]){
                visit[i+1] = true;
                q.push({i+1, move + 1});
            }
            for(int x : um[arr[i]]){
                if(x != i && !visit[x]){
                    visit[x] = true;
                    q.push({x, move + 1});
                }
            }
            um[arr[i]].clear();
        }
        return -1;
    }
};