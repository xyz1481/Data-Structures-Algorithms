class Solution {
public:
    int cal(int r,int c){
        return (abs(r)+abs(c));
    }
    int maxDistance(string moves) {
        int n = moves.size();
        int r=0,c=0;
        int count = 0;
        for(int i=0;i<n;i++){
            if(moves[i] == 'U') c++;
            else if(moves[i] == 'D') c--;
            else if(moves[i] == 'L') r--;
            else if(moves[i] == 'R') r++;
            else if(moves[i] == '_') count++;
        }
        return cal(r,c) + count;
    }
};