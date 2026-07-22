class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    int maxVowels(string s, int k) {
        int count = 0;

        // build first window
        for (int i = 0; i < k; i++)
            if (isVowel(s[i])) count++;

        int maxCount = count;

        // slide window
        for (int i = k; i < (int)s.size(); i++) {
            if (isVowel(s[i]))     count++;   // new char enters
            if (isVowel(s[i-k]))   count--;   // old char leaves
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};