class Solution {
public:
    double myPow(double x, int n) {
        double product = 1;
        long long absN = n;
        if(n<0) absN = -(long long)n;
        while(absN>0){
            if(absN%2==0){
                x*=x;
                absN/=2;
            }else{
                product*=x;
                absN--;
            }
        }
        if(n<0) product=1/product;
        return product;
    }
};