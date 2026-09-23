class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        vector<pair<int,char>>v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }

        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.first>b.first;
        });

        string ans="";
        for(auto it:v){
            ans+=string(it.first,it.second);
        }

        return ans;

        
    }
};