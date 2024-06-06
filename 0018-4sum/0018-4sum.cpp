class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> output;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long ijsum = nums[i]+nums[j];
                long long req = target-ijsum;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    if(nums[k]+nums[l]==req){
                        vector<int> innerOutput = {nums[i],nums[j],nums[k],nums[l]};
                        output.push_back(innerOutput);
                        k++;
                        l--;
                        while(k<l && nums[k]==innerOutput[2]) k++;
                        while(k<l && nums[l]==innerOutput[3]) l--;
                    }
                    else if(nums[k]+nums[l]>req){
                        l--;
                    }
                    else{
                        k++;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1]) j++; 
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return output;
    }
};