class Solution {
public:
    // Helper function to check if a word satisfies the universal condition
    bool isUniversal(const string& a, const unordered_map<char, int>& mppW2) {
        unordered_map<char, int> wordFreq;
        for (char ch : a) {
            wordFreq[ch]++;
        }
        for (const auto& [ch, freq] : mppW2) {
            if (wordFreq[ch] < freq) {
                return false;
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> mppW2;

        // Build the maximum frequency map for words2
        for (const string& word : words2) {
            unordered_map<char, int> temp;
            for (char ch : word) {
                temp[ch]++;
            }
            for (const auto& [ch, freq] : temp) {
                mppW2[ch] = max(freq, mppW2[ch]);
            }
        }

        vector<string> ans;
        // Check each word in words1
        for (const string& word : words1) {
            if (isUniversal(word, mppW2)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
