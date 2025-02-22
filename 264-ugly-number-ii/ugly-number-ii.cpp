class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long>uglyNums;
        uglyNums.insert(1);
        long long first = 1;
        for(int i=0; i<n; i++){
            first = *uglyNums.begin();
            uglyNums.insert(first*2);
            uglyNums.insert(first*3);
            uglyNums.insert(first*5);
            uglyNums.erase(uglyNums.begin());
        }
        return first;
    }
};