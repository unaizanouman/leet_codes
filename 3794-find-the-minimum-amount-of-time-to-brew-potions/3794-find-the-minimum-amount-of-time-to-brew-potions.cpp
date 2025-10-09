class Solution{
public:
    long long minTime(vector<int>& skill, vector<int>& mana){
        int n=skill.size(),m=mana.size();
        long long s_prev=0;
        for(int j=1;j<m;j++){
            long long s_j=LLONG_MIN/4;
            long long sumPrev=0;
            long long sumCurrEx=0;
            for(int k=0;k<n;k++){
                sumPrev+=1LL*skill[k]*mana[j-1];
                if(k>=1) sumCurrEx+=1LL*skill[k-1]*mana[j];
                long long term=s_prev+sumPrev-sumCurrEx;
                if(term>s_j) s_j=term;
            }
            s_prev=s_j;
        }
        long long lastSum=0;
        for(int i=0;i<n;i++) lastSum+=1LL*skill[i]*mana[m-1];
        return s_prev+lastSum;
    }
};
