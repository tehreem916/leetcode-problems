class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;   // edge case: no product can be < 1

        int left = 0;
        int product = 1;
        int count = 0;

        for (int right = 0; right < (int)nums.size(); right++) {
            product *= nums[right];

            // shrink window while product >= k
            while (product >= k) {
                product /= nums[left];
                left++;
            }

            // all subarrays ending at right within window are valid
            count += right - left + 1;
        }

        return count;
    }
};