#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

using namespace std;
typedef long long ll;

struct Node {
    Node *child[26];
    ll high, toHigh;

    Node()
    {
        high = toHigh = 0;
        REP(i, 26) child[i] = NULL;
    }
};

Node *root;

void addString(string s)
{
    Node *p = root;
    REP(i, s.size())
    {
        if (p->child[s[i] - 'a'] == NULL)
            p->child[s[i] - 'a'] = new Node();
        p = p->child[s[i] - 'a']
        p->high = i + 1;
    }
}

void dfs(Node *p)
{
    p->toHigh = p->high;
    REP(i, 26)
    {
        if (p->child[i] != NULL)
        {
            dfs(p->child[i]);
            p->toHigh += p->child[i]->toHigh;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    int n;
    cin >> n;
    REP(x, n)
    {
        cin >> s;
        addString(s);
    }

    dfs(root);
    cout << root->toHigh << '\n';
    return 0;
}
