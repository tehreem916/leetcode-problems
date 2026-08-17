class Solution {
public:
    int findTheWinner(int n, int k) {
        int pos = 0;   // winner position in 0-indexed circle of size 1

        for (int m = 2; m <= n; m++) {
            pos = (pos + k) % m;   
        }

        return pos + 1;   // convert to 1-indexed
    }
};