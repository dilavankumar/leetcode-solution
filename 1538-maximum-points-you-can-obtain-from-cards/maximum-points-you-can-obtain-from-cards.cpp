class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        int r=n-1;
        int sum=0;
        for(int l=0;l<k;l++){
            sum+=nums[l];
        }
        int ans=sum;
        for(int l=k-1;l>=0;l--){
            sum-=nums[l];
            sum+=nums[r];
            r--;
            ans=max(ans,sum);
        }
        return ans;
        
    }
};