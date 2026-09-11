class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int maxLen=0;
        int zero=0;

        while(r<nums.size()){
            if(nums[r]==0){
                zero++;
            }
            if(zero>k){
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
            if(zero<=k){
                int len=r-l+1;
                maxLen=max(maxLen,len);
            }
            r++;
        }
        return maxLen;
        
    }
};