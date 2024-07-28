class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char,char> matching {{'(',')'},{'{','}'},{'[',']'}};
        for(char c:s){
            if(matching.find(c)!=matching.end()){
                stk.push(c);
            }
            else{
                if(stk.empty()) return false;
                char prev = stk.top();
                if(matching[prev]!=c){
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};