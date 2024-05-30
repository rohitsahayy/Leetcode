class Solution {
public:
    int majorityElement(vector<int>& nums) {
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
    }
};