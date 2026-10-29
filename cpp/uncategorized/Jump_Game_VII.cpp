class Solution {
public:
    #define maxN 100005
    bool canReach(string s, int minJump, int maxJump) {
        int pre[maxN+maxN] = {};
        int n = s.size();
        pre[minJump] = 1;
        pre[maxJump + 1] = -1;
        if(s[n-1] == '1') return false;
        for(int i = 1; i < n; ++i){
            pre[i] += pre[i-1];
            if(pre[i] && s[i] == '0'){
                pre[i + minJump] += 1;
                pre[i + maxJump + 1] -= 1;
            }
        }
        return pre[n-1];
    }
};