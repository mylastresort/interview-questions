class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        std::map<int, std::vector<int>, std::greater<int>> sorted_map;
        for (const auto &b : nums) {
            int num = b;
            std::vector<int> digits;
            if (num == 0) digits.push_back(mapping[0]);
            while (num) {
                int digit = num % 10;
                // cout << "digit" << digit << endl;
                digits.push_back(mapping[digit]);
                num /= 10;
            }
            int i = 0;
            for (int s = digits.size() - 1; s != -1; s--) {
                i += digits[s] * std::pow(10, s);
            }
            // std::cout << i << std::endl;
            auto &vec = (sorted_map[i]);
            vec.push_back(b);
        }
        std::vector<int> ret;
        for (const auto & v : sorted_map) {
            cout << "first" << v.first;
            for (const auto & n: v.second) {
                cout << " " << n;
            }
            cout << endl;
            ret.insert(ret.begin(), v.second.begin(), v.second.end());
        }
        return ret;
    }
};