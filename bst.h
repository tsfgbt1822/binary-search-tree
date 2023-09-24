#ifndef _bst_h
#define _bst_h

// Symbolic Constants




// Data types

// NOTE! - You will want to fill out this data structure.
typedef struct _BST
{
    void *data; //stores satellite data
    long long key;
    struct _BST *lchild; //left child
    struct _BST *rchild; //right child
} BST;

typedef void (*NODEVISITFUNC)(void * parm);




// Prototypes
BST * NewBST();
void TreeInsert(BST * pBST, void * satellite, long long key);
void InOrder(BST * pBST, NODEVISITFUNC func);
void PreOrder(BST * pBST, NODEVISITFUNC func);
void PostOrder(BST * pBST, NODEVISITFUNC func);
void * Search(BST * pBST, long long key);
void TreeDelete(BST * pBST, long long key);
BST * IOSuccessor(BST * pBST);



#endif
