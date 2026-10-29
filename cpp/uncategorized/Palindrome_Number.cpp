class Solution {
public:
    typedef long long ll;
    bool isPalindrome(int x) {
        if(x < 0) return false;
        ll rx = 0;
        ll x2 = x;
        while(x2 > 0){
            rx *= 10;
            rx += x2 % 10;
            x2 /= 10;
        }
        return x == rx;
    }
};