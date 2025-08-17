#include <bits/stdc++.h>
#include <chrono> // thêm để đo thời gian
using namespace std;
using namespace std::chrono;

int dem = 0;

long long chia(int pt, int hs){
    dem += 1;
    if(hs == 0){
        return 0;
    }
    if(pt == 0){
        return 1;
    }
    if(pt < hs){
        return chia(pt, pt);
    }
    return chia(pt, hs-1) + chia(pt-hs, hs);
}

long long chia2(int pt, int hs){
    long long a[pt+1][hs+1] = {};
    for(int i = 0; i <= pt; ++i){
        a[i][0] = 0;
    }
    for(int i = 0; i <= hs; ++i){
        a[0][i] = 1;
    }
    for(int i = 1; i <= pt; ++i){
        a[i][1] = 1;
    }
    for(int i = 2; i <= hs; ++i){
        for(int j = 1; j <= pt; ++j){
            if(i > j){
                a[j][i] = a[j][i-1];
            } else{
                a[j][i] = a[j][i-1] + a[j-i][i];
            }
            dem += 1;
        }
    }
    return a[pt][hs];
}

long long chia3(int pt, int hs){
    if(pt == 0) return 1;
    if(hs == 0) return 0;
    if(hs == 1) return 1;
    if(pt < hs) hs = pt;
    long long a[pt + 1];
    for(int i = 0; i <= pt; ++i){
        a[i] = 1;
    }
    for(int i = 2; i <= hs; ++i){
        for(int j = i; j <= pt; ++j){
            a[j] = a[j] + a[j-i];
            dem += 1;
        }
    }
    return a[pt];
}

int main(){
    // bắt đầu đo thời gian
    auto start = high_resolution_clock::now();

    long long m = chia3(7, 10);
    cout << m << "\n";
    cout << dem << "\n";

    // kết thúc đo thời gian
    auto end = high_resolution_clock::now();
    duration<double> duration_sec = end - start;

    cout << "Thoi gian chay: " << duration_sec.count() << " giay" << endl;

    return 0;
}
