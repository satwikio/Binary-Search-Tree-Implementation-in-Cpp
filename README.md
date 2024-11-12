# Binary Search Tree (BST) Implementation in C++

This project provides a comprehensive C++ implementation of a Binary Search Tree (BST), a fundamental data structure in computer science. A BST is a binary tree where each node has a key greater than all keys in its left subtree and less than all keys in its right subtree. This BST implementation includes basic operations like insertion, deletion, and searching, as well as additional functionalities like in-order traversal, finding predecessors/successors, and rank and selection of elements.

## Table of Contents
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation and Execution](#compilation-and-execution)
- [Usage](#usage)
  - [Sample Output](#sample-output)
- [Code Structure](#code-structure)
- [Class and Function Descriptions](#class-and-function-descriptions)
- [Example Usage](#example-usage)
- [License](#license)

## Features

This Binary Search Tree implementation provides the following functionalities:
- **Insertion**: Insert a new value into the BST, maintaining the BST property.
- **Search**: Check if a value exists in the BST.
- **Minimum and Maximum**: Retrieve the minimum and maximum values in the BST.
- **In-order Traversal**: Obtain a sorted list of values by traversing the tree in order.
- **Predecessor and Successor**: Find the predecessor or successor of a specific value in the BST.
- **Deletion**: Remove a node from the BST, adjusting pointers to maintain structure.
- **Selection**: Retrieve the k-th smallest element in the BST.
- **Rank**: Determine the rank (position in sorted order) of a specified value.

## Getting Started

### Prerequisites

To compile and run this code, you need:
- A C++ compiler that supports C++11 or higher, such as `g++`.

### Compilation and Execution

1. **Clone this repository**:
    ```bash
    git clone https://github.com/your-username/bst-cpp.git
    cd bst-cpp
    ```

2. **Compile the code**:
    ```bash
    g++ main.cpp -o bst
    ```

3. **Run the compiled executable**:
    ```bash
    ./bst
    ```

## Usage

### Sample Output

Below is an example output for the operations provided in the `main` function:

```plaintext
In-order Traversal: 5 10 20
Minimum: 5
Maximum: 20
Select (2nd smallest): 20
Rank (of 20): 2
Predecessor of 10: 5
Successor of 10: 20
In-order Traversal after deletion: 5 20
```

##Code Structure

The project is structured into two main components:

-**BSTNode Struct:** Defines the structure of each node in the BST, holding a key and pointers to left, right, and parent.
-**BinarySearchTree Class:** Contains methods for inserting, searching, deleting, and managing the BST, along with helper methods for additional functionality.

##Class and Function Descriptions

###BSTNode Structure

-Represents a node in the BST.
-Holds the key, pointers to left and right children, and a parent pointer for efficient upward traversal.

##BinarySearchTree Class

-**void insert(int key):** Inserts a new key into the BST.
-**bool search(int key):** Searches for a key and returns true if found, false otherwise.
-**int find_minimum():** Returns the minimum value in the BST.
-**int find_maximum():** Returns the maximum value in the BST.
-**vector<int> inorder_traversal():** Returns a vector containing the in-order traversal of the BST.
-**int find_predecessor(int value):** Finds and returns the predecessor of a specified value.
-**int find_successor(int value):** Finds and returns the successor of a specified value.
-**void delete_key(int value):** Deletes a node with the specified key.
-**int select(int ind):** Returns the k-th smallest element in the BST.
-**int rank(int value):** Finds the rank of a specified value.

##Example Usage

The following example demonstrates how to use the BinarySearchTree class to perform various operations on the BST.

```cpp
#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree bst;
    
    // Insert values into the BST
    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    
    // Print in-order traversal of the BST
    std::cout << "In-order Traversal: ";
    for (int val : bst.inorder_traversal()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    // Find and print minimum and maximum values
    std::cout << "Minimum: " << bst.find_minimum() << std::endl;
    std::cout << "Maximum: " << bst.find_maximum() << std::endl;

    // Retrieve the 2nd smallest element and rank of 20
    std::cout << "Select (2nd smallest): " << bst.select(2) << std::endl;
    std::cout << "Rank (of 20): " << bst.rank(20) << std::endl;

    // Find predecessor and successor of 10
    std::cout << "Predecessor of 10: " << bst.find_predecessor(10) << std::endl;
    std::cout << "Successor of 10: " << bst.find_successor(10) << std::endl;

    // Delete a key from the BST and print the updated traversal
    bst.delete_key(10);
    std::cout << "In-order Traversal after deletion: ";
    for (int val : bst.inorder_traversal()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```
