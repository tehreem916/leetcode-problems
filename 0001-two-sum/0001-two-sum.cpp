class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> paired(n);

        // save value with original index
        for (int i = 0; i < n; i++)
            paired[i] = {nums[i], i};

        // sort by value
        sort(paired.begin(), paired.end());

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int sum = paired[left].first + paired[right].first;

            if (sum == target)
                return {paired[left].second, paired[right].second};
            else if (sum < target)
                left++;
            else
                right--;
        }

        return {};
    }
};