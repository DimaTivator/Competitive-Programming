struct Node {
    map <char, Node*> to;
    int en = 0;  // the number of words ending in this node 
    int cnt = 0; // the number of words containing this node
};

class Trie {
    private:
        Node* root;

    public:

        Trie() : root(new Node()) {}

        void insert(const string& s) {
            Node* cur = root;
            for (char c : s) {
                if (cur->to.find(c) == cur->to.end()) {
                    cur->to[c] = new Node();
                }
                cur = cur->to[c];
                cur->cnt++;
            }
            cur->en++;
        }

};

