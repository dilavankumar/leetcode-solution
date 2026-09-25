class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>start;
        vector<int>end;
        for(auto interval:intervals){
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int n=intervals.size();
        int i=0;
        int j=0;
        int count=0;
        int maxCount=0;
        while(i<n && j<n){
            if(start[i]<=end[j]){
                count++;
                maxCount=max(maxCount,count);
                i++;
            }
            else{
                count--;
                j++;
            }
            
        }
        return maxCount;
        
    }
};