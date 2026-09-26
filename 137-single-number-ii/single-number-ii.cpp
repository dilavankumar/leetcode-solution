class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        for(auto it:mp){
            int val=it.first;
            int freq=it.second;
            if(freq==1){
                return val;
            }

        }
        return -1;
        
    }
};