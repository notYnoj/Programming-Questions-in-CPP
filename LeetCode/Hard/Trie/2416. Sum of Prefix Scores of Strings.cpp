struct Trie {
    int score;
    Trie *children[26];
    Trie () {
        score = 0;
        memset(children, 0, sizeof(children));
    }
    void add(string &s, int i) {
        if (i) score++;
        if (i == s.size()) return;
        if (!children[s[i]-'a']) children[s[i]-'a'] = new Trie();
        children[s[i]-'a']->add(s, i+1);
    }
    int dfs(string &s, int i) {
        if (i == s.size()) return score;
        return score + children[s[i]-'a']->dfs(s, i+1);
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *trie = new Trie();
        for (string &s : words) trie->add(s, 0);
        vector<int> res;
        for (string &s : words) res.push_back(trie->dfs(s, 0));
        return res;
    }
};
