class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> words;
        int j = 0;
        
        // split text into words
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                words.push_back(text.substr(j, i - j));
                j = i + 1;
            }
        }
        words.push_back(text.substr(j)); // add last word

        int count = 0;
        for (auto &w : words) {
            bool canType = true;
            for (int k = 0; k < brokenLetters.size(); k++) {
                if (w.find(brokenLetters[k]) != string::npos) {
                    canType = false;
                    break;
                }
            }
            if (canType) count++;
        }
        return count;

    }
};