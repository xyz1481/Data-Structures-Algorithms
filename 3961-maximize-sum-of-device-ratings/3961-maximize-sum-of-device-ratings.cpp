class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units[0].size();
        int m = units.size();
        long long ans = 0;
        if(n==1){
            for(auto it : units){
                ans += it[0];
            }
            return ans;
        }
        long long min_of_1st_min = LLONG_MAX;
        long long sum_of_all_2nd_min = 0;
        //find all the 2nd mins and 1st mins
        vector<pair<long long,long long>> v(m,{LLONG_MAX,LLONG_MAX});
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i].first > units[i][j]){
                    v[i].second = v[i].first;
                    v[i].first = units[i][j];
                }else if(v[i].second > units[i][j]){
                    v[i].second = units[i][j];
                }
            }
            min_of_1st_min = min(min_of_1st_min,v[i].first);
        }
        long long min_of_2nd_min = INT_MAX;
        for(auto it :v){
            min_of_2nd_min = min(min_of_2nd_min,it.second);
            sum_of_all_2nd_min += it.second;
        }
        long long answer = sum_of_all_2nd_min + min_of_1st_min - min_of_2nd_min;
        return answer;
    }
};


//ye sab bakwas hai i had to see the sol at the end
// i have to remove 1 unit and give it to another one
// i can give my max or min 
// if i give min then my next min might increase my capacity but might decrease someones capacity as well if its shorter
// if i give max then it might be wasteful for someone bcz his min is still smaller than my max
// receiver capacity = min(received_capacity,min_capacity of this device)
// sender capacity = next min sender device

//[45,46][2,5]
//[1,3][2,2]
// 1 , 2
// let every device donate his mean and check for the capacity gain
// the device with min capacity gain can be dumped with the donations or min 
// get all the second mins
// get all the first mins
// 1st mins ke min mai dump all the 1st mins