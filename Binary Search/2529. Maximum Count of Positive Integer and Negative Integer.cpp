#include<stdio.h>
#include<stdlib.h>

class Solution{
public:
    int maximumCount(vector<int> &nums){
        int n = nums.size();
        int i=0,j=n-1;
        int neglast = 0;
        int posfirst = 0;
        int poslast = 0;
        int p=0;
        int neg=0;

        if(nums[0]==0 && nums[n-1]==0){
                return 0;
            }
                /// finding last negative occurance
                while(i<=j){
                    int mid = i+(j-i)/2;
                    if(nums[mid]<0){
                        neglast = mid;
                        i=mid+1;
                    }

                    else if(nums[mid]>=0){
                        j=mid-1;
                    }
                }

                i=0;j=n-1;
                // finding first positive occurance
                while(i<=j){
                    int mid = i+(j-i)/2;

                    if(nums[mid]>0){
                        posfirst = mid;
                        j=mid-1;
                    }

                    else if(nums[mid]<=0){
                        i=mid+1;
                    }
                }
                if(nums[n-1]>0){
                    poslast = n-1;
                }

                p = poslast-posfirst+1;
                neg = neglast-0+1;

                return max(p,neg);
    }
}

int main()
{
    Solution solution;
    vector<int> nums = {2,3,4,-1,-2,3,9,-9};
    int maxCount = solution.maximumCount(nums);
    cout<<maxCount;
    
    return 0;
}
