/***********************************************************************
 * Header File:
 *    ApplyImpulse : Decorator for the advance() method of a bird
 * Author:
 *    Savannah Harvey
 * Summary:
 *    Parent class for the decorator pattern that applies an impulse to a bird's velocity
 ************************************************************************/

#pragma once
class Bird;
#include "position.h"
#include "bird.h"
#include <list>

/**********************
 * ApplyImpulse
 * Decorator for the advance() method of a bird
 **********************/
class ApplyImpulse
{
public:
	virtual void impulse(Bird& bird) = 0;
};

/**********************
 * ApplyInertia
 * Concrete decorator for the advance() method of a bird
 **********************/
class ApplyInertia : public ApplyImpulse
{
public:
	virtual void impulse(Bird& bird);
};

/**********************
 * ApplyGravity
 * Concrete decorator for the advance() method of a bird
 **********************/
class ApplyGravity : public ApplyImpulse
{
public:
	virtual void impulse(Bird& bird);
};

/**********************
 * ApplyBouyancy
 * Concrete decorator for the advance() method of a bird
 **********************/
class ApplyBouyancy : public ApplyImpulse
{
public:
	virtual void impulse(Bird& bird);
};

/**********************
 * ApplyDrag
 * Concrete decorator for the advance() method of a bird
 **********************/
class ApplyDrag : public ApplyImpulse
{
public:
	virtual void impulse(Bird& bird);
};

/**********************
 * ApplyTurn
 * Concrete decorator for the advance() method of a bird
 **********************/
class ApplyTurn : public ApplyImpulse
{
public:
	virtual void impulse(Bird& bird);
};