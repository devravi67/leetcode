class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if(n == 0) return result;  // if empty array, return empty result
        
        int start = nums[0]; // starting point of current range
        
        for(int i = 1; i <= n; i++) {
            // if we reached the end OR sequence breaks
            if(i == n || nums[i] != nums[i-1] + 1) {
                if(start == nums[i-1]) {
                    // single number range
                    result.push_back(to_string(start));
                } else {
                    // multiple numbers range
                    result.push_back(to_string(start) + "->" + to_string(nums[i-1]));
                }
                // update start for next range (if not end)
                if(i < n) start = nums[i];
            }
        }
        return result;
    }
};
