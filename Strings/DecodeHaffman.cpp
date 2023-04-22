#include <iostream>
#include <string>

using namespace std;

int len = 0;

class Node {
public:

    Node() = default;
    Node(string& ch_, string& code_) {
        left = nullptr;
        right = nullptr;
        ch = ch_;
        code = code_;
    }

    void build_tree(string& code, string& ch) {
        Node* cur = this;

        for (int i = 0; i < code.size(); i++)
        {
            if (code[i] == '0' && cur->left == nullptr) {
                string cur_ch = "";
                string cur_code = cur->code + "0";
                cur->left = new Node(cur_ch, cur_code);
                cur = cur->left;
            }
            if (code[i] == '1' && cur->right == nullptr) {
                string cur_ch = "";
                string cur_code = cur->code + "1";
                cur->right = new Node(cur_ch, cur_code);
                cur = cur->right;
            }

            if (code[i] == '0' && cur->left != nullptr) {
                cur = cur->left;

            }
            if (code[i] == '1' && cur->right != nullptr) {
                cur = cur->right;
            }

        }
        cur->ch = ch;
    }

    string find(string& cod) {
        Node* cur = this;
        
        for (int i = 0; i < cod.size(); i++) {
            if (cod[i] == '0') {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
       
        return cur->ch;
    }

    string ch = "";
    string code = "";
    Node* left = nullptr;
    Node* right = nullptr;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    Node root;
    int min_l = 1000000;
    for (int i = 0; i < n; i++)
    {
        string ch, code;
        cin >> ch;
        cin >> code;
        ch = ch[0];
        if (len < code.size()) {
            len = code.size();
        }
        if (min_l > code.size()) {
            min_l = code.size();
        }
        root.build_tree(code, ch);
    }

    

    string encodedMessage = "";
    cin >> encodedMessage;
    
    string str = "";
    string ans = "";
    for (int i = 0; i < encodedMessage.size(); i++) {
        str += encodedMessage[i];
        if (str.size() < min_l) {
            continue;
        }
        string letter = root.find(str);
        if (letter != "") {
            ans += letter;
            str = "";
        }
    }
    cout << ans;
    return 0;
}