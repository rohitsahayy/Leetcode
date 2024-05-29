class Solution {
public:
    bool binary_search(vector<int>&matrix,int target){
        int flag = 0;
        int low = 0;
        int high = matrix.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[mid]==target){
                return true;
            }
            else if(matrix[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //brute force solution:
        /* 
        for(int i=0;i<matrix.size();i++){
             for(int j=0;j<matrix[0].size();j++){
                 if(matrix[i][j]==target){
                     return true;
                }
            }
        }
        return false;
        */

        
        //optimal : 
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                bool flag = binary_search(matrix[i],target);
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }
};