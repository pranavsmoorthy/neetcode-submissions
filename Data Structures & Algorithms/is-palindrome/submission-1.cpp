class Solution {
public:
    bool isPalindrome(string s) {
        string alphanum = "";
        string alphanum_reversed = "";

        for (char c : s) {
            if (
                (c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9')
            ) {
                char lower = (char) tolower(c);
                alphanum += lower;
                alphanum_reversed = lower + alphanum_reversed;
            }
        }

        cout << alphanum << endl;
        cout << alphanum_reversed << endl;

        return alphanum == alphanum_reversed;
    }
};
