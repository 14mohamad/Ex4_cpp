# Tree Container
# ’Tree Visualization with Qt’
# ’המחשת עצים ב-Qt’
## Overview

This project implements a generic k-ary tree container in C++. A k-ary tree is a tree in which each node has at most k children. By default, the tree is a binary tree (k=2).

## Features

- Generic container supporting keys of any type (e.g., numbers, strings, classes).
- Supports various traversal methods:
  - Pre-Order
  - Post-Order
  - In-Order
  - BFS (Breadth-First Search)
  - DFS (Depth-First Search)
- Custom iterator implementation for each traversal method.
- Function to transform a binary tree into a minimum heap (not fully implemented).
- Destructor to delete the entire tree.
- Print function to display the tree structure.

## Usage

### Building

To build the project, run the following command:

```bash
make
```
