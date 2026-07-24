class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;    // stores indices
        vector<int> result;
        int n = (int)nums.size();

        for (int i = 0; i < n; i++) {
            // remove elements outside window from front
            while (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();

            // remove smaller elements from back (they're useless)
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // window is fully formed
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};