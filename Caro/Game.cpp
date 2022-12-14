#include <string.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

char key,menu, back, again, turn ; //nút bấm: key là ingame, menu là trong menu, back là trong howtoplay, again là trong chiến thắng

char a[100][100], b[100][100]; //a là mảng X O , b là mảng menu 

long i = 0; // lượt chơi

int x, y; // tọa độ

int twinkle = 1;

int x1, y6, x2, y2, x3, y3, x4, y4, x5, y5;

int point1 = 0, point2 = 0;

//Hằng số

#define BOARD_SIZE 12 // Kích thức ma trận bàn cờ

#define TRAI 2 // Tọa độ trái màn hình bàn cờ

#define TREN 1 // Tọa độ trên màn hình bàn cờ

//Đổi màu chữ và màu nền
void TextColor(int x)//Xac dinh mau cua chu
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

// Hàm nhóm View
void FixConsoleWindow() {
	
		HWND consoleWindow = GetConsoleWindow();
	
		LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	
		style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	
		SetWindowLong(consoleWindow, GWL_STYLE, style);
	
}

// Hàm nhóm View
void GotoXY(int x, int y) {
	
		COORD coord;
	
		coord.X = x;
	
		coord.Y = y;
	
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	
}

//Ẩn chuột
void Hidden()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}

//Hiện con trỏ
void Appear()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}

//Khởi tạo mảng nguyên sơ
void BlankMatrix()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			a[i][j] = ' ';
			b[i][j] = ' ';
		}
	}
}

//vẽ console trắng
void White()
{
	for (int i = 0; i <= 29; i++)
	{
		for (int j = 0; j <= 119; j++)
		{
			TextColor(240);
			GotoXY(j, i);
			cout << " ";
		}
	}
}

//Chữ X O đứng trong Menu
void ChuXOdung()
{
	//Chữ X
	TextColor(244);
	GotoXY(31, 7); cout << "* * *                   * * *";
	GotoXY(33, 8); cout << "* * *               * * *";
	GotoXY(35, 9); cout << "* * *           * * *";
	GotoXY(37, 10); cout << "* * *       * * *";
	GotoXY(39, 11); cout << "* * *   * * *";
	GotoXY(41, 12); cout << "* * * * *";
	GotoXY(43, 13); cout << "* * *";
	GotoXY(41, 14); cout << "* * * * *";
	GotoXY(39, 15); cout << "* * *   * * *";
	GotoXY(37, 16); cout << "* * *       * * *";
	GotoXY(35, 17); cout << "* * *           * * *";
	GotoXY(33, 18); cout << "* * *               * * *";
	GotoXY(31, 19); cout << "* * *                   * * *";
	TextColor(240);

	//Chữ O
	TextColor(241);
	GotoXY(62, 7); cout << "* * * * * * * * * * * * *";
	GotoXY(62, 8);  cout << "* * * * * * * * * * * * *";
	GotoXY(62, 9); cout << "* *                   * *";
	GotoXY(62, 10); cout << "* *                   * *";
	GotoXY(62, 11); cout << "* *                   * *";
	GotoXY(62, 12); cout << "* *                   * *";
	GotoXY(62, 13); cout << "* *                   * *";
	GotoXY(62, 14); cout << "* *                   * *";
	GotoXY(62, 15); cout << "* *                   * *";
	GotoXY(62, 16); cout << "* *                   * *";
	GotoXY(62, 17); cout << "* *                   * *";
	GotoXY(62, 18);  cout << "* * * * * * * * * * * * *";
	GotoXY(62, 19);  cout << "* * * * * * * * * * * * *";
	TextColor(240);
} 

//Chữ X O chạy trong Intro
void ChuXOChay()
{
	//Chữ X
	TextColor(244);
	GotoXY(31, 7); cout << "* * *                   * * *";
	Sleep(100);
	GotoXY(33, 8); cout << "* * *               * * *";
	Sleep(100);
	GotoXY(35, 9); cout << "* * *           * * *";
	Sleep(100);
	GotoXY(37, 10); cout << "* * *       * * *";
	Sleep(100);
	GotoXY(39, 11); cout << "* * *   * * *";
	Sleep(100);
	GotoXY(41, 12); cout << "* * * * *";
	Sleep(100);
	GotoXY(43, 13); cout << "* * *";
	Sleep(100);
	GotoXY(41, 14); cout << "* * * * *";
	Sleep(100);
	GotoXY(39, 15); cout << "* * *   * * *";
	Sleep(100);
	GotoXY(37, 16); cout << "* * *       * * *";
	Sleep(100);
	GotoXY(35, 17); cout << "* * *           * * *";
	Sleep(100);
	GotoXY(33, 18); cout << "* * *               * * *";
	Sleep(100);
	GotoXY(31, 19); cout << "* * *                   * * *";
	Sleep(100);
	TextColor(240);

	//Chữ O
	TextColor(241);
	GotoXY(62, 7); cout << "* * * * * * * * * * * * *";
	Sleep(100);
	GotoXY(62, 8);  cout << "* * * * * * * * * * * * *";
	Sleep(100);
	GotoXY(62, 9); cout << "* *                   * *";
	Sleep(100);
	GotoXY(62, 10); cout << "* *                   * *";
	Sleep(100);
	GotoXY(62, 11); cout << "* *                   * *";
	Sleep(100);
	GotoXY(62, 12); cout << "* *                   * *";
	Sleep(100);
	GotoXY(62, 13); cout << "* *                   * *";
	Sleep(100);
	GotoXY(62, 14); cout << "* *                   * *";
	Sleep(100);
	GotoXY(62, 15); cout << "* *                   * *";
	Sleep(100);
	GotoXY(62, 16); cout << "* *                   * *";
	Sleep(100);
	GotoXY(62, 17); cout << "* *                   * *";
	Sleep(100);
	GotoXY(62, 18);  cout << "* * * * * * * * * * * * *";
	Sleep(100);
	GotoXY(62, 19);  cout << "* * * * * * * * * * * * *";
	TextColor(240);
} 

//kiểm tra chẵn lẽ chia lượt game 
int Chan(long i)
{
	if (i % 2 == 0) return 1;
	else return 0;
}

//lẻ lượt X, chẵn lượt O
char OX(long i)
{
	if (Chan(i) == 1) return 'X';
	else return 'O';
}

//Vẽ X O
void VeOX(long x, long y)
{
	if (a[x][y] != 'X' && a[x][y] != 'O') {
		if (Chan(i) == 1) TextColor(12); else TextColor(3);
		a[x][y] = OX(i);
		if (a[x][y] == 'X')
		{
			TextColor(244);
			cout << a[x][y];
		}

		if (a[x][y] == 'O')
		{
			TextColor(241);
			cout << a[x][y];
		}

		i += 1;
	}
	TextColor(7);
}

// Kẻ bàn cờ
void DrawBoard(int pSize) 
{
	//góc trái trên
	GotoXY(TRAI, TREN);
	putchar(218); 

	//hàng trên có móc
	for (int i = 3; i <= BOARD_SIZE+BOARD_SIZE; i+=2)
	{
		GotoXY(i * 2, TREN);
		putchar(194); 
	}

	//góc phải trên
	GotoXY((BOARD_SIZE +BOARD_SIZE +1) * 2, TREN);
	putchar(191);


	// ngang trên
	for (int i = 3; i < 6; i++)
	{
		GotoXY(i, TREN);
		putchar(196);
	}

	for (int i = 7; i < 10; i++)
	{
		GotoXY(i, TREN);
		putchar(196);
	}

	for (int i = 11; i < 14; i++)
	{
		GotoXY(i, TREN);
		putchar(196);
	}
	
	for (int i = 15; i < 18; i++)
	{
		GotoXY(i, TREN);
		putchar(196);
	}

	for (int i = 19; i < 22; i++)
	{
		GotoXY(i, TREN);
		putchar(196);
	}

	for (int i = 23; i < 26; i++)
	{
		GotoXY(i, TREN);
		putchar(196);
	}

	for (int i = 27; i < 30; i++)
	{
		GotoXY(i, TREN);
		putchar(196);
	}

	for (int i = 31; i < 34; i++)
	{
		GotoXY(i, TREN);
		putchar(196);
	}

	for (int i = 35; i < 38; i++)
	{
		GotoXY(i, TREN);
		putchar(196);
	}

	for (int i = 39; i < 42; i++)
	{
		GotoXY(i, TREN);
		putchar(196);
	}

	for (int i = 43; i < 46; i++)
	{
		GotoXY(i, TREN);
		putchar(196);
	}

	for (int i = 47; i < 50; i++)
	{
		GotoXY(i, TREN);
		putchar(196);
	}

	//cột dọc trái có móc
	for (int i = 1; i < BOARD_SIZE; i+=1)
	{
		GotoXY(TRAI,TREN + i * 2);
		putchar(195);
	}

	//cột dọc trái
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		GotoXY(TRAI, TREN + i*2 + 1);
		putchar(179);
	}

	//góc trái dưới
	GotoXY(TRAI, (BOARD_SIZE)*2+1);
	putchar(192);

	//ngang dưới có móc
	for (int i = 3; i <= BOARD_SIZE+BOARD_SIZE; i += 2)
	{
		GotoXY(i * 2, BOARD_SIZE +BOARD_SIZE+1);
		putchar(193);
	}

	//ngang dưới
	for (int i = 3; i < 6; i++)
	{
		GotoXY(i, BOARD_SIZE+BOARD_SIZE+1);
		putchar(196);
	}

	for (int i = 7; i < 10; i++)
	{
		GotoXY(i, BOARD_SIZE + BOARD_SIZE + 1);
		putchar(196);
	}

	for (int i = 11; i < 14; i++)
	{
		GotoXY(i, BOARD_SIZE + BOARD_SIZE + 1);
		putchar(196);
	}

	for (int i = 15; i < 18; i++)
	{
		GotoXY(i, BOARD_SIZE + BOARD_SIZE + 1);
		putchar(196);
	}

	for (int i = 19; i < 22; i++)
	{
		GotoXY(i, BOARD_SIZE + BOARD_SIZE + 1);
		putchar(196);
	}

	for (int i = 23; i < 26; i++)
	{
		GotoXY(i, BOARD_SIZE + BOARD_SIZE + 1);
		putchar(196);
	}

	for (int i = 27; i < 30; i++)
	{
		GotoXY(i, BOARD_SIZE + BOARD_SIZE + 1);
		putchar(196);
	}

	for (int i = 31; i < 34; i++)
	{
		GotoXY(i, BOARD_SIZE + BOARD_SIZE + 1);
		putchar(196);
	}

	for (int i = 35; i < 38; i++)
	{
		GotoXY(i, BOARD_SIZE + BOARD_SIZE + 1);
		putchar(196);
	}

	for (int i = 39; i < 42; i++)
	{
		GotoXY(i, BOARD_SIZE + BOARD_SIZE + 1);
		putchar(196);
	}

	for (int i = 43; i < 46; i++)
	{
		GotoXY(i, BOARD_SIZE + BOARD_SIZE + 1);
		putchar(196);
	}

	for (int i = 47; i < 50; i++)
	{
		GotoXY(i, BOARD_SIZE + BOARD_SIZE + 1);
		putchar(196);
	}

	//góc phải dưới
	GotoXY((BOARD_SIZE +BOARD_SIZE+ 1) * 2, BOARD_SIZE + BOARD_SIZE + 1);
	putchar(217);

	//cột dọc phải có móc
	for (int i = 1; i < BOARD_SIZE; i += 1)
	{
		GotoXY((BOARD_SIZE + BOARD_SIZE + 1) * 2, TREN + i * 2);
		putchar(180);
	}

	//cột dọc phải 
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		GotoXY((BOARD_SIZE + BOARD_SIZE + 1) * 2, TREN + i * 2 + 1);
		putchar(179);
	}

	//chữ thập bên trong
	for (int i = 3; i < BOARD_SIZE+BOARD_SIZE; i+=2)
	{
		for (int j = 3; j < BOARD_SIZE + BOARD_SIZE; j += 2)
		{
			GotoXY(j * 2, TREN * i);
			putchar(197);
		}
	}

	//ngang bên trong
	//ngang giua
	for (int i = 1; i <= BOARD_SIZE + BOARD_SIZE+2; i += 2)
	{
		for (int j = 2; j <= BOARD_SIZE + BOARD_SIZE+1; j += 2)
		{
			GotoXY(j * 2, TREN * i);
			putchar(196);
		}
	}

	//ngang trai
	for (int i = 1; i <= BOARD_SIZE + BOARD_SIZE+2; i += 2)
	{
		for (int j = 2; j <= BOARD_SIZE + BOARD_SIZE+1; j += 2)
		{
			GotoXY(j *2-1, TREN * i);
			putchar(196);
		}
	}

	//ngang phai
	for (int i = 1; i <= BOARD_SIZE + BOARD_SIZE+2; i += 2)
	{
		for (int j = 2; j <= BOARD_SIZE + BOARD_SIZE; j += 2)
		{
			GotoXY(j * 2 + 1, TREN * i);
			putchar(196);
		}
	}

	//dọc bên trong
	for (int i = 2; i <= BOARD_SIZE + BOARD_SIZE; i += 2)
	{
		for (int j = 3; j <= BOARD_SIZE + BOARD_SIZE; j += 2)
		{
			GotoXY(j * 2 , TREN * i);
			putchar(179);
		}
	}
}

//Kẻ khung ingame
void Frame()
{
	TextColor(240);
	// góc trái trên
	GotoXY(1, 0); putchar(201);

	//cột dọc trái
	for (int i = 1; i < 26; i++)
	{
		GotoXY(1, i); putchar(186);
	}
	GotoXY(1, 26); putchar(200);

	//ngang trên
	for (int i = 2; i < 85; i++)
	{
		GotoXY(i, 0); putchar(205); 
	}

	//ngang dưới
	for (int i = 2; i < 85; i++)
	{
		GotoXY(i, 26); putchar(205);
	}

	//góc phải trên
	GotoXY(85, 0); putchar(187); 

	//góc phải dưới
	GotoXY(85, 26); putchar(188); 

	//cột dọc phải
	for (int i = 1; i < 26; i++)
	{
		GotoXY(85, i); putchar(186);
	}

	//nút giữa trên
	GotoXY(51, 0); putchar(203);

	// nút giữ dưới
	GotoXY(51, 26); putchar(202); 

	//cột giữa
	for (int i = 1; i < 26; i++)
	{
		GotoXY(51, i); putchar(186);
	}

	GotoXY(51, 11); putchar(204);
	GotoXY(85, 11); putchar(185);

	//ngang giữa
	for (int i = 52; i < 85; i++)
	{
		GotoXY(i, 11); putchar(205);
	}

	TextColor(244);
	GotoXY(60, 2); putchar(177); cout << "     "; putchar(177);
	GotoXY(61, 3); putchar(177); cout << "   "; putchar(177);
	GotoXY(62, 4); putchar(177); cout << " "; putchar(177);
	GotoXY(63, 5); putchar(177);
	GotoXY(62, 6); putchar(177); cout << " "; putchar(177);
	GotoXY(61, 7); putchar(177); cout << "   "; putchar(177);
	GotoXY(60, 8); putchar(177); cout << "     "; putchar(177);


	TextColor(241);
	GotoXY(69, 2); putchar(177); putchar(177); putchar(177); putchar(177); putchar(177); putchar(177); putchar(177);
	GotoXY(69, 3); putchar(177); cout << "     "; putchar(177);
	GotoXY(69, 4); putchar(177); cout << "     "; putchar(177);
	GotoXY(69, 5); putchar(177); cout << "     "; putchar(177);
	GotoXY(69, 6); putchar(177); cout << "     "; putchar(177);
	GotoXY(69, 7); putchar(177); cout << "     "; putchar(177);
	GotoXY(69, 8); putchar(177); putchar(177); putchar(177); putchar(177); putchar(177); putchar(177); putchar(177);

	TextColor(244);
	GotoXY(54, 17); cout << "Player X: " << point1;
	TextColor(240);
	GotoXY(59, 18); cout << "VS";
	TextColor(241);
	GotoXY(54, 19); cout << "Player O: " << point2;

	TextColor(240);
	GotoXY(54, 12); cout << "Total turns: " << i;

	if (Chan(i) == 1)
	{
		GotoXY(54, 13); cout << "Turn: "; TextColor(244); cout << "X"; TextColor(240);
	}
	else if (Chan(i) == 0)
	{
		GotoXY(54, 13); cout << "Turn: "; TextColor(241); cout << "O"; TextColor(240);
	}

	GotoXY(54, 22); cout << "R: Reset";
	GotoXY(54, 23); cout << "L: Save game";
	GotoXY(54, 24); cout << "T: Load game";
	GotoXY(54, 25); cout << "ESC: Exit";
}

//Chạm biên 
void Bien(int &x,int &y)
{
	if (x >= 48) x = 48;
	if (x <= 4) x = 4;
	if (y <= 2) y = 2;
	if (y >= 24) y = 24;
}

//Điều kiện để O thắng
int winO()
{
	for (int h = 4; h <= 48; h += 4)       // h là hoành độ
	{
		for (int t = 2; t <= 24; t += 2)    //t là tung độ
		{
			//thắng theo hàng ngang
			if ((a[h][t] == 'O') && (a[h + 4][t] == 'O') && (a[h + 8][t] == 'O') && (a[h + 12][t] == 'O') && (a[h + 16][t] == 'O') && ((a[h + 20][t] != 'X') || (a[h - 4][t] != 'X')))
			{
				x1 = h;
				y6 = t;
				x2 = h + 4;
				y2 = t;
				x3 = h + 8;
				y3 = t;
				x4 = h + 12;
				y4 = t;
				x5 = h + 16;
				y5 = t;
				return 1;
			}

			//thắng theo hàng dọc
			if ((a[h][t] == 'O') && (a[h][t + 2] == 'O') && (a[h][t + 4] == 'O') && (a[h][t + 6] == 'O') && (a[h][t + 8] == 'O') && ((a[h][t + 10] != 'X') || (a[h][t - 2] != 'X')))
			{
				x1 = h;
				y6 = t;
				x2 = h;
				y2 = t + 2;
				x3 = h;
				y3 = t + 4;
				x4 = h;
				y4 = t + 6;
				x5 = h;
				y5 = t + 8;
				return 1;
			}

			//thắng theo hàng chéo qua phải
			if ((a[h][t] == 'O') && (a[h + 4][t + 2] == 'O') && (a[h + 8][t + 4] == 'O') && (a[h + 12][t + 6] == 'O') && (a[h + 16][t + 8] == 'O') && ((a[h + 20][t + 10] != 'X') || (a[h - 4][t - 2] != 'X')))
			{
				x1 = h;
				y6 = t;
				x2 = h + 4;
				y2 = t + 2;
				x3 = h + 8;
				y3 = t + 4;
				x4 = h + 12;
				y4 = t + 6;
				x5 = h + 16;
				y5 = t + 8;
				return 1;
			}

			//thắng theo hàng chéo qua trái
			//if ((a[h][t] == 'O') && (a[h - 4][t + 2] == 'O') && (a[h - 8][t + 4] == 'O') && (a[h - 12][t + 6] == 'O') && (a[h - 16][t + 8] == 'O') && ((a[h - 20][t + 10] != 'X') || (a[h + 4][t - 2] != 'X'))) return 1;
		}
	}

	for (int h = 20; h <= 48; h += 4)       // h là hoành độ
	{
		for (int t = 2; t <= 24; t += 2)    //t là tung độ
		{
			//thắng theo hàng chéo qua trái
			if ((a[h][t] == 'O') && (a[h - 4][t + 2] == 'O') && (a[h - 8][t + 4] == 'O') && (a[h - 12][t + 6] == 'O') && (a[h - 16][t + 8] == 'O') && ((a[h - 20][t + 10] != 'X') || (a[h + 4][t - 2] != 'X')))
			{
				x1 = h;
				y6 = t;
				x2 = h - 4;
				y2 = t + 2;
				x3 = h - 8;
				y3 = t + 4;
				x4 = h - 12;
				y4 = t + 6;
				x5 = h - 16;
				y5 = t + 8;
				return 1;
			}
		}
	}

	return 0;
}

//Điều kiện để X thắng
int winX()
{
	for (int h = 4; h <= 48; h += 4)       // h là hoành độ
	{
		for (int t = 2; t <= 24; t += 2)    //t là tung độ
		{
			//thắng theo hàng ngang
			if ((a[h][t] == 'X') && (a[h + 4][t] == 'X') && (a[h + 8][t] == 'X') && (a[h + 12][t] == 'X') && (a[h + 16][t] == 'X') && ((a[h + 20][t] != 'O') || (a[h - 4][t] != 'O')))
			{
				x1 = h;
				y6 = t;
				x2 = h + 4;
				y2 = t;
				x3 = h + 8;
				y3 = t;
				x4 = h + 12;
				y4 = t;
				x5 = h + 16;
				y5 = t;
				return 1;
			}

			//thắng theo hàng dọc
			if ((a[h][t] == 'X') && (a[h][t + 2] == 'X') && (a[h][t + 4] == 'X') && (a[h][t + 6] == 'X') && (a[h][t + 8] == 'X') && ((a[h][t + 10] != 'O') || (a[h][t - 2] != 'O')))
			{
				x1 = h;
				y6 = t;
				x2 = h;
				y2 = t + 2;
				x3 = h;
				y3 = t + 4;
				x4 = h;
				y4 = t + 6;
				x5 = h;
				y5 = t + 8;
				return 1;
			}

			//thắng theo hàng chéo qua phải
			if ((a[h][t] == 'X') && (a[h + 4][t + 2] == 'X') && (a[h + 8][t + 4] == 'X') && (a[h + 12][t + 6] == 'X') && (a[h + 16][t + 8] == 'X') && ((a[h + 20][t + 10] != 'O') || (a[h - 4][t - 2] != 'O')))
			{
				x1 = h;
				y6 = t;
				x2 = h + 4;
				y2 = t + 2;
				x3 = h + 8;
				y3 = t + 4;
				x4 = h + 12;
				y4 = t + 6;
				x5 = h + 16;
				y5 = t + 8;
				return 1;
			}

			//thắng theo hàng chéo qua trái
			//if ((a[h][t] == 'X') && (a[h - 4][t + 2] == 'X') && (a[h - 8][t + 4] == 'X') && (a[h - 12][t + 6] == 'X') && (a[h - 16][t + 8] == 'X') && ((a[h - 20][t + 10] != 'O') || (a[h + 4][t - 2] != 'O'))) return 1;
		}
	}

	for (int h = 20; h <= 48; h += 4)       // h là hoành độ
	{
		for (int t = 2; t <= 24; t += 2)    //t là tung độ
		{
			//thắng theo hàng chéo qua trái
			if ((a[h][t] == 'X') && (a[h - 4][t + 2] == 'X') && (a[h - 8][t + 4] == 'X') && (a[h - 12][t + 6] == 'X') && (a[h - 16][t + 8] == 'X') && ((a[h - 20][t + 10] != 'O') || (a[h + 4][t - 2] != 'O')))
			{
				x1 = h;
				y6 = t;
				x2 = h - 4;
				y2 = t + 2;
				x3 = h - 8;
				y3 = t + 4;
				x4 = h - 12;
				y4 = t + 6;
				x5 = h - 16;
				y5 = t + 8;
				return 1;
			}
		}
	}

	
	return 0;
}

//save game
void Save()
{
	ofstream save;
	save.open("caro.txt", ios_base::out);
	save << i << " " << point1 << " " << point2 << " ";

	for (int x = 4; x <= 48; x += 4)       
	{
		for (int y = 2; y <= 24; y += 2)    
		{
			if (a[x][y] == 'X')
			{
				save << x << " " << y << " " << 'X';
			}
			if (a[x][y] == 'O')
			{
				save << x << " " << y << " " << 'O';
			}
		}
	}

	save.close();
	Hidden();
	TextColor(242);
	GotoXY(61, 10); cout << "Game is saved";
	Sleep(2500);
	GotoXY(61, 10); cout << "             ";
	TextColor(240);
	GotoXY(x, y);
	Appear();
}

//loadgame
void Load()
{
	char temp;
	system("cls");
	BlankMatrix();
	White();
	DrawBoard(BOARD_SIZE);
	Frame();
	ifstream load;

	load.open("caro.txt", ios_base::in);
	load >> i;
	load >> point1;
	load >> point2;

	for (int j = 0; j <= i; j++)
	{
		load >> x;
		load >> y;
		load >> temp;
		a[x][y] = temp;
		GotoXY(x, y); 
		if (temp == 'X')
		{
			TextColor(244);
			cout << temp;
		}
		if (temp == 'O')
		{
			TextColor(241);
			cout << temp;
		}
	}
	load.close();

	TextColor(240);
	if (Chan(i) == 1)
	{
		GotoXY(54, 13); cout << "Turn: "; TextColor(244); cout << "X"; TextColor(240);
	}
	else if (Chan(i) == 0)
	{
		GotoXY(54, 13); cout << "Turn: "; TextColor(241); cout << "O"; TextColor(240);
	}
	TextColor(244);
	GotoXY(54, 17); cout << "Player X: " << point1;
	TextColor(240);
	GotoXY(59, 18); cout << "VS";
	TextColor(241);
	GotoXY(54, 19); cout << "Player O: " << point2;

	TextColor(240);
	GotoXY(54, 12); cout << "Total turns: " << i;
	GotoXY(x, y);
}

//Vào game
void VaoGame()
{
	system("cls");
	White();
	Appear();
	x = 4;
	y = 2;
	BlankMatrix();
	i = 0; //TO DO

	//Hiển thị
	DrawBoard(BOARD_SIZE);//Vẽ bàn cờ
	Frame();

	while (1)
	{

		//Điều khiển
		GotoXY(x, y); //Điểm ban đầu

		//Player X A S D W SPACE
		if (i % 2 == 0)
		{
			if (_kbhit())
			{
				key = _getch();
				if (key == 'D' or key == 'd')
				{
					x = x + 4;
					Bien(x, y);  //Xử lí chạm biên


				}
				if (key == 'S' or key == 's')
				{
					y = y + 2;
					Bien(x, y);  //Xử lí chạm biên


				}
				if (key == 'A' or key == 'a')
				{
					x = x - 4;
					Bien(x, y);  //Xử lí chạm biên


				}
				if (key == 'W' or key == 'w')
				{
					y = y - 2;
					Bien(x, y);  //Xử lí chạm biên

				}
				if (key == ' ') // Điền X bằng space
				{


					VeOX(x, y);

					//HIỆN THỊ

					TextColor(240);
					GotoXY(54, 12); cout << "Total turns: " << i;


					// Hiện lượt X hay O

					if (Chan(i) == 1)
					{
						GotoXY(54, 13); cout << "Turn: "; TextColor(244); cout << "X"; TextColor(240);
					}
					else if (Chan(i) == 0)
					{
						GotoXY(54, 13); cout << "Turn: "; TextColor(241); cout << "O"; TextColor(240);
					}

					GotoXY(x, y); //Trả con trỏ về vị trí hiện tại

				}

				if (key == 'R' or key == 'r')
				{
					VaoGame();
					break;
				}
				if (key == 27) break;
				if (key == 'L' or key == 'l') Save();
				if (key == 'T' or key == 't') Load();

			}
		}

		//player O mũi tên + enter
		else
		{
			if (_kbhit())
			{
				key = _getch();
				if (key == 77)
				{
					x = x + 4;
					Bien(x, y);  //Xử lí chạm biên


				}
				if (key == 80)
				{
					y = y + 2;
					Bien(x, y);  //Xử lí chạm biên


				}
				if (key == 75)
				{
					x = x - 4;
					Bien(x, y);  //Xử lí chạm biên


				}
				if (key == 72)
				{
					y = y - 2;
					Bien(x, y);  //Xử lí chạm biên

				}
				if (key == 13) // Điền O bằng enter
				{


					VeOX(x, y);

					//HIỆN THỊ

					TextColor(240);
					GotoXY(54, 12); cout << "Total turns: " << i;


					// Hiện lượt X hay O

					if (Chan(i) == 1)
					{
						GotoXY(54, 13); cout << "Turn: "; TextColor(244); cout << "X"; TextColor(240);
					}
					else if (Chan(i) == 0)
					{
						GotoXY(54, 13); cout << "Turn: "; TextColor(241); cout << "O"; TextColor(240);
					}
					GotoXY(x, y); //Trả con trỏ về vị trí hiện tại

				}

				if (key == 'r' or key == 'R') {
					VaoGame();
					exit(0);
					
				}
				if (key == 27) exit(0);
				if (key == 'L' or key == 'l') Save();
				if (key == 'T' or key == 't') Load();
			}
		}

		//Xử lí thắng thua

		//Khi O thắng
		if (winO() == 1)
		{
			
			Hidden();
			TextColor(241);
			GotoXY(x1, y6); cout << " ";
			GotoXY(x2, y2); cout << " ";
			GotoXY(x3, y3); cout << " ";
			GotoXY(x4, y4); cout << " ";
			GotoXY(x5, y5); cout << " ";
			Sleep(500);
			GotoXY(x1, y6); cout << "O";
			GotoXY(x2, y2); cout << "O";
			GotoXY(x3, y3); cout << "O";
			GotoXY(x4, y4); cout << "O";
			GotoXY(x5, y5); cout << "O";
			Sleep(500);
			GotoXY(x1, y6); cout << " ";
			GotoXY(x2, y2); cout << " ";
			GotoXY(x3, y3); cout << " ";
			GotoXY(x4, y4); cout << " ";
			GotoXY(x5, y5); cout << " ";
			Sleep(500);
			GotoXY(x1, y6); cout << "O";
			GotoXY(x2, y2); cout << "O";
			GotoXY(x3, y3); cout << "O";
			GotoXY(x4, y4); cout << "O";
			GotoXY(x5, y5); cout << "O";
			Sleep(500);
			GotoXY(x1, y6); cout << " ";
			GotoXY(x2, y2); cout << " ";
			GotoXY(x3, y3); cout << " ";
			GotoXY(x4, y4); cout << " ";
			GotoXY(x5, y5); cout << " ";
			Sleep(500);
			GotoXY(x1, y6); cout << "O";
			GotoXY(x2, y2); cout << "O";
			GotoXY(x3, y3); cout << "O";
			GotoXY(x4, y4); cout << "O";
			GotoXY(x5, y5); cout << "O";
			Sleep(500);
			GotoXY(x1, y6); cout << " ";
			GotoXY(x2, y2); cout << " ";
			GotoXY(x3, y3); cout << " ";
			GotoXY(x4, y4); cout << " ";
			GotoXY(x5, y5); cout << " ";
			Sleep(500);

			TextColor(240);


			system("cls");
			White();
			//O win
			TextColor(241);
			GotoXY(43, 10); cout << "* * * * * * * * * * * * *";
			GotoXY(43, 11);  cout << "* * * * * * * * * * * * *";
			GotoXY(43, 12); cout << "* *                   * *";
			GotoXY(43, 13); cout << "* *                   * *";
			GotoXY(43, 14); cout << "* *                   * *";
			GotoXY(43, 15); cout << "* *                   * *";
			GotoXY(43, 16); cout << "* *                   * *";
			GotoXY(43, 17); cout << "* *                   * *";
			GotoXY(43, 18); cout << "* *                   * *";
			GotoXY(43, 19); cout << "* *                   * *";
			GotoXY(43, 20); cout << "* *                   * *";
			GotoXY(43, 21);  cout << "* * * * * * * * * * * * *";
			GotoXY(43, 22);  cout << "* * * * * * * * * * * * *";
			TextColor(246);
			GotoXY(41, 8); cout << "* * * * * * * * * * * * * * *"; //Vương miện
			GotoXY(41, 7); cout << "* * * * * * * * * * * * * * *";
			GotoXY(41, 6); cout << " * * *      * * *      * * *";
			GotoXY(41, 5); cout << "  * *	      * *        * * ";
			GotoXY(41, 4); cout << "   *	       *          *";

			TextColor(240);
			GotoXY(43, 24); cout << "Do you want to play again?"; //Ask to play again
			GotoXY(43, 25); cout << "(Y) Yes";
			GotoXY(63, 25); cout << "(N) NO";

			while (1)
			{
				again = _getch();
				if (again == 'y' or again == 'Y')
				{
					point2 += 1;
					VaoGame();
					exit(0);
				}

				if (again == 'n' or again == 'N') exit(0);
			}
			Appear();
		}

		//Khi X thắng
		if (winX() == 1)
		{
		
			Hidden();

			TextColor(244);
			GotoXY(x1, y6); cout << " ";
			GotoXY(x2, y2); cout << " ";
			GotoXY(x3, y3); cout << " ";
			GotoXY(x4, y4); cout << " ";
			GotoXY(x5, y5); cout << " ";
			Sleep(500);
			GotoXY(x1, y6); cout << "X";
			GotoXY(x2, y2); cout << "X";
			GotoXY(x3, y3); cout << "X";
			GotoXY(x4, y4); cout << "X";
			GotoXY(x5, y5); cout << "X";
			Sleep(500);
			GotoXY(x1, y6); cout << " ";
			GotoXY(x2, y2); cout << " ";
			GotoXY(x3, y3); cout << " ";
			GotoXY(x4, y4); cout << " ";
			GotoXY(x5, y5); cout << " ";
			Sleep(500);
			GotoXY(x1, y6); cout << "X";
			GotoXY(x2, y2); cout << "X";
			GotoXY(x3, y3); cout << "X";
			GotoXY(x4, y4); cout << "X";
			GotoXY(x5, y5); cout << "X";
			Sleep(500);
			GotoXY(x1, y6); cout << " ";
			GotoXY(x2, y2); cout << " ";
			GotoXY(x3, y3); cout << " ";
			GotoXY(x4, y4); cout << " ";
			GotoXY(x5, y5); cout << " ";
			Sleep(500);
			GotoXY(x1, y6); cout << "X";
			GotoXY(x2, y2); cout << "X";
			GotoXY(x3, y3); cout << "X";
			GotoXY(x4, y4); cout << "X";
			GotoXY(x5, y5); cout << "X";
			Sleep(500);
			GotoXY(x1, y6); cout << " ";
			GotoXY(x2, y2); cout << " ";
			GotoXY(x3, y3); cout << " ";
			GotoXY(x4, y4); cout << " ";
			GotoXY(x5, y5); cout << " ";
			Sleep(500);

			TextColor(240);
			system("cls");
			White();

			TextColor(244);
			GotoXY(41, 10); cout << "* * *                  * * *";
			GotoXY(43, 11); cout << "* * *               * * *";
			GotoXY(45, 12); cout << "* * *           * * *";
			GotoXY(47, 13); cout << "* * *       * * *";
			GotoXY(49, 14); cout << "* * *   * * *";
			GotoXY(50, 15); cout << "* * * * *";
			GotoXY(53, 16); cout << "* * *";
			GotoXY(50, 17); cout << "* * * * *";
			GotoXY(49, 18); cout << "* * *   * * *";
			GotoXY(47, 19); cout << "* * *       * * *";
			GotoXY(45, 20); cout << "* * *           * * *";
			GotoXY(43, 21); cout << "* * *               * * *";
			GotoXY(41, 22); cout << "* * *                   * * *";

			TextColor(246);
			GotoXY(41, 8); cout << "* * * * * * * * * * * * * * *"; //Vương miện
			GotoXY(41, 7); cout << "* * * * * * * * * * * * * * *";
			GotoXY(41, 6); cout << " * * *      * * *      * * *";
			GotoXY(41, 5); cout << "  * *	      * *        * * ";
			GotoXY(41, 4); cout << "   *	       *          *";

			TextColor(240);
			GotoXY(43, 24); cout << "Do you want to play again?"; //Ask to play again
			GotoXY(43, 25); cout << "(Y) Yes";
			GotoXY(63, 25); cout << "(N) NO";

			while (1)
			{
				again = _getch();
				if (again == 'y' or again == 'Y')
				{
					point1 += 1;
					VaoGame();
					exit(0);
				}

				if (again == 'n' or again == 'N') exit(0);
			}
			Appear();
		}



		if (i == 144) //Khi hòa
		{
			Hidden();
			system("cls");
			White();

			//chữ X
			TextColor(244);
			GotoXY(27, 10); cout << "* * *                  * * *";
			GotoXY(28, 11); cout << "* * *               * * *";
			GotoXY(30, 12); cout << "* * *           * * *";
			GotoXY(32, 13); cout << "* * *       * * *";
			GotoXY(34, 14); cout << "* * *   * * *";
			GotoXY(35, 15); cout << "* * * * *";
			GotoXY(38, 16); cout << "* * *";
			GotoXY(35, 17); cout << "* * * * *";
			GotoXY(34, 18); cout << "* * *   * * *";
			GotoXY(32, 19); cout << "* * *       * * *";
			GotoXY(30, 20); cout << "* * *           * * *";
			GotoXY(28, 21); cout << "* * *               * * *";
			GotoXY(26, 22); cout << "* * *                   * * *";

			TextColor(246);
			GotoXY(41, 8); cout << "* * * * * * * * * * * * * * *"; //Vương miện
			GotoXY(41, 7); cout << "* * * * * * * * * * * * * * *";
			GotoXY(41, 6); cout << " * * *      * * *      * * *";
			GotoXY(41, 5); cout << "  * *	      * *        * * ";
			GotoXY(41, 4); cout << "   *	       *          *";

			//chữ O
			TextColor(241);
			GotoXY(57, 10); cout << "* * * * * * * * * * * * *";
			GotoXY(57, 11);  cout << "* * * * * * * * * * * * *";
			GotoXY(57, 12); cout << "* *                   * *";
			GotoXY(57, 13); cout << "* *                   * *";
			GotoXY(57, 14); cout << "* *                   * *";
			GotoXY(57, 15); cout << "* *                   * *";
			GotoXY(57, 16); cout << "* *                   * *";
			GotoXY(57, 17); cout << "* *                   * *";
			GotoXY(57, 18); cout << "* *                   * *";
			GotoXY(57, 19); cout << "* *                   * *";
			GotoXY(57, 20); cout << "* *                   * *";
			GotoXY(57, 21);  cout << "* * * * * * * * * * * * *";
			GotoXY(57, 22);  cout << "* * * * * * * * * * * * *";


			TextColor(240);
			GotoXY(43, 24); cout << "Do you want to play again?"; //Ask to play again
			GotoXY(43, 25); cout << "(Y) Yes";
			GotoXY(63, 25); cout << "(N) NO";


			while (1)
			{
				again = _getch();
				if (again == 'y' or again == 'Y')
				{
					VaoGame();
					exit(0);
				}

				if (again == 'n' or again == 'N') exit(0);
			}
		}
		Sleep(1);
	}
}

//Menu game
void Menu()
{
	system("cls");
	Hidden();
	White();
	ChuXOdung();
	TextColor(240);
	x = 51;
	y = 22;


	GotoXY(53, 22); cout << "Stat game";
	GotoXY(53, 23); cout << "How to play";
	GotoXY(53, 24); cout << "Quit";
	GotoXY(x, y); putchar(175);


	while (1)
	{





		if (_kbhit())
		{

			menu = _getch();

			if (menu == 'S' or menu == 's' or menu == 80)
			{
				y = y + 1;
				if (y > 24) y = 22;

				system("cls");
				ChuXOdung();
				GotoXY(53, 22); cout << "Stat game";
				GotoXY(53, 23); cout << "How to play";
				GotoXY(53, 24); cout << "Quit";
				GotoXY(x, y); putchar(175);


			}

			if (menu == 'W' or menu == 'w' or menu == 72)
			{
				y = y - 1;
				if (y < 22) y = 24;

				system("cls");
				ChuXOdung();
				GotoXY(53, 22); cout << "Stat game";
				GotoXY(53, 23); cout << "How to play";
				GotoXY(53, 24); cout << "Quit";
				GotoXY(x, y); putchar(175);


			}
			if (menu == 13 or menu == ' ') // enter or space để chon mục 
			{
				if (b[x][y] != 'c')
				{
					b[x][y] = 'c';
				}

				// Vào game
				if (b[51][22] == 'c')
				{
					VaoGame();
					break;
				}

				// Hướng dẫn chơi
				if (b[51][23] == 'c')
				{
					system("cls");
					White();
					Hidden();
					GotoXY(47, 7); cout << "Player 1:";
					GotoXY(47, 8); cout << "Press A, S, D, W to move";
					GotoXY(47, 9); cout << "Press SPACE to input "; TextColor(244); cout << "X "; TextColor(240);

					GotoXY(47, 13); cout << "Player 2: ";
					GotoXY(47, 14); cout << "Press KEYBOARD ARROW to move";
					GotoXY(47, 15); cout << "Press ENTER to input ";  TextColor(241); cout << "O "; TextColor(240);

					GotoXY(45, 20); putchar(247);
					GotoXY(68, 20); putchar(247);
					GotoXY(47, 20); cout << "FIVE IN A ROW TO WIN";

					GotoXY(53, 24); cout << "Back";
					GotoXY(51, 24); putchar(175);
					
					turn = _getch();
					if (turn == ' ' or turn == 13)
					{
						BlankMatrix();
						Menu();
						break;
					}
				}

				// Thoát
				if (b[51][24] == 'c') break; 

			}

		}
	}
}

//Intro trước khi vào menu
void Intro()
{
	Hidden();
	White();

	ChuXOChay();

	//Chạy loading
	TextColor(10);
	GotoXY(0, 29);
	for (int i = 0; i < 20; i++)
	{
		putchar(219);
		Sleep(20);
	}

	putchar(219);
	Sleep(800);

	for (int i = 20; i < 110; i++)
	{
		putchar(219);
		Sleep(20);
	}

	putchar(219);
	Sleep(1000);
	for (int i = 110; i < 118; i++)
	{
		putchar(219);
		Sleep(20);
	}


	GotoXY(0, 29);
	for (int i = 0; i < 188; i++)
	{
		TextColor(240);
		cout << ' ';
	}
	Appear();

}

int main()
{
	//Cố định màn hình console
	FixConsoleWindow(); 

	Intro(); 
	Menu();

	return 0;
}