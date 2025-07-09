class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int map[4000];

        for (int i = 0; i != 4000; i++) {
            map[i] = 0;
        }

        vector<int> ret;

        for (int i = 0; i != numbers.size(); i++) {
            int df = target - numbers[i];

            int index = df + 1000;

            if (map[index]) {
                ret.push_back(map[index]);
                ret.push_back(i + 1);
                return ret;
            }

            map[numbers[i] + 1000] = i + 1;
        }
        return ret;
    }
};