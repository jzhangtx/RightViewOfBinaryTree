Right View of Binary Tree (Pleae refer to the docx version of README for better understanding)


There are different ways to look at a binary tree. The right view of a binary tree contains the set of nodes that will be visible if you look at the binary tree from the right side.

Given the root node of a binary tree, return an array containing the node elements in the right view, from top to bottom.

right-view-binary-tree
Testing
Input Format
The first line contains an integer T denoting the number of test cases.

For each test case, the input has 2 lines:

The first line contains an integer n denoting the number of nodes in the tree (including the NULL nodes).
The second line contains n space-separated integers that will form the binary tree. The integers follow level order traversal of the tree where -1 indicates a NULL node.
Output Format
For each test case, the output contains a line with space-separated integers representing the right view of the binary tree.

Sample Input
6
7
1 2 -1 4 -1 5 6
3
6 -1 4
7
8 -1 9 -1 10 11 12
5
28 14 11 -1 48
1
6
7
3 -1 2 1 5 -1 6
Expected Output
1 2 4 6
6 4
8 9 10 12
28 11 48
6
3 2 5 6