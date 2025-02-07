class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        unordered_map<int, int> colorCount;
        unordered_map<int,int>colorOfBall;

        vector<int>ans; //stores distinct colours in each step;
        for(int i=0; i<queries.size(); i++){
            int num = queries[i][0];
            int color = queries[i][1];

            if(colorOfBall.find(num)==colorOfBall.end()){                  // ball not coloured

            }
            else{                                                        //ball already present
                colorCount[colorOfBall[num]]--;
                if(colorCount[colorOfBall[num]]==0) colorCount.erase(colorOfBall[num]);

            }
            colorOfBall[num] = color;
            colorCount[color]++;

            ans.push_back(colorCount.size());
        }

        return ans;
    }
};