#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = 0;
    int endWith = 0;
    int countPrefix = 0;

    bool containKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(Node *node, char ch)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = 1;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Tries
{
private:
    Node *root;

public:
    Tries()
    {
        root = new Node();
    }

    void insert(string s)
    {
        Node *node = root;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (!node->containKey(s[i]))
            {
                node->put(new Node(), s[i]);
            }
            node = node->get(s[i]);
            node->countPrefix++;
        }
        node->endWith++;
        node->setEnd();
    }

    int CountWordEqualTo(string s)
    {
        Node *node = root;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (!node->containKey(s[i]))
            {
                return 0;
            }
            node = node->get(s[i]);
        }

        if (node->isEnd())
        {
            return node->endWith;
        }
        else
        {
            return 0;
        }
    }

    int CountWordStartWith(string s)
    {
        Node *node = root;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (!node->containKey(s[i]))
            {
                return 0;
            }
            node = node->get(s[i]);
        }
        return node->countPrefix;
    }

    void Erease(string s)
    {
        Node *node = root;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (node->containKey(s[i]))
            {
                node = node->get(s[i]);
                node->countPrefix--;
            }
        }

        if (node->isEnd())
        {
            node->endWith--;
        }
    }
};

int main()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    Tries trie;
    trie.insert(s1);
    trie.insert(s2);
    trie.insert(s3);
    trie.insert(s4);
    cout << trie.CountWordEqualTo("apps") << endl; // Output: 1 (true)
    // cout << trie.CountWordStartWith("appl") << endl; // Output: 0 (false)
    trie.Erease("apps");
    cout << trie.CountWordEqualTo("apps") << endl; // Output: 1 (true)
    trie.Erease("apps");
    cout << trie.CountWordEqualTo("apps") << endl; // Output: 1 (true
    return 0;
}
