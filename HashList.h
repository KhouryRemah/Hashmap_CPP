#ifndef HASHLIST_H
#define HASHLIST_H

#include "HashNode.h"
#include <assert.h>

template <class Key, class Value>
class HashList {
	int size;
	HashNode<Key, Value>* head;
public:
	HashList();
	~HashList();

	//insert new hashnode in the start of the list.
	void insert(Key key, Value value);

	void remove(Key key);

	bool exist(Key key);

	Value find(Key key);

	bool empty();

	int getSize();

	Key getHeadKey();

	Value getHeadValue();

	HashNode<Key, Value>* getHead();
};

template <class Key, class Value>
HashList<Key, Value>::HashList() :size(0), head(NULL) {}

template <class Key, class Value>
HashList<Key, Value>::~HashList() {}

//insert new hashnode in the start of the list.
template <class Key, class Value>
void HashList<Key, Value>::insert(Key key, Value value) {
	//first check if existed.
	if (exist(key))return;
	HashNode<Key, Value>* newNode = new HashNode<Key, Value>(key, value);
	size++;
	if (head) {
		head->setPrev(newNode);
	}
	newNode->setNext(head);
	head = newNode;
}

template <class Key, class Value>
void HashList<Key, Value>::remove(Key key) {
	if (!exist(key))return;
	HashNode<Key, Value>* curr = head;
	while (curr) {
		if (curr->getKey() == key) {
			HashNode<Key, Value>* next = curr->getNext();
			HashNode<Key, Value>* prev = curr->getPrev();

			if (curr == head)head = next;
			if (next) next->setPrev(prev);
			if (prev)prev->setNext(next);
			delete curr;
			size--;
			return;
		}
		else {
			curr = curr->getNext();
		}
	}
}

template <class Key, class Value>
bool HashList<Key, Value>::exist(Key key) {
	HashNode<Key, Value>* curr = head;
	while (curr) {
		if (curr->getKey() == key) {
			return true;
		}
		curr = curr->getNext();
	}
	return false;
}

template <class Key, class Value>
Value HashList<Key, Value>::find(Key key) {
	assert(exist(key));
	HashNode<Key, Value>* curr = head;
	while (curr) {
		if (curr->getKey() == key) {
			return curr->getValue();
		}
		curr = curr->getNext();
	}
}

template <class Key, class Value>
bool HashList<Key, Value>::empty() {
	return (size <= 0);
}

template <class Key, class Value>
int HashList<Key, Value>::getSize() {
	return size;
}

template <class Key, class Value>
Key HashList<Key, Value>::getHeadKey() {
	assert(size > 0);
	return head->getKey();
}

template <class Key, class Value>
Value HashList<Key, Value>::getHeadValue() {
	assert(size > 0);
	return head->getValue();
}

template <class Key, class Value>
HashNode<Key, Value>* HashList<Key, Value>::getHead() {
	return head;
}

#endif //HASHLIST_H