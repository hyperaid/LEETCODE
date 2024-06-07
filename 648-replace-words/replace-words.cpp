class Solution {
public:
    vector<string> split(const string& str) {
        vector<string> words;
        string word;
        for (char c : str) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        return words;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<char, vector<string>> hashMap;

        for (const string& word : dictionary) {
            hashMap[word[0]].push_back(word);
        }

        for (auto& entry : hashMap) {
            sort(entry.second.begin(), entry.second.end(),
                 [](const string& a, const string& b) {
                     return a.size() < b.size();
                 });
        }

        vector<string> words = split(sentence);
        vector<string> resultWords;

        for (string& word : words) {
            char firstChar = word[0];
            bool replaced = false;

            if (hashMap.find(firstChar) != hashMap.end()) {
                for (const string& root : hashMap[firstChar]) {
                    if (word.substr(0, root.size()) == root) {
                        resultWords.push_back(root);
                        replaced = true;
                        break;
                    }
                }
            }

            if (!replaced) {
                resultWords.push_back(word);
            }
        }

        string result;
        for (size_t i = 0; i < resultWords.size(); ++i) {
            if (i > 0) {
                result += " ";
            }
            result += resultWords[i];
        }

        return result;
    }
};