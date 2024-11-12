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
