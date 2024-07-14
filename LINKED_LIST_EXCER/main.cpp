#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct ListNode {
    int data;
    ListNode *link;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ListNode *head = new ListNode();
    head->data = 45;
    head->link = NULL;

    ListNode *current = new ListNode();
    current->data = 98;
    current->link = NULL;

    head->link = current;
    return 0;
}
