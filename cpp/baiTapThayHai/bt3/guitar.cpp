#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

using namespace std;
int n,p;
stack <int> st[7];

void guitar()
{
    int result = 0;
    int s,f;
    cin >> n >> p;
    for(int i = 1; i<=n ;i++)
    {
        cin >> s >>f;
        while(!st[s].empty() && st[s].top() > f)
        {
            st[s].pop();
            result += 1;
        }
        if(st[s].empty() || st[s].top() < f)
        {
            st[s].push(f);
            result += 1;
        }
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GUITAR.INP", "r", stdin);
    freopen("GUITAR.OUT", "w", stdout);
    guitar();
    return 0;
}
