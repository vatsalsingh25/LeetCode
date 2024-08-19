class Solution {
public:
    int addDigits(int num) {
        int sum = INT_MAX;
        while(sum>9){
            sum=0;
            while(num>0){
                int digit = num%10;
                num/=10;
                sum+=digit;
            }
            num=sum;
        }
        return sum;
    }
};