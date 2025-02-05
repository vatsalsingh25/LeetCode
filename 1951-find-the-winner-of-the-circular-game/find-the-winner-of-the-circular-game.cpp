class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> players(n, 0); // 0 means player is still in the game
        int count = 0; // Number of eliminated players
        int index = 0; // Start from the first player
        
        while (count < n - 1) { // Stop when only one player remains
            int steps = k; 
            while (steps > 0) {
                if (players[index] == 0) { // Only count active players
                    steps--;
                }
                if (steps > 0) index = (index + 1) % n; // Move to the next player
            }
            players[index] = 1; // Eliminate the player
            count++;
            // Move to the next available player
            while (players[index] == 1) {
                index = (index + 1) % n;
            }
        }
        
        return index + 1; // Return 1-based index of the winner
    }
};
