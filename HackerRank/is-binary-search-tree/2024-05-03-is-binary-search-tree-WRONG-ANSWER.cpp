/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

	// bool checkBST(Node* root) {
		
	// }
    
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool checkBST(Node* root) {
    if (root == NULL)
        return true;
    if (root->left != NULL && root->left->data > root->data)
        return false;
    else if (root->right != NULL && root->right->data < root->data)
        return false;
    else
        return checkBST(root->left) && checkBST(root->right);
}


TEST_CASE("single node") {
    Node* root = new Node();
    root->data = 3;

    CHECK(checkBST(root) == true);
}

TEST_CASE("2 nodes, left (5) > root (3) == false") {
    Node* leftNode = new Node();
    leftNode->data = 5;
    
    Node* root = new Node();
    root->data = 3;
    root->left = leftNode;

    CHECK(checkBST(root) == false);
}

TEST_CASE("2 nodes, left (2) < root (3) == true") {
    Node* leftNode = new Node();
    leftNode->data = 2;
    
    Node* root = new Node();
    root->data = 3;
    root->left = leftNode;

    CHECK(checkBST(root) == true);
}

TEST_CASE("2 nodes, right (1) < root (3) == false") {
    Node* rightNode = new Node();
    rightNode->data = 1;
    
    Node* root = new Node();
    root->data = 3;
    root->right = rightNode;

    CHECK(checkBST(root) == false);
}

TEST_CASE("2 nodes, right (6) > root (3) == true") {
    Node* rightNode = new Node();
    rightNode->data = 6;
    
    Node* root = new Node();
    root->data = 3;
    root->right = rightNode;

    CHECK(checkBST(root) == true);
}

TEST_CASE("3 nodes -> true") {
    Node* leftNode = new Node();
    leftNode->data = 2;

    Node* rightNode = new Node();
    rightNode->data = 6;
    
    Node* root = new Node();
    root->data = 3;
    root->left = leftNode;
    root->right = rightNode;

    CHECK(checkBST(root) == true);
}

TEST_CASE("3 nodes -> false") {
    Node* leftNode = new Node();
    leftNode->data = 5;

    Node* rightNode = new Node();
    rightNode->data = 2;
    
    Node* root = new Node();
    root->data = 3;
    root->left = leftNode;
    root->right = rightNode;

    CHECK(checkBST(root) == false);
}

TEST_CASE("3 nodes -> 1 2 2 == true") {
    Node* leftNode = new Node();
    leftNode->data = 1;

    Node* rightNode = new Node();
    rightNode->data = 2;
    
    Node* root = new Node();
    root->data = 2;
    root->left = leftNode;
    root->right = rightNode;

    CHECK(checkBST(root) == true);
}

/**
          10
     5           20
NULL    11    NULL   NULL
-> should be false
*/
TEST_CASE("4 nodes -> false") {
    Node* rightNode2ndLevel = new Node();
    rightNode2ndLevel->data = 11;

    Node* leftNode = new Node();
    leftNode->data = 5;
    leftNode->right = rightNode2ndLevel;

    Node* rightNode = new Node();
    rightNode->data = 20;
    
    Node* root = new Node();
    root->data = 10;
    root->left = leftNode;
    root->right = rightNode;

    CHECK(checkBST(root) == false);
}
