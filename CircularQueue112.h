#pragma once
#include <iostream>

class CircularQueue112 {
	int* arr = nullptr;
	int size = 0;
public:
	CircularQueue112() = default;
	CircularQueue112(const CircularQueue112& cq);
	CircularQueue112(CircularQueue112&& cq);
	~CircularQueue112();

	CircularQueue112& operator=(const CircularQueue112& cq);
	CircularQueue112& operator=(CircularQueue112&& cq);

	inline int getSize() const { return this->size; }
	inline bool empty() const { return size == 0; }

	inline int back() const { return this->arr[0]; }
	inline int& back() { return this->arr[0]; }

	inline int front() const { return this->arr[this->size - 1]; }
	inline int& front() { return this->arr[this->size - 1]; }

	void print() const;
	void push(int el);
	void pop(bool toEnd = true);
};