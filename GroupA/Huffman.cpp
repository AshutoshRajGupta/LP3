#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char data;
    int frequency;
    Node *left, *right;
    Node(char d, int f) : data(d), frequency(f), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(Node* a, Node* b) { return a->frequency > b->frequency; }
};

map<char, string> huffmanCodes;

void generateHuffmanCodes(Node* root, string code = "") {
    if (!root) return;
    if (!root->left && !root->right) huffmanCodes[root->data] = code;
    generateHuffmanCodes(root->left, code + "0");
    generateHuffmanCodes(root->right, code + "1");
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    map<char, int> freq;
    for (char c : s) freq[c]++;

    priority_queue<Node*, vector<Node*>, CompareNodes> pq;
    for (auto p : freq) pq.push(new Node(p.first, p.second));

    while (pq.size() > 1) {
        Node *l = pq.top(); pq.pop();
        Node *r = pq.top(); pq.pop();
        Node *n = new Node('\0', l->frequency + r->frequency);
        n->left = l; n->right = r;
        pq.push(n);
    }

    generateHuffmanCodes(pq.top());

    cout << "Huffman Codes:\n";
    for (auto p : huffmanCodes) cout << p.first << ": " << p.second << endl;
    
    return 0;
}


