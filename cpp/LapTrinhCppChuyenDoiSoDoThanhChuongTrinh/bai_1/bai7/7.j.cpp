//Cho số nguyên dương n. Thiết kế thuật toán thực hiện
// j) Tìm chứ số lớn nhất và số lượng chữ số lớn nhất của n
#include <iostream>
#include <cmath>
using namespace std;

void tinhGiaTri(int n, int &maxVal, int &maxNum)
{
    while (n>0) {
        if (n%10 > maxVal){
            maxVal = n%10;
            maxNum = 1;
        } else{
            if(n%10 == maxVal)
            {
                maxNum = maxNum + 1;
            }
        }
        n = n / 10;
    }
}

int main()
{
    int n, maxVal = 0, maxNum = 0;
    cin>>n;
    tinhGiaTri(n, maxVal, maxNum);
    cout<<maxVal<<" "<<maxNum;
    return 0;
}
