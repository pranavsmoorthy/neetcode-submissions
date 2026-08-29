class Solution {
public:

    string encode(vector<string>& strs) {
        string val = "";

        for (string s : strs) {
            for (char c : s) {
                val += to_string(static_cast<int>(c));
                val += "+";
            }

            val += "_";
        }

        return val;
    }

    vector<string> decode(string s) {
        cout << s << endl;
        vector<string> vect;

        string working_string = "";
        string working_char = "";

        for (char c : s) {
            if (c == '_') {
                vect.push_back(working_string);
                working_string = "";
                cout << "newline" << endl;
            } else if (c == '+') {
                int representation = 0;

                if (working_char.size() == 1) {
                    representation = working_char[0] - '0';
                } else if (working_char.size() == 2) {
                    representation = working_char[1] - '0';
                    representation += (working_char[0] - '0') * 10;
                } else {
                    representation = working_char[2] - '0';
                    representation += (working_char[1] - '0') * 10;
                    representation += (working_char[0] - '0') * 100;
                }

                cout << working_char << "  " << representation << "  " << static_cast<char>(representation) << endl;
                working_string += static_cast<char>(representation);
                working_char = "";
            } else {
                working_char += c;
            }
        }

        return vect;
    }
};
