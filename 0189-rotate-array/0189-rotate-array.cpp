class Solution {
public:
    // two pointer reverse helper
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;               // handle k > n

        reverse(nums, 0, n-1);   // step 1: reverse whole
        reverse(nums, 0, k-1);   // step 2: reverse first k
        reverse(nums, k, n-1);   // step 3: reverse rest
    }
};