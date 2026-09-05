class Solution {
public:
    int sumSquares(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = sumSquares(n);

        while (fast != 1 && slow != fast) {
            slow = sumSquares(slow);           
            fast = sumSquares(sumSquares(fast)); 
        }

        return fast == 1;
    }
};