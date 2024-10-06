class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split both sentences into words
        vector<string> v1, v2;
        stringstream s1(sentence1), s2(sentence2);
        string word;

        while (s1 >> word) v1.push_back(word);
        while (s2 >> word) v2.push_back(word);

        int i = 0, j = 0;
        int n1 = v1.size(), n2 = v2.size();
        
        // Start from the beginning and check for matching words
        while (i < n1 && i < n2 && v1[i] == v2[i]) i++;

        // Start from the end and check for matching words
        while (j < n1 - i && j < n2 - i && v1[n1 - j - 1] == v2[n2 - j - 1]) j++;

        // If i + j covers all the words in the shorter sentence, they are similar
        return i + j >= min(n1, n2);
    }
};
