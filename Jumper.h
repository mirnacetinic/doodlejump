#pragma once
#include "Objects/GameObject.h"

using namespace sf;

class Jumper:public GameObject
{
private:
	float jumpLen;
	float lastY;

	int score;
	bool jumping;
	bool onPlat;

	//inicijalizacija
	void initTex();

public:
	Jumper();
	virtual ~Jumper();

	void update();
	void jump();
	void setOnPlat(bool i);
	void move(const float x1,const float y1);

	//dohvæanje
	int getScore();
	bool getonPlat();
	bool isJumping();
};

