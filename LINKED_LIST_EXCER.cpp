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

int countNodes(node *ptr)
{
    int m = 0;
    while (ptr != NULL)
    {
        m++;
        ptr = ptr->link;
    }
    return m;
}

void addAtPosition(node *ptr, int pos, int data)
{
    node *ptr_2 = createNode(data);

    pos--;
    while (pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }

    ptr_2->link = ptr->link;
    ptr->link = ptr_2;
}

void PrintLinkedList()
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << ' ';
        ptr = ptr->link;
    }
    cout << '\n';
}

node *deleteFirstNode(node *ptr)
{
    node *temp = ptr->link;
    ptr = NULL;
    return temp;
}

void deleteLastNode(node *ptr)
{
    node *temp = ptr;
    while (temp->link->link != NULL)
        temp = temp->link;
    temp->link = NULL;
}

void deleteAtPosition(node *ptr, int pos)
{
    node *current = ptr;
    node *prev = ptr;
    while (pos != 1)
    {
        prev = current;
        current = current->link;
        pos--;
    }
    prev->link = current->link;
    current = NULL;
}

node* deleteEntire(node *ptr)
{
    node *temp = ptr;
    while (temp != NULL)
    {
        temp = temp->link;
        ptr = temp;
    }
    return ptr;
}

node* reverseLinkedList(node *head)
{
    node *prev = NULL;
    node *next = NULL;
    while (head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
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
    PrintLinkedList();
    head = reverseLinkedList(head);
    PrintLinkedList();
    return 0;
}
