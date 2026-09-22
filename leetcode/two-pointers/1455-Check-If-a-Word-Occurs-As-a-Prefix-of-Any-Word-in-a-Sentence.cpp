class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream s(sentence);
        string word;
        int count = 1;
        while(s >> word) {
            if(word.rfind(searchWord, 0) == 0) return count;
            count++;
        }
        return -1;
    }
};