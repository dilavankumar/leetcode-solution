class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> sorted=arr;
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int>mp;
        int r=1;
        for(int num:sorted){
            if(mp.find(num)==mp.end()){
                mp[num]=r++;
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};