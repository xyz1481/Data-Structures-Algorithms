class Solution {
public:
    long long MOD = 1e9+7;
    long long find_power(long long a,long long b){
        long long ans = 1;
        while(b > 0){
            if(b%2==1){
                ans = (ans*a)%MOD;
                b--;
            }else{
                b = b/2;
                a = (a*a)%MOD; 
            }
        }
        return ans;
    }
    void find(long long num,long long &w,long long &x,long long &y){
        int n=0;
        long long temp = num;
        while(temp > 0){
            n++;
            temp = temp/10;
        }
        long long l = 1;
        for(int i=0;i<n-w;i++) l = l*10;
        x = num/l;
        y = num%l;
    }
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long solution = 0;
        for(int i=0;i<n;i++){
            long long w = nums[i]%10;
            long long d = floor(nums[i]/10);
            long long ans_x = 0,ans_y = 0;
            find(d,w,ans_x,ans_y);
            solution = (solution + find_power(ans_x,ans_y))%MOD;
        }
        return solution;
    }
};