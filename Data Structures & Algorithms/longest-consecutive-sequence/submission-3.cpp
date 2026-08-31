class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        nums.insert(nums.begin(), nums[0] - 1);

        for (int i : nums) {
            cout << i << " ";
        }
        // cout << endl;

        vector<vector<int>> seq;
        vector<int> working = {};

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == 1) {
                working.push_back(nums[i]);
                // std::cout << nums[i] << " ";
            } else if (nums[i] - nums[i - 1] == 0) {
                continue;
            } else {
                seq.push_back(working);
                working.clear();
                working.push_back(nums[i]);
                // std::cout << endl;
            }
        }

        seq.push_back(working);

        int val = 0;
        for (vector<int> v : seq) {
            if (v.size() > val) {
                val = v.size();
            }
        }

        return val;
    }
};
