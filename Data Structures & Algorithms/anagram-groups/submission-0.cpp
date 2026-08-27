class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) {
            return {};
        }

        if (strs.size() == 1) {
            return {{strs[0]}};
        }

        map<string, vector<string>> str_map;

        for (string str : strs) {
            string sorted_string = str;
            std::sort(sorted_string.begin(), sorted_string.end());

            if (str_map.find(sorted_string) == str_map.end()) {
                str_map[sorted_string] = {};
            }

            str_map[sorted_string].push_back(str);
        }

        vector<vector<string>> val;

        for (const auto& s : str_map) {
            val.push_back(s.second);
        }

        return val;
    }
};
