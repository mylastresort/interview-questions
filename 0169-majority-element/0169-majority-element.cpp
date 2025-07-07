class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int pmax = 0;
        int pval = nums[0];
        int max = 0;
        int val = nums[0];
        for (auto i: nums) {
            if (i == val) {
                max++;
            } else {
                if (pmax < max) {
                    pmax = max;
                    pval = val;
                }
                max = 1;
                val = i;
            }
        }

        return pmax > max ? pval : val;
    }
};