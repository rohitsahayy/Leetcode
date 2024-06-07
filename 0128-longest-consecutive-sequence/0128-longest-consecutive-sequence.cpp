class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Brute Force :
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count = 1;
        int ans = 1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            if (nums[i]==nums[i-1]+1){
                count++;
                ans = max(ans,count);
            }
            else{
                count=1;
            }
        }
        return ans; 

    }
};