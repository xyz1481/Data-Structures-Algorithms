class Solution {
private:
    bool f(int last_jump,int index,vector<int> &nums,vector<vector<int>> &pos_map){
        if(index==nums.size()-1) return true;
        if(pos_map[index][last_jump] != -1) return pos_map[index][last_jump];
        for(int i = last_jump-1;i<last_jump+2;i++){
            if(i<=0) continue;
            //search if it exists    
            auto it = find(nums.begin()+index+1,nums.end(),nums[index]+i);
            if(it!=nums.end()){
            if(f(i,it-nums.begin(),nums,pos_map)==true) return pos_map[index][last_jump] = true;
            }
        }
        return pos_map[index][last_jump]=false;
    }
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]!= 1) return false;
        int n = stones.size();
        vector<vector<int>> pos_map(n,vector<int> (n+1,-1));
        return f(1,1,stones,pos_map);
    }
};
//usign memorization
// class Solution {
// private:
//     bool f(int last_jump,int index,vector<int> &nums,vector<vector<int>> &pos_map){
//         if(index==nums.size()-1) return true;
//         if(pos_map[index][last_jump] != -1) return pos_map[index][last_jump];
//         for(int i = last_jump-1;i<last_jump+2;i++){
//             if(i<=0) continue;
//             //search if it exists    
//             auto it = find(nums.begin()+index+1,nums.end(),nums[index]+i);
//             if(it!=nums.end()){
//             if(f(i,it-nums.begin(),nums,pos_map)==true) return pos_map[index][last_jump] = true;
//             }
//         }
//         return pos_map[index][last_jump]=false;
//     }
// public:
//     bool canCross(vector<int>& stones) {
//         int n = stones.size();
//         vector<vector<int>> pos_map(n,vector<int> (n+1,-1));
//         return f(1,1,stones,pos_map);
//     }
// };

//cal possible jumps for each index
//check if those jumps are possible 
//if possible make further recursion call
//else dont

// 0 1 3 5 6 8 12 17
// 1 2 3 4 5 6 7  8