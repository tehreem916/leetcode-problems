class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0;   // scans even indices
        int odd  = 1;   // scans odd indices

        while (even < nums.size() && odd < nums.size()) {
            // find misplaced odd at even index
            while (even < nums.size() && nums[even] % 2 == 0)
                even += 2;
            // find misplaced even at odd index
            while (odd < nums.size() && nums[odd] % 2 != 0)
                odd += 2;

            if (even < nums.size() && odd < nums.size()) {
                swap(nums[even], nums[odd]);
                even += 2;
                odd  += 2;
            }
        }

        return nums;
    }
};