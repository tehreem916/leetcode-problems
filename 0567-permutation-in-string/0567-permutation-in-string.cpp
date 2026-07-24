class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> need(26, 0), window(26, 0);
        for (char c : s1) need[c - 'a']++;

        for (int i = 0; i < m; i++) {
            window[s2[i] - 'a']++;               // add new char (right)

            if (i >= n)
                window[s2[i - n] - 'a']--;        // remove old char (left)

            if (i >= n - 1 && window == need)     // window fully formed & matches
                return true;
        }

        return false;
    }
};