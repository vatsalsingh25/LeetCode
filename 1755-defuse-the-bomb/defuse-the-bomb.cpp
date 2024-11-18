class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>arr = code;
        for(int i=0; i<n; i++){
            if(k>=0){
                int sum = 0;
                for(int j=0; j<k; j++){
                    sum+=arr[(i+1+j)%n];
                }
                code[i]=sum;
            }
            else{
                int sum = 0;
                for(int j=0; j<-k; j++){
                    sum+=arr[(i-1-j+n)%n]; // -1 % 5 = -1
                }
                code[i]=sum;
            }
        }
        
        return code;
    }
};