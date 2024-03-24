#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node {
    int data;
    Node* _nxt;
};

void travel(Node* head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << ' ';
        curr = curr->_nxt;
    }
}

bool searchLinkedList(Node *head, int target)
{
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == target)
            return true;
        curr = curr->_nxt;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}
