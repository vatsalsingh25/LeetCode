class Solution {
public:
    bool isPrime(int num){
        if(num==1) return false;
        for(int i=2; i<=sqrt(num); i++){
            if(num%i==0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        int prev = -1;
        int a = -1;
        int b = -1;
        int minDiff = INT_MAX;

        for(int i=left; i<=right; i++){
            if(isPrime(i)){
                if(prev!=-1){
                    int diff = i-prev;
                    if(diff<minDiff){
                        minDiff = diff;
                        a = prev;
                        b = i;
                    }
                    if(diff<=2) return {a,b};
                }
                prev = i;
            } 
            
        }

        return {a,b};
    }
};