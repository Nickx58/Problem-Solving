#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
};

Node *getNewNode(Node *root, int data)
{
  Node *node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node *insert(Node *root, int data)
{
  if (root == NULL)
  {
    root = getNewNode(root, data);
  }
  else if (data <= root->data)
  {
    root->left = getNewNode(root->left, data);
  }
  else
  {
    root->right = getNewNode(root->right, data);
  }
  return root;
}

bool searchNode(Node *root, int data)
{
  if (root == NULL)
    return false;
  if (root->data == data)
  {
    return true;
  }
  bool leftResp = searchNode(root->left, data);
  if (leftResp)
  {
    return true;
  }
  bool rightResp = searchNode(root->right, data);
  return rightResp;
}

int main()
{
  Node *root = NULL;
  root = insert(root, 15);
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 25);
  root = insert(root, 8);
  root = insert(root, 12);
  if (searchNode(root, 10) != 0)
  {
    cout << "Found in the binary tree" << endl;
  }
  else
  {
    cout << "Not Found" << endl;
  }
  return 0;
}