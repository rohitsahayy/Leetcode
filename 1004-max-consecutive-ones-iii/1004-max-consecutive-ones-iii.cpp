class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0;
        int ans = 0;
        int count=0;
        for(right=0;right<nums.size();right++){
            if(nums[right]==0){
                count++;
            }
            while(count>k){
                if(nums[left]==0){
                    count--;
                }
                left++;
            }
            int len = right-left+1;
            ans = max(ans,len);
        }
        return ans;
    }
};