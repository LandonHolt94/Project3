#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	node* Left_link;
	node* Right_link;
};
node* root;
class IntBinaryTree
{
public:
	IntBinaryTree()
	{
		root = NULL;
	}
public:
	node* insert2(node* temp, node* newnode)
	{
		if (temp == NULL)
		{
			temp = newnode;
		}
		else if (temp->data < newnode->data)
		{
			insert2(temp->Right_link, newnode);
			if (temp->Right_link == NULL)
				temp->Right_link = newnode;
		}
		else
		{
			insert2(temp->Left_link, newnode);
			if (temp->Left_link == NULL)
				temp->Left_link = newnode;
		}
		return temp;
	}
public:
	void insert1(int n)
	{
		node* temp = root;
		node* newnode;
		newnode = new node;
		newnode->Left_link = NULL;
		newnode->Right_link = NULL;
		newnode->data = n;
		root = insert2(temp, newnode);
	}
public:
	int LeafCount(struct node* node = root)
	{
		if (node == NULL)
			return 0;
		if (node->Left_link == NULL && node->Right_link == NULL)
			return 1;
		else
			return LeafCount(node->Left_link) + LeafCount(node->Right_link);
	}
public:
	int TreeHeight(struct node* node = root)
	{
		if (node == NULL)
			return 0;
		else
		{
			int lDepth = TreeHeight(node->Left_link);
			int rDepth = TreeHeight(node->Right_link);
			if (lDepth > rDepth)
				return(lDepth + 1);
			else
				return(rDepth + 1);
		}
	}
public:
	int TreeWidth(struct node* root, int level)
	{
		if (root == NULL)
			return 0;
		if (level == 1)
			return 1;
		else if (level > 1)
			return TreeWidth(root->Left_link, level - 1) + TreeWidth(root->Right_link, level - 1);
	}
public:
	void inorder_traversal(node* t = root)
	{
		if (root == NULL)
		{
			cout << "The Tree is Empty" << endl;
		}
		else if (t != NULL)
		{
			inorder_traversal(t->Left_link);
			cout << t->data << "->";
			inorder_traversal(t->Right_link);
		}
	}
};
int main()
{
	IntBinaryTree obj;
	int opt, opt2, n, key;
	while (1)
	{
		cout << "\nImplementation of Binary Tree" << endl;
		cout << "\n-------------------------------" << endl;
		cout << "\n1. Insert numbers (validate for numeric):" << endl;
		cout << "\n2. Display the tree (in order)" << endl;
		cout << "\n3. Display Leaf Count" << endl;
		cout << "\n4. Display Tree Height" << endl;
		cout << "\n5. Display Tree Width" << endl;
		cout << "\n6. -Exit" << endl;
		cout << "Enter your Option " << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "Enter The Node" << endl;
			cin >> n;
			obj.insert1(n);
			break;
		case 2:
			cout << "\n------------------------------------------" << endl;
			cout << "\nDisplay Elemnts using Inorder Treversal" << endl;
			cout << "\n------------------------------------------" << endl;
			obj.inorder_traversal();
			break;
		case 3:
			cout << "\nLeaf count of the tree is:" << obj.LeafCount() << endl;
			break;
		case 4:
			cout << "\nThe Height of the Tree is: " << obj.TreeHeight() << endl;
			break;
		case 5:
			cout << "\nThe Width of the Tree is: " << obj.TreeWidth(root, 2);
			break;
		case 6:
			exit(0);
		default:
			cout << "Invalid Choice!Please Select Correct One" << endl;
		}
	}
	return 0;
}