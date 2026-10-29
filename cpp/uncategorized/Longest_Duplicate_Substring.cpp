class Solution {
public:
    #define maxN 30005
    typedef long long ll;
    ll hash1[maxN], hash2[maxN];
    ll base1 = 31, mod1 = 1e9+7;
    ll base2 = 37, mod2 = 1e9+9;
    ll pow1[maxN], pow2[maxN];
    ll n;
    ll idx = -1;
    void buildHash(string &s){
        hash1[0] = s[0] - 'a' + 1;
        hash2[0] = s[0] - 'a' + 1;
        for(int i = 1; i < n; ++i){
            hash1[i] = (hash1[i-1] * base1 + s[i] - 'a' + 1) % mod1;
            hash2[i] = (hash2[i-1] * base2 + s[i] - 'a' + 1) % mod2;
        }
        pow1[0] = 1;
        pow2[0] = 1;
        for(int i = 1; i < maxN; ++i){
            pow1[i] = pow1[i-1] * base1 % mod1;
            pow2[i] = pow2[i-1] * base2 % mod2;
        }
    }
    ll getHash(int j, int i){
        if(j == 0) return hash1[i] + hash2[i] * mod1;
        ll h1 = (hash1[i] - hash1[j-1] * pow1[i-j+1] + mod1*mod1) % mod1;
        ll h2 = (hash2[i] - hash2[j-1] * pow2[i-j+1] + mod2*mod2) % mod2;
        return (h1 + h2 * mod1);
    }
    bool check(int len){
        unordered_set<ll> us;
        for(int i = 0; i + len - 1 < n; ++i){
            ll v = getHash(i, i + len - 1);
            if(us.find(v) != us.end()){
                idx = i;
                return true;
            }
            us.insert(v);
        }
        return false;
    }
    string longestDupSubstring(string s) {
        n = s.size();
        buildHash(s);
        ll d = 1, c = n - 1;
        ll res = -1;
        ll sidx = -1;
        while(d <= c){
            ll half = (d + c) / 2;
            if(check(half)){
                d = half + 1;
                res = half;
                sidx = idx;
            } else{
                c = half - 1;
            }
        }
        string ans;
        if(res != -1){
            ans = s.substr(sidx, res);
        }
        return ans;
    }
};