class Solution {
public:
    #define maxN 1000005
    #define maxN2 100005
    typedef long long ll;
    bool prime[maxN] = {};
    bool visit[maxN2] = {};
    bool vprime[maxN] = {};
    void sieve(){
        for(int i = 2; i < maxN; ++i) prime[i] = true;
        int m = sqrt(maxN);
        for(int i = 2; i < m; ++i){
            if(prime[i]){
                for(int j = i*i; j < maxN; j += i){
                    prime[j] = false;
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        sieve();
        int n = nums.size();
        unordered_map<int, vector<int>> point;
        for(int i = 0; i < n; ++i){
            int val = nums[i];
            for(int p = 2; p*p <= val; ++p){
                if(val % p == 0){
                    point[p].push_back(i);
                    while(val % p == 0) val /= p;
                }
            }
            if(val > 1) point[val].push_back(i);
        }
        visit[0] = true;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(q.size() > 0){
            pair<int, int> curr = q.front();
            int next = curr.second+1;
            int idx = curr.first;
            q.pop();
            if(idx == n-1) return curr.second;
            if(prime[nums[idx]] && !vprime[nums[idx]]){
                vprime[nums[idx]] = true;
                for(int x : point[nums[idx]]){
                    if(!visit[x]){
                        visit[x] = true;
                        //cout << x << " " << next << "\n";
                        q.push({x, next});
                    }
                }
            }
            if(idx+1 < n && !visit[idx+1]) {
                //cout << idx+1 << " " << next << "\n";
                visit[idx+1] = true;
                q.push({idx+1, next});
            }
            if(idx-1 >= 0 && !visit[idx-1]) {
                //cout << idx-1 << " " << next << "\n";
                visit[idx-1] = true;
                q.push({idx-1, next});
            }
        }
        return n-1;
    }
};