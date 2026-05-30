class Solution {
public:
    int passwordStrength(string password) {
        unordered_map<char,int> mpp;
        int ans = 0;
        for(int i=0;i<password.size();i++){
            mpp[password[i]]++;
        }
        for(auto it : mpp){
            if(it.first >= 'a' && it.first <= 'z') ans += 1;
            if(it.first >= 'A' && it.first <= 'Z') ans += 2;
            if(it.first >= '0' && it.first <= '9') ans += 3;
            if(it.first == '!' || it.first == '@' || it.first == '#' || it.first == '$') ans += 5;
        }
        return ans;
    }
};