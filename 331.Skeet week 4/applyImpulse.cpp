/***********************************************************************
 * Source File:
 *    ApplyImpulse : Decorator for the advance() method of a bird
 * Author:
 *    Savannah Harvey
 * Summary:
 *    Parent class for the decorator pattern that applies an impulse to a bird's velocity
 ************************************************************************/

#include "position.h"
#include "ApplyImpulse.h"
#include "bird.h"
#include <random>
#include <list>


/******************************************************************
 * APPLY INERTIA IMPULSE
 * Moves the bird forward based on its current velocity
 ****************************************************************/
void ApplyInertia::impulse(Bird& bird)
{
	Velocity v = bird.getVelocity();
	Position p = bird.getPosition();
	p += v;
	bird.setPosition(p);
}

/******************************************************************
 * APPLY GRAVITY IMPULSE
 * Pulls the bird downward by reducing vertical velocity
 ****************************************************************/
void ApplyGravity::impulse(Bird& bird)
{
	Velocity v = bird.getVelocity();
	v.addDy(-0.07);
	bird.setVelocity(v);
}

/******************************************************************
 * APPLY BUOYANCY IMPULSE
 * Pushes the bird upward by increasing vertical velocity
 ****************************************************************/
void ApplyBuoyancy::impulse(Bird& bird)
{
	Velocity v = bird.getVelocity();
	v.addDy(0.05);
	bird.setVelocity(v);
}

/******************************************************************
 * APPLY DRAG LIGHT IMPULSE
 * Applies a small amount of drag to slow the bird slightly
 ****************************************************************/
void ApplyDragLight::impulse(Bird& bird)
{
	Velocity v = bird.getVelocity();
	v *= 0.995;
	bird.setVelocity(v);
}

/******************************************************************
 * APPLY DRAG HEAVY IMPULSE
 * Applies a large amount of drag to slow the bird significantly
 ****************************************************************/
void ApplyDragHeavy::impulse(Bird& bird)
{
	Velocity v = bird.getVelocity();
	v *= 0.990;
	bird.setVelocity(v);
}

/******************************************************************
 * APPLY TURN IMPULSE
 * Randomly changes the bird's direction every half second or so
 ****************************************************************/
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