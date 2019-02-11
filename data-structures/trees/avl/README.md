MIT 6.006 Introduction to Algorithms, Fall 2011
Lecture 6 Notes
https://www.youtube.com/watch?v=FNeL18KsWPc

AVL Insert:

    1) Simple BST insert
    2) Fix AVL property from changed node up (Look at rotation section)
        a) Suppose x is lowest node violating AVL
        b) Assume right(x) higher (x.right)
        c) If: x's right child is right-heavy or balanced
            - update height
        d) else: 
        
AVL Rotations:

    1) Left Rotations:
        a) Rotates the root to the left
![altText](https://raw.githubusercontent.com/NamanhTran/data-structures/master/etc/pictures/RotateL.PNG)

    2) Right Rotations:
        a) Rotates the root to the right
![altText](https://raw.githubusercontent.com/NamanhTran/data-structures/master/etc/pictures/RotateR.PNG)

    3) Double Rotations:
        a) Case for zig-zags in tree
        b) Two Rotations
        c) Can be Left Rotation then Right Rotations or Right Rotation then Left Rotation
        d) Want to rotate one node down
![altText](https://raw.githubusercontent.com/NamanhTran/data-structures/master/etc/pictures/RotateLR.PNG)

AVL Sort:

    a) Insert n items - Big-Theta(nlog(n))
    b) In-order traversal - Big-Theta(n)

Implementation:

    a) Abstract Data Type:
        - Priority Queue
            - insert & delete
            - min
        - Successor/Predcessor

    b) Data Structure
        - Implement priority queue using Heap data structure
