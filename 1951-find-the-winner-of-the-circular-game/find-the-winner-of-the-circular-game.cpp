class Solution {
public:
    // int func(int n, int k){
    //     if(n==0) return 0;
    //     return (func(n-1,k)+k)%n;
    // }
    // int findTheWinner(int n, int k) {
    //     return func(n,k)+1; //1 based indexing
    // }
    int findTheWinner(int n, int k) {
        vector<int>players;
        for(int i=1; i<=n; i++){
            players.push_back(i);
        }
        int startInd = 0;
        while(players.size()>1){
            int removeInd = (startInd+k-1)%players.size();
            players.erase(players.begin()+removeInd);
            startInd = removeInd; // since the previous index is deleted, remove index automatically takes next place
        }
        return players[0];
    }
};
