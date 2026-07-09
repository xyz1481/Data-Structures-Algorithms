class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        int n = occupiedIntervals.size();
        vector<vector<int>> ans1,ans2;
        for(int i=0;i<n;i++){
            if(ans1.empty() || ans1.back()[1]+1 < occupiedIntervals[i][0]){
                ans1.push_back(occupiedIntervals[i]);
            }else{
                ans1.back()[1] = max(ans1.back()[1],occupiedIntervals[i][1]);
            }
        }
          for(auto &it : ans1){
            if(it[1] < freeStart) ans2.push_back(it);
            if(it[0]==freeStart && it[1]==freeEnd) continue;
            if(it[0] < freeStart && it[1] >= freeStart) ans2.push_back({it[0],freeStart-1});
            if(it[0] >= freeStart && it[1] <= freeEnd) continue;
            if(it[0] <= freeEnd && it[1] > freeEnd) ans2.push_back({freeEnd+1,it[1]});
            if(it[0] > freeEnd) ans2.push_back(it);
        }
        return ans2;
    }
};