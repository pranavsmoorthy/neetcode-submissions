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

        std::size_t reps = s.length();
        for (std::size_t x = 0; x <= reps; x++) {
            if (s.length() == 1 && t.length() == 1) {
                return s[0] == t[0];
            }

            std::size_t index = t.find(s[x]);

            if (index == std::string::npos) {
                return false;
            } else {
                s.erase(x, 1);
                t.erase(index, 1);

                reps--;
                x = 0;

                //std::cout << s << ", " << t << std::endl;
            }
        }

        return s.length() == 0 && t.length() == 0;
    }
};
