class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int map[10];
        for (int i = 0; i != digits.size(); i++) {
            map[digits[i]] += 1;
        }
        vector<int> ret;
        for (int i = 100; i != 1000; i++) {
            if (i % 2 == 1) {
                continue;
            }
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;

            if (!map[a] || !map[b] || !map[c]) {
                continue;
            }

            if (a == b && b == c) {
                if (map[a] >= 3) {
                    ret.push_back(i);
                }
            } else if ((a == b && map[a] >= 2) || (a == c && map[a] >= 2) ||
                       (b == c && map[b] >= 2) ||
                       (a != b && a != c && b != c)) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};