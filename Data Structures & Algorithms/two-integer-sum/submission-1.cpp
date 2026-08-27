#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> indices;

        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]] = i;
        }

        vector<int> coords = {0,0};
        for (int i = 0; i < nums.size(); i++) {
            if (indices.count(target - nums[i]) && indices[target - nums[i]] != i) {
                coords = {i, indices[target - nums[i]]};
                return coords;
            }
        }

        return coords;
    }
};
