#ifndef HASHNODE_H
#define HASHNODE_H

template <class Key, class Value>
class HashNode {
	Key key;
	Value value;
	HashNode<Key, Value>* next;
	HashNode<Key, Value>* prev;

public:
	HashNode(Key key, Value value);
	~HashNode();
	Key getKey();
	void setKey(Key key1);
	Value getValue();
	void setValue(Value value1);
	HashNode<Key, Value>* getNext();
	void setNext(HashNode<Key, Value>* next1);
	HashNode<Key, Value>* getPrev();
	void setPrev(HashNode<Key, Value>* prev1);

};
template <class Key, class Value>
HashNode<Key, Value>::HashNode(Key key, Value value) :key(key), value(value), next(NULL), prev(NULL) {}

template <class Key, class Value>
HashNode<Key, Value>::~HashNode() {}

template <class Key, class Value>
Key HashNode<Key, Value>::getKey() {
	return key;
}

template <class Key, class Value>
void HashNode<Key, Value>::setKey(Key key1) {
	key = key1;
}

template <class Key, class Value>
Value HashNode<Key, Value>::getValue() {
	return value;
}

template <class Key, class Value>
void HashNode<Key, Value>::setValue(Value value1) {
	value = value1;
}

template <class Key, class Value>
HashNode<Key, Value>* HashNode<Key, Value>::getNext() {
	return next;
}

template <class Key, class Value>
void HashNode<Key, Value>::setNext(HashNode<Key, Value>* next1) {
	next = next1;
}

template <class Key, class Value>
HashNode<Key, Value>* HashNode<Key, Value>::getPrev() {
	return prev;
}

template <class Key, class Value>
void HashNode<Key, Value>::setPrev(HashNode<Key, Value>* prev1) {
	prev = prev1;
}

#endif //HASHNODE_H