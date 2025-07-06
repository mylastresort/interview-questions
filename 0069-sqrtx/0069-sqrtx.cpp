class Solution {
public:
    int mySqrt(int x) {
        long l = 0;
        long m = x / 2;
        long h = x;

        if (x == 1)
            return 1;

        while (m * m != x) {
            if (m * m > x) {
                h = m;
                m -= (h - l) / 2;
            } else if (m * m < x) {
                l = m;
                m += (h - l) / 2;
            }
            if (h - l == 1 || l == h) {
                m = l;
                break;
            }
        }

        return m;
    }
};