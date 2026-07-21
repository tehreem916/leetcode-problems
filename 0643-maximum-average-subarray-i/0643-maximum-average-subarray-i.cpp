class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // build first window
        double windowSum = 0;
        for (int i = 0; i < k; i++)
            windowSum += nums[i];

        double maxSum = windowSum;

        // slide window
        for (int i = k; i < (int)nums.size(); i++) {
            windowSum += nums[i];         // add new element
            windowSum -= nums[i - k];     // remove old element
            maxSum = max(maxSum, windowSum);
        }

        return maxSum / k;
    }
};