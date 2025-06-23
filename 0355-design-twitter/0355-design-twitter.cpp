class Twitter {
private:
    unordered_map<int,set<int>> following; // keeps a track of following <userId,{no. of people he follows}>
    unordered_map<int,vector<pair<int,int>>> posts; // keeps track of time,post <userId,{<postId,time>,<postId,time>}>
    long long time =0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto it : posts[userId]) pq.push({it.first,it.second}); //push all the tweets by the user
        for(auto it1 : following[userId]){ //it1 itself is a vector (list of followers)
            for(auto it2 : posts[it1]) pq.push({it2.first,it2.second});//push all the tweets made by that followed person
        }
        vector<int>ans;
        while(!pq.empty() && ans.size()<10){
           ans.push_back(pq.top().second);
           pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId); //add the new one
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId); //remove from list of followers
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

 // 1 -> 6,7
 // 2 -> 9,10
 // 1 follows 2 
 // when we retrive posts for 1 we should be able to see 6,7,9,10 bcs he follows 2
 // 1 unfollows 2
 // when we retrive feed of 1 we should get only 6,7



//  class Twitter {
// private:
//     unordered_map<int,vector<int>> following; // keeps a track of following <userId,{no. of people he follows}>
//     unordered_map<int,vector<pair<int,int>>> posts; // keeps track of time,post <userId,{<postId,time>,<postId,time>}>
//     long long time =0;
// public:
//     Twitter() {
        
//     }
    
//     void postTweet(int userId, int tweetId) {
//         posts[userId].push_back({time,tweetId});
//         time++;
//     }
    
//     vector<int> getNewsFeed(int userId) {
//         priority_queue<pair<int,int>> pq;
//         for(auto it : posts[userId]) pq.push({it.first,it.second}); //push all the tweets by the user
//         for(auto it1 : following[userId]){ //it1 itself is a vector (list of followers)
//             for(auto it2 : posts[it1]) pq.push({it2.first,it2.second});//push all the tweets made by that followed person
//         }
//         vector<int>ans;
//         while(!pq.empty() && ans.size()<10){
//            ans.push_back(pq.top().second);
//            pq.pop();
//         }
//         return ans;
//     }
    
//     void follow(int followerId, int followeeId) {
//         following[followerId].push_back(followeeId); //add the new one
//     }
    
//     void unfollow(int followerId, int followeeId) {
//          auto &vec = following[followerId];
//         vec.erase(remove(vec.begin(), vec.end(), followeeId), vec.end()); //remove from list of followers
//     }
// };
//This code wont work for a testcase where a user follows multiple times the same person
//dry run on this tc
//["Twitter","postTweet","follow","follow","getNewsFeed"]
//[[],[2,5],[1,2],[1,2],[1]]
//Expected : [null,null,null,null,[5]]
//my output  : [null,null,null,null,[5,5]] clearly we dont need to add same follower twice;
//using set instead
