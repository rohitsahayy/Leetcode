class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<int> stk;
        for(int i =0 ;i<temperatures.size();i++){
            while(!stk.empty() && temperatures[i]>temperatures[stk.top()]){
                int j = stk.top();
                ans[j] = i-j;
                stk.pop();
            }
            stk.push(i);
        }
            return ans;
        }
};