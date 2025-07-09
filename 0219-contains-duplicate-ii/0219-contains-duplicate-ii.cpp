class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> map;

        for (int i = 0, j = 0; j != nums.size(); j++) {
            if (j > k) {
                map.erase(nums[i]);
                i++;
            }
            if (i != j && map.find(nums[j]) != map.end())
                return true;
            map.insert(nums[j]);
        }
        return false;
    }
};