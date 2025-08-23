#include <bits/stdc++.h>

using namespace std;
string s = "WRYRWRWY", t;

int sol(string th)
{
    t = "";
    for(char c : s)
    {
        int cd = t.length();
        if(cd < 3)
        {
            if(cd == 0 && c == th[0] || cd == 1 && c == th[1] || cd == 2 && c == th[2]){
                t += c;
            }
        }
        else
        {
            char a = t[cd-1];
            char b = t[cd - 2];
            if(a!=c && a!=b && b!=c)
            {
                t += c;
            }
        }
    }
    return t.length();
}

int maxx(int a, int b, int c, int d, int e, int f){
    return max(a, max(b, max(c, max(d, max(e, f)))));
}

int main()
{
    cout << maxx(sol("WRY"), sol("WYR"), sol("RWY"), sol("RYW"), sol("YWR"), sol("YRW"));
    return 0;
}
