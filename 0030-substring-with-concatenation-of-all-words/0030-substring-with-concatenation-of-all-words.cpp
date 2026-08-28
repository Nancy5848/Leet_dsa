class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen)
            return ans;

        // Frequency of words required
        unordered_map<string, int> required;

        for (string word : words) {
            required[word]++;
        }

        // Try every possible starting offset
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int right = offset;
            int count = 0;

            unordered_map<string, int> current;

            while (right + wordLen <= s.size()) {

                // Extract word of wordLen characters
                string word = s.substr(right, wordLen);
                right += wordLen;

                // If word is not required, reset window
                if (required.find(word) == required.end()) {
                    current.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                // Add word to current window
                current[word]++;
                count++;

                // If word occurs too many times, remove from left
                while (current[word] > required[word]) {
                    string leftWord = s.substr(left, wordLen);
                    current[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // If all words are present
                if (count == wordCount) {
                    ans.push_back(left);

                    // Move left forward to search for next window
                    string leftWord = s.substr(left, wordLen);
                    current[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};