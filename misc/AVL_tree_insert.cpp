#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	Node *left, *right;
	int height;
	Node(int val){
		this->val = val;
		this->left = this->right = NULL;
		this->height = 1;
	}
};
int h(Node* root){
	if(root == NULL)	return 0;
	return root->height;
}

Node* leftrot(Node* root){
	Node* right = root->right;
	root->right = right->left;
	right->left = root;
	return right;
}
Node* rightrot(Node* root){
	Node* left = root->left;
	root->left = left->right;
	left->right = root;
	return left;
}
bool lgreater(Node* root){
	if(root == NULL)	return false;
	return h(root->left) > h(root->right) + 1;
}
bool rgreater(Node* root){
	if(root == NULL)	return false;
	return h(root->right) > h(root->left) + 1;
}
Node* insert(Node* root, int x){
	if(root == NULL)	return new Node(x);
	
	if(x < root->val)
		root->left = insert(root->left, x);
	else
		root->right = insert(root->right, x);

	//rotation right
	if( lgreater(root) ){
		if( lgreater(root->left) )
			root->left = rightrot(root->left);
		else if( rgreater(root->left) )
			root->left = leftrot(root->left);
		root = rightrot(root);
	}

	//rotation left
	if( rgreater(root) ){
		if( lgreater(root->right) )
			root->right = rightrot(root->right);
		else if( rgreater(root->right) )
			root->right = leftrot(root->right);
		root = leftrot(root);
	}

	//update height
	root->height = max(h(root->left), h(root->right) ) + 1;
	return root;
}

void inorder(Node* root, vector<int>& arr, int& i){
	if(root == NULL)	return;
	inorder(root->left, arr, i);
	assert(root->val == arr[i++]);
	inorder(root->right, arr, i);
}

int main(){
	Node* root = NULL;
	int n; cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
		root = insert(root, arr[i]);
	}
	sort(arr.begin(), arr.end());
	int i = 0;
	inorder(root, arr, i);
	return 0;
};
