#include <stdio.h>
#include <stdlib.h>

typedef struct binaryTree_s {
	int data;
	struct binaryTree_s *left;
	struct binaryTree_s *right;
} binaryTree;


binaryTree *createNode(int data) {
	binaryTree *newNode = (binaryTree *)malloc(sizeof(binaryTree));
	if (newNode == NULL) {
		printf("Malloc returned NULL\n");
		exit(1);
	}
	newNode->data  = data;
	newNode->left  = NULL;
	newNode->right = NULL;
	return newNode;
}

void push(binaryTree **tree, int data) {
	binaryTree *tmp = *tree;
	if (tmp == NULL) {
		*tree = newNode;
	}
	else if (data < tmp->data) {
		if (tmp->left == NULL) {
			tmp->left = createNode(data);
		}
		else {
			push(&(tmp->left), data);
		}
	}
	else if (data > tmp->data) {
		if (tmp->right == NULL) {
			tmp->right = createNode(data);
		}
		else {
			push(&(tmp->right), data);
		}
	}
}

// рекурсивный обход в глубину
void printInDepthRecursively(binaryTree *tree) {
	if (tree == NULL) {
		return;
	}
	else {
		printf("%d ", tree->data);
		if (tree->left != NULL) {
			printInDepthRecursively(tree->left);
		}
		if (tree->right != NULL) {
			printInDepthRecursively(tree->right);
		}
	}
}

// Итеративный обход в глубину. Using C++ std container #include <vector>
// void printInDepthIteratively(binaryTree *root) {
// 	if (root == NULL) {
// 		return;
// 	}
// 	binaryTree *node = root;
// 	vector<binaryTree *> stack;
// 	stack.push_back(node);

// 	while(stack.empty() == false) {
// 		node = stack.back();
// 		std::cout << node->data << std::endl;
// 		stack.pop_back();
// 		if (node->right != NULL) {
// 			stack.push_back(node->right);
// 		}
// 		if (node->left != NULL) {
// 			stack.push_back(node->left);
// 		}
// 	}
// }

// Итеративный обход в ширину. Using C++ std container #include <queue>
// void printInWidthIteratively(binaryTree *root) {
// 	queue<binaryTree *> q;
// 	if (root != NULL) {
// 		q.push(root);
// 	}
// 	while(q.empty() == false) {
// 		binaryTree *node = q.front();
// 		q.pop();
// 		std::cout << node->data << std::endl;
// 		if (node->left != NULL) {
// 			q.push(node->left);
// 		}
// 		if (node->right != NULL) {
// 			q.push(node->right);
// 		}
// 	}
// }

// Рекурсивный обход в ширину. Using C++ std container #include <queue>
// void printInWidthRecursively(queue<binaryTree *> q) {
// 	if (q.empty() == false) {
// 		binaryTree *node = q.front();
// 		q.pop();
// 		std::cout << node->data << std::endl;
// 		if (node->left != NULL) {
// 			q.push(node->left);
// 		}
// 		if (node->right != NULL) {
// 			q.push(node->right);
// 		}
// 		printInWidthRecursively(q);
// 	}
// }

void printSorted(binaryTree *root) {
	if (root != NULL) { 
		printSorted(root->left); 
		printf("%d ",root->data);
		printSorted(root->right); 
	}
}

int main() {
	binaryTree *tree = NULL;
	push(&tree, 5);
	push(&tree, 7);
	push(&tree, 3);
	push(&tree, 4);
	push(&tree, 6);
	push(&tree, 2);
	push(&tree, 1);
	printSorted(tree);
	printf("\n");
}










