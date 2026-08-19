class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix_n(n+1,0);
        vector<int> prefix_y(n+1,0);

        for(int i=1;i<=n;i++){
            if(customers[i-1]=='Y'){
                prefix_y[i] = prefix_y[i-1] + 1;
                prefix_n[i] = prefix_n[i-1];
            }else{
                prefix_n[i] = prefix_n[i-1] + 1;
                prefix_y[i] = prefix_y[i-1];
            }
        }

        int ans = -1;
        int min_penalty = INT_MAX;
        for(int i=0;i<=n;i++){
            int left = prefix_n[i];
            int right = prefix_y[n] - prefix_y[i];
            if(min_penalty > left+right){
                ans = i;
                min_penalty = left+right;
            }
        }

        return ans;

    }
};




// class Solution {
// public:
//     int bestClosingTime(string customers) {
//         int n = customers.size();
//         int min_penalty = INT_MAX;
//         int ans = -1;
//         for(int i=0;i<=n;i++){
//             int penalty=0;
//             for(int j=0;j<i;j++){
//                 if(customers[j]=='N') penalty++;
//             }
//             for(int k=i;k<n;k++){
//                 if(customers[k]=='Y') penalty++;
//             }
//             if(min_penalty > penalty){
//                 min_penalty = penalty;
//                 ans = i;
//             }
//         }
//         return ans;
//     }
// };


