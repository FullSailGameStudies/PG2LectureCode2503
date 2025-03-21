#pragma once
class GameObject
{
public:

	GameObject(int x, int y, int speed)
		: x_(x), y_(y), speed_(speed)
	{
	}

	int X() const { return x_; }
	void X(int x) { x_ = x; }

	int Y() const { return y_; }
	void Y(int y) { y_ = y; }

	int Speed() const { return speed_; }
	void Speed(int speed) { speed_ = speed; }

	virtual void Move() = 0;//pure virtual making the class abstract
protected:
	int x_, y_, speed_;

};

