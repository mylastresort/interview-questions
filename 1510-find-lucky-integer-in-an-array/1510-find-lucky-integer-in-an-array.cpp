class Solution {
public:
    int findLucky(vector<int>& arr) {
        int map[500] = {0};

        for (auto i : arr) {
            map[i - 1]++;
        }

        for (int i = 499; i != -1; i--) {
            if (map[i] == i + 1)
                return i + 1;
        }
        return -1;
    }
};