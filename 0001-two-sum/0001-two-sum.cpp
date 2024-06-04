class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* BRUTE FORCE
        vector<int> output;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int present = nums[i];
            int req = target-present;
            if(mp.find(req) != mp.end()){
                return {mp[req],i};
            }
            mp[present] = i;
        }
        return {-1,-1};
        */

    vector<pair<int,int>> a;
    for(int i=0;i<nums.size();i++){
        a.push_back({nums[i],i});
    }
    sort(a.begin(),a.end());

    int left = 0;
    int right = a.size()-1;
    while(left<=right){
        if(a[left].first+a[right].first==target){
            return {a[left].second,a[right].second};
        }
        else if(a[left].first+a[right].first>target){
            right--;
        }
        else{
            left++;
        }
    }
    return {-1,-1};
    }
};