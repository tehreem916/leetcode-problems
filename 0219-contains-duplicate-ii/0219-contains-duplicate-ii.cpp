class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < (int)nums.size(); i++) {
            // duplicate found within window
            if (window.count(nums[i]))
                return true;

            window.insert(nums[i]);

            // shrink window to size k
            if ((int)window.size() > k)
                window.erase(nums[i - k]);
        }

        return false;
    }
};