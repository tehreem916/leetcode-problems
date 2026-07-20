class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge = "";
        int i = 0, j = 0;
        int n = word1.size(), m = word2.size();

        while (i < n && j < m) {
            // compare remaining substrings from current positions
            if (word1.substr(i) >= word2.substr(j)) {
                merge += word1[i++];
            } else {
                merge += word2[j++];
            }
        }

        // append remaining
        while (i < n) merge += word1[i++];
        while (j < m) merge += word2[j++];

        return merge;
    }
};