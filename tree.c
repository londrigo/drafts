#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 15

typedef struct Node {
    int data;

    struct Node *left;
    struct Node *right;
} Node;

Node* insert(Node *root, int data) {
    Node *temp= (Node*)malloc(sizeof(Node));

    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

    if(root==NULL){
        root=temp;
    }
    else{
        Node *current=root;
        Node *parent=NULL;
        while(1){
            parent=current;
            if(data<parent->data){
                current=current->left;

                if (current==NULL){
                    parent->left=temp;
                    return root;
                }
            }
            else{
                current=current->right;
                if (current==NULL){
                    parent->right = temp;
                    return root;
                }
            }
        }
        
    }
    return root;
}

int search(Node *root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return 1;
    }
    if (root->data > data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

void inorder_traversal(struct Node* root) {
    if (root) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    
    }
}

int main(){
    int i;
    int array[ARRAY_LENGTH] = {14,84,15,0,2,99,79,9,88,89,18,31,39,100,101};
    Node *root = NULL;

    for(i = 0; i < ARRAY_LENGTH; i++){
        root = insert(root, array[i]);
        printf("Inserted %d\n", array[i]);
    };

    printf("\nInorder traversal: ");
    inorder_traversal(root);
    int search_val = 88;
    int temp = search(root,search_val );
    if (temp){
        printf("\n[%d] Found \n", search_val);
    } else {
        printf("\n[x] (%d) Not found\n", i);
    }

    int search_val2 = 87;
    int temp2 = search(root,search_val2 );
    if (temp2){
        printf("\n[%d] Found \n", search_val2);
    } else {
        printf("\n[x] (%d) Not found\n", i);
    }


    return 0;
}