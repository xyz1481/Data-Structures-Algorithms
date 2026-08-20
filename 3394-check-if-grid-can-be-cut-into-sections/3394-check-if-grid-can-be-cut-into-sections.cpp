class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> vertical;
        for(auto it : rectangles){
            vertical.push_back({it[0],it[2]});
        }
        sort(vertical.begin(),vertical.end());
        //merge intervals
        vector<vector<int>> v_pos; 
        for(auto it : vertical){
            if(v_pos.empty() || v_pos.back()[1] <= it[0]) v_pos.push_back(it);
            else{
                v_pos.back()[1] = max(v_pos.back()[1],it[1]);
            }
        }
        if(v_pos.size()>=3) return true;

        vector<vector<int>> horizontal;
        for(auto it : rectangles){
            horizontal.push_back({it[1],it[3]});
        }
        sort(horizontal.begin(),horizontal.end());
        vector<vector<int>> h_pos;
        for(auto it : horizontal){
            if(h_pos.empty() || h_pos.back()[1] <= it[0]) h_pos.push_back(it);
            else{
                h_pos.back()[1] = max(h_pos.back()[1],it[1]);
            }
        }
        if(h_pos.size()>=3) return true;

        return false;
        
    }
};


// brute force
// class Solution {
// public:
//     bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
//         //for vetical
//         unordered_set<int> vertical;
//         for(auto it : rectangles){
//             int s_row = it[0];
//             int e_row = it[2];
//             if(s_row != 0) vertical.insert(s_row);
//             if(e_row != n) vertical.insert(e_row); 
//         }
//         int i = 0;
//         vector<int> ans;
//         for(auto cut : vertical){
//             for(i=0;i<rectangles.size();i++){
//                 if(rectangles[i][0] < cut && rectangles[i][2] > cut) break;
//             }
//             if(i==rectangles.size()){
//                 ans.push_back(cut);
//             } 
//             if(ans.size()==2) return true;
//         }

//         //for horizontal
//         vector<int> res;
//         unordered_set<int> horizontal;
//         for(auto it : rectangles){
//             int s_col = it[1];
//             int e_col = it[3];
//             if(s_col != 0) horizontal.insert(s_col);
//             if(e_col != n) horizontal.insert(e_col); 
//         }
//         for(auto cut : horizontal){
//             for(i=0;i<rectangles.size();i++){
//                 if(rectangles[i][1] < cut && rectangles[i][3] > cut) break;
//             }
//             if(i==rectangles.size()){
//                 res.push_back(cut);
//             } 
//             if(res.size()==2) return true;
//         }

//         return false;
//     }
// };