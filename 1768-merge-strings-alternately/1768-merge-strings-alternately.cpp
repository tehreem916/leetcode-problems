class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i = 0;
        int n = word1.size();
        int m = word2.size();

        while (i < n && i < m) {
            res += word1[i];
            res += word2[i];
            i++;
        }

        if (i < n) res += word1.substr(i);
        if (i < m) res += word2.substr(i);

        return res;
    }
};