class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q;
        unordered_set<string> dead(deadends.begin(),deadends.end());
        unordered_set<string> vis;
        if(dead.count("0000")) return -1;
        q.push({"0000",0});
        while(!q.empty()){
            string cur = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(cur==target) return steps;
            for(int i=0;i<4;i++){
                string up = cur;
                string down = cur;
                up[i] = (cur[i]=='9') ? '0' : cur[i]+1;
                down[i] = (cur[i]=='0') ? '9' : cur[i]-1;

                for(auto &it : {up,down}){
                    if(!dead.count(it) && !vis.count(it)){
                        vis.insert(it);
                        q.push({it,steps+1});
                    }
                }
            }
        }
        return -1;
    }
};