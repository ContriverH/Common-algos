#include <iostream>
using namespace std;

class Node
{
public:
  bool isLeaf;
  Node *children[26];

  Node()
  {
    isLeaf = false;
    for (auto &child : children)
      child = nullptr;
  }
};

class Trie
{
private:
  Node *root;

  bool search(char *word, Node *node)
  {
    if (node == nullptr)
      return false;

    if (*word == '/0')
    {
      if (node->isLeaf == true)
        return true;
    }

    char letterIndex = int(*word) - 'a';
    return search(++word, node->children[letterIndex]);
  }

  void insert(char *word, Node *node)
  {
    if (*word == '/0')
    {
      node->isLeaf = true;
      return;
    }

    char letterIndex = int(*word) - 'a';
    if ((node->children[letterIndex]) == nullptr)
    {
      node->children[letterIndex] = new Node();
    }

    insert(++word, node->children[letterIndex]);
  }

public:
  Trie()
  {
    root = new Node();
  }

  void insertWord(char *word)
  {
    insert(word, root);
  }

  bool searchWord(char *word)
  {
    return search(word, root);
  }
};

int main()
{
  Trie trie;
  trie.insertWord("himanshu");
  trie.insertWord("nishchay");
  trie.insertWord("palhimanshu");
  trie.insertWord("nishchayverma");

  if (trie.searchWord("himanshu") == true)
    cout << "himanshu" << endl;

  return 0;
}