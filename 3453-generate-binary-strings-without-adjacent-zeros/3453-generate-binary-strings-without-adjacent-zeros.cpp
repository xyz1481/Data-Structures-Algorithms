class Solution {
private:
    void f(int index,int n,string &sub,vector<string> &ans){
        if(index == n){
            ans.push_back(sub);
            return;
        }
            if(sub.empty() || sub.back() !='0'){
                sub += '0';
                f(index+1,n,sub,ans);
                sub.pop_back(); 
            }
            sub += '1';
            f(index+1,n,sub,ans);
            sub.pop_back();
    }
public:
    vector<string> validStrings(int n) {
        string sub;
        vector<string> ans;
        f(0,n,sub,ans);
        return ans;
    }
};


