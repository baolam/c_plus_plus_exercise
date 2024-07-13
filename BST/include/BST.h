#ifndef BST_H
#define BST_H


class BST
{
    private:
        struct node
        {
            int key;
            node *left;
            node *right;
        };

        node *root;

    public:
        BST();
        node* CreateLeaf(int key);

};

#endif // BST_H
