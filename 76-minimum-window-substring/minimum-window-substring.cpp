class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int l=0,r=0;
        int minLen=INT_MAX;
        int count=0;
        int sIndex=-1;
        unordered_map<char,int>mp;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        while(r<n){
            if(mp[s[r]]>0){
                count++;
                
            }
            mp[s[r]]--;
            while(count==m){
                int len=r-l+1;
                if(len<minLen){
                    minLen=len;
                    sIndex=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    count--;
                }
                l++;
                

            }
            r++;
        }
        return sIndex==-1?"":s.substr(sIndex,minLen);
        
    }
};