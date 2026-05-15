/***********************************************************************
 * Source File:
 *    ApplyImpulse : Decorator for the advance() method of a bird
 * Author:
 *    Savannah Harvey
 * Summary:
 *    Parent class for the decorator pattern that applies an impulse to a bird's velocity
 ************************************************************************/

#pragma once
#include "position.h"
#include "ApplyImpulse.h"
#include "bird.h"
#include <random>
#include <list>


/******************************************************************
* IMPULSE
* These functions wrap the bird advance function.
****************************************************************/
void ApplyInertia::impulse(Bird& bird)
{
	Velocity v = bird.getVelocity();
	Position p = bird.getPosition();
	p += v;
	bird.setPosition(p);
}

/******************************************************************
* IMPULSE
* These functions wrap the bird advance function.
****************************************************************/
void ApplyGravity::impulse(Bird& bird)
{
	Velocity v = bird.getVelocity();
	v.addDy(-0.04);
	bird.setVelocity(v);
}

/******************************************************************
* IMPULSE
* These functions wrap the bird advance function.
******************************************************************/
void ApplyBouyancy::impulse(Bird& bird)
{
	Velocity v = bird.getVelocity();
	v.addDy(0.05);
	bird.setVelocity(v);
}

/******************************************************************
* IMPULSE
* These functions wrap the bird advance function.
*******************************************************************/
void ApplyDrag::impulse(Bird& bird)
{
	Velocity v = bird.getVelocity();
	v *= 0.99;
	bird.setVelocity(v);
}

/*************************************************
* IMPULSE
* These functions wrap the bird advance function.
***************************************/
void ApplyTurn::impulse(Bird& bird)
{
	if ((rand() % 16) == 0)
	{
		Velocity v = bird.getVelocity();
		v.addDy((rand() % 300) / 100.0 - 1.5);
		v.addDx((rand() % 300) / 100.0 - 1.5);
		bird.setVelocity(v);
	}
}