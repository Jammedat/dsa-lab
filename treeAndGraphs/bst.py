class Node:
    """A node in the Binary Search Tree"""
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BST:
    """Binary Search Tree class"""
    def __init__(self):
        self.root = None

    def insert(self, key):
        """Insert a node into the BST"""
        self.root = self._insert_recursive(self.root, key)

    def _insert_recursive(self, node, key):
        """Helper function to insert recursively"""
        if node is None:
            return Node(key)
        
        if key < node.key:
            node.left = self._insert_recursive(node.left, key)
        elif key > node.key:
            node.right = self._insert_recursive(node.right, key)
        
        return node

    def search(self, key):
        """Search for a key in the BST"""
        return self._search_recursive(self.root, key)

    def _search_recursive(self, node, key):
        """Helper function to search recursively"""
        if node is None or node.key == key:
            return node
        
        if key < node.key:
            return self._search_recursive(node.left, key)
        return self._search_recursive(node.right, key)

    def inorder_traversal(self):
        """Inorder traversal of the BST"""
        result = []
        self._inorder_recursive(self.root, result)
        return result

    def _inorder_recursive(self, node, result):
        """Helper function for inorder traversal"""
        if node:
            self._inorder_recursive(node.left, result)
            result.append(node.key)
            self._inorder_recursive(node.right, result)

# Example Usage
bst = BST()
values = [50, 30, 70, 20, 40, 60, 80]
for v in values:
    bst.insert(v)

print("Inorder Traversal:", bst.inorder_traversal())  # Sorted output
print("Search for 40:", "Found" if bst.search(40) else "Not Found")
print("Search for 90:", "Found" if bst.search(90) else "Not Found")
