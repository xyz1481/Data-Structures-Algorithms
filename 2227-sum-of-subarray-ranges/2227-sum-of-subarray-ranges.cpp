class Solution {
private:
    vector<int> find_nse(vector<int> &nums,int n){
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> find_pse(vector<int> &nums,int n){
        stack<int> st;
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    long long min_sum(vector<int> &nums){
        long long sum =0,n = nums.size();
        vector<int> nse = find_nse(nums,n);
        vector<int> pse = find_pse(nums,n);
        for(int i=0;i<n;i++){
            sum += 1LL*(nse[i]-i)*(i-pse[i])*nums[i];
        }
        return sum;
    }
    vector<int> find_nge(vector<int> &nums,int n){
        stack<int> st;
        vector<int> nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<= nums[i]) st.pop();
            if(st.empty()) nge[i] = n;
            else nge[i] = st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> find_pge(vector<int> &nums,int n){
        stack<int> st;
        vector<int> pge(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]< nums[i]) st.pop();
            if(st.empty()) pge[i] = -1;
            else pge[i] = st.top();
            st.push(i);
        }
        return pge;
    }
    long long max_sum(vector<int> &nums){
        long long sum=0,n=nums.size();
        vector<int> nge = find_nge(nums,n);
        vector<int> pge = find_pge(nums,n);
        for(int i=0;i<n;i++){
            sum +=1LL*(nge[i]-i)*(i-pge[i])*nums[i];
        }
        return sum;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return max_sum(nums) - min_sum(nums);
    }
};

// 1 2 5 7 6 3 2 8 9 