#include <bits/stdc++.h>
#include "BST.h"

using namespace std;
typedef int ll;

int main()
{
    int input = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int TreeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
    BST myTree;
    cout << "Printing the tree in order\nBefore adding numbers\n";
    myTree.PrintInOrder();
    for (int i = 0; i < 16; i++)
        myTree.AddLeaf(TreeKeys[i]);
    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree.PrintInOrder();
    cout << '\n';

    cout << "The smallest value in the tree is " << myTree.FindSmallest() << '\n';
    cout << "Enter a key value to delete. Enter -1 to stop the process\n";
    while(input != -1)
    {
        cout << "Delete Node: ";
        cin >> input;
        if (input != -1)
        {
            cout << '\n';
            myTree.RemoveNode(input);
            myTree.PrintInOrder();
            cout << '\n';
        }
    }
    return 0;
}
