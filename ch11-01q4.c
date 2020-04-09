#include <stdio.h>
#include <stdlib.h>


typedef struct _BinNode {
    int value;
    struct _BinNode* left;
    struct _BinNode* right;
} BinNode;

void set(BinNode* node, BinNode* root) {
    if (node->value < root-> value) {
        if (root->left) {
            set(node, root->left);
        } else {
            root->left = node;
        }
    } else {
        if (root->right) {
            set(node, root->right);
        } else {
            root->right = node;
        }
    }
}

void scanInorder(BinNode* root) {
    if (root->left) {
        scanInorder(root->left);
    }
    printf("%i ", root->value);
    if (root->right) {
        scanInorder(root->right);
    }
}

int main(int argc, char** argv) {
    BinNode nodes[argc];
    nodes[0].value = 0;
    nodes[0].left = nodes[0].right = NULL;
    for (int i = 1; i < argc; i++) {
        nodes[i].left = nodes[i].right = NULL;
        nodes[i].value = atoi(argv[i]);
        set(nodes + i, nodes);
    }
    scanInorder(nodes);
    printf("\n");
    return 0;
}
