#include "CircularQueue112.h";

CircularQueue112::CircularQueue112(const CircularQueue112& cq) {
	if (cq.arr == nullptr)
		return;
	this->arr = new int[cq.size];
	this->size = cq.size;
	for (size_t i = 0; i < cq.size; i++)
		this->arr[i] = cq.arr[i];
}
CircularQueue112::CircularQueue112(CircularQueue112&& cq) {
	std::swap(this->arr, cq.arr);
	std::swap(this->size, cq.size);
}
CircularQueue112::~CircularQueue112() {
	if (this->arr != nullptr) {
		delete[] this->arr;
		this->arr = nullptr;
		this->size = 0;
	}
}
CircularQueue112& CircularQueue112::operator=(const CircularQueue112& cq) {
	if (this == &cq)
		return *this;
	if (cq.arr == nullptr) {
		this->~CircularQueue112();
		return *this;
	}
	if (this->size != cq.size) {
		this->arr = new int[cq.size];
		this->size = cq.size;
	}
	for (size_t i = 0; i < cq.size; i++)
		this->arr[i] = cq.arr[i];
	return *this;
}
CircularQueue112& CircularQueue112::operator=(CircularQueue112&& cq) {
	if (this->arr != nullptr)
		this->~CircularQueue112();
	std::swap(this->arr, cq.arr);
	std::swap(this->size, cq.size);
	return *this;
}

void CircularQueue112::print() const {
	for (size_t i = 0; i < this->size; i++) {
		if (i != 0)
			std::cout << ' ';
		std::cout << this->arr[i];
	}
}
void CircularQueue112::push(int el) {
	int* nArr = new int[this->size + 1];
	for (size_t i = 0; i < this->size; i++)
		nArr[i] = this->arr[i];
	nArr[this->size++] = el;
	if (this->arr != nullptr)
		delete[] this->arr;
	this->arr = nArr;
}
void CircularQueue112::pop(bool toEnd) {
	if (this->arr == nullptr)
		return;
	if (toEnd) {
		for (size_t i = 0; i < this->size - 1; i++)
			std::swap(this->arr[i], this->arr[i + 1]);
		return;
	}
	if (this->size == 1) {
		this->~CircularQueue112();
		return;
	}
	int* nArr = new int[--this->size];
	for (size_t i = 0; i < this->size; i++)
		nArr[i] = this->arr[i + 1];
	delete[] this->arr;
	this->arr = nArr;
}