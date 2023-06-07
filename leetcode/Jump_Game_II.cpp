class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int reach = 0;
        int furthest = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            furthest = max(furthest, i + nums[i]);
            if (i == reach) {
                ans++;
                reach = furthest;
            }
        }
        return ans;
    }
};