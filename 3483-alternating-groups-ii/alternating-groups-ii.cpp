class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        colors.insert(colors.end(), colors.begin(), colors.end());
        int count = 0;

        int l=0, r=1;
        while(r<n+k-1){
            if(colors[r]==colors[r-1]){
                l=r;
                r=l+1;
                continue;
            }
            r++;

            if(r-l<k) continue;

            count++;
            l++;
        }
        return count;

    }
};