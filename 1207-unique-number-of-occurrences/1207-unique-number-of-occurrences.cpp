class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (int num : arr)
            freq[num]++;

        unordered_set<int> countSet;
        for (auto& p : freq)
            countSet.insert(p.second);

        return freq.size() == countSet.size();
    }
};