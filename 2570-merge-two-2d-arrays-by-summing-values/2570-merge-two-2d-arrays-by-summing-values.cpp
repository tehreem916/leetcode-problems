class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        int p1 = 0, p2 = 0;

        while (p1 < nums1.size() && p2 < nums2.size()) {
            int id1 = nums1[p1][0], val1 = nums1[p1][1];
            int id2 = nums2[p2][0], val2 = nums2[p2][1];

            if (id1 < id2) {
                result.push_back({id1, val1});
                p1++;
            } else if (id1 > id2) {
                result.push_back({id2, val2});
                p2++;
            } else {
                result.push_back({id1, val1 + val2});
                p1++; p2++;
            }
        }

        // leftover elements
        while (p1 < nums1.size()) result.push_back(nums1[p1++]);
        while (p2 < nums2.size()) result.push_back(nums2[p2++]);

        return result;
    }
};