#pragma once

template<typename E>
class ArrVector{
public:
	ArrVector();
	int sizeV() const { return n; } // returns vector size
	E& operator[](int i) { return V[i]; } //redefine []
	bool isEmpty() const { return sizeV() == 0; } // checks if vector is empty
	E& elementAtRank(int r) { return V[r]; } //access element at rank r
	void remove(int r); // remove element at rank r
	void insert(const E&e); // insert element e
	void overflow(); // handle overflow of array
private:
	int capacity; //length of array
	int n; // number of elements in vector
	E* V; // array V, stores elements
};

template<typename E>
ArrVector<E>::ArrVector() : capacity(0), n(0), V(nullptr) {}

template<typename E>
void ArrVector<E>::overflow() {
	if (capacity == 0)
		++capacity;
	capacity *= 2;
	E* B = new E[capacity];
	for (int i = 0; i < n; i++) {
		B[i] = V[i];
	}
	delete[] V;
	V = B;
}

template<typename E>
void ArrVector<E>::remove(int r) {
	for (int i = r; i < n; i++) {
		V[i] = V[i + 1];
		n--;
	}
}

template<typename E>
void ArrVector<E>::insert(const E& e) {
	if (n >= capacity)
		overflow();
	V[n] = e;
	n++;
}