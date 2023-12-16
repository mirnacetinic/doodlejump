#pragma once
#include <random>
#include "Jumper.h"

class Platforms
{
private:
	Sprite plat;
	Texture tex1;
	Vector2f xy;
	vector<Vector2f>position;

	float theHighest;

public:
	Platforms();
	virtual ~Platforms();

	bool jumpedOn(Jumper* doodle);

	virtual void show(RenderTarget* target);
	void drop(Jumper* doodle);
	void initTex();

	vector<Vector2f> getPos();
	float getTheHighestPlat();

};