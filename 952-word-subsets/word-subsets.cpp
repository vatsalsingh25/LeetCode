class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> globalFreq;

        // Step 1: Build the global frequency map for words2
        for (const string& word : words2) {
            unordered_map<char, int> wordFreq;
            for (char ch : word) {
                wordFreq[ch]++;
            }
            for (const auto& [ch, freq] : wordFreq) {
                globalFreq[ch] = max(globalFreq[ch], freq);
            }
        }

        vector<string> result;

        // Step 2: Check each word in words1
        for (const string& word : words1) {
            unordered_map<char, int> wordFreq;
            for (char ch : word) {
                wordFreq[ch]++;
            }

            bool isUniversal = true;
            for (const auto& [ch, freq] : globalFreq) {
                if (wordFreq[ch] < freq) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                result.push_back(word);
            }
        }

        return result;
    }
};
