/* 
 * File:   main.cpp
 * Author: lukemiller
 *
 * Created on November 20, 2019, 10:30 PM
 */

#include <cstdlib>
#include <iostream>
#include<stdio.h> 
#include<stdlib.h>

using namespace std;

/*
 * 
 */

struct Node 
{ 
    int data; 
    Node* left; 
    Node* right; 
};

//root = 5
//key = 2

Node* search(Node* root, int key, Node * & parent){
    //cout<<"here1"<<endl;
    do{
        parent = root;
        if(root == NULL|| key == root->data){
            //cout<<"root == key and or is null"<<endl;
            return root;
        }
        if(key < root->data){
            root = root->left;
            //cout<<"root > key"<<endl;
        }
        else if(key > root->data){
            root = root->right;
            //cout<<"root < key"<<endl;
        }
            
        
        //cout<<"here6"<<endl;
    }while(root->left != NULL || root->right != NULL);
    
    return NULL;
}

Node* insert(Node* root, int key){
    
    Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    
    
    
    
    if(root == NULL)
        return temp;
    if(key < root->data)
        root->left = insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);
    return root;
    
    
  
    
}

void inorder (Node* root){
   //cout<<"here3"<<endl;
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout<<root->data<<endl; 
        inorder(root->right); 
    } 
}




int main(int argc, char** argv) {
    Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 7); 
    insert(root, 2); 
    insert(root, 99); 
    insert(root, 7); 
    insert(root, 87); 
    insert(root, 22); 
    inorder(root);
    cout<<"search(root, 99,root) " << search(root, 99,root)->data<<endl;
    insert(root, 50); 
    insert(root, 7); 
    //theis should seg fault if not in tree
    //cout<<"search(root, 3,root) " << search(root, 3,root)->data<<endl;
    
    insert(root, 2); 
    inorder(root);
    return 0;
}

