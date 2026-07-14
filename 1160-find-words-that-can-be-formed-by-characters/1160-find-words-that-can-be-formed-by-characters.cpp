class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int result = 0;
        int charsFreq[26] = {0};

        // build chars frequency once
        for (char c : chars)
            charsFreq[c - 'a']++;

        for (string word : words) {
            int wordFreq[26] = {0};

            // build word frequency
            for (char c : word)
                wordFreq[c - 'a']++;

            // compare
            bool good = true;
            for (int i = 0; i < 26; i++) {
                if (wordFreq[i] > charsFreq[i]) {
                    good = false;
                    break;
                }
            }

            if (good) result += word.length();
        }

        return result;
    }
};