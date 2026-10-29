class Solution {
public:
    double angleClock(int hour, int minutes) {
        double phut = minutes * 6;
        double gio = (double)(hour%12) * 30 + (double)minutes * 0.5;
        double res = abs(phut - gio);
        if(res > 180) res = 360 - res;
        return res;
    }
};