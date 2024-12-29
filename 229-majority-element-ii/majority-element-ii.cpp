class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int ele1=INT_MIN, ele2=INT_MIN;
        int count1=0, count2=0;
        for(int i=0; i<n; i++){
            if(count1==0 && nums[i]!=ele2){                    // && nums[i]!=ele2 so that the ele1 and ele2 does not become s
                ele1=nums[i];
                count1++;
            }
            else if(count2==0 && nums[i]!=ele1){
                ele2=nums[i];
                count2++;
            }

            else if(nums[i]==ele1) count1++;
            else if(nums[i]==ele2) count2++;

            else count1--, count2--;
        }

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele1) cnt1++;
            if (nums[i] == ele2) cnt2++;
        }
        int mini = (n / 3) + 1;
        if (cnt1 >= mini) ans.push_back(ele1);
        if (cnt2 >= mini) ans.push_back(ele2);
        return ans;
    }

};