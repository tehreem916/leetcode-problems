class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);   // idx = [0,1,2,...,n-1]

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return heights[a] > heights[b];
        });

        vector<string> result(n);
        for (int i = 0; i < n; i++)
            result[i] = names[idx[i]];

        return result;
    }
};