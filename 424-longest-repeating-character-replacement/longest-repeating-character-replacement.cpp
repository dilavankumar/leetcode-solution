class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0;
        int maxLen=0;
        int maxFre=0;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            maxFre=max(maxFre,mp[s[r]]);
            if((r-l+1)-(maxFre)>k){
                mp[s[l]]--;
                l++;
            }
            if((r-l+1)-(maxFre)<=k){
                int len=r-l+1;
                maxLen=max(maxLen,len);
            }
            r++;
        }
        return maxLen;
    }
};