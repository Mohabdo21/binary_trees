# 0x1D. C - Binary Trees

This project is part of the Alx - SE curriculum of software engineering. The main objective is to understand and implement the concepts of binary trees in C.

## Authors

- Mohamed Elfadil Ali
- Mohannad Babeker

## Learning Objectives

- Understand what a binary tree is.
- Learn the difference between a binary tree and a Binary Search Tree (BST).
- Understand the potential time complexity advantages of binary trees compared to linked lists.
- Learn about the depth, height, and size of a binary tree.
- Understand the different traversal methods to navigate through a binary tree.
- Learn what complete, full, perfect, and balanced binary trees are.

## Project Overview

The project is divided into several sections, each focusing on a different type of tree and the operations that can be performed on them.

### Binary Trees

- Node creation, insertion, and deletion
- Leaf and root identification
- Traversal methods: pre-order, in-order, post-order
- Measurement of height, depth, size, and balance factor
- Identification of full or perfect binary trees
- Sibling and uncle identification

### Binary Search Trees (BST)

- Validation of BST
- Value insertion
- BST construction from an array
- Value search
- Node removal

### AVL Trees

- Validation of AVL Tree
- Value insertion
- AVL tree construction from an array
- Node removal
- AVL tree construction from a sorted array

### Binary Heaps

- Validation of Max Binary Heap
- Value insertion
- Max Binary Heap construction from an array
- Root node extraction
- Conversion of Binary Max Heap to a sorted array of integers

## Time and Space Complexity Analysis of Binary Tree Operations

| Operation                    | Best Case | Average Case | Worst Case |
| ---------------------------- | :-------: | :----------: | :--------: |
| **Binary Tree**              |           |              |            |
| Insertion                    | O(1)      | O(log n)     | O(n)       |
| Deletion                     | O(1)      | O(log n)     | O(n)       |
| Search                       | O(1)      | O(log n)     | O(n)       |
| **Binary Search Tree (BST)** |           |              |            |
| Insertion                    | O(log n)  | O(log n)     | O(n)       |
| Deletion                     | O(log n)  | O(log n)     | O(n)       |
| Search                       | O(log n)  | O(log n)     | O(n)       |
| **AVL Tree**                 |           |              |            |
| Insertion                    | O(log n)  | O(log n)     | O(log n)   |
| Deletion                     | O(log n)  | O(log n)     | O(log n)   |
| Search                       | O(log n)  | O(log n)     | O(log n)   |
| **Binary Heap**              |           |              |            |
| Insertion                    | O(1)      | O(log n)     | O(log n)   |
| Deletion                     | O(log n)  | O(log n)     | O(log n)   |
| Search                       | O(1)      | O(n)         | O(n)       |

## Additional Resources

- `binary_tree_print.c`: A utility function for printing a binary tree.
- `binary_trees.h`: The header file containing the function prototypes and the necessary structures for building a binary tree.

## Note

For more details and usage examples, please refer to the individual files.
