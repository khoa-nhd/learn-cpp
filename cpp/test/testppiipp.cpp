#include <iostream>
#include <cstdio>
#include <chrono>

using namespace std;

int main() {
    // Bắt đầu đo thời gian
    auto start = chrono::high_resolution_clock::now();
    int x;
    // Đoạn code cần đo
    for (int i = 0; i <= 1000000000; i++) {
        x = i;
    }

    // Kết thúc đo thời gian
    auto end = chrono::high_resolution_clock::now();

    // Tính và in ra thời gian chạy dưới dạng giây (double)
    chrono::duration<double> duration = end - start;
    cout << "Thoi gian chay: " << duration.count() << " giay" << endl;

    return 0;
}
