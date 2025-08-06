// Xe 1 đi trong vòng t1 giờ với tốc độ v1 km/giờ sau đó dùng lại t1 giờ để nạp năng lượng
// Xe 2 tương tự, xác định kết quả 2 xe đi với tốc độ x km
// distance of cycle, numbers of cycles, total distance, time stopping, remaining
#include <iostream>
#include <cstdio>
using namespace std;
/*int racing(int x, int t, int v){
    int kmMotVong = t*v;
    int soVong = x/kmMotVong;
    int soKm = kmMotVong*soVong;
    int thoiGian = t * soVong * 2;
    if(soKm == x){
        thoiGian = thoiGian - t;
    } else{
        thoiGian = thoiGian + (x-soKm+v-1)/v;
    }
    return thoiGian;
}*/
/*double racing(int x, int t, int v){
    double kmMotVong = t*v;
    double soVong = x/kmMotVong;
    double soKm = kmMotVong*soVong;
    double thoiGian = t * soVong * 2;
    if(soKm == x){
        thoiGian = thoiGian - t;
    } else{
        thoiGian = thoiGian + (x-soKm)/v;
    }
    return thoiGian;
}*/
double racing(int x, int t, int v){
    int kmMotVong = t*v;
    int soVong = x/kmMotVong;
    int soKm = kmMotVong*soVong;
    double thoiGian = t * soVong * 2;
    if(soKm == x){
        thoiGian = thoiGian - t;
    } else{
        thoiGian = thoiGian + ((double)x-(double)soKm)/(double)v;
    }
    return thoiGian;
}
int main(){
    freopen("RACING.INP", "r", stdin);
    freopen("RACING.OUT", "w", stdout);
    int t1, v1, t2, v2, x;
    cin>>t1>>v1>>t2>>v2>>x;
    double thoiGian1 = racing(x, t1, v1);
    double thoiGian2 = racing(x, t2, v2);
    if(thoiGian1 == thoiGian2){
        cout<<"DRAW";
    } else if (thoiGian1 < thoiGian2){
        cout<<"FIRST";
    } else{
        cout<<"SECOND";
    }
    return 0;
}
