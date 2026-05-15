// Self Balancing Tree

int height(node* n)
{
    if(n == NULL) return -1;
    return n->ht;
}

int getBalance(node* n)
{
    if(n == NULL) return 0;
    return height(n->left) - height(n->right);
}

node* rightRotate(node* y)
{
    node* x = y->left;
    node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->ht = max(height(y->left), height(y->right)) + 1;
    x->ht = max(height(x->left), height(x->right)) + 1;

    return x;
}

node* leftRotate(node* x)
{
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->ht = max(height(x->left), height(x->right)) + 1;
    y->ht = max(height(y->left), height(y->right)) + 1;

    return y;
}

node * insert(node * root,int val)
{
    if(root == NULL)
    {
        node* temp = new node;
        temp->val = val;
        temp->left = temp->right = NULL;
        temp->ht = 0;
        return temp;
    }

    if(val < root->val)
        root->left = insert(root->left, val);
    else if(val > root->val)
        root->right = insert(root->right, val);

    root->ht = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    // LL Case
    if(balance > 1 && val < root->left->val)
        return rightRotate(root);

    // RR Case
    if(balance < -1 && val > root->right->val)
        return leftRotate(root);

    // LR Case
    if(balance > 1 && val > root->left->val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if(balance < -1 && val < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}