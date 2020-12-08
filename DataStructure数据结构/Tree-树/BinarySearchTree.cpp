/*
Binary search tree:
In computer science, a binary search tree (BST), also called an ordered or sorted binary tree, 
is a rooted binary tree whose internal nodes each store a key greater than all the keys in the 
node's left subtree and less than those in its right subtree.
A binary tree is a type of data structure for storing data such as numbers in an organized way. 
Binary search trees allow binary search for fast lookup,
addition and removal of data items, and can be used to implement dynamic sets and lookup tables.
The order of nodes in a BST means that each comparison skips about half of the remaining tree,
so the whole lookup takes time proportional to the binary logarithm of the number of items stored in the tree. 
This is much better than the linear time required to find items by key in an (unsorted) array,
but slower than the corresponding operations on hash tables. Several variants of the binary search tree have been studied.
*/
#include<iostream>
#include<algorithm>
#include <string>

using namespace std;

//TreeNode
struct TreeNode
{
	//member vars
	int data;
	TreeNode *lchild, *rchild;

	//constructor
	TreeNode(int data) : data(data), lchild(nullptr), rchild(nullptr){}
};


class BSTree
{
public:
	// constructors
	BSTree() : root(nullptr) {}
	BSTree(TreeNode* rootNode) : root(rootNode) {}

	// member functions
	void Print();
	void Insert(int val);
	bool Contains(int val);
	void Remove(int val);

private:
	TreeNode* root;
	string SubTreeAsString(TreeNode* node);  // Helper method for Print()

	//void Insert(int val, TreeNode* node); // Helper method for Insert(int val)
	//  change Insert(int val, TreeNode* node) to Insert(int val, TreeNode*& node), passing each node pointer as a reference instead of a copy.
	void Insert(int val, TreeNode*& node); 
	
	bool Contains(int val, TreeNode*& node); // Helper method for Contains(int val)
	void Remove(int val, TreeNode*& node);  // Helper method for Remove(int val)
	TreeNode*& FindMin(TreeNode*& node); // Helper method for Remove(int val)
};


/// Print the tree
void BSTree::Print() {
	if (this->root == nullptr) {
		std::cout << "{}" << std::endl;
	}
	else {
		std::cout << this->SubTreeAsString(this->root) << std::endl;
	}
}
/*
Notes:
Here we represent each node as a set of three elements, {data, leftChild, rightChild} with empty trees represented as {}.
We use a private helper method SubTreeAsString(TreeNode* node) that recursively pieces together a string \
representation of the current node¡¯s data and string representations of it¡¯s children¡¯s data.
*/
string BSTree::SubTreeAsString(TreeNode* node)
{
	string leftstr = (node->lchild == nullptr) ? "{}" : SubTreeAsString(node->lchild);
	string rightstr = (node->rchild == nullptr) ? "{}" : SubTreeAsString(node->rchild);

	string result = "{" + std::to_string(node->data) + ", " + leftstr + ", " + rightstr + "}";
	return result;
}


/// Insert a new value into the tree
void BSTree::Insert(int val)
{
	this->Insert(val, this->root);
}
void BSTree::Insert(int val, TreeNode*& node)
{
	if (node == nullptr) {
		// Case: node is a nullptr
	   // Make a new TreeNode for it to point to
		node = new TreeNode(val);
	}
	else
	{
		if (val < node->data) {
			// Case: val is < node's data
			Insert(val, node->lchild);
		}
		else if (val > node->data)
		{
			//Case:val is > node's data
			Insert(val, node->rchild);
		}
		else
		{
			// Case: val is equal to node's data
			std::cout << "Warning: Value already exists, so nothing will be done." << std::endl;
		}
	}
}

/// Check if the given value exists in the BSTree
bool BSTree::Contains(int val) {
	return Contains(val, this->root);
}
/// Check if the given value exists in the subtree
/// starting at node
bool BSTree::Contains(int val, TreeNode*& node) {
	if (node == nullptr) {
		return false;
	}
	else if (val == node->data) {
		return true;
	}
	else if (val < node->data) {
		return this->Contains(val, node->lchild);
	}
	else {
		return this->Contains(val, node->rchild);
	}
}

/// Remove given value from the tree
void BSTree::Remove(int val) {
	this->Remove(val, this->root);
}
/*Now lets implement Remove(int val) for removing a single node from a tree.
In determinig the logic for removing a node, we need to consider five cases.

	1.val doesn¡¯t exist
		We notify the userand then do nothing.
	2.val exists at a leaf node
		We delete the node.
	3.val exists at a node with a left child but not a right child
		We make the node¡¯s parent point at the node¡¯s left childand then delete the node.
	4.val exists at a node with a right child but not a left child
		We make the node¡¯s parent point at the node¡¯s right childand then delete the node.
	5.val exists at a node with leftand right children
		This is the tricky case, but the solution is elegantly simple.
		We replace the node¡¯s value with the minimum value in its right subtree.
		Then we delete that node(i.e the min - value node from the right subtree we just found).
		Convince yourself that the resulting tree is still a valid Binary Search Tree.
		(Note that there are other solutions to this problem.)*/
void BSTree::Remove(int val, TreeNode*& node)
{
	if (node == nullptr) {
		cout << "val doesn¡¯t exist" << endl;
	}
	else if (node->data == val) {
		//Found val
		TreeNode* trash = nullptr;
	
		if (node->lchild == nullptr && node->rchild == nullptr) {
			//val exists at a leaf node
			trash = node;
			node = nullptr;
		}
		else if (node->lchild!=nullptr && node->rchild==nullptr) {
			//val exists at a node with a left child but not a right child
			// Point node's parent at node's left subtree
			trash = node;
			node = node->lchild;
		}
		else if (node->lchild==nullptr&&node->rchild!=nullptr) {
			//val exists at a node with a right child but not a left child
			trash = node;
			node = node->rchild;
		}
		else if (node->lchild!=nullptr&&node->rchild!=nullptr)
		{
			// Case: node has left and right subtrees
			TreeNode*& minNode = this->FindMin(node->rchild); // returns a reference to the pointer in the tree
			node->data = minNode->data;
			this->Remove(minNode->data, minNode);
		}
		// Free memory
		if (trash != nullptr) delete trash;
	}
	else if (node->data > val)
	{
		Remove(val, node->lchild);
	}
	else
	{
		Remove(val, node->rchild);
	}
}
/// Search the subtree starting at node and return a pointer to the minimum-value node
/// The returned pointer will be a reference of an actual pointer in the tree, not a copy
TreeNode*& BSTree::FindMin(TreeNode*& node) {
	if (node == nullptr) {
		throw "Min value not found";
	}
	else if (node->lchild == nullptr) {
		return node;
	}
	else {
		return this->FindMin(node->lchild);
	}
}


int main(void)
{

	// Make the tree
	//    5
	//   / \
	//  4   6

	// Make the nodes
	TreeNode root(5);
	TreeNode leftChild(4);
	TreeNode rightChild(6);

	// Connect nodes
	root.lchild = &leftChild;
	root.rchild = &rightChild;


	// Print info about the root
	//std::cout << root.data << " " << root.lchild->data << " " << root.rchild->data << endl;
	//{5, {4, {}, {}}, {6, {}, {}}}
	// Make and print the tree
	BSTree myTree{ &root };
	myTree.Print();
	cout << "------------Insert----------------" << endl;

	BSTree myTree2{};

	myTree2.Insert(5);
	myTree2.Insert(4);
	myTree2.Insert(6);
	myTree2.Insert(10);
	myTree2.Insert(12);
	myTree2.Insert(13);
	myTree2.Insert(15);
	myTree2.Insert(20);
	myTree2.Print();
	std::cout << std::boolalpha << myTree.Contains(4) << std::endl;
	std::cout << std::boolalpha << myTree.Contains(2) << std::endl;

	cout << "------------Remove----------------" << endl;
	myTree2.Remove(8);
	myTree2.Print();
	myTree2.Remove(6);
	myTree2.Print();







	return 0;
}