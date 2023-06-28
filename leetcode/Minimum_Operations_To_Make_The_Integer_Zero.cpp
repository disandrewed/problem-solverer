class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num1 < num2) {
            return -1;
        }
        if (num1 == 0) {
            return 0;
        }
        for (long long ans = 0; ans <= 50; ans++) { 
            long long diff = num1 - 1LL*(num2) * ans; 

            long long bits = 0;
            long long copy = diff;
            while (copy > 0) {
                bits += copy & 1;
                copy >>= 1;
            }

            if (bits <= ans && ans <= diff) { 
                return ans; 
            } 
        }
        return -1;
    }
};