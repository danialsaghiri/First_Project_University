#include<iostream>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<cstdlib>
#include<fstream>
using namespace std;
int Tol = 5;
int Arz = 4;
int TedadToop = 5;
void Hashiye();
void menu();
void Play(int Tol,int Arz,int ToopNumber);
void Printmenu();
void Option(int& Tol, int& Arz, int& TedadToop);
void PrintOption(int TedadToop);
void Help();
void ScoreList();
int Exit();
void sabad(int Tol, int Arz, int x, int y);
void gotoxy (short int x, short int y);
void Toop(int x,int y);
int Harkat(int Xpartab, int Ypartab, int Tolsabad, int Arzsabadint ,int LocX1,int LocY1,int LocX2,int LocY2,int LocX3,int LocY3,int BazeyeSabad);
void Maximizewindow();
int main()
{
	Maximizewindow();
	menu();
}
void gotoxy(int x, int y)
{
	COORD coord = { 0,0 };
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Maximizewindow()
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}
void sabad(int Tol, int Arz, int x, int y)
{
	gotoxy(x, y);
	int copyArz;
	int spacecounter = 0;
	copyArz = Arz;
	for (int i = 0; i < Arz; i++)
	{
		for (int i = 0;i < spacecounter;i++)
			cout << " ";
		cout << char(92);
		if (i < Arz - 1)
			for (int j = 0; j < (Tol + ((copyArz - 1) * 2)); j++)
				cout << " ";
		else
			for (int j = 0;j < Tol;j++)
				cout << "_";
		cout << "/";
		y += 1;
		gotoxy(x, y);
		copyArz--;
		spacecounter++;
	}
}
void Toop(int x,int y)
{
	gotoxy(x, y);
	cout << "* *";
	gotoxy(x, y + 1);
	cout << "* *";
}
void Hashieyeh()
{
	for (int i = 0;i < 49;i++)
	{
		for (int j = 0;j < 210;j++)
		{
			if (i == 0 || i == 48 || j == 0 || j == 209)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
}
void menu()
{
	system("cls");

	Printmenu();
	int F;
	gotoxy(3, 44);
	cout << "WHAT YOU WANNA DO? INTER THAT NUMBER.";
	F = _getch() - '0';
	switch (F)
	{
	case(1):
		Play(Tol, Arz, TedadToop);
		break;
	case(2):
		Option(Tol, Arz, TedadToop);
		break;
	case(3):
		Help();
		break;
	case(4):
		ScoreList();
		break;
	case(5):
		Exit();
		break;
	}
}
int Harkat(int Xpartab, int Ypartab, int Tolsabad, int Arzsabad, int LocX1, int LocY1, int LocX2, int LocY2, int LocX3, int LocY3, int BazeyeSabad)//dahan sabad
{
	int Emtiyaz = 0;
	int Xtoop = 3;
	int X1toop = Xtoop;
	int Xtoopave = 0;
	int Ytoop = 46;
	bool dakhelshodan = false;
	while (1)
	{
		Sleep(100);
		system("cls");
		Hashieyeh();
		Toop(Xtoop, Ytoop);
		sabad(Tolsabad, Arzsabad, LocX1, LocY1);
		sabad(Tolsabad, Arzsabad, LocX2, LocY2);
		sabad(Tolsabad, Arzsabad, LocX3, LocY3);
		if (Xtoopave > LocX1 && Xtoopave < LocX1 + BazeyeSabad+1)
		{
			int CYtoop;
			CYtoop = Ytoop;
			for (int j = 0;j < ((-Ypartab) - 2);j++)
			{
				CYtoop--;
				if (CYtoop == LocY1)
				{
					Emtiyaz += 3;
					for (int i = 0; i < 3; i++)
					{
						system("color 20");
						Sleep(500);
						system("color 0f");
						Sleep(500);
					}
					dakhelshodan = true;
					break;
				}
			}
		}
		if (Xtoopave > LocX2 && Xtoopave < LocX2 + BazeyeSabad+1)
		{
			int CYtoop;
			CYtoop = Ytoop;
			for (int j = 0;j < ((-Ypartab) - 2);j++)
			{
				CYtoop--;
				if (CYtoop == LocY2)
				{
					Emtiyaz += 3;
					for (int i = 0; i < 3; i++)
					{
						system("color 20");
						Sleep(500);
						system("color 0f");
						Sleep(500);
					}
					dakhelshodan = true;
					break;
				}
			}
		}
		if (Xtoopave > LocX3 && Xtoopave < LocX3 + BazeyeSabad+1) 
		{
			int CYtoop;
			CYtoop = Ytoop;
			for (int j = 0;j < ((-Ypartab) - 2);j++)
			{
				CYtoop--;
				if (CYtoop == LocY3)
				{
					Emtiyaz += 3;
					for (int i = 0; i < 3; i++)
					{
						system("color 20");
						Sleep(500);
						system("color 0f");
						Sleep(500);
					}
					dakhelshodan = true;
					break;
				}
			}
		}
		if (dakhelshodan == true)
			break;
		if (Ytoop > 47 || Ytoop < 0)
		{
			for (int i = 0; i < 3; i++)
			{
				system("color 40");
				Sleep(500);
				system("color 0f");
				Sleep(500);
			}
			break;
		}
		Xtoop += Xpartab;
		Xtoopave = (X1toop + Xtoop) / 2;
		X1toop = Xtoop;
		Ytoop -= Ypartab;
		Ypartab -= 1;
	}

	return Emtiyaz;
}
void Play(int Tol, int Arz, int ToopNumber)
{
	ofstream RECORD("record.txt",ios::app);
	system("cls");
	Hashieyeh();
	string name;
	gotoxy(60, 10);
	cout << "PLEASE RIGHT YOUR NAME :  ";
	cin >> name;
	srand(time(0));
	char F;
	bool A = false;
	int LocX1, LocY1, LocX2, LocY2, LocX3, LocY3, Xpartab, Ypartab;
	int CopyToopNumber = ToopNumber;
	int EmtiyazMarhaleh;
	int EmtiyazKol = 0;
	int Bazeyesabad = (Tol + ((Arz - 1) * 2));
	for (int i = 0; i < ToopNumber; i++)
	{
		system("cls");
		system("color 0A");
		Hashieyeh();
		gotoxy(31, 7);
		if (ToopNumber == 7)
			cout << "DIFFICULTY  :  EASY";
		else if (ToopNumber == 5)
			cout << "DIFFICULTY  :  MEDIUM";
		else if (ToopNumber == 3)
			cout << "DIFFICULTY  :  HARD";
		gotoxy(92, 7);
		cout << "EMTIYAZKOL :  " << EmtiyazKol;
		gotoxy(141, 7);
		cout << "BALL REMAIN  :  " << CopyToopNumber;
		gotoxy(80, 14);
		cout << "DO YOU WANT TO CONTINUE?  (IF YES ENTER Y / IF NO ENTER N)";
		F = tolower(_getch());
		switch (F)
		{
		case('y'):
			break;
		case('n'):
			A = true;
			break;
		default:
			break;
		}
		system("cls");
		Hashieyeh();

		if (A)
			break;
		LocX1 = (rand() % 40) + 90;
		LocY1 = (rand() % 20) + 20;
		LocX2 = (rand() % 40) + 120;
		LocY2 = (rand() % 20) + 20;
		LocX3 = (rand() % 40) + 150;
		LocY3 = (rand() % 20) + 20;
		Toop(3, 46);
		sabad(Tol, Arz, LocX1, LocY1);
		sabad(Tol, Arz, LocX2, LocY2);
		sabad(Tol, Arz, LocX3, LocY3);
		gotoxy(3, 5);
		cout << "INTER THE VALUE FOR Xpartab...";
		cin >> Xpartab;
		gotoxy(3, 7);
		cout << "INTER THE VALUE FOR Ypartab...";
		cin >> Ypartab;
		EmtiyazMarhaleh = Harkat(Xpartab, Ypartab, Tol, Arz, LocX1, LocY1, LocX2, LocY2, LocX3, LocY3, Bazeyesabad);
		EmtiyazKol += EmtiyazMarhaleh;
		CopyToopNumber -= 1;
	}
	RECORD << name  << " " << EmtiyazKol << " ";
	system("cls");
	Hashieyeh();
	system("color 0B");
	if (A)
	{
		gotoxy(90, 24);
		cout << "YOU GAVE UP EARLY";
		gotoxy(90, 25);
		cout << "EMTIYAZKOL :  " << EmtiyazKol;
	}
	else
	{
		gotoxy(82, 24);
		cout << "NICE TRY , YOU GET BETTER AND BETTER";
		gotoxy(90, 25);
		cout << "EMTIYAZKOL :  " << EmtiyazKol;
	}
	Sleep(3000);
	menu();
}
void Printmenu()
{
	system("color 0A");
	Hashieyeh();
	gotoxy(95, 8);
	cout << "1-START GAME";
	gotoxy(97, 16);
	cout << "2-OPTION";
	gotoxy(98, 24);
	cout << "3-HELP";
	gotoxy(95, 32);
	cout << "4-SCORE LIST";
	gotoxy(98, 40);
	cout << "5-EXIT";

}
void PrintOption(int TedadToop)
{
	system("color 0B");
	Hashieyeh();
	gotoxy(98, 8);
	cout << "1-EASY";
	if (TedadToop == 7)
	{
		gotoxy(105, 8);
		cout << "#";
	}
	gotoxy(97, 16);
	cout << "2-MEDIUM";
	if (TedadToop == 5)
	{
		gotoxy(107, 16);
		cout << "#";
	}
	gotoxy(98, 24);
	cout << "3-HARD";
	if (TedadToop == 3)
	{
		gotoxy(105, 24);
		cout << "#";
	}
	gotoxy(95, 32);
	cout << "4-BACK MENU";
}
void Option(int& Tol, int& Arz, int& TedadToop)
{

	system("cls");
	PrintOption(TedadToop);
	int F;
	gotoxy(3, 44);
	cout << "WHAT YOU WANNA DO? INTER THAT NUMBER.";
	F = _getch() - '0';
	switch (F)
	{
	case(1):
		Tol = 7;
		Arz = 5;
		TedadToop = 7;
		break;
	case(2):
		Tol = 6;
		Arz = 4;
		TedadToop = 5;
		break;
	case(3):
		Tol = 5;
		Arz = 3;
		TedadToop = 3;
		break;
	case(4):
		menu();
		break;
	default:
		menu();
	}
	menu();
}
void Help()
{
	system("cls");
	system("color 06");
	Hashieyeh();
	char F;
	gotoxy(60, 5);
	cout << "Danial Saghiri";
	gotoxy(62, 6);
	cout << "4011226308";
	gotoxy(135, 5);
	cout << "Taha Khostavi";
	gotoxy(137, 6);
	cout << "4011226561";
	Sleep(2000);
	gotoxy(40, 20);
	cout << "NAHVEYE BAZI:shoma dar in bazi 3 halat EASY , MEDIUM va HARD darid ke mitavanid az tarigh MENU va entekhab OPTION taghiir dahid";
	Sleep(500);
	gotoxy(28, 21);
	cout << "ke dar halat EASY sabad ha be TOL 6 va ARZ 5 hastand va TEDADTOOP shoma 7 adad hast , dar halat MEDIUM sabad ha be TOL 5 va ARZ 6 va TEDADTOOP shoma 5 adad hast";
	Sleep(500);
	gotoxy(29, 22);
	cout << "dar halat HARD sabad ha be TOL 4 va ARZ 3 hastand va shoma 3 TEDADTOOP darekhtiyar darid SHOMA BARAYEH ESBAT KHODETON BE DIGARAN MOTINID RO HARD KAR KONID ;)";
	Sleep(500);
	gotoxy(32, 23);
	cout << " dar bazi ba tavajoh be taghrib shakhsi va mohasebat zehni mitavanid ba dadan X v Y monaseb shans khod ra barayeh partab khobi emtehan konid ";
	Sleep(500);
	gotoxy(53, 38);
	cout << "in prozhe be dalil ekhtelal bazehyeh zamani ba dargiri hayeh bozorgi tanha dar 2 roz anjam shodeh";
	Sleep(500);
	gotoxy(52, 39);
	cout << " va talash hayeh sorat gerefteh ba tavajoh be feshordegi mojod ba tamarkoz monasebi soorat nagareft ";
	Sleep(500);
	gotoxy(52, 40);
	cout << "vali bel ejbar prozheh be zahmat be zaman tahvil resid har chan az khodemon tavagho bishtari dashtim .";
	Sleep(500);
	gotoxy(78, 41);
	cout << "che mishe kard ke zanman monasebi nabod!!";
	Sleep(500);
	gotoxy(83, 42);
	cout << "( ba tashakor az zahamat shoma )";
	Sleep(500);
	gotoxy(84, 45);
	cout << "PRESS A LETTER FOR BACK TO MENU";
	F = _getch();
	menu();
}
void ScoreList()
{
	system("cls");
	Hashieyeh();
	system("color 04");
	ifstream RECORD("record.txt");
	string Oname;
	int Oemtiyazkol;
	int U = 0;
	int Y = 7;
	while (RECORD >> Oname>> Oemtiyazkol)
	{
		gotoxy(60, Y);
		cout << Oname;
		gotoxy(120, Y);
		cout << Oemtiyazkol;
		Y += 7;
		U += 1;
		if (U == 5)
			break;
	}
	int F;
	F = _getch();
	menu();
	/*system("cls");
	Hashieyeh();
	system("color 04");
	gotoxy(85, 24);
	cout << " ERROR....PRESS ANY LETTER TO BACK TO MENU";
	int F;
	F = _getch();
	menu();*/
}
int Exit()
{
	system("cls");
	Hashieyeh();
	gotoxy(85, 24);
	system("color 01");
	cout << "HOPE YOU ENJOYED!SEE YOU IN A ANOTHER FIELD";
	Sleep(2000);
	return 0;
}
