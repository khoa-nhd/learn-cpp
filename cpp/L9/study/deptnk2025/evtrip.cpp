#include <iostream>
#include <cstdio>
using namespace std;

int code(int station, int maxcharge, int target)
{
    int result = -1, km[1001] = {}, i = 0;
    for (i = 0; i < station; ++i)
    {
        cin >> km[i];
        if (i > 0 && km[i] - km[i - 1] > maxcharge)
        {
            return -1;
        }
        if (i == 0 && km[i] > maxcharge)
        {
            return -1;
        }
        if (i == station && target - km[i] > maxcharge)
        {
            return -1;
        }
    }
    km[i] = target;
    i = 0;
    while (i < station)
    {
        while (i < station - 1 && (km[i + 1] - km[i]) + (km[i + 2] - km[i + 1]) < maxcharge)
        {
            km[i] = 0;
            i += 1;
        }
        i += 1;
    }
    i = 0;
    while (i <= station)
    {
        if (km[i] > 0)
        {
            result += 1;
        }
        i += 1;
    }
    return result;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("result.txt", "w", stdout);
    int result, target, maxcharge, station;
    cin >> station >> maxcharge >> target;
    result = code(station, maxcharge, target);
    cout << result;
    return 0;
}
