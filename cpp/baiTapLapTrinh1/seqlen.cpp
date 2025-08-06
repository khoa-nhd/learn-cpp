// Dãy số: 123456789101112131415
// Hỏi dãy số được tạo từ 1 đến n có chiều dài bao nhiêu
#include <iostream>
#include <cstdio>
using namespace std;

int demChuSo(long long n) {
    int i = 0;
    while (n>0){
        n = n / (long long)10;
        i = i + 1;
    }
    return i;
}

long long seqlen(long long n) {
    long long result = 0, j = 1;
    int soChuSo = demChuSo(n), i = 1;
    while (i < soChuSo) {
        result += (long long)i*(long long)j*(long long)9;
        //cout << i << " - " << j << " - " << i*j*9 << "\n";
        ++i;
        j *= 10;

    }
    //cout << (j*(soChuSo-1) - 1) << "\n";
    long long conLai = (long long)n - (long long)j + (long long)1;
    //cout << conLai << "\n";
    result = result + conLai * (long long)i;
    return result;
}

int main(){
    freopen("SEQLEN.INP", "r", stdin);
    freopen("SEQLEN.OUT", "w", stdout);
    long long n, m;
    cin>>n;
    m = seqlen(n);
    cout<<m;
    return 0;
}
