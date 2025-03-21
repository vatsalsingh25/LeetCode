class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string>ans;
        unordered_set<string>st;
        for(int i=0; i<supplies.size(); i++){
            st.insert(supplies[i]);
        }
        vector<int>vis(recipes.size(),0);
        
        int n = recipes.size();
        while(n--){
            for(int i=0; i<ingredients.size(); i++){
                if(!vis[i]){
                    bool flag = true;
                    for(auto it: ingredients[i]){
                        if(st.find(it)==st.end()){
                            flag = false;
                        }
                    }
                    if(flag){
                        ans.push_back(recipes[i]);
                        st.insert(recipes[i]);
                        vis[i]=1;
                    }
                }
            }
        }

        return ans;
    }
};