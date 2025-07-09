class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>*> map;

        vector<vector<string>> ret;

        for (auto s : strs) {
            string c(s);

            sort(c.begin(), c.end());

            if (map.count(c)) {
                map[c]->push_back(s);
            } else {
                vector<string> *grp = new vector<string>();
                map[c] = grp;
                grp->push_back(s);
            }
        }

        for (auto grp: map) {
            ret.push_back(*grp.second);
        }

        return ret;
    }
};