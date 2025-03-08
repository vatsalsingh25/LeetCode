class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        for(int i=0; i<k; i++){
            if(blocks[i]=='W') count++;
        }
        int mini = count;
        int l=0; 
        int r=k;
        while(r<blocks.size()){
            if(blocks[r]=='W') count++;
            if(blocks[l]=='W') count--;
            r++;
            l++;
            mini = min(mini,count);
        }
        return mini;
    }
};