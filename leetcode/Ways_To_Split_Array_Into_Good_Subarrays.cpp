class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int sz = nums.size();
        vector<long long> gaps;
        int sw = -1;
        int cnt = 0;
        for (int i = 0; i < sz; i++) {
            if (sw == 1 && nums[i] == 0) {
                cnt++;
            }
            if (nums[i] == 1 && sw == 1) {
                cnt++;
                gaps.push_back(cnt);
                cnt = 0;
            }
            if (nums[i] == 1 && gaps.empty()) {
                sw *= -1;
            }
        }
        
        long long ans = 1;
        if (gaps.empty() && sw == -1) {
            return 0;
        }
        for (auto n : gaps) {
            ans = (ans * n) % 1000000007;
        }
        return ans;
    }
};