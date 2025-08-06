// Cho bảng nhân số
// Tô tất cả số màu đen, các số chẵn màu đỏ, số chia hết cho 3 thành màu xanh lá cây, số chia hết cho 5 màu xanh da trời
// Cho biết số lượng màu theo thứ tự đỏ, xanh lá cây, xanh da trời, đen
#include <iostream>
#include <cstdio>
using namespace std;

void coloring(int m, int n){
    int dor = 0, xanh = 0, troi = 0, den = 0, value = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            value = i*j;
            if(value%5 == 0){
                troi += 1;
            } else if(value%3 == 0){
                xanh += 1;
            } else if(value%2 == 0){
                dor += 1;
            } else{
                den += 1;
            }
        }
    }
    cout<<dor<<"\n";
    cout<<xanh<<"\n";
    cout<<troi<<"\n";
    cout<<den<<"\n";
}

int main(){
    freopen("COLORING.INP", "r", stdin);
    freopen("COLORING.OUT", "w", stdout);
    int n, m;
    cin>>m>>n;
    coloring(m, n);
    return 0;
}
