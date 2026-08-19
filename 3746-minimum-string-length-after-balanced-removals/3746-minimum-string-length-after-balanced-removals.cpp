class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int cnt_a = 0;
        int cnt_b = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a') cnt_a++;
            else cnt_b++;
        }
        return abs(cnt_a-cnt_b);
    }
};