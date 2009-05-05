//============================================================================
// Name        : LonelySoul.cpp
// Author      : deka
// Version     :
// Copyright   : GPL
// Description : La unión del mundo
//============================================================================

#include <iostream>
#include "Engine.h"
#include <string>

const Uint32 WIDTH = 1024;
const Uint32 HEIGHT = 768;

int main( int argc, char* argv[] )
{
	Engine motor;
	motor.mainLoop();
	return 0;
}
