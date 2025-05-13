class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int map[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; i != s.size(); i++) {
            map[s[i] - 'a'] += 1;
        }
        for (int i = 1; i <= t; i++) {
            int cache[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int j = 0; j != 26; j++) {
                if (!map[j])
                    continue;
                if ('z' == j + 'a') {
                    cache[0] = map[25];
                    cache[1] = cache[1] % 1000000007 + map[25] % 1000000007;
                    continue;
                }
                cache[j + 1] = map[j];
            }
            for (int i = 0; i != 26; i++) {
               map[i] = cache[i];
            }
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            // cout << char(i + 'a') << " " << map[i] << endl;
            count = count  % 1000000007 + map[i] % 1000000007;
        }
        return count % 1000000007;
    }
};