class Solution{
public:
    int largestRectangleArea(vector<int>&h){
        stack<int>st;
        int n=h.size(),ans=0;
        for(int i=0;i<=n;i++){
            int cur=(i==n?0:h[i]);
            while(!st.empty()&&cur<h[st.top()]){
                int ht=h[st.top()]; st.pop();
                int w=st.empty()?i:i-st.top()-1;
                ans=max(ans,ht*w);
            }
            st.push(i);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>&matrix){
        if(matrix.empty()) return 0;
        int r=matrix.size(),c=matrix[0].size(),ans=0;
        vector<int>h(c,0);
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1') h[j]++;
                else h[j]=0;
            }
            ans=max(ans,largestRectangleArea(h));
        }
        return ans;
    }
};