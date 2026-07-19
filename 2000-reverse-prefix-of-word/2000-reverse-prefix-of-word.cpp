class Solution {
public:
    string reversePrefix(string word, char ch) {
        int right = word.find(ch);    // find first occurrence

        if (right == string::npos)    // ch not found
            return word;

        int left = 0;

        while (left < right) {
            swap(word[left], word[right]);
            left++;
            right--;
        }

        return word;
    }
};