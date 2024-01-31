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

**Binary Trees:**

- Creation, insertion, and deletion of nodes
- Checking if a node is a leaf or a root
- Different traversal methods (pre-order, in-order, post-order)
- Measuring the height, depth, size, and balance factor of a binary tree
- Checking if a binary tree is full or perfect
- Finding the sibling or uncle of a node

**Binary Search Trees (BST):**

- Checking if a binary tree is a valid BST
- Inserting a value in a BST
- Building a BST from an array
- Searching for a value in a BST
- Removing a node from a BST

**AVL Trees:**

- Checking if a binary tree is a valid AVL Tree
- Inserting a value in an AVL Tree
- Building an AVL tree from an array
- Removing a node from an AVL tree
- Building an AVL tree from a sorted array

**Binary Heaps:**

- Checking if a binary tree is a valid Max Binary Heap
- Inserting a value in Max Binary Heap
- Building a Max Binary Heap tree from an array
- Extracting the root node of a Max Binary Heap
- Converting a Binary Max Heap to a sorted array of integers

| Operation                    | Best Case | Average Case | Worst Case |
| ---------------------------- | --------- | ------------ | ---------- |
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

## Additional Files

- `binary_tree_print.c`: Function to print a binary tree.
- `binary_trees.h`: Header file containing the prototypes of all functions and the structures to build a binary tree.

## Note

Please refer to individual files for more details.
