class Solution {
public:
    int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>>pq;

        long long sum = 0;
        long long ans = 0;
        for(auto &[e,s]:v){
            sum += s;
            pq.push(s);

            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }

            ans = max(ans,1LL*sum*e);
        }
        return ans%MOD;
    }
    
};


//https://chatgpt.com/share/6a893462-ff70-83ee-aa9d-7cd1deac40b3
//check the 2nd query ^
//I was trying to do pick = cost + f(i+1..) but this is wrong i the sum is not additive 
//we dont want to add like at each step we calculate the ans in the end 
// current_performance + future_performance
// But performance is (total speed) × (minimum efficiency), so future engineers can change the multiplier of the entire accumulated speed. Therefore, you must carry the state (sum, min efficiency) and evaluate the final combination, not add intermediate performances.
// class Solution {
// public:
//     int f(int i,int s,int e,int n, vector<int>& speed, vector<int>& efficiency, int k){
//         if(i>=n || k<=0) return 0;
//         int n_e = min(e,efficiency[i]);
//         int pick = (s+speed[i] * e_n)+f(i+1,s+speed[i],n_e,n,speed,efficiency,k-1);
//         int not_pick = f(i+1,s,e,n,speed,efficiency,k);
//         return max(pick,not_pick);
//     }
//     int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
//         return f(0,0,INT_MAX,n,speed,efficiency,k);
//     }
// };
// class Solution {
// public:
//     int f(int i,int s,int e,int n, vector<int>& speed, vector<int>& efficiency, int k){
//         if(i>=n || k<=0) return s*e;
//         int n_e = min(e,efficiency[i]);
//         int pick =f(i+1,s+speed[i],n_e,n,speed,efficiency,k-1);
//         int not_pick = f(i+1,s,e,n,speed,efficiency,k);
//         return max(pick,not_pick);
//     }
//     int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
//         return f(0,0,INT_MAX,n,speed,efficiency,k);
//     }
// };