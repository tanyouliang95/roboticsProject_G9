// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "motion.h"
#include <Windows.h>

int main() {
	init();
	/*
	arm_motion(egg, 0, 1);
	arm_motion(egg, 0, 2);
	arm_motion(bread, 1, 1);
	arm_motion(bread, 2, 1);
	*/
	arm_motion(drinks, 0, 0);
}

