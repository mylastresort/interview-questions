class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;

        vector<vector<int>> counts(nums.size() + 1, vector<int>());

        int map[20001];

        for (int i = 0; i != 20001; i++) {
            map[i] = 0;
        }

        for (auto a : nums) {
            int ct = map[a + 10000];

            auto old = find(counts[ct].begin(), counts[ct].end(), a);

            if (old != counts[ct].end()) {
                counts[ct].erase(old);
            }
            ct++;
            counts[ct].push_back(a);

            map[a + 10000]++;
        }

        for (auto i = counts.rbegin(); i != counts.rend() && k; i++) {
            if (i->size() >= 1) {
                for (auto n : *i) {
                    ret.push_back(n);
                    k--;
                }
            }
        }

        return ret;
    }
};