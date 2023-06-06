class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int num = x;
        while (num != 0) {
            int low = num % 10;
            num = num / 10;
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && low > 7)) {
                return 0;
            }
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && low < -8)) {
                return 0;
            }
            ans = ans * 10 + low;
        }
        return ans;
    }
};