class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size(),ans=0;
        auto check=[&](int start,int dir){
            vector<int>a=nums;
            int i=start,d=dir;
            while(i>=0&&i<n){
                if(a[i]==0)i+=d;
                else{a[i]--;d=-d;i+=d;}
            }
            for(int x:a)if(x!=0)return false;
            return true;
        };
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(check(i,1))ans++;
                if(check(i,-1))ans++;
            }
        }
        return ans;
    }
};
