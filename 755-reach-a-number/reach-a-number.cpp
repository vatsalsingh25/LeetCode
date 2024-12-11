class Solution {
public:
    int reachNumber(int target) {
        int step = 0;
        int sum = 0;
        target = abs(target);
        while(sum<target){
            sum+=step;
            step++;
        }
        while((sum-target)%2==1){
            sum+=step;
            step++;
        }
        return step-1;
    }
};