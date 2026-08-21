#include <string>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        if (s.length() == 1 && t.length() == 1) {
            return s[0] == t[0];
        }

        int freq[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for (int f : freq) {
            if (f != 0) {
                return false;
            }
        }

        return true;
    }
};
