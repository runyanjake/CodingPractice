#@author Jake Runyan
#@desc BST data structure

import sys

class Node(object):
    data = None
    left = None
    right = None
    def __init__(self, d):
        self.data = d
    def __str__(self):
        strin = "Node " + str(self.data) + " Left: "
        if self.left:
            strin = strin + str(self.left.data)
        else:
            strin = strin + "None"
        strin = strin + " Right: "
        if self.right:
            strin = strin + str(self.right.data)
        else:
            strin = strin + "None"
        return strin 

class BSTException(Exception):
    pass
    
#height balanced BST, no duplicates allowed
class BST(object):
    root = None
    def __init__(self):
        self.root = None

    def printall(self):
        print("BST with root: " + str(self.root.data))
        self.__printall(self.root)
        sys.stdout.write("\n")

    def __printall(self, root):
        if not(root is None):
            self.__printall(root.left)
            sys.stdout.write("Node " + str(root.data))
            if root.left is None:
                sys.stdout.write("\tLeft: None\n")
            else:
                sys.stdout.write("\tLeft: " + str(root.left.data) + "\n")
            if root.right is None:
                sys.stdout.write("\tRight: None\n")
            else:
                sys.stdout.write("\tRight: " + str(root.right.data) + "\n")
            self.__printall(root.right)
        
    #Parent stays constant, is parent of subtree we rotate about
    #node is updated to hold the new value of the node. (the child of parent)
    #returns the old node in its new location, so can be recursively sorted
    def leftrotation(self, node, parent):
        ret = None
        if parent is None: #at root
            tmp = node.right
            node.right = node.right.left
            tmp.left = node
            ret = tmp.left #moved node to be returned 
            node = tmp #update node with new switched value.
            #parent stays consistent
        elif parent.left == node: 
            parent.left = node.right
            node.right = node.right.left
            parent.left.left = node
            node = parent.left #update node with new switched value
            ret = parent.left.left #moved node to be returned
            #parent stays consistent
        else: #parent.right == node:
            parent.right = node.right
            node.right = node.right.left
            parent.right.left = node
            node = parent.right #update node with new switched value
            ret = parent.right.left #moved node to be returned
            #parent stays consistent
        return (ret,node,parent)

    def rightrotation(self, node, parent):
        ret = None
        if parent is None: #at root
            tmp = node.left
            node.left = node.left.right
            tmp.right = node
            ret = tmp.right #moved node to be returned 
            node = tmp #update node with new switched value.
            #parent stays consistent
        elif parent.right == node: 
            parent.right = node.left
            node.left = node.left.right
            parent.right.right = node
            node = parent.right #update node with new switched value
            ret = parent.right.right #moved node to be returned
            #parent stays consistent
        else: #parent.left == node:
            parent.left = node.left
            node.left = node.left.right
            parent.left.right = node
            node = parent.left #update node with new switched value
            ret = parent.left.right #moved node to be returned
            #parent stays consistent
        return (ret,node,parent)

    def balance(self):
        if self.root == None:
            return
        while abs(self.__height(self.root.left) - self.__height(self.root.right)) > 1:
            self.__balance(self.root, None)

    def __balance(self, root, parent):
        if root is None:
            return
        self.__balance(root.left, root)
        self.__balance(root.right, root)
        left = self.__height(root.left)
        right = self.__height(root.right)
        if(abs(left-right) > 1):
            if left < right: #desire move left
                (new_subtree, updated_root, parent) = self.leftrotation(root,parent)
                if root == self.root:
                    self.root = updated_root
                else:
                    root = updated_root
                print("AFTER LEFTSHIFT AROUND " + str(new_subtree.data) + ", BEFORE REBALANCING:")
                self.printall()
                self.__balance(new_subtree, updated_root)
                print("AFTER LEFTSHIFT AROUND " + str(new_subtree.data) + ", AFTER REBALANCING:")
                self.printall()
            else: #desire move right
                (new_subtree, updated_root, parent) = self.rightrotation(root,parent)
                if root == self.root:
                    self.root = updated_root
                else:
                    root = updated_root
                print("AFTER RIGHTSHIFT AROUND " + str(new_subtree.data) + ", BEFORE REBALANCING:")
                self.printall()
                self.__balance(new_subtree, updated_root)
                print("AFTER RIGHTSHIFT AROUND " + str(new_subtree.data) + ", AFTER REBALANCING:")
                self.printall()
        else:
            #bubble up recursion once balanced
            pass

    def insert(self, data):
        print("insert " + str(data))
        self.__insert(self.root, data)

    def __insert(self, root, data):
        if data is None:
            raise BSTException("BST.insert(): null data.")
        if self.root == None:
            self.root = Node(data)
        else:
            if data == root.data:
                raise BSTException("BST.insert(): value exists in BST already.")
            elif data > root.data:
                if root.right is None:
                    root.right = Node(data)
                else:
                    self.__insert(root.right,data)
            else: #data < root.data
                if root.left is None:
                    root.left = Node(data)
                else:
                    self.__insert(root.left,data)

    def delete(self, target):
        self.__delete(self.root, None, target)
        self.balance()
    
    def __delete(self, node, parent, target):
        if node is None:
            return
        if node.data == target:
            if parent is None: #deleting root
                if node.right is None:
                    self.root = node.right
                else:
                    newroot = self.root.right
                    newleft = self.root.left
                    overflow = newroot.left
                    if newleft is None:
                        newleft = overflow
                    else:
                        tmp = newleft
                        while tmp.right is not None:
                            tmp = tmp.right
                        tmp.right = overflow
                    self.root = newroot
                    self.root.left = newleft
            else:
                if node.right is None:
                    if parent.left == node:
                        parent.left = node.left
                    else:
                        parent.right = node.left
                else:
                    if parent.left == node:
                        newroot = parent.left.right
                        newleft = parent.left.left
                        overflow = newroot.left
                        if newleft is None:
                            newleft = overflow
                        else:
                            tmp = newleft
                            while tmp.right is not None:
                                tmp = tmp.right
                            tmp.right = overflow
                        parent.left = newroot
                        parent.left.left = newleft
                    else:
                        newroot = parent.right.right
                        newleft = parent.right.left
                        overflow = newroot.left
                        if newleft is None:
                            newleft = overflow
                        else:
                            tmp = newleft
                            while tmp.right is not None:
                                tmp = tmp.right
                            tmp.right = overflow
                        parent.right = newroot
                        parent.right.left = newleft
        elif node.data > target:
            self.__delete(node.left, node, target)
        else: #node.data < target
            self.__delete(node.right, node, target)

    def inorder(self):
        self.__inorder(self.root)
        sys.stdout.write("\n")

    def __inorder(self, root):
        if not(root is None):
            self.__inorder(root.left)
            sys.stdout.write(str(root.data) + " ")
            self.__inorder(root.right)

    def preorder(self):
        self.__preorder(self.root)
        sys.stdout.write("\n")
        
    def __preorder(self, root):
        if not(root is None):
            sys.stdout.write(str(root.data) + " ")
            self.__preorder(root.left)
            self.__preorder(root.right)

    def postorder(self):
        self.__postorder(self.root)
        sys.stdout.write("\n")

    def __postorder(self, root):
        if not(root is None):
            self.__postorder(root.left)
            self.__postorder(root.right)
            sys.stdout.write(str(root.data) + " ")

    def height(self):
        return self.__height(self.root)

    def __height(self, root):
        if root is None:
            return 0
        return max(self.__height(root.left), self.__height(root.right)) + 1

    def search(self, data):
        return self.__search(self.root, data)

    def __search(self, node, data):
        if node is None:
            return False
        if node.data == data:
            return True
        elif node.data < data:
            return self.__search(node.right, data)
        else: #node.data > data
            return self.__search(node.left, data)

if __name__ == "__main__":
    bst = BST()
    #create 1-6 tree with inserts
    bst.insert(1)
    bst.insert(2)
    bst.insert(3)
    bst.insert(4)
    bst.insert(5)
    bst.insert(6)
    bst.insert(7)
    bst.insert(8)
    bst.insert(9)
    bst.insert(10)
    bst.insert(11)
    bst.insert(12)
    bst.insert(13)
    bst.insert(14)

    bst.delete(7)

    bst.inorder()
    bst.printall()

    print(bst.search(1))
    
    #test left and right rotation
    # n1 = Node(1)
    # n2 = Node(2)
    # n3 = Node(3)
    # n4 = Node(4)
    # n5 = Node(5)
    # n6 = Node(6)
    # n7 = Node(7)
    # n8 = Node(8)
    # n9 = Node(9)
    # n10 = Node(10)
    # n11 = Node(11)
    # n12 = Node(12)
    # n13 = Node(13)
    # n14 = Node(14)
    # n1.right = n2
    # n2.right = n3
    # n3.right = n4
    # n4.right = n5
    # n5.right = n6
    # n6.right = n7
    # n7.right = n8
    # n8.right = n9
    # n9.right = n10
    # n10.right = n11
    # n11.right = n12
    # n12.right = n13
    # n13.right = n14
    
    # bst.root = n1
    # print("BEFORE Function")
    # bst.inorder()
    # bst.preorder()
    # bst.printall()
    # print("\n\n\n")

    # bst.balance()

    # print("\n\n\nAFTER Function")
    # bst.inorder()
    # bst.preorder()
    # bst.printall()

    # bst.inorder()
    # bst.preorder()
    # bst.postorder()