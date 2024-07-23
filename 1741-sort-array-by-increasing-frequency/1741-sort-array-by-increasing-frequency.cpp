class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        std::map<int, int> sums;
        std::map<int, std::set<int, std::greater<int>>> sorted_sums;
        for (const auto & a: nums) {
            const int i = ++(sums[a]);
            sorted_sums[i].insert(a);
            sorted_sums[i - 1].erase(a);
        }
        std::vector<int> ret;
        for (const auto & b: sorted_sums) {
            for (const auto & c: b.second) {
                for (int i = 1; i <= b.first; i++) {
                    ret.push_back(c);
                }
            }
        }
        return ret;
    }
};