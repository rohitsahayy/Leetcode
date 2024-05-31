class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /* O(N) :SC
        unordered_map<int,int> mp1;
        for(auto num:nums){
            mp1[num]++;
        }

    int max_count = 0;
    int majority = 0;
    for(auto pair:mp1){
        if(pair.second>max_count){
            max_count = pair.second;
            majority = pair.first;
        }
    }
    return majority;
    */

    //For O(1) SC:

    int majority = nums[0];
    int vote = 1;
    for(int i=1;i<nums.size();i++){
        if(vote==0){
            majority=nums[i];
            vote=1;
        }
        else if(majority==nums[i]){
            vote++;
        }
        else{
            vote--;
        }
    }

    return majority;

    }
};