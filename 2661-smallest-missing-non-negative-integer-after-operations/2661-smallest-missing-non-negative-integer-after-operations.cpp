class Solution{
public:
    int findSmallestInteger(vector<int>& nums, int value){
        unordered_map<int,int> freq;
        for(int x: nums){
            int mod = ((x % value) + value) % value;
            freq[mod]++;
        }
        int mex = 0;
        while(true){
            int mod = mex % value;
            if(freq[mod] > 0){
                freq[mod]--;
                mex++;
            }else break;
        }
        return mex;
    }
};
