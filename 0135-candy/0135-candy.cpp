class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(),sum;
        vector<int> left(n);
        left[0] = 1;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i] > ratings[i-1]) left[i] = left[i-1]+1;
            else left[i] = 1; 
        }
        sum = left[n-1];
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]) left[i] = max(left[i],left[i+1]+1);
            else left[i] = max(left[i],1);
            sum += left[i]; 
        }

        return sum;
    }
};

// 1 3 4 5 2
// 1 2 3 4 1
// 1 1 1 2 1