#include <iostream>
#include<ctime>
#include<conio.h>
#include <cstdlib>
#include<fstream>
#include<Windows.h>
#include<iomanip>
#include<string>
using namespace std;
//This Function is used to check the score according to the candies
//This function add the score of each candy in the total score of the game and display a sweet message.
void checkscore(char arr[][50], char n, int& score)
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
	else if (n == '?') {
		score = score + 10;
		cout << "Sweet" << endl;
	}
	else if (n == '*') {
		score = score + 10;
		cout << "Sweet" << endl;
	}
	else if (n == '%') {
		score = score + 10;
		cout << "Sweet" << endl;
	}
}
//this function is used to search the candies according to the row and coloumn
//This Function Search the candies in the draw board and  then by puting row and coloumn we select the candy 
void candysearch(char arr[][50], int n)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (arr[i][j] == n)
				arr[i][j] = { 0 };
		}
	}
}
//This function is used to generate  the candies
//which is removed after crushing 
//this function will generate candies according to the give candis of combination 
void shifting(char arr[][50])
{
	srand(time(NULL));
	char alphabet[] = { 'H', '#', '$', '&', '@', '%', '*', '?', '\0' };
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (arr[i][j] == '\x1' || arr[i][j] == ' ' || arr[i][j] == '\0')
			{
				for (int k = i; k > 0; k--)
					arr[k][j] = arr[k - 1][j];
				arr[i][j] = alphabet[rand() % 8];
			}
		}
	}

}
//this fuction is used to draw the board of random characters for sisplaying candies in a board
//this function only generate draw board and generate given  candies rendomly 
void drawBoard(char board[][50])
{
	int rows, columns;
	char random[50][50];
	char alphabet[] = { 'H', '#', '$', '&', '@', '%', '*', '?', '\0' };
	int flag;
	srand(time(NULL));
	for (int rows = 0; rows < 12; rows++)
	{
		for (columns = 0; columns < 12; columns++)
		{
			flag = 0;
			do
			{
				random[rows][columns] = rand() % 8;
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
void check(char arr[][50], bool& flag, int& score)
{
	flag = false;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
			{
				arr[i][j] = '\0';
				arr[i][j + 1] = '\0';
				arr[i][j + 2] = '\0';
				shifting(arr);
				flag = true;
			}
			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])
			{
				arr[i][j] = '\0';
				arr[i + 1][j] = '\0';
				arr[i + 2][j] = '\0';
				flag = true;
				shifting(arr);
			}
		}
	}
}
//this function is used to priiting 2D array in the game board 
void print(char arr[][50])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout << "   " << arr[i][j];
		}
		cout << endl << endl;
	}
}

////////////////////////////////////////////////////////////

void stripecandy(char arr[][50], bool& flag, int& score)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j])
			{
				flag = true;
				arr[i][j] = 's';
				arr[i + 1][j] = '\0';
				arr[i + 2][j] = '\0';
				arr[i + 3][j] = '\0';
				shifting(arr);
			}
			else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3])
			{
				flag = true;
				arr[i][j] = 's';
				arr[i][j + 1] = '\0';
				arr[i][j + 2] = '\0';
				arr[i][j + 3] = '\0';
				shifting(arr);
			}
		}
	}
}
void wrapcandy(char arr[][50], bool& flag, int& score)
{
	flag = false;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j + 1] == arr[i + 1][j] && arr[i][j + 1] == arr[i + 2][j])
			{
				flag = true;
				arr[i][j] = 'w';
				arr[i][j + 1] = '\0';
				arr[i][j + 2] = '\0';
				arr[i + 1][j] = '\0';
				arr[i + 2][j] = '\0';
				shifting(arr);
			}
		}
	}
}
void colourbomb(char arr[][50], bool& flag, int& score)
{
	flag = false;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == arr[i][j + 4])
			{
				flag = true;
				arr[i][j] = 'c';
				arr[i][j + 1] = '\0';
				arr[i][j + 2] = '\0';
				arr[i][j + 3] = '\0';
				arr[i][j + 4] = '\0';
				shifting(arr);
			}
		}
	}
	for (int a = 0; a < 12; a++)
	{
		for (int b = 0; b < 12; b++)
		{
			if (arr[a][b] == arr[a + 1][b] && arr[a][b] == arr[a + 2][b] && arr[a][b] == arr[a + 3][b] && arr[a][b] == arr[a + 4][b])
			{
				flag = true;
				arr[a][b] = 'c';
				arr[a + 1][b] = '\0';
				arr[a + 2][b] = '\0';
				arr[a + 3][b] = '\0';
				arr[a + 4][b] = '\0';
				shifting(arr);
			}
		}
	}
}
void stripeclear(char arr[][50])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (arr[i][j] == 's' && arr[i][j + 1] == arr[i][j + 2])
			{
				for (int k = i, l = 0; l < 12; l++)
					arr[i][l] = '\0';
				for (int a = j, b = 0; b < 12; b++)
					arr[b][a] = '\0';
				shifting(arr);
			}

		}
	}
}
void twocolourbomb(char arr[][50])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (arr[i][j] == 'c' && arr[i][j + 1] == 'c')
				cout << "  |1| |2| |3| |4| |5| |6| |7| |8| |9| |10||11||12|" << endl;
			drawBoard(arr);
		}
	}
}
void bombsamecandy(char arr[][50], int n)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (arr[i][j] == 'c')
			{
				arr[i][j] = '\0';
				if (n == 1)
					candysearch(arr, arr[i][j + 1]);
				else if (n == 2)
					candysearch(arr, arr[i][j - 1]);
				else if (n == 3)
					candysearch(arr, arr[i - 1][j]);
				else if (n == 4)
					candysearch(arr, arr[i + 1][j]);
			}
			shifting(arr);
		}
	}
}
void stripecolourbomb(char arr[][50])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (arr[i][j] == 's' && arr[i][j + 1] == 'c')
			{
				for (int k = i, l = 0; l < 9; l++)
					arr[i][l] = '\0';
				for (int a = j, b = 0; b < 9; b++)
					arr[b][a] = '\0';
				shifting(arr);
			}

		}
	}
}
void wrapcolourbomb(char arr[][50])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (arr[i][j] == 'c' && arr[i][j + 1] == 'w')
			{
				for (int a = i, b = 0; b < 3; b++)
					arr[a][b] = '\0';
			}

		}
	}
}


//////////////////////////////////////////////////////////
void againcheck(char arr[][50], bool& flag, int& score)
{
	check(arr, flag, score);
	shifting(arr);
}
//This function is used to read the score which is saved in a notepad file
void scorerecord() {
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
void candycrush2()
{
	char arr[50][50];
	ifstream fin;
	ofstream fout;
	string name;
	int i = 0;
	char rep;
	int moves = 15;
	int score = 0;
	cout << "\tTo load Game Press >L< or to start New Game Press >S<" << endl;
	cin >> rep;
	while (rep != 'S' &&rep != 's'&& rep != 'L'&&rep != 'l')
	{
		cout << "\tInvalid Input" << endl;
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
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 12; j++)
				{
					fin >> arr[i][j];
				}
			}
		}
		else
			cout << "\tNo save Game Found" << endl;
		fin.close();
	}
	int targetscore = 150;
	int n, j = 0;
	bool hurdle = 'H';		//Hurdle comes with a alphabebt H.
	bool flag;
	int a = 0, b = 0;
	cout << "\tTarget Score: " << targetscore << endl;
	cout << "\tScore: " << score << endl;
	cout << "\tRemaining Moves " << moves << endl;
	cout << "  |1| |2| |3| |4| |5| |6| |7| |8| |9| |10||11||12|" << endl;
	drawBoard(arr);
	print(arr);

	for (i = 0; i < 15; i++)
	{
		cout << "\tEnter Row of Candy You want to Move" << endl;
		cin >> a;
		while (a < 1 || a > 12)
		{
			cout << "\tInvalid input" << endl;
			cin >> a;
		}
		a--;
		cout << "\tEnter Column of Candy You want to Move:" << endl;
		cin >> b;
		while (b < 1 || b > 12)
		{
			cout << "\tInvalid Input" << endl;
			cin >> b;
		}
		b--;
		cout << "\tTo move Candy Right Press >1< \n To move Candy left Press >2<\n To move Candy up Press >3< \n To move Candy down Press >4<\n";
		cout << "\tPress >5< to save the Game" << endl;
		cin >> n;
		while (n < 1 || n>5)
		{
			cout << "\tInvalid Input" << endl;
			cin >> n;
		}
		if (n == 1)//for right direction
		{
			if (arr[a][b + 1] == hurdle) {
				cout << "\tHurdle" << endl;
				cout << "\t>Yot cannot Swap Hurdles<" << endl;
			}
			else {
				moves--;

				swap(arr[a][b], arr[a][b + 1]);
				///////////////////////////
				checkscore(arr, arr[a][b], score);
				colourbomb(arr, flag, score);
				bombsamecandy(arr, n);
				twocolourbomb(arr);
				wrapcandy(arr, flag, score);
				stripecandy(arr, flag, score);
				stripecolourbomb(arr);
				stripeclear(arr);
				///////////////////////////
				check(arr, flag, score);
				againcheck(arr, flag, score);
				if (flag == false)
					swap(arr[a][b + 1], arr[a][b]);
				else
					checkscore(arr, arr[a][b], score);

				Sleep(1000);
				system("cls");
				againcheck(arr, flag, score);
				cout << "\tTarget score: " << targetscore << endl;
				cout << "\tScore: " << score << endl;
				cout << "\tMoves remaining: " << moves << endl;
				/////////////////////////
				againcheck(arr, flag, score);
				////////////////////////
				print(arr);
			}

		}
		else if (n == 2)//for left direction
		{
			if (arr[a][b - 1] == hurdle) {
				cout << "\tHurdle" << endl;
				cout << "\t>Yot cannot Swap Hurdles<" << endl;
			}
			else {
				moves--;

				swap(arr[a][b], arr[a][b - 1]);
				////////////////////////////
				checkscore(arr, arr[a][b], score);
				colourbomb(arr, flag, score);
				bombsamecandy(arr, n);
				twocolourbomb(arr);
				wrapcandy(arr, flag, score);
				stripecandy(arr, flag, score);
				stripecolourbomb(arr);
				stripeclear(arr);
				//////////////////////////
				check(arr, flag, score);
				againcheck(arr, flag, score);
				if (flag == false)
					swap(arr[a][b - 1], arr[a][b]);
				else
					checkscore(arr, arr[a][b], score);

				Sleep(1000);
				system("cls");
				againcheck(arr, flag, score);
				cout << "\tTarget Score: " << targetscore << endl;
				cout << "\tScore: " << score << endl;
				cout << "\tMoves Remaining: " << moves << endl;
				//////////////////
				againcheck(arr, flag, score);
				/////////////////////
				print(arr);
			}

		}
		else if (n == 3)//for upword direction
		{
			if (arr[a - 1][b] == hurdle) {
				cout << "\tHurdle" << endl;
				cout << "\t>Yot cannot Swap Hurdles<" << endl;
			}
			else {
				moves--;
				swap(arr[a][b], arr[a - 1][b]);
				////////////////////////////////
				checkscore(arr, arr[a][b], score);
				colourbomb(arr, flag, score);
				bombsamecandy(arr, n);
				twocolourbomb(arr);
				wrapcandy(arr, flag, score);
				stripecandy(arr, flag, score);
				stripecolourbomb(arr);
				stripeclear(arr);
				////////////////////////////
				check(arr, flag, score);
				againcheck(arr, flag, score);
				if (flag == false)
					swap(arr[a - 1][b], arr[a][b]);
				else
					checkscore(arr, arr[a][b], score);

				Sleep(1000);
				system("cls");
				againcheck(arr, flag, score);
				cout << "\tTarget Score: " << targetscore << endl;
				cout << "\tScore: " << score << endl;
				cout << "\tMoves Remaining: " << moves << endl;
				////////////////////
				againcheck(arr, flag, score);
				///////////////////
				print(arr);
			}

		}
		else if (n == 4)//foe down direction
		{
			if (arr[a + 1][b] == hurdle) {
				cout << "\tHurdle" << endl;
				cout << "\t>Yot cannot Swap Hurdles<" << endl;
			}
			else {
				moves--;

				swap(arr[a][b], arr[a + 1][b]);
				////////////////////////
				checkscore(arr, arr[a][b], score);
				colourbomb(arr, flag, score);
				bombsamecandy(arr, n);
				twocolourbomb(arr);
				wrapcandy(arr, flag, score);
				stripecandy(arr, flag, score);
				(arr);
				stripeclear(arr);
				//////////////////////
				check(arr, flag, score);
				againcheck(arr, flag, score);
				if (flag == false)
					swap(arr[a + 1][b], arr[a][b]);
				else
					checkscore(arr, arr[a][b], score);

				Sleep(1000);
				system("cls");
				againcheck(arr, flag, score);
				cout << "\tTarget Score: " << targetscore << endl;
				cout << "\tScore: " << score << endl;
				cout << "\tMoves Remaining: " << moves << endl;
				////////////////////////
				againcheck(arr, flag, score);
				////////////////////////
				print(arr);
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
