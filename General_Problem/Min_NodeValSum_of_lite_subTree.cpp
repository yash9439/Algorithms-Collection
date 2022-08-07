// Lite tree are tree whose inorder traversal are in ascending or decending order
// input is of Tree in level order
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    long long int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Node
{
    struct TreeNode *num;
    struct Node *next;
    struct Node *prev;
};

struct Queue
{
    int size;
    struct Node *head;
    struct Node *tail;
};

struct TreeNode *CreateTreeNode()
{
    struct TreeNode *n;
    n = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node *createNode()
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->next = NULL;
    n->prev = NULL;
    return n;
}

struct Queue *createQueue()
{
    struct Queue *q;
    q = (struct Queue *)malloc(sizeof(struct Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

void pop(struct Queue *q)
{
    if (q->head == NULL)
    {
        return;
    }
    if (q->head->prev == NULL)
    {
        // free(q->head);
        q->size--;
        q->head = NULL;
        q->tail = NULL;
        return;
    }
    q->head = q->head->prev;
    // free(q->head->next);
    q->size--;
    q->head->next = NULL;
    return;
}

void push(struct Queue *q, struct TreeNode * num)
{
    struct Node * n = createNode();
    n->num = num;
    if (q->tail == NULL)
    {
        q->head = n;
        q->tail = n;
        q->size++;
        return;
    }
    q->tail->prev = n;
    n->next = q->tail;
    q->tail = n;
    q->size++;
    return;
}

struct TreeNode *front(struct Queue *q)
{
    if (q->head == NULL)
    {
        return NULL;
    }
    return q->head->num;
}


long long int Noise(struct TreeNode * T) {
    if(T == NULL) {
        return 0;
    }
    long long int sum = T->val;
    sum += Noise(T->left)+Noise(T->right);
    return sum;
}


long long int Min(long long int a, long long int b) {
    if(a > b) {
        return b;
    }
    return a;
}


long long int BSTAc(struct TreeNode * root, long long int range_min, long long int range_max)
{
    if(root == NULL)
        return 1;
    
    if (root->val < range_min || root->val > range_max)
        return 0;
    
    if (BSTAc(root->left, range_min, root->val-1))
        if (BSTAc(root->right, root->val+1, range_max))
            return 1;
    return 0;
}


long long int isBSTAc(struct TreeNode * root)
{
    if (BSTAc(root, -999999999, 999999999))
        return 1;
    return 0;
}



long long int BSTDc(struct TreeNode * root, long long int range_max, long long int range_min)
{
    if(root == NULL)
        return 1;
    
    if (root->val > range_max || root->val < range_min)
        return 0;
    
    if (BSTDc(root->left,range_max, root->val+1))
        if (BSTDc(root->right,root->val-1, range_min))
            return 1;
    return 0;
}


long long int isBSTDc(struct TreeNode * root)
{
    if (BSTDc(root, 999999999, -999999999))
        return 1;
    return 0;
}


void inorder(struct TreeNode * root) {
    if( root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%lld ",root->val);
    inorder(root->right);
}


int main()
{
    long long int testCase;
    scanf("%lld", &testCase);

    long long bc[testCase];
    long long int Case = testCase;
    while (Case--)
    {
        long long int n;
        scanf("%lld", &n);
        struct TreeNode *root = CreateTreeNode();
        struct TreeNode * NodeArr[n];
        long long int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }

        long long int tempIdx = 0;
        root->val = arr[0];
        NodeArr[tempIdx++] = root;


        struct Queue *q = createQueue();


        long long int leftChk = 1;
        struct TreeNode *cur = NULL;
        push(q, root);

        for (int i = 1; i < n; i++)
        {
            struct TreeNode *n1 = NULL;
            if (arr[i] != 0)
            {
                n1 = CreateTreeNode();
                n1->val = arr[i];
                NodeArr[tempIdx++] = n1;
                push(q, n1);
            }

            if (leftChk == 1)
            {
                cur = front(q);
                if(cur == NULL) {
                    cur->left = NULL;
                    cur->right = NULL;
                    break;
                }
                pop(q);
                cur->left = n1;
                leftChk = 0;
            }
            else
            {
                cur->right = n1;
                leftChk = 1;
            }
        }

        // inorder(root);
        // printf("\n");

        long long int min = 99999999;
        for(int i = 0 ; i < tempIdx ; i++) {
            if(isBSTAc(NodeArr[i]) || isBSTDc(NodeArr[i])) {
                min = Min(Noise(NodeArr[i]),min);
            }
        }

        // printf("%lld",min);
        bc[Case] = min;
        free(root);
    }
    
    for(int i = testCase-1 ; i >= 0 ; i--) {
        printf("%lld\n",bc[i]);
    }

    return 0;
}