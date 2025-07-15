class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        string vowels = "aeiouAEIOU";
        if(n < 3) return false;
        bool vowel = false,consonant = false,specialChar = false;
        for(int i=0;i<n;i++){
            if(!isalnum(word[i])) return false;
            else if(vowels.find(word[i])!= string::npos) vowel = true;
            else if(isalpha(word[i])) consonant = true;
            else if(isalnum(word[i])) continue;
        } 
        return vowel && consonant;
    }
};