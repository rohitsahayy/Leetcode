#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int result = 0;
        int left = 0;
        int right = nums.size()-1;
        if(nums[n-1]!=n){
            return n;
        }
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==mid){
                left = mid+1;
            }
            else if(nums[mid]>mid){
                result = mid;
                right = mid - 1;
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> arr = {1,4,3,5,7,9,0,2,8};
    int res = solution.missingNumber(arr);
    return res;
}
