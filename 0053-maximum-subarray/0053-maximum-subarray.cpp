class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int curr=nums[0],maxSum=nums[0];
        for(int i=1;i<nums.size();i++){
            curr=max(nums[i],curr+nums[i]);
            maxSum=max(maxSum,curr);
        }
        return maxSum;
    }
};
