class Solution {
public:
    char findTheDifference(string s, string t) {
        int smap[26];
        int tmap[26];
        for (int i = 0; i != s.length(); i++) {
            smap[s[i] - 'a'] += 1;
            tmap[t[i] - 'a'] += 1;
        }
        tmap[t[t.length() - 1] - 'a'] += 1;
        for (int i = 0; i != 26; i++) {
            if (smap[i] != tmap[i]) {
                return char(i + 'a');
            }
        }
        return '\0';
    }
};