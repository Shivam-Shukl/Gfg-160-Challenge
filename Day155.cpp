// User function template for C++
class Trie {
  public:
    
    Trie* children[26];
    bool isLeaf;
    
    Trie() {
        // implement Trie
        isLeaf = false;
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
    }
    void ins(Trie* curr, string &key){
       
        for(char c : key){
            if(curr -> children[c - 'a'] == nullptr){
                Trie* newNode = new Trie();
                curr -> children[c-'a'] = newNode;
            }
            curr = curr -> children[c-'a'];
        }
        curr -> isLeaf = true;
        
    }
    void insert(string &word) {
        // insert word into Trie
        ins(this,word);
    }
    
    bool sea(Trie* curr, string &key){
        
        for(char c: key){
            if(curr -> children[c-'a'] == nullptr){
                return false;
            }
            curr = curr -> children[c - 'a'];
        }
        return curr -> isLeaf;
    }
    bool search(string &word) {
        // search word in the Trie
        return sea(this,word);
    }
    
    bool isPre(Trie* curr, string &key){
        
        for(char c: key){
            if(curr -> children[c-'a'] == nullptr){
                return false;
            }
            curr = curr -> children[c - 'a'];
        }
        return true;
    }
    bool isPrefix(string &word) {
        // search prefix word in the Trie
        return isPre(this, word);
    }
};
