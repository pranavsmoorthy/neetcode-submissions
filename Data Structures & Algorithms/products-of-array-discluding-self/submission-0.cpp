class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products;

        //product without 0
        int total_product = 1;
        int zero_count = 0;
        for (int n : nums) {
            if (n != 0){
                total_product *= n;
            } else {
                zero_count++;
            }
        }

        if (zero_count > 1) {
            for (int i = 0; i < nums.size(); i++) {
                products.push_back(0);
            }
        } else if (zero_count == 1) {
            for (int n : nums) {
                if (n == 0) {
                    products.push_back(total_product);
                } else {
                    products.push_back(0);
                }
            }
        } else {
            for (int n : nums) {
                products.push_back(total_product/n);
            }
        }

        return products;
    }
};
