class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";

        unordered_map<char,int> tFreq;
        for (char c : t) tFreq[c]++;

        unordered_map<char,int> window;
        int have = 0;
        int need = (int)tFreq.size();   // unique chars needed

        int left = 0;
        int minLen = INT_MAX;
        int resLeft = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            // expand window
            char c = s[right];
            window[c]++;

            // check if this char satisfies a requirement
            if (tFreq.count(c) && window[c] == tFreq[c])
                have++;

            // shrink window while valid
            while (have == need) {
                // update result
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    resLeft = left;
                }

                // shrink from left
                char leftChar = s[left];
                window[leftChar]--;
                if (tFreq.count(leftChar) && window[leftChar] < tFreq[leftChar])
                    have--;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(resLeft, minLen);
    }
};