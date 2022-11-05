#include <iostream>
#include <list>

using namespace std;

template <typename T> struct treeNode {
  T data;
  struct treeNode *left;
  struct treeNode *right;

  treeNode<T>() {}

  treeNode<T>(T data, treeNode<T> *left = nullptr,
              treeNode<T> *right = nullptr) {
    this->data = data;
    this->left = left;
    this->right = right;
  }

  bool isLeaf() { return (left == nullptr) && (right == nullptr); }

  ~treeNode<T>() {
    delete left;
    delete right;
  }
};

template <class T> class BinaryTree {
private:
  struct treeNode<T> *head;

  void preOrderPrintHelper(treeNode<T> *node) const {
    cout << node->data << " ";
    if (node->left != nullptr) {
      preOrderPrintHelper(node->left);
    }
    if (node->right != nullptr) {
      preOrderPrintHelper(node->right);
    }
  }

  void inOrderPrintHelper(treeNode<T> *node) const {
    if (node->left != nullptr) {
      inOrderPrintHelper(node->left);
    }
    cout << node->data << " ";
    if (node->right != nullptr) {
      inOrderPrintHelper(node->right);
    }
  }

  void postOrderPrintHelper(treeNode<T> *node) const {
    if (node->left != nullptr) {
      postOrderPrintHelper(node->left);
    }
    if (node->right != nullptr) {
      postOrderPrintHelper(node->right);
    }
    cout << node->data << " ";
  }

  int subTreeSizeHelper(treeNode<T> *node) {
    if (node == nullptr)
      return 0;
    else
      return 1 + subTreeSizeHelper(node->left) + subTreeSizeHelper(node->right);
  }

public:
  BinaryTree<T>() { this->head = nullptr; }

  BinaryTree<T>(treeNode<T> *node) { this->head = node; }

  /**
    Prints the nodes to stdout in preorder (visits the root, then the left
    child, then the right child)
    @tested:
      Empty tree / Single node tree
      Tree with repeating data
      Linear tree
      Full tree
  */
  void preOrderPrint() const {
    if (head != nullptr) {
      preOrderPrintHelper(head);
    }
    cout << endl;
  }

  /**
    Prints the nodes to stdout in inorder (visits the left child, then the root,
    then the right child)
    @tested:
      Empty tree / Single node tree
      Tree with repeating data
      Linear tree
      Full tree
  */
  void inOrderPrint() const {
    if (head != nullptr) {
      inOrderPrintHelper(head);
    }
    cout << endl;
  }

  /**
    Prints the nodes to stdout in postorder (visits the left child, then the
    right child, then the root)
    @tested:
      Empty tree / Single node tree
      Tree with repeating data
      Linear tree
      Full tree
  */
  void postOrderPrint() const {
    if (head != nullptr) {
      postOrderPrintHelper(head);
    }
    cout << endl;
  }

  /**
    Adds `node` at the highest possible level in the tree, if multiple locations
    are available, the leftmost one is selected
    @input:
      `treeNode<T> *node` pointer to a node of type `T`
    @tested:
      Empty tree
      Linear tree
      Tree with multiple available locations for `node`
      Full tree (2^n-1 nodes with depth n)
  */
  void addNode(treeNode<T> *node) {
    if (head == nullptr) {
      this->head = node;
      return;
    }

    list<treeNode<T> *> queue = list<treeNode<T> *>();
    queue.push_front(head);

    while (!queue.empty()) {
      treeNode<T> *current = queue.back();
      queue.pop_back();

      // check left child
      if (current->left != nullptr) {
        queue.push_front(current->left);
      } else {
        current->left = node;
        break;
      }

      // check right child
      if (current->right != nullptr) {
        queue.push_front(current->right);
      } else {
        current->right = node;
        break;
      }
    }
  }

  /**
    Deletes the highest leaf node whose data is equal to `element`
    @input:
      `T element` data of type `T`
    @tested:
      Empty tree
      Tree with multiple leaf nodes of data `element`
      The node is not a leaf
      No data is equal to node
  */
  void deleteNode(const T element) {
    if (head == nullptr) {
      cout << "Cannot delete node: Tree is empty" << endl;
      return;
    }

    list<treeNode<T> *> queue = list<treeNode<T> *>();
    queue.push_front(head);

    while (!queue.empty()) {
      treeNode<T> *current = queue.back();
      queue.pop_back();

      // check left child
      if (current->left != nullptr) {
        if (current->left->isLeaf() && current->left->data == element) {
          current->left->~treeNode<T>();
          current->left = nullptr;
          return;
        }
        queue.push_front(current->left);
      }

      // check right child
      if (current->right != nullptr) {
        if (current->right->isLeaf() && current->right->data == element) {
          current->right->~treeNode<T>();
          current->right = nullptr;
          return;
        }
        queue.push_front(current->right);
      }
    }
    cout << "Cannot delete node " << element << endl;
  }

  /**
    @returns the number of nodes in the three
    @tested:
      Empty tree / Multiple nodes
    @implementation:
      Calls `subTreeSize()`
  */
  int treeSize() {
    if (head == nullptr)
      return 0;
    else
      return subTreeSize(head->data);
  }

  /**
    @returns the number of nodes of the highest subtree whose data is equal to
    `element`, returns 0 if no such node exists
    @input:
      `T element` data of type `T`
    @tested:
      Multiple nodes whose data is equal to `element`
      No node whose data is equal to `element`
      Only leaf nodes have data equal to `element`
      Only root has data equal to `element`
  */
  int subTreeSize(int element) {
    if (head == nullptr) {
      return 0;
    }

    list<treeNode<T> *> queue = list<treeNode<T> *>();
    queue.push_front(head);

    while (!queue.empty()) {
      treeNode<T> *current = queue.back();
      queue.pop_back();

      if (current->data == element) {
        return subTreeSizeHelper(current);
      }

      if (current->left != nullptr) {
        queue.push_front(current->left);
      }

      if (current->right != nullptr) {
        queue.push_front(current->right);
      }
    }
    return 0;
  }

  ~BinaryTree<T>() { delete head; }
};

int main() {
  const list<int> nodesToAdd = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const list<int> nodesToCheckSize = {0, 4, 6, 2, 1, -1};
  const list<int> nodesToDelete = {8, 1, 6, 3, 5, 2};

  // Adding nodes to tree
  cout << "Adding elements of list: { ";
  for (int element : nodesToAdd) {
    cout << element << " ";
  }
  cout << "} to a binary tree: ";

  BinaryTree<int> tree = BinaryTree<int>();
  for (int i : nodesToAdd) {
    tree.addNode(new treeNode<int>(i));
  }
  cout << endl;

  // Printing tree in multiple orders
  cout << "preOrder: ";
  tree.preOrderPrint();
  cout << "inOrder: ";
  tree.inOrderPrint();
  cout << "postOrder: ";
  tree.postOrderPrint();
  cout << endl;

  // Checking tree and subtree sizes
  cout << "Total tree size: " << tree.treeSize() << endl;
  for (int i : nodesToCheckSize) {
    cout << "Subtree " << i << " has size of " << tree.subTreeSize(i) << endl;
  }
  cout << endl;

  // Removing nodes from tree
  cout << "Removing elements of list: { ";
  for (int element : nodesToDelete) {
    cout << element << " ";
  }
  cout << "} from tree: " << endl << endl;

  for (int i : nodesToDelete) {
    tree.deleteNode(i);
    cout << "inOrder: ";
    tree.inOrderPrint();
    cout << endl;
  }
}