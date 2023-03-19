class WordDictionary {
public:
    struct trie{
      trie* child[26]={NULL};
        bool terminal = false;
    };
    trie* root;
    WordDictionary() {
        root = new trie;
    }
    
    void addWord(string word) {
        trie* p = root;
        for(char c:word)
        {
            if(p->child[c-'a'] == NULL)
                p->child[c-'a'] = new trie;
            p = p->child[c-'a'];
        }
        p->terminal = true;
    }
    
    bool search(string word) {
        return searchutil(root,word,0);
    }
    bool searchutil(trie* root, string word, int pos)
    {
        if(root == NULL)
            return false;
        if(pos == word.length())
            return root->terminal;
        if(word[pos] == '.')
        {
            for(int i = 0;i<26;i++)
            {
                if(searchutil(root->child[i],word,pos+1))
                    return true;
            }
        }
        else if(root->child[word[pos]-'a'] == NULL)
            return false;
        else
            return searchutil(root->child[word[pos]-'a'],word,pos+1);
        return false;
    }
};