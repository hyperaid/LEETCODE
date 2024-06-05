class Solution {
    void cosection(string word, vector<int>& freq) {
        int freqWord[26] = {0};
        for(auto &it : word)
            ++freqWord[it - 'a'];
        for(int i = 0; i < 26; ++i) 
            freq[i] = min(freq[i], freqWord[i]);
    }

public:
    vector<string> commonChars(vector<string>& words) {
        ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
        vector<int> freq(26, 100);
        for(auto &word : words) {
            cosection(word, freq);
        }
        words.clear();
        for(int i = 0; i < 26; ++i) {
            while(freq[i]--) {
                words.push_back(string(1, 'a' + i));
            }
        }
        return words;
    }
};