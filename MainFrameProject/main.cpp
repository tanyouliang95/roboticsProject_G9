#include "stdafx.h"
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<string>
#include <iostream>

using namespace std;

#define PORT_NUM 6

char ChoiceFilePath[] = "../UI_display/static/choice.txt";
char StatusFilePath[] = "../UI_display/static/status.txt";

int writeUI(string status){
	//write status command to status.txt
	ofstream myfile;
	myfile.open (StatusFilePath);
	myfile << status;
	myfile.close();
	return 0;
}

std::string readUI(){
	//read selection from choice.txt
	//return array address of selection
	string line;
	ifstream myfile (ChoiceFilePath);
	if (myfile.is_open())
	{
	  while ( getline (myfile,line) )
	  {
		cout << choice << '\n';
	  }
	  myfile.close();
	}
	else cout << "Unable to open file";
	return 0;
}

int main()
{
	/*user input number of bread,number of cup,tea or coffee*/
	/*Read a txt file */
	string choice = readUI();

	//choice is in "c,1,0" or "t,2,2" format
	char drink = choice[0];
	int numBread = atoi(choice[2].c_str());
	int numEgg = atoi(choice[4].c_str());




    /*Initialize Arduino*/
    ArdSensor* ard1(PORT_NUM);


	/*for bread*/
	for (i = 1; i < numBread; i++)
	{
		startPos = ultraRead();
		writeUI("Bread");
		arm_motion(Bread, startPos, NULL);

	}

	/*for egg*/
	for (i = 1; i < numEgg; i++)
	{
		writeUI("Egg");
		arm_motion(Egg, NULL, i + 1);

	}

	/*for drinks*/
	writeUI("Drink");
	arm_motion(Drink, NULL, NULL);



	/*Read ultrasonic reading of bread*/


	int ultraRead(ArdSensor* ard1)
	{
		int distance = ard1->ardRead(U);


		if (0 < distance < 10)
		{
			startPos = 1;
			return startPos;
		}

		else if (10 < distance < 20)
		{
			startPos = 2;
			return startPos;
		}

		else if (distance < 30)
		{
			startPos = 3;
			return startPos;
		}

		else if (distance < 40)
		{
			startPos = 4;
			return startPos;
		}

		else if (distance < 50)
		{
			startPos = 5;
			return startPos;
		}

		else
		{
			/*ask ultrasonic sensor scan the distance again*/
			startPos = ultraRead(ard1);
			return startPos;
		}
	}
}
