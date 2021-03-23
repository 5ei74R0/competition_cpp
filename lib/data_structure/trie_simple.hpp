// Trie (simple)
// Verified : 
//
#include <bits/stdc++.h>


 
/* Chars */
// 
// Static attributes
// 1. size : number of possible characters
//
// Static Methods
// 1. char2idx : convert character into index
// 
// e.g. LowerChars
struct LowerChars {
    static const std::size_t size;
    static std::size_t char2idx(char ch) { return ch - 'a'; }
};
const std::size_t LowerChars::size = 26;
 

/* Trie (simple) */
// efficient prefix search
//
// Methods
// 1. add : add keyword
// 2. exist : find keyword
//
template<typename Chars>
class Trie {
  public:
    Trie() : root(new Node('*')) {}
    void add(std::string str) {
        auto nd = root.get();
        for (const auto& ch : str) {
            if (nd->children[Chars::char2idx(ch)]) {
                nd = nd->children[Chars::char2idx(ch)].get();
            } else {
                nd->children[Chars::char2idx(ch)] = std::unique_ptr<Node>(new Node(ch));
                nd = nd->children[Chars::char2idx(ch)].get();
            }
        }
        nd->is_tail = true;
    }
    bool exist(std::string str, bool include_substr = false) {
        auto nd = root.get();
        for (const auto& ch : str) {
            if (nd->children[Chars::char2idx(ch)]) {
                nd = nd->children[Chars::char2idx(ch)].get();
            } else {
                return false;
            }
        }
        if (include_substr) return true;
        else if (nd->is_tail) return true;
        return false;
    }
 
  private:
    struct Node {
        Node(char ch) : ch(ch), is_tail(false) {}
        char ch;
        bool is_tail;
        std::array<std::unique_ptr<Node>, Chars::size> children;
    };
    std::unique_ptr<Node> root;
};


// e.g.
// signed main() {
//
//     Trie<LowerChars> trie;
//
//     std::string s;
//     for (int i1 = 0; i1 < 26; ++i1) {
//         s.push_back('a' + i1);
//         for (int i2 = 0; i2 < 26; ++i2) {
//             s.push_back(('a' + i2));
//             trie.add(s);
//             s.clear();
//         }
//     }
//
//     for (int i1 = 0; i1 < 26; ++i1) {
//         s.push_back('a' + i1);
//         for (int i2 = 0; i2 < 26; ++i2) {
//             s.push_back(('a' + i2));
//             if (!trie.exist(s)) std::cout << "not exist!" << '\n';
//             s.clear();
//         }
//     }
// }
