class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int total = 1 << k;   // 2^k total codes needed
        unordered_set<string> seen;

        for (int i = 0; i <= (int)s.size() - k; i++) {
            seen.insert(s.substr(i, k));

            // early exit — found all codes
            if ((int)seen.size() == total)
                return true;
        }

        return false;
    }
};