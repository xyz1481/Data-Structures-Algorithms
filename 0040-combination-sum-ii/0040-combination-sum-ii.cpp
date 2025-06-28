class Solution {
private:
     void f(int index,vector<int> &candidates,int n,int target,vector<vector<int>> &ans,vector<int>&sub){
            if(target == 0){
                ans.push_back(sub);
                return;
            }
            for(int i = index;i<n;i++){
                if(i > index && candidates[i]==candidates[i-1]) continue;
                if(candidates[i] > target) break;
                sub.push_back(candidates[i]);
                f(i+1,candidates,n,target-candidates[i],ans,sub);
                sub.pop_back();
            }
     }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        f(0,candidates,n,target,ans,sub);
        return ans;
    }
};

    //this code just works for unique nos but i learnt a good thing read comments
    // void f(int index,vector<int> &candidates,int n,int sum,int target,set<vector<int>> &ans,vector<int>&sub){
    //     if(sum == target){
    //         ans.insert(sub);
    //         return;
    //     }
    //     if(index==n || sum > target) return; //isko niche hi rakho below your target condition 
    //     //or else whenever we hit index==n it will return and we wont be able to push back our ans 
    //     //pick
    //     sub.push_back(candidates[index]);
    //     f(index+1,candidates,n,sum+candidates[index],target,ans,sub);
    //     sub.pop_back();
    
    //     //not pick
    //     f(index+1,candidates,n,sum,target,ans,sub);
    // }