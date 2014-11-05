//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/10/01

#include "SSet.h"

template <class Key, class T>
class Node {
public:
	Key k;
	T data;
	Node* left;
	Node* right;
};

template <class Key, class T>
class BST : public SSet < Key, T > {
public:
	BST();
	~BST();

	//Return the number of items currently in the SSet
	virtual unsigned long size();

	//Add a new item, x, with Key k.
	// If an item with Key k already exists, overwrite it
	virtual void add(Key k, T x);

	//Remove the item with Key k. If there is no such item, do nothing.
	virtual void remove(Key k);

	//Return the item with Key k. 
	// If there is no such item, throw an exception.
	virtual T find(Key k);
	//Return true if there is an item with Key k in the table. If not,
	// return false
	virtual bool keyExists(Key k);

	//If there is a key in the set that is > k,
	// return the first such key. If not, return k
	virtual Key next(Key k);
	//If there is a key in the set that is < k,
	// return the first such key. If not, return k
	virtual Key prev(Key k);

private:
	Node<Key, T>* root;

	virtual unsigned long size(Node<Key, T>* r);
	//These are the recursive versions of each of your methods.
	// You should return the address of the new root node, whether
	// or not the root node changes.
	virtual Node<Key, T>* add(Key k, T x, Node<Key, T>* r);
	virtual Node<Key, T>* remove(Key k, Node<Key, T>* r);

	//This one returns the address of the found node, NULL
	// if not found
	virtual Node<Key, T>* find(Key k, Node<Key, T>* r);

	//Find the item in the sub-tree rooted at r which has the smallest key
	virtual Node<Key, T>* min(Node<Key, T>* r);

	//Find the item in the sub-tree rooted at r which has the largest key
	virtual Node<Key, T>* max(Node<Key, T>* r);

	//Find the next/prev node, and return its address
	virtual Node<Key, T>* next(Key k, Node<Key, T>* r);
	virtual Node<Key, T>* prev(Key k, Node<Key, T>* r);

};


//Code ideas from class and Open Data Structures
//Basic structure of add and remove from StackOverflow
//deleteAll method from StackOverflow



#define NULL 0
#include <string>

template <class Key, class T>
BST<Key, T>::BST(){
	root = NULL;
}

template <class Key, class T>
BST<Key, T>::~BST(){
	deleteAll(root);
}

template <class Key, class T>
BST<Key, T>::deleteAll(Node<Key, T>* r){
		{
			if (r == NULL)
				return;
			if (r->left != NULL)
				return deleteAll(r->left);
			if (r->right != NULL)
				return deleteAll(r->right);

			delete r;

			return;
		}


	//Return the number of items currently in the SSet
	template <class Key, class T>
	unsigned long BST<Key, T>::size(){
		return size(root);
	}

	template <class Key, class T>
	unsigned long BST<Key, T>::size(Node<Key, T>* r){
		if (r == NULL) return 0;
		return 1 + size(r->left) + size(r->right);
	}

	//Add a new item, x, with Key k.
	// If an item with Key k already exists, overwrite it
	template <class Key, class T>
	void BST<Key, T>::add(Key k, T x){
		root = add(k, x, root);
	}

	//Remove the item with Key k. If there is no such item, do nothing.
	template <class Key, class T>
	void BST<Key, T>::remove(Key k){

		remove(k, root);

		/*case2: no children(leaf key), find key delete it, update prev node to null return null
		case3: internal node 1 child: find node, delete node, return pointer to next node of deleted to deleted prev node
		case4: internal node 2 children: find node, find max item in left subtree, swap keys and vals of 2 nodes, recursively remove the node set prev to null*/

	}

	//Return the item with Key k. 
	// If there is no such item, throw an exception.
	template <class Key, class T>
	T BST<Key, T>::find(Key k){
		return find(k, root);
	}

	//Return true if there is an item with Key k in the table. If not,
	// return false
	template <class Key, class T>
	bool BST<Key, T>::keyExists(Key k){
		if (find(k) == true){
			return true;
		}

		return false;
	}

	//If there is a key in the set that is > k,
	// return the first such key. If not, return k
	template <class Key, class T>
	Key BST<Key, T>::next(Key k){
		if (next(k, root)->k > k){
			return next(k, root)->k;
		}
		return k;
	}

	template <class Key, class T>
	Node<Key, T>* BST<Key, T>::next(Key k, Node<Key, T>* r){
		if (r == NULL){
			return NULL;
			{
		else if (r->k < k || r->k == k){
			return next(k, r->right);
		}
		else if (r->left != NULL && max(r->left)->k > k){
			return next(k, r->left);
		}
			else
				return r;
	}


//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key, T>::prev(Key k){
	if (prev(k, root)->k < k){
		return prev(k, root)->k;
	}
	return k;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::prev(Key k, Node<Key, T>* r){
	if (r == NULL){
		return NULL;
	}
	else if (r->k > k || r->k == k){
		return prev(k, r->left);
	}
	else if (r->right != NULL && min(r->right)->k < k){
		return prev(k, r->left);
	}
		else
			return r;

	}
}


template <class Key, class T>
Node<Key, T>* BST<Key, T>::add(Key k, T x, Node<Key, T>* r){
	if (r == NULL){
		r = new Node(k, x);
		r->left = NULL;
		r->right = NULL;
		return r;
	}
	else if (r->k == k){
		r->data = x;
	}
	else if (r->k < k)	{
		r->right = add(k, x, r->right);

	}
	else {
		r->left = add(k, x, r->left);

	}
	return r;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::remove(Key k, Node<Key, T>* r){
	//TODO
	return NULL;
}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::find(Key k, Node<Key, T>* r){
	if (r == NULL){
		throw std::string("Item can't be found");
	}

	else if (r->k == k){
		return r;
	}

	else if (k < r->k){
		return find(k, r->left);
	}

	else {
		return find(k, r->right);
	}

}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::max(Node<Key, T>* r){
	if (r == NULL){
		throw std::string("No max");
	}

	else if (r->right == NULL){
		return r;
	}

	else {
		return max(r->right);
	}

}

template <class Key, class T>
Node<Key, T>* BST<Key, T>::min(Node<Key, T>* r){
	if (r == NULL){
		throw std::string("No min");
	}

	else if (r->left == NULL){
		return r;
	}

	else {
		return max(r->left);
	}

}

