#include <iostream>
#include <vector>
using namespace std;

// Define a structure for a node in the Binary Search Tree (BST)
struct BSTNode
{
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;

    // Constructor to initialize a node with a given value
    BSTNode(int value) : key(value), left(nullptr), right(nullptr), parent(nullptr){}
};

// Define a class for the Binary Search Tree
class BinarySearchTree {
private:
    BSTNode* root;  // Root node of the BST

    // Helper function to insert a value into the BST recursively
    BSTNode* insertMain(BSTNode* node, int value) {
        if (node == nullptr) {
            return new BSTNode(value);  // Create a new node if the current node is null
        }
        else if (value > node->key) {
            node->right = insertMain(node->right, value);  // Insert into the right subtree
            node->right->parent = node;  // Set parent of the new node
        }
        else {
            node->left = insertMain(node->left, value);  // Insert into the left subtree
            node->left->parent = node;  // Set parent of the new node
        }
        return node;
    }

    // Helper function to search for a value in the BST
    bool searchMain(BSTNode* node, int value) {
        if (node == nullptr) {
            return false;  // Value not found
        }
        else if (value == node->key) {
            return true;  // Value found
        }
        else if (value < node->key) {
            return searchMain(node->left, value);  // Search in the left subtree
        }
        else {
            return searchMain(node->right, value);  // Search in the right subtree
        }
    }

    // Helper function to find the minimum value in the BST
    BSTNode* find_minimum_main(BSTNode* node) {
        if (node == nullptr) {
            cout << "No data in the BST" << endl;
            return nullptr;
        }
        if (node->left == nullptr) {
            return node;  // Minimum found
        }
        return find_minimum_main(node->left);  // Go to the leftmost node
    }

    // Helper function to find the maximum value in the BST
    BSTNode* find_maximum_main(BSTNode* node) {
        if (node == nullptr) {
            cout << "No data in the BST" << endl;
            return nullptr;
        }
        if (node->right == nullptr) {
            return node;  // Maximum found
        }
        return find_maximum_main(node->right);  // Go to the rightmost node
    }

    // Helper function to perform in-order traversal of the BST
    void inorder_main(vector<int>& inorder_vector, BSTNode* node) {
        if (node != nullptr) {
            inorder_main(inorder_vector, node->left);
            inorder_vector.push_back(node->key);  // Add current node to in-order vector
            inorder_main(inorder_vector, node->right);
        }
    }

    // Helper function to find the successor of a node in the BST
    BSTNode* find_successor_main(BSTNode* node) {
        if (node->right != nullptr) {
            return find_minimum_main(node->right);  // Successor is the minimum of the right subtree
        }
        while (node->parent != nullptr && node->parent->left != node) {
            node = node->parent;  // Move up until we find the successor
        }
        return node->parent;
    }

    // Helper function to find the predecessor of a node in the BST
    BSTNode* find_predecessor_main(BSTNode* node) {
        if (node->left != nullptr) {
            return find_maximum_main(node->left);  // Predecessor is the maximum of the left subtree
        }
        while (node->parent != nullptr && node->parent->right != node) {
            node = node->parent;  // Move up until we find the predecessor
        }
        return node->parent;
    }

   // Helper function to delete a node from the Binary Search Tree (BST)
void delete_main(BSTNode* node) {
    if (node == nullptr) {
        return;  // Nothing to delete if the node is null
    }

    // Case 1: Node has only a right child or no child
    if (node->left == nullptr) {
        if (node->parent != nullptr) {
            // Update the parent to bypass the node being deleted
            if (node->parent->left == node) {
                node->parent->left = node->right;
            } else {
                node->parent->right = node->right;
            }
        }
        if (node->right != nullptr) {
            // Update the parent pointer of the right child
            node->right->parent = node->parent;
        }
        delete node;  // Free the memory occupied by the node
    } 
    // Case 2: Node has only a left child
    else if (node->right == nullptr) {
        if (node->parent != nullptr) {
            // Update the parent to bypass the node being deleted
            if (node->parent->left == node) {
                node->parent->left = node->left;
            } else {
                node->parent->right = node->left;
            }
        }
        if (node->left != nullptr) {
            // Update the parent pointer of the left child
            node->left->parent = node->parent;
        }
        delete node;  // Free the memory occupied by the node
    } 
    // Case 3: Node has two children
    else {
        // Find the in-order successor of the node (smallest key in the right subtree)
        BSTNode* succ = find_successor_main(node);
        
        // Copy the successor's key to the current node
        node->key = succ->key;

        // Recursively delete the successor node
        delete_main(succ);
    }
}


public:
    // Constructor to initialize an empty BST
    BinarySearchTree() : root(nullptr) {}

    // Public function to insert a key into the BST
    void insert(int key) {
        root = insertMain(root, key);
    }

    // Public function to search for a key in the BST
    bool search(int key) {
        return searchMain(root, key);
    }

    // Public function to find the minimum key in the BST
    int find_minimum() {
        BSTNode* minNode = find_minimum_main(root);
        return minNode->key;
    }

    // Public function to find the maximum key in the BST
    int find_maximum() {
        BSTNode* maxNode = find_maximum_main(root);
        return maxNode->key;
    }

    // Helper function to locate a specific node by its value
    BSTNode* findNode(int value) {
        BSTNode* node = root;
        while (node != nullptr) {
            if (value == node->key) { return node; }
            else if (value > node->key) { node = node->right; }
            else { node = node->left; }
        }
        cout << "This element is not present in the BST." << endl;
        return node;
    }

    // Public function to find the predecessor of a given value
    int find_predecessor(int value) {
        BSTNode* node = findNode(value);
        return find_predecessor_main(node)->key;
    }

    // Public function to find the successor of a given value
    int find_successor(int value) {
        BSTNode* node = findNode(value);
        return find_successor_main(node)->key;
    }

    // Public function to get the in-order traversal of the BST
    vector<int> inorder_traversal() {
        vector<int> inorder_vector;
        inorder_main(inorder_vector, root);
        return inorder_vector;
    }

    // Public function to delete a key from the BST
    void delete_key(int value) {
        BSTNode* node = findNode(value);
        delete_main(node);
    }

    // Public function to find the k-th smallest element in the BST
    int select(int ind) {
        vector<int> inorder_array = inorder_traversal();
        return inorder_array[ind];
    }

    // Helper function to perform binary search in an in-order traversal array
    int binary_search(int num, vector<int> inorder_array) {
        int left = 0;
        int right = inorder_array.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (num == inorder_array[mid]) {
                return mid;  // Element found
            } else if (num > inorder_array[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;  // Element not found
    }

    // Public function to get the rank (position) of a given value in the BST
    int rank(int value) {
        vector<int> inorder_array = inorder_traversal();
        return binary_search(value, inorder_array);
    }
};

int main() {
    BinarySearchTree bst;
    
    // Insert values into the BST
    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    
    // Print in-order traversal of the BST
    cout << "In-order Traversal: ";
    vector<int> inorder = bst.inorder_traversal();
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;
    
    // Find and print minimum and maximum values in the BST
    cout << "Minimum: " << bst.find_minimum() << endl;
    cout << "Maximum: " << bst.find_maximum() << endl;

    // Find the 2nd smallest element and rank of 20
    cout << "Select (2nd smallest): " << bst.select(2) << endl;
    cout << "Rank (of 20): " << bst.rank(20) << endl;

    // Find and print the predecessor and successor of 10
    cout << "Predecessor of 10: " << bst.find_predecessor(10) << endl;
    cout << "Successor of 10: " << bst.find_successor(10) << endl;

    // Delete key 10 from the BST
    bst.delete_key(10);
    cout << "In-order Traversal after deletion: ";
    inorder = bst.inorder_traversal();
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
