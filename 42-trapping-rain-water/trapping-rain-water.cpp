class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>preMax(n);
        int preMaxi = 0;
        for(int i=0; i<n; i++){
            if(height[i]>preMaxi) preMaxi = height[i];
            preMax[i] = preMaxi;
        }
        vector<int>postMax(n);
        int postMaxi = 0;
        for(int i=n-1; i>=0; i--){
            if(height[i]>postMaxi) postMaxi = height[i];
            postMax[i] = postMaxi;
        }
        
        int water = 0;
        for(int i=0; i<n; i++){
            water += (min(preMax[i], postMax[i])-height[i]);
        }
        return water;
    }
};