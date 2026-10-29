class Solution {
public:
    int mm, nn, kk;
    bool check(int x){
        int res = 0;
        for(int i = 1; i <= nn; ++i){
            res += min(mm, x / i);
            if(res >= kk) return true;
        }
        return res >= kk;
    }
    int findKthNumber(int m, int n, int k) {
        mm = m;
        nn = n;
        kk = k;
        if(nn > mm) swap(nn, mm);
        int d = 1, c = n * m;
        int res = -1;
        while(d <= c){
            int half = (d + c) >> 1;
            if(!check(half)){
                d = half + 1;
            } else{
                c = half - 1;
                res = half;
            }
        }
        return res;
    }
};