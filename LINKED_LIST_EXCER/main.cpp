#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node {
    int data;
    node *link;
};

int x;
node *head = NULL;

node* createNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->link = NULL;
    return temp;
}

node* addAtEnd(node *ptr, int data)
{
    node *temp = createNode(data);
    ptr->link = temp;
    return temp;
}

node* addAtBegining(node *ptr, int data)
{
    node *temp = createNode(data);
    temp->link = ptr;
    return temp;
}

void PrintLinkedList()
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << ' ';
        ptr = ptr->link;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    node *ptr;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (head == NULL)
        {
            head = createNode(x);
            ptr = head;
        }
        else
            ptr = addAtEnd(ptr, x);
    }
    head = addAtBegining(head, 234);
    PrintLinkedList();
    return 0;
}
