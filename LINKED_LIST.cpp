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

int Length(Node *head)
{
    int len = 0;
    Node* curr = head;
    while (curr != NULL)
    {
        len++;
        curr = curr->_nxt;
    }
    return len;
}

void insertAtBegining(Node **head_ref, int new_data)
{
    Node *node = new Node();
    node->data = new_data;

    node->_nxt = *head_ref;
    *head_ref = node;
}

void insertAtEnd(Node **head_ref, int new_data)
{
    Node *node = new Node();
    node->data = new_data;
    node->_nxt = NULL;

    Node *last = *head_ref;
    if (*head_ref == NULL)
    {
        *head_ref = node;
        return;
    }

    while (last->_nxt != NULL)
        last = last->_nxt;

    last->_nxt = node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}
