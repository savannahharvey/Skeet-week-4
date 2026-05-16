/***********************************************************************
 * Header File:
 *    ApplyImpulse : Decorator for the advance() method of a bird
 * Author:
 *    Savannah Harvey
 * Summary:
 *    Parent class for the decorator pattern that applies an impulse to a bird's velocity
 ************************************************************************/

#pragma once

#include "position.h"
#include <list>

class Bird;

enum ImpulseType
{
	INERTIA,
	GRAVITY,
	BUOYANCY,
	DRAG_LIGHT,
	DRAG_HEAVY,
	TURN
};

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
	void impulse(Bird& bird);
};

/**********************
 * ApplyGravity
 * Concrete decorator for the advance() method of a bird
 **********************/
class ApplyGravity : public ApplyImpulse
{
public:
	void impulse(Bird& bird);
};

/**********************
 * ApplyBuoyancy
 * Concrete decorator for the advance() method of a bird
 **********************/
class ApplyBuoyancy : public ApplyImpulse
{
public:
	void impulse(Bird& bird);
};

/**********************
 * ApplyDragLight
 * Concrete decorator for the advance() method of a bird
 **********************/
class ApplyDragLight : public ApplyImpulse  // 0.995 for Standard
{
public:
	void impulse(Bird& bird);
};

/**********************
 * ApplyDragHeavy
 * Concrete decorator for the advance() method of a bird
 **********************/
class ApplyDragHeavy : public ApplyImpulse  // 0.990 for Floater
{
public:
	void impulse(Bird& bird);
};

/**********************
 * ApplyTurn
 * Concrete decorator for the advance() method of a bird
 **********************/
class ApplyTurn : public ApplyImpulse
{
public:
	void impulse(Bird& bird);
};