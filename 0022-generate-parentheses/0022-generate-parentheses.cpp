class Solution {
private :
    void f(int close,int open,int cnt,vector<string> &ans,string &sub){
        if(cnt<0) return;
        if(close ==0 && open ==0){
            ans.push_back(sub);
            return;
        }
        if(open){
            sub += '(';
            f(close,open-1,cnt+1,ans,sub);
            sub.pop_back();
        }
        if(close){
            sub += ')';
            f(close-1,open,cnt-1,ans,sub);
            sub.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string sub;
        f(n,n,0,ans,sub);
        return ans;
    }
};