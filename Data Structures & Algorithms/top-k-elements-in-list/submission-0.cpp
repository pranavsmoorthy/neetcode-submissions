class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        vector<int> val;

        for (int n : nums) {
            if (freq.find(n) == freq.end()) {
                freq[n] = 0;
            }

            freq[n]++;
        }
        
        priority_queue<pair<int, int>> freq_queue;
        for (const auto& fr : freq) {
            freq_queue.push({fr.second, fr.first});
        }

        for (int i = 0; i < k && !freq_queue.empty(); i++) {
            val.push_back(freq_queue.top().second);
            freq_queue.pop();
        }

        return val;
    }
};
