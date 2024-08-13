class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        getSubset(nums,ans,subset,0);
        return ans;
    }

    void getSubset(vector<int>&nums,vector<vector<int>>&ans,vector<int>&subset,int index){
        if(index==nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        getSubset(nums,ans,subset,index+1);
        subset.pop_back();
        getSubset(nums,ans,subset,index+1);
    }
};