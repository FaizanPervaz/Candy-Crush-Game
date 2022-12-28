#include"Header2.h"
#include"Header.h"
int main()
{
	int number;
	string name;
	cout << endl;
	cout << "	>----------Welcome To Candy Crush-----------<" << endl;
	cout << "	Play Game-------------------(1)\n" << endl;
	cout << "	Credits  -------------------(2)\n" << endl;
	cout << "	Instruction and Rules-------(3)\n" << endl;
	cout << "	Score    -------------------(4)\n" << endl;
	cout << "	Exit     -------------------(5)\n" << endl;
	cout << "	>-------------------------------------------<" << endl;
	cout << "	Select Given Option" << endl;
	cin >> number;
	switch (number) {
	case 1: {
				int n;
				cout << "	Player Name:" << endl;
				cin >> name;
				cout << "	Easy Mode----------------(1)" << endl;
				cout << "	Hard Mode----------------(2)" << endl;
				cout << "	Select Options" << endl;
				cin >> n;
				switch (n) {
				case 1:
					cout << "	Easy Mode" << endl;
					candycrush();
					break;
				case 2:
					cout << "	Hard Mode" << endl;
					candycrush2();
					break;
				default:
					cout << "	Invalid\n Expected Input (1,2)" << endl;
				}
				break;
	}
	case 2:
		cout << "	Credits:" << endl;
		cout << "	Ahmad Idrees---(20F-1087)" << endl;
		cout << "	Asfand Yar-----(20F-1001)" << endl;
		system("	color 1B");
		break;
	case 3:
		cout << "	Rules/Instruction" << endl;
		cout << "	-----------WELCOME TO CANDYCRUSH--------------\n" << endl;
		cout << "	First Select Play Game and chose The Mode You want to PLay\n:"
			<< "	There Are Following Two MOdes In Game:\n"
			<< "	(Easy Mode------(1))"
			<< "	(Hard Mode------(2))" << endl;
		cout << "	After selecting Mode You will have Two options, if You want to Load the Previous Game Press Then ...(L)...\n If You want to Start a New Game Then Press ...(S)..." << endl;
		cout << "	When the Board Appears: Enter Number of Row for Candy to Select \n Enter Number of Coloumn for Candy to Select" << endl;
		cout << "	Then Select the Given Options to swap a Candy with other Candies" << endl;
		cout << "	........Expected Option.......\n"
			<< "	|To Move Candy Right, Press ...1...|\n"
			<< "	|To Move Candy Left, Press ...2...|\n"
			<< "	|To Move Candy Upward, Press ...3...|\n"
			<< "	|To Move Candy Down, Press ...4...|\n" << endl;
		cout << "	|Press 5 to Save the Game.|" << endl;
		system("color 1B");
		break;

	case 4:
		cout << "	Score Record" << endl;
		cout << "	Hard Mode Score---------(2)\nEasy Mode Score--------(1)" << endl;
		int sc;
		cin >> sc;
		switch (sc) {
		case 1:
			scorerecord();		//called the funtion to show scoreboard.
			break;
		case 2:
			scorerecord1();		//called the funtion to show scoreboard.
			break;
		default:
			cout << "	invalid\nExpected Options (1,2)" << endl;
		}
		system("color 1B");
		break;
	case 5:
		cout << "	Exit:(" << endl;
		system("color 1B");
		break;
	default:
		cout << "	invalid Input\n Expected Inputs(1,2,3,4,5)" << endl;
	}

	system("pause");
	return 0;
}
