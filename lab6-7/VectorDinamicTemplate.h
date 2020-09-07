#pragma once
#include "Car.h"
template<typename TElem>
class IteratorVectorT;


template <typename TElem>
class VectorDinamic {
private:
	int lg, cap;
	TElem* elems;

	void cresteDim();
	void scadeDim();

public:
	// constructor
	VectorDinamic();

	// copy constructor
	VectorDinamic(const VectorDinamic<TElem>& ot);

	// destructor
	~VectorDinamic();

	VectorDinamic& operator=(const VectorDinamic<TElem>& ot);
	
	void addElem(const TElem& elem);
	int findElem(const TElem& elem);
	void deleteElem(int poz);
	TElem& getElem(int poz);
	int getLungime();
	friend class IteratorVectorT<TElem>;
	IteratorVectorT<TElem> begin();
	IteratorVectorT<TElem> end();

};

template <typename TElem>
VectorDinamic<TElem>::VectorDinamic() {
	this->cap = 5;
	this->lg = 0;
	this->elems = new TElem[this->cap];
}

template <typename TElem>
VectorDinamic<TElem>::VectorDinamic(const VectorDinamic<TElem>& vectorDinamic) {
	this->cap = vectorDinamic.cap;
	this->lg = vectorDinamic.lg;
	this->elems = new TElem[this->cap];

	for (int i = 0; i < this->lg; i++)
		this->elems[i] = vectorDinamic.elems[i];

}

template <typename TElem>
VectorDinamic<TElem>::~VectorDinamic() {
	delete[] this->elems;
}

template <typename TElem>
VectorDinamic<TElem>& VectorDinamic<TElem> ::operator=(const VectorDinamic<TElem>& ot) {
	if (this == &ot) {
		return *this;
	}
	delete[] elems;
	elems = new TElem[ot.cap];
	
	for (int i = 0; i < ot.lg; i++) {
		elems[i] = ot.elems[i];  
	}
	lg = ot.lg;
	cap = ot.cap;
	return *this;
}

template <typename TElem>
void VectorDinamic<TElem>::addElem(const TElem& elem) {
	if (this->cap - 1 == this->lg)
		cresteDim();
	this->elems[lg] = elem;
	this->lg++;
}

template <typename TElem>
void VectorDinamic<TElem>::deleteElem(int poz) {
	for (int i = poz; i < this->lg; i++)
		this->elems[i] = this->elems[i + 1];
	if (this->cap / 2 == this->lg)
		scadeDim();
	this->lg--;
}

template <typename TElem>
int VectorDinamic<TElem>::getLungime() {
	return this->lg;
}

template <typename TElem>
TElem& VectorDinamic<TElem>::getElem(int poz) {
	return this->elems[poz];
}

template <typename TElem>
int VectorDinamic<TElem>::findElem(const TElem& elem) {
	for (int i = 0; i < this->lg; i++)
		if (this->elems[i] == elem)
			return i;
	return -1;
}

template <typename TElem>
void VectorDinamic<TElem>::cresteDim() {
	this->cap *= 2;
	TElem* largerElems = new TElem[this->cap];

	for (int i = 0; i <= this->lg; i++)
		largerElems[i] = this->elems[i];

	delete[] this->elems;
	this->elems = largerElems;
}

template <typename TElem>
void VectorDinamic<TElem>::scadeDim() {
	this->cap /= 2;
	TElem* smallerElems = new TElem[this->cap];

	for (int i = 0; i < this->lg; i++)
		smallerElems[i] = this->elems[i];

	delete[] this->elems;
	this->elems = smallerElems;
}

template <typename TElem>
IteratorVectorT<TElem> VectorDinamic<TElem>::begin() {
	return IteratorVectorT<TElem>(*this);
}template <typename TElem>
IteratorVectorT<TElem> VectorDinamic<TElem>::end() {
	return IteratorVectorT<TElem>(*this,lg);
}

template <typename TElem>
class IteratorVectorT {
private:
	const VectorDinamic<TElem>& v;
	int poz = 0;
public:
	IteratorVectorT(const VectorDinamic<TElem>& v) noexcept;
	IteratorVectorT(const VectorDinamic<TElem>& v, int poz) noexcept;
	bool valid()const;
	TElem& element()const;
	void next();
	TElem& operator*();
	IteratorVectorT& operator++();
	bool operator==(const IteratorVectorT& ot)noexcept;
	bool operator!=(const IteratorVectorT& ot)noexcept;
};

template<typename TElem>
IteratorVectorT<TElem>::IteratorVectorT(const VectorDinamic<TElem>& v) noexcept :v{ v } {}

template<typename TElem>
IteratorVectorT<TElem>::IteratorVectorT(const VectorDinamic<TElem>& v, int poz)noexcept : v{ v }, poz{ poz } {}


template<typename TElem>
inline bool IteratorVectorT<TElem>::valid() const
{
	return poz < v.lg;
}

template <typename TElem>
TElem& IteratorVectorT<TElem>::element()const {
	return v.elems[poz];
}

template <typename TElem>
void IteratorVectorT<TElem>::next() {
	poz++;
}

template <typename TElem>
TElem& IteratorVectorT<TElem>::operator*() {
	return element();
}

template <typename TElem>
IteratorVectorT<TElem>& IteratorVectorT<TElem>::operator++() {
	next();
	return *this;
}
template <typename TElem>
bool IteratorVectorT<TElem>::operator==(const  IteratorVectorT<TElem>& ot)noexcept {
	return poz == ot.poz;
}
template <typename TElem>
bool IteratorVectorT<TElem>::operator!=(const  IteratorVectorT<TElem>& ot)noexcept {
	return poz != ot.poz;
}

