#include <iostream>
#include <queue>

using namespace std;

struct BST {
    int data;
    BST *left, *right;
};

BST * getNewNode(int data)
{
    BST *newNode = new BST();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BST * insertData(BST *root, int data){
    if(root == NULL)
        root = getNewNode(data);
    else if(data <= root->data)
        root->left = insertData(root->left, data);
    else if(data > root->data)
        root->right = insertData(root->right, data);
    return root;
}
BST* FindMin(BST *root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
// Function to search a delete a value from tree.
BST* deleteData(BST *root, int data) {
	if(root == NULL) return root;
	else if(data < root->data)
        root->left = deleteData(root->left,data);
	else if (data > root->data)
        root->right = deleteData(root->right,data);
	// Wohoo... I found you, Get ready to be deleted
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child
		else if(root->left == NULL) {
			BST *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			BST *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			BST *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = deleteData(root->right,temp->data);
		}
	}
	return root;
}

bool searchData(BST *root, int data)
{
    if(root == NULL)
        return false;
    if(root->data == data)
        return true;
    if(data <= root->data)
        searchData(root->left, data);
    else searchData(root->right, data);
}
int findMin(BST *root)
{
    if(root == NULL)
        return 1;
    if(root->left == NULL)
        return root->data;
    return findMin(root->left);
}
int findMax(BST *root)
{
    if(root == NULL)
        return 1;
    if(root->right == NULL)
        return root->data;
    return findMax(root->right);
}
int findHeight(BST *root)
{
    if(root == NULL)
        return -1;
    int hl = findHeight(root->left);
    int hr = findHeight(root->right);
    return max(hl, hr)+1;
}
///BFS
void LevelOrder(BST *root) {
	if(root == NULL) return;
	queue<BST*> Q;
	Q.push(root);
	//while there is at least one discovered node
	while(!Q.empty()) {
		BST* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}
///DFS
void preOrder(BST *root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(BST *root)
{
    if(root == NULL)
        return;
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}
void postOrder(BST *root)
{
    if(root == NULL)
        return;
    preOrder(root->left);
    preOrder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    BST *root = NULL;
    root = insertData(root, 15);
    root = insertData(root, 10);
    root = insertData(root, 25);
    root = insertData(root, 5);
    root = insertData(root, 17);
    root = insertData(root, 13);
    root = insertData(root, 8);

    if(searchData(root, 25))
        cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;

    LevelOrder(root); cout<<endl;
    preOrder(root); cout<<endl;
    inOrder(root); cout<<endl;
    postOrder(root); cout<<endl;


    cout<<"min: "<<findMin(root)<<endl;
    cout<<"max: "<<findMax(root)<<endl;
    cout<<"height: "<<findHeight(root)<<endl;
    inOrder(root); cout<<endl;
    root = deleteData(root, 8);
    inOrder(root);

    return 0;
}
