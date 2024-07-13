#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, x;
struct Node {
    int data;
    Node *pLeft, *pRight;
};

void addNode(Node *p, int val) {
    if (p == NULL)
}

Node *root;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    cin >> n;
    cin >> x;
    root->data = x;
    for (ll i = 2; i <= n; i++)
    {
        cin >> x;
        addNode(root, x);
    }
    return 0;
}
