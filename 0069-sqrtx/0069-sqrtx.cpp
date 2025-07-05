class Solution {
public:
    int mySqrt(int x) {
        long ret = 0;
        while (ret * ret < x) {
            ret++;
        }
        return ret * ret == x ? ret : ret - 1;
    }
};