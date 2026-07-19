class Solution {
public:
    bool check(string s,string t,int m){
        //calculating prefix sum
        vector<int> p_t(m,0); //prefix of t
        vector<int> p_s(m,0);
        int t_cnt =0,s_cnt =0;
        for(int i=0;i<m;i++){
            if(s[i]=='1'){
                s_cnt++;
                p_s[i] = s_cnt;
            }
            if(s[i]=='0') p_s[i] = s_cnt;
            if(t[i]=='1'){
                t_cnt++;
                p_t[i] = t_cnt;
            }
            if(t[i]=='0') p_t[i] = t_cnt;
            if(p_s[i] < p_t[i]) return false;
        }
        return true;
    }
    int count(string t,char c,int m){
        int cnt = 0;
        for(int i=0;i<m;i++){
            if(t[i]==c) cnt++;
        }
        return cnt;
    }
    vector<bool> transformStr(string s, vector<string>& strs) {
        int m = s.size();
        int n = strs.size();
        int one_s =0,zero_s=0;
        for(int i=0;i<m;i++){
            if(s[i]=='1') one_s++;
            else zero_s++;
        }
        vector<bool> ans;
        for(int i=0;i<n;i++){
            string t = strs[i];
            int one_t = count(t,'1',m);
            int zero_t = count(t,'0',m);
            int diff_one = one_s - one_t;
            int diff_zero = zero_s - zero_t;
            for(int j=0;j<m;j++){
                if(t[j]=='?'){
                    if(diff_zero){
                        t[j] = '0';
                        diff_zero--;
                    } 
                    else{
                        t[j] = '1';
                        diff_one--;
                    } 
                }
            }
            //case when we dont have equal 1s
            one_t = count(t,'1',m);
            if(one_t != one_s) ans.push_back(false);
            else if(check(s,t,m)) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};