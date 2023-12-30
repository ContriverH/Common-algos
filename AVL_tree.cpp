#include <iostream>
using namespace std;

class Node
{
public:
  int key;
  int height;
  Node *right;
  Node *left;

  Node(int k)
  {
    key = k;
    height = 1;
    right = nullptr;
    left = nullptr;
  }
};

class AVLTree
{
private:
  Node *root;

  int getHeight(Node *node)
  {
    return node == nullptr ? 0 : node->height;
  }

  int getBalanceFactor(Node *node)
  {
    return node == nullptr ? 0 : getHeight(node->left) - getHeight(node->right);
  }

  Node *rotateRight(Node *pivot)
  {
    Node *leftSubtree = pivot->left;
    Node *rightChildOfLeftSubtree = leftSubtree->right;

    // Perform rotation
    leftSubtree->right = pivot;
    pivot->left = rightChildOfLeftSubtree;

    // Update height
    pivot->height = 1 + max(getHeight(pivot->left), getHeight(pivot->right));
    leftSubtree->height = 1 + max(getHeight(leftSubtree->left), getHeight(leftSubtree->right));

    return leftSubtree;
  }

  Node *rotateLeft(Node *pivot)
  {
    Node *rightSubtree = pivot->right;
    Node *leftChildOfRightSubtree = rightSubtree->left;

    // Perform rotation
    rightSubtree->left = pivot;
    pivot->right = leftChildOfRightSubtree;

    // Update height
    pivot->height = 1 + max(getHeight(pivot->left), getHeight(pivot->right));
    rightSubtree->height = 1 + max(getHeight(rightSubtree->left), getHeight(rightSubtree->right));

    return rightSubtree;
  }

  Node *balance(Node *node)
  {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balanceFactor = getBalanceFactor(node);

    // Left heavy
    if (balanceFactor > 1)
    {
      // Right child of the left subtree is heavy, make it left-left case, then rotate right
      if (getBalanceFactor(node->left) < 0)
      {
        node->left = rotateLeft(node->left);
      }
      return rotateRight(node);
    }
    // Right heavy
    else if (balanceFactor < -1)
    {
      // Left child of the right subtree is heavy, make it right-right case, then rotate left
      if (getBalanceFactor(node->right) > 0)
      {
        node->right = rotateRight(node->right);
      }
      return rotateLeft(node);
    }

    return node;
  }

  Node *insertNode(Node *root, int newKey)
  {
    if (root == nullptr)
    {
      return new Node(newKey);
    }

    if (newKey < root->key)
    {
      root->left = insertNode(root->left, newKey);
    }
    else if (newKey > root->key)
    {
      root->right = insertNode(root->right, newKey);
    }
    else
    {
      // Duplicate keys are not allowed in this example
      return root;
    }

    return balance(root);
  }

  void inOrderTraversal(Node *root)
  {
    if (root == nullptr)
    {
      return;
    }

    inOrderTraversal(root->left);
    cout << root->key << " ";
    inOrderTraversal(root->right);
  }

public:
  AVLTree() : root(nullptr){};

  void insert(int key)
  {
    root = insertNode(root, key);
  }

  void printInOrder()
  {
    inOrderTraversal(root);
  }
};

int main()
{
  AVLTree avlTree;

  // Insert some keys into the AVL tree
  avlTree.insert(10);
  avlTree.insert(20);
  avlTree.insert(30);
  avlTree.insert(15);
  avlTree.insert(5);

  // Print the AVL tree using in-order traversal
  avlTree.printInOrder();

  return 0;
}