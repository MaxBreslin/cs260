#ifndef TABLE_H
#define TABLE_H
//table.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;;
};

void build(node * & root);  //supplied
void display(node *  root); //supplied
void destroy(node * & root); //supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
int sumOfEvenNodes(node * root);
void copyNonLeaf(node * root, node *& newRoot);
node * copyToNewRoot(node * root, node * newRoot);
#endif
