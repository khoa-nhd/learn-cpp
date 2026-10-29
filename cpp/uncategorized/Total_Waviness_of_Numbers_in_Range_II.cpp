class Solution {
public:
    typedef long long ll;
    ll cnt[16][10][10], sum[16][10][10];
    pair<ll, ll> dfs(int pos, int prev, int curr, bool tight, bool lead, string &n){
        if(pos == n.size()) return {1, 0};
        if(!tight && !lead && prev >= 0 && curr >= 0 && cnt[pos][prev][curr] != -1){
            return{cnt[pos][prev][curr], sum[pos][prev][curr]};
        }
        ll c = 0, s = 0;
        int limit = tight ? n[pos] - '0' : 9;
        for(int i = 0; i <= limit; ++i){
            bool newlead = lead && i == 0;
            int newprev = curr;
            int newcurr = newlead ? -1 : i;
            int newtight = tight && i == limit;
            pair<ll, ll> t = dfs(pos+1, newprev, newcurr, newtight, newlead, n);
            if(!newlead && prev >= 0 && curr >= 0){
                if((prev < curr && curr > i) || (prev > curr && curr < i)) s += t.first;
            }
            c += t.first;
            s += t.second;
        }
        if(!tight && !lead && prev >= 0 && curr >= 0){
            cnt[pos][prev][curr] = c;
            sum[pos][prev][curr] = s;
        }
        return {c, s};
    }
    long long totalWaviness(long long num1, long long num2){
        num1 -= 1;
        string n1 = to_string(num1);
        string n2 = to_string(num2);
        ll a, b;
        memset(cnt, -1, sizeof(cnt));
        memset(sum, -1, sizeof(sum));
        if(num1 > 100) a = dfs(0, -1, -1, 1, 1, n1).second;
        else a = 0;
        memset(cnt, -1, sizeof(cnt));
        memset(sum, -1, sizeof(sum));
        if(num2 > 100) b = dfs(0, -1, -1, 1, 1, n2).second;
        else b = 0;
        return b - a;
    }
};