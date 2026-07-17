class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);

        int left = 0;                  // next position for less
        int right = n - 1;             // next position for greater
        int pivotCount = 0;

        // count pivots first
        for (int num : nums)
            if (num == pivot) pivotCount++;

        // middle section boundaries
        int mid = left;                // will be filled after less section
        // we need to know where middle starts
        // first count how many less elements
        int lessCount = 0;
        for (int num : nums)
            if (num < pivot) lessCount++;

        // fill result in one pass
        int li = 0;               // index for less section
        int mi = lessCount;       // index for equal section
        int gi = lessCount + pivotCount;  // index for greater section

        for (int num : nums) {
            if (num < pivot)       result[li++] = num;
            else if (num == pivot) result[mi++] = num;
            else                   result[gi++] = num;
        }

        return result;
    }
};