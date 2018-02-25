#include "Player.h"
#include <assert.h>
#include <windows.h>

void Player::Init()
{
	
	w = 10;
	h = 60;

	posX = 0;
	posY = 0;

	speed = 10;
}

void Player::Update()
{

	assert(mySide != Side_Undefined);

	float delta = 0;

	if(mySide == Side_Left)
	{	

		if(GetAsyncKeyState('Q') != 0)
		{
			delta -= speed;
		}

		if(GetAsyncKeyState('A') != 0)
		{
			delta += speed;
		}

	}

	if(mySide == Side_Right)
	{

		if(GetAsyncKeyState('P') != 0)
		{
			delta -= speed;
		}

		if(GetAsyncKeyState('L') != 0)
		{
			delta += speed;
		}

	}

	if(( posY + delta > 100) && ((posY + delta) < (600 - h )))
	{
		posY += delta;
	}
}

void Player::SetSide(Side eSide)
{
	mySide = eSide;

	if(mySide == Side_Left)
	{
		posX = 30;
	}

	if(mySide == Side_Right)
	{
		posX = 760;
	}
}
