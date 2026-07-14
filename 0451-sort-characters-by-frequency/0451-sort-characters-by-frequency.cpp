class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for (char c : s)
            freq[c]++;

        // buckets[i] = list of chars with frequency i
        int n = s.length();
        vector<vector<char>> buckets(n + 1);

        for (auto& p : freq)
            buckets[p.second].push_back(p.first);

        string result = "";
        // read from highest frequency to lowest
        for (int i = n; i >= 1; i--) {
            for (char c : buckets[i]) {
                result += string(i, c);  // repeat char i times
            }
        }

        return result;
    }
};