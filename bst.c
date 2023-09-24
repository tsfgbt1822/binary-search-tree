#ifdef DEBUG
#include <stdio.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bst.h"

// Local functions

// These are stubs.  That is, you need to implement these functions.

//createsand initializes a new BST
BST * NewBST()
{
    long k=0;
    BST* tree;//tree
    tree=malloc(sizeof(BST));
    tree->data=NULL;//satellite data
    tree->key=k;//key
    tree->lchild=NULL;//left child
    tree->rchild=NULL;//right child
    return tree;
}

//pBST is the binary search tree
//sattellite is the customer
//key is the account number
void TreeInsert(BST * pBST, void * satellite, long long key)
{
    if (NULL==pBST)
    {
        pBST->data=satellite;
        pBST->key=key;
    }

    if(pBST->key==-1)//if BST is empty, insert pBST into root
    {
        pBST->data=satellite;//
        pBST->key=key;
    }
    else
        if(pBST->key<key)//if key is larger than pBST, go to right child
            TreeInsert(pBST->rchild, satellite, key);
        else//if key is smaller than pBST, go to left child
            TreeInsert(pBST->lchild, satellite, key);
}
//in order traversal
void InOrder(BST * pBST, NODEVISITFUNC func)
{
    if(pBST!=NULL)//if pBST is not empty
    {
        InOrder(pBST->lchild,func);//visit farthest left child
        func(pBST);//visit node
        InOrder(pBST->rchild,func);//visit right child
    }
}

//preorder traversal
void PreOrder(BST * pBST, NODEVISITFUNC func)
{
    if(pBST!=NULL)
    {
        func(pBST);//visit node
        PreOrder(pBST->lchild,func);//visit left child
        PreOrder(pBST->rchild,func);//visit right child 
    }
}

//post order traversal
void PostOrder(BST * pBST, NODEVISITFUNC func)
{
    if(pBST!=NULL)//if pBST is not empty
    {
        PostOrder(pBST->lchild, func);//visit far left child
        PostOrder(pBST->rchild, func);//vsit far right child
        func(pBST);//visit node
    }
}

//search using key
void * Search(BST * pBST, long long key)
{
    if(pBST==NULL)//if pBST is null, tree is empty
        return NULL;
    if(pBST->key==key)//if pBST is what we're looking for, return
        return pBST;
    if(key>pBST->key)//if key is greter than pBST's key, go to right child
        return Search(pBST->rchild, key);
   //otherwise, visit left child
   return Search(pBST->lchild, key);
}


void TreeDelete(BST * pBST, long long key)
{
    BST *temp;
    //search for the node to be deleted
    pBST=Search(pBST,key);
    if(pBST!=NULL)
    {

        //no children
        if(pBST->lchild==NULL && pBST->rchild==NULL)
        {
            free(pBST);
        }

        //one child
        else if(pBST->lchild==NULL || pBST->rchild==NULL)
        {
            if(pBST->lchild==NULL)
            {
                temp=pBST->rchild;
                free(pBST);
            }
            else
            {
                temp=pBST->lchild;
                free(pBST);
            }
        }

        //two children
        else
        {
            temp=IOSuccessor(pBST);//find in order successor
            pBST->key=temp->key;//put IO successor's key into pBST
            pBST->data=temp->data;//put IO successor's data into pBST
            TreeDelete(temp, temp->key);
        }
    }
}

//finds the inorder successor
BST * IOSuccessor(BST * pBST)
{
    pBST=pBST->rchild;
    while(pBST!=NULL && pBST->lchild!=NULL)
        pBST=pBST->lchild;
    return pBST;
}

