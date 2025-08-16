#include <iostream>
#include <chrono>
#include <iomanip> // For std::fixed and std::setprecision

using namespace std;

long long gcd(long long x, long long y){
    long long m = 0;
    if (x == 0){
        return y;
    }
    if (y == 0){
        return x
    }
    while(y != 0){
        m = x;
        x = y;
        y = m % y;
    }
    return x;
}

long long lcm(long long x, long long y){
    long long m = gcd(x, y);
    return x * y / m;
}

int main(){
    long long x = 3, y = 6, m, n;

    // Start time
    auto start = chrono::high_resolution_clock::now();

    m = gcd(x, y);
    n = lcm(x, y);
    cout << "UCLN " << m << "\n";
    cout << "BCNN " << n << "\n";

    // End time
    auto end = chrono::high_resolution_clock::now();

    // Duration in seconds (as double)
    chrono::duration<double> duration = end - start;

    // Output in fixed-point format with 6 decimal places
    cout << fixed << setprecision(6);
    cout << "Execution time: " << duration.count() << " seconds" << endl;

    return 0;
}
