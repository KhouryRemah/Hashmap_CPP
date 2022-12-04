#ifndef HASHMAP_H
#define HASHMAP_H

#define INITIAL_SIZE 3
#define LOAD_FACTOR 0.75


#include "HashList.h"


template <class Key>
struct KeyHash {
	unsigned long operator()(const Key& key, int tableSize) const {
		return static_cast<unsigned long>(key) % tableSize;
	}
};

template <class Key, class Value>
class HashMap {
	int size;
	HashList<Key, Value>** arr;
	int counter;

	void rehash(int newSize);

	void rehashIfNeeded();

public:
	HashMap();

	~HashMap();

	void insert(Key key, Value value);

	void remove(Key key);

	bool exist(Key key);

	Value get(Key key);

	void print();
};


template <class Key, class Value>
void HashMap<Key, Value>::rehash(int newSize) {
	HashList < Key, Value>** newArr = new HashList < Key, Value>*[newSize];
	for (int i = 0; i < newSize; i++) {
		newArr[i] = new HashList<Key, Value>();
	}
	for (int i = 0; i < size; i++) {
		HashList<Key, Value>* hashlist = arr[i];
		while (!hashlist->empty()) {
			Key key = hashlist->getHeadKey();
			Value value = hashlist->getHeadValue();
			hashlist->remove(key);
			KeyHash<Key> hash;
			unsigned long newIndex = hash(key, newSize);
			newArr[newIndex]->insert(key, value);
		}
		delete hashlist;
	}
	arr = newArr;

	size = newSize;
}

template <class Key, class Value>
void HashMap<Key, Value>::rehashIfNeeded() {
	//std::cout << (double)counter / (double)size << "    " << LOAD_FACTOR;
	if ((double)counter / (double)size >= LOAD_FACTOR)rehash(size * 2);
	else if ((double)counter / (double)size < 1 - LOAD_FACTOR && size / 2 >= 3)rehash(size / 2);

}

template <class Key, class Value>
HashMap<Key, Value>::HashMap() :size(INITIAL_SIZE) {
	arr = new HashList<Key, Value>*[size];
	for (int i = 0; i < size; i++) {
		arr[i] = new HashList<Key, Value>();
	}
}

template <class Key, class Value>
HashMap<Key, Value>::~HashMap() {
	for (int i = 0; i < size; i++) {
		delete arr[i];
	}
	delete[]arr;
}

template <class Key, class Value>
void HashMap<Key, Value>::insert(Key key, Value value) {
	KeyHash<Key> hash;
	unsigned long index = hash(key, size);
	arr[index]->insert(key, value);
	counter++;
	rehashIfNeeded();

}

template <class Key, class Value>
void HashMap<Key, Value>::remove(Key key) {
	KeyHash<Key> hash;
	unsigned long index = hash(key, size);
	arr[index]->remove(key);
	counter--;
	rehashIfNeeded();
}

template <class Key, class Value>
bool HashMap<Key, Value>::exist(Key key) {
	KeyHash<Key> hash;
	unsigned long index = hash(key, size);
	return arr[index]->exist(key);
}

template <class Key, class Value>
Value HashMap<Key, Value>::get(Key key) {
	KeyHash<Key> hash;
	unsigned long index = hash(key, size);
	return arr[index]->find(key);
}

template <class Key, class Value>
void HashMap<Key, Value>::print() {
	for (int i = 0; i < size; i++) {
		std::cout << i << " : ";
		HashList<Key, Value>* hashlist = arr[i];
		HashNode<Key, Value>* node = hashlist->getHead();
		while (node) {
			Key key = node->getKey();
			Value value = node->getValue();
			std::cout << "{" << key << "," << value << "},";
			node = node->getNext();
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

#endif //HASHMAP_H 	