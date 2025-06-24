class Solution {
private : 
    vector<int> find_nse(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>= arr[i]) st.pop();
            if(st.empty()) nse[i] = n; 
            else nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> find_pse(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]> arr[i]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0,mod = 1e9+7;
        vector<int> nge = find_nse(arr);
        vector<int> pse = find_pse(arr);
        for(int i=0;i<arr.size();i++){
            int next_index = nge[i];
            int prev_index = pse[i];
            sum = (sum + (1LL*(next_index-i)%mod*(i-prev_index)%mod*arr[i])%mod)%mod;
        }
        return sum;
    }
};
