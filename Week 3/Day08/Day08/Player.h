#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	Player(int x, int y) :
		//call a base ctor here
		GameObject(x, y, 0),//calling a method
		score_(0),
		lives_(3),
		rotation_(90)
	{
	}
	Player(int x, int y, int speed, int score, int lives, int rotation) : 
		//call a base ctor here
		GameObject(x,y,speed),//calling a method
		score_(score), 
		lives_(lives), 
		rotation_(rotation)
	{
		speed_ = speed;
	}
	Player(int score, int lives, int rotation) :
		//call a base ctor here
		GameObject(0, 0, 0),//calling a method
		score_(score),
		lives_(lives),
		rotation_(rotation)
	{
	}

	void Move() override;//override the pure-virtual base method

	int GetScore() const { return score_; }
	void SetScore(int score) { score_ = score; }

	int Lives() const { return lives_; }
	void Lives(int lives) { lives_ = lives; }

	int Rotation() const { return rotation_; }
	void Rotation(int rotation) { rotation_ = rotation; }

private:
	int score_, lives_, rotation_;

};

