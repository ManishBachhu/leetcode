class Trie {
    bool isEndOfWord = false;
    vector<Trie*> nodes;
public:
    Trie() {
        nodes = vector<Trie*>(26, nullptr);
    }
    
    void insert(string word) {
        Trie* ptr = this;
        for(auto ch: word) {
            if(ptr->nodes[ch -'a'] == nullptr) {
                Trie* node = new Trie();
                ptr->nodes[ch - 'a'] = node;
                ptr = node;
            }
            else 
                ptr = ptr->nodes[ch -'a'];
        }
        ptr->isEndOfWord = true;
    }
    
    bool search(string word) {
        Trie* ptr = this;
        for(auto ch: word) {
            if(ptr->nodes[ch -'a'] == nullptr)
                return false;

            ptr = ptr->nodes[ch -'a'];
        }
        return ptr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        Trie* ptr = this;
        for(auto ch: prefix) {
            if(ptr->nodes[ch -'a'] == nullptr)
                return false;

            ptr = ptr->nodes[ch -'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
