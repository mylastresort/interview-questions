struct Comp {
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) const {
        return a.second < b.second;
    }
};

class Solution {
public:

    string frequencySort(string s) {
        unordered_map<char, int> map;

        for (auto c : s) {
            if (map.count(c))
                map[c]++;
            else
                map[c] = 1;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, Comp> h;

        for (auto c : map) {
            h.push(make_pair(c.first, c.second));
        }

        string sol;
        sol.reserve(s.size());
        while (h.size()) {
            auto i = h.top();
            sol.append(i.second, i.first);
            h.pop();
        }

        return sol;
    }
};