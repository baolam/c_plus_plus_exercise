#include <bits/stdc++.h>
#include "BST.h"

using namespace std;
typedef int ll;

int main()
{
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
    //myTree.PrintChildren(myTree.ReturnRootKey());
    for (int i = 0; i < 16; i++) {
        myTree.PrintChildren(TreeKeys[i]);
        cout << '\n';
    }
    return 0;
}
