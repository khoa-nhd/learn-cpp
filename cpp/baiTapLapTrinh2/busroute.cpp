#include <iostream>
#include <cstdio>
using namespace std;
#define maxN 1000000

int a[maxN], n, di, b;

void readData(){
    cin>>di>>b>>n;
}

int busroute(){
    int gia, soDiem, diem, giaHienTai = 0, giaThapNhap = -1;
    bool founda = false;
    for(int i = 0; i<n; ++i){
        cin>>gia>>soDiem;
        founda = false;
        for(int j = 0; j<soDiem; ++j){
            cin>>diem;
            if(diem == di){
                founda = true;
            }
            if(founda){
                if(diem == b){
                    giaHienTai = gia;
                    if(giaThapNhap > giaHienTai || giaThapNhap == -1){
                        giaThapNhap = giaHienTai;
                    }
                }
            }
        }
    }
    return giaThapNhap;
}

int main(){
    freopen("BUSROUTE.INP", "r", stdin);
    freopen("BUSROUTE.OUT", "w", stdout);
    readData();
    int result;
    result = busroute();
    cout<<result;
    return 0;
}

