class Solution {
public:
    bool isPalin(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left  = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                // try skipping left OR skipping right
                return isPalin(s, left+1, right) ||
                       isPalin(s, left, right-1);
            }
            left++;
            right--;
        }

        return true;   
    }
};