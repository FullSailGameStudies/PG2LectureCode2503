#pragma once
#include "GameObject.h"
class Enemy : public GameObject
{
public:
	int Value() const { return value_; }
	void Value(int value) { value_ = value; }

	int Size() const { return size_; }
	void Size(int size) { size_ = size; }
private:
	int value_, size_;
};

