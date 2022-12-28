#include <iostream>
#include<ctime>
#include<conio.h>
#include <cstdlib>
#include<fstream>
#include<Windows.h>
#include<iomanip>
#include<string>
using namespace std;
//this Function is used to check the score according to the candies
//this function add the score of each candy in the total score of the game and display a sweet message.
void checkscore1(char arr[][50], char n, int& score)
{
	if (n == '@') {
		score = score + 10;
		cout << "Sweet" << endl;
	}
	else if (n == '$') {
		score = score + 10;
		cout << "Sweet" << endl;
	}
	else if (n == '&') {
		score = score + 10;
		cout << "Sweet" << endl;
	}
	else if (n == '#') {
		score = score + 10;
		cout << "Sweet" << endl;
	}
}
//this function is used to search the candies according to the row and coloumn
//This Function Search the candies in the draw board and  then by puting row and coloumn we select the candy 
void candysearch1(char arr[][50], int n)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == n)
				arr[i][j] = { 0 };
		}
	}
}
//This function is used to generate  the candies
//which is removed after crushing 
//this function will generate candies according to the give candis of combination 
void shifting1(char arr[][50])
{
	srand(time(0));
	char alphabet[] = { 'H', '#', '$', '&', '@', '\0' };
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == '\x1' || arr[i][j] == ' ' || arr[i][j] == '\0')
			{
				for (int k = i; k > 0; k--)
					arr[k][j] = arr[k - 1][j];
				arr[i][j] = alphabet[rand() % 5];
			}
		}
	}

}
//this fuction is used to draw the board of random characters for sisplaying candies in a board
//this function only generate draw board and generate given  candies rendomly 
void drawBoard1(char board[][50])
{
	int rows, columns;
	char random[50][50];
	char alphabet[] = { 'H', '#', '$', '&', '@', '\0' };
	int flag;
	srand(time(NULL));
	for (int rows = 0; rows < 8; rows++)
	{
		for (columns = 0; columns < 8; columns++)
		{
			flag = 0;
			do
			{
				random[rows][columns] = rand() % 5;
				board[rows][columns] = alphabet[random[rows][columns]];
				if (board[rows][columns] == board[rows - 1][columns] || board[rows][columns] == board[rows][columns - 1])
				{
					flag = 0;
					continue;
				}
				else
				{
					flag = 1;

				}
			} while (flag == 0);
		}
	}
}
void check1(char arr[][50], bool& flag, int& score)
{
	flag = false;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
			{
				arr[i][j] = '\0';
				arr[i][j + 1] = '\0';
				arr[i][j + 2] = '\0';
				shifting1(arr);
				flag = true;
			}
			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])
			{
				arr[i][j] = '\0';
				arr[i + 1][j] = '\0';
				arr[i + 2][j] = '\0';
				flag = true;
				shifting1(arr);
			}
		}
	}
}
//this function is used to priiting 2D array in the game board 
void print1(char arr[][50])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << "   " << arr[i][j];
		}
		cout << endl << endl;
	}
}
void againcheck1(char arr[][50], bool& flag, int& score)
{
	check1(arr, flag, score);
	shifting1(arr);
}
//This function is used to read the score whis is saved in a notepad file
void scorerecord1() {
	ifstream read("Data.txt", ios::out);
	char ab;
	while (!read.eof()) {
		read.get(ab);
		cout << ab;
	}
	read.close();
}
//This Function is our Hard mode play game function 
//Every Function given in this header file is called in this function candycrush2
//this Function is also used to the movement of candies and also to save the score
void candycrush()
{
	char arr[50][50];
	ifstream fin;
	ofstream fout;
	string name;
	int i = 0;
	char rep;
	int moves = 15;
	int score = 0;
	cout << "\tTo Load Game Press <L> or to Start New Game Press <S>" << endl;
	cin >> rep;
	while (rep != 'S' &&rep != 's'&& rep != 'L'&&rep != 'l')
	{
		cout << "\tInvalid input\n";
		cin >> rep;
	}
	if (rep == 'S' || rep == 's')
	{
		i = 0;
		score = 0;
		moves = 15;
	}
	else if (rep == 'L' || rep == 'l')
	{
		fin.open("Data.txt");
		if (fin)
		{
			fin >> i;
			fin >> score;
			fin >> moves;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					fin >> arr[i][j];
				}
			}
		}
		else
			cout << "\tNo Save Game Found" << endl;
		fin.close();
	}
	int targetscore = 150;
	int n, j = 0;
	char hurdle = 'H';
	bool flag;
	int a = 0, b = 0;
	cout << "\tTarget Score: " << targetscore << endl;
	cout << "\tScore: " << score << endl;
	cout << "\tMoves Remaining: " << moves << endl;
	drawBoard1(arr);
	print1(arr);

	for (i = 0; i < 15; i++)
	{
		cout << "\tEnter The Row of Candy You want to Move" << endl;
		cin >> a;
		while (a < 1 || a > 8)
		{
			cout << "\tInvalid input\n";
			cin >> a;
		}
		a--;
		cout << "\tEnter the Column of candy You want to Move\n";
		cin >> b;
		while (b < 1 || b>8)
		{
			cout << "\tInvalid input\n";
			cin >> b;
		}
		b--;
		cout << "\tTo Move Candy Right Press >1<\nTo Move Candy Left Press >2<\nTo Move Candy Up Press >3<\nTo Move Candy Down Press >4<\n";
		cout << "\tPress 5 to save the Game" << endl;
		cin >> n;
		while (n < 1 || n>5)
		{
			cout << "\tInvalid input\n";
			cin >> n;
		}
		if (n == 1)//for right direction
		{
			if (arr[a][b + 1] == hurdle) {
				cout << "\tHurdle" << endl;
				cout << "\tYou cannot Swap Hurdle" << endl;
			}
			else {
				moves--;

				swap(arr[a][b], arr[a][b + 1]);
				///////////////////////////

				///////////////////////////
				check1(arr, flag, score);
				againcheck1(arr, flag, score);
				if (flag == false)
					swap(arr[a][b + 1], arr[a][b]);
				else
					againcheck1(arr, flag, score);
				checkscore1(arr, arr[a][b], score);
				againcheck1(arr, flag, score);

				Sleep(1000);
				system("cls");
				againcheck1(arr, flag, score);
				cout << "\tTarget Score: " << targetscore << endl;
				cout << "\tScore: " << score << endl;
				cout << "\tMoves Remaining: " << moves << endl;
				/////////////////////////
				againcheck1(arr, flag, score);
				////////////////////////
				print1(arr);
			}

		}
		else if (n == 2)//for left direction
		{
			if (arr[a][b - 1] == hurdle) {
				cout << "\tHurdle" << endl;
				cout << "\tYou cannot Swap Hurdle" << endl;
			}
			else {
				moves--;

				swap(arr[a][b], arr[a][b - 1]);
				////////////////////////////

				//////////////////////////
				check1(arr, flag, score);
				if (flag == false)
					swap(arr[a][b - 1], arr[a][b]);
				else
					checkscore1(arr, arr[a][b], score);

				Sleep(1000);
				system("cls");
				againcheck1(arr, flag, score);
				cout << "\tTarget score: " << targetscore << endl;
				cout << "\tScore: " << score << endl;
				cout << "\tMoves remaining: " << moves << endl;
				//////////////////
				againcheck1(arr, flag, score);
				/////////////////////
				print1(arr);
			}

		}
		else if (n == 3)//for upword direction
		{
			if (arr[a - 1][b] == hurdle) {
				cout << "\tHurdle" << endl;
				cout << "\tYou cannot Swap Hurdle" << endl;
			}
			else {
				moves--;
				swap(arr[a][b], arr[a - 1][b]);
				////////////////////////////////

				////////////////////////////
				check1(arr, flag, score);
				if (flag == false)
					swap(arr[a - 1][b], arr[a][b]);
				else
					checkscore1(arr, arr[a][b], score);

				Sleep(1000);
				system("cls");
				againcheck1(arr, flag, score);
				cout << "\tTarget score: " << targetscore << endl;
				cout << "\tScore: " << score << endl;
				cout << "\tMoves remaining: " << moves << endl;
				////////////////////
				againcheck1(arr, flag, score);
				///////////////////
				print1(arr);
			}

		}
		else if (n == 4)//foe down direction
		{
			if (arr[a + 1][b] == hurdle) {
				cout << "\tHurdle" << endl;
				cout << "\tYou cannot Swap Hurdle" << endl;
			}
			else {
				moves--;

				swap(arr[a][b], arr[a + 1][b]);
				////////////////////////

				//////////////////////
				check1(arr, flag, score);
				if (flag == false)
					swap(arr[a + 1][b], arr[a][b]);
				else
					checkscore1(arr, arr[a][b], score);

				Sleep(1000);
				system("cls");
				againcheck1(arr, flag, score);
				cout << "\tTarget Score: " << targetscore << endl;
				cout << "\tScore: " << score << endl;
				cout << "\tMoves Remaining: " << moves << endl;
				////////////////////////
				againcheck1(arr, flag, score);
				////////////////////////
				print1(arr);
			}
		}
		else if (n == 5)
		{
			fout.open("Data.txt");
			fout << i << endl;
			cout << "\tPlayer Name:" << endl;
			cin >> name;
			fout << name << endl;
			fout << "\tHighest Score:" << score << endl;
			fout << "\tMoves:" << moves << endl;
			fout << "\tTable:" << endl;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					fout << arr[i][j];
				}
				fout << endl;
			}
			fout.close();
			break;
		}
	}
	if (score >= 150) {
		cout << "\t>.....................<" << endl;
		cout << "\tYou Win" << endl;
		cout << "\t>.....................<" << endl;
	}
	else
		cout << "\t>.....................<" << endl;
	cout << "\tYou lose" << endl;
	cout << "\t>.....................<" << endl;
}
