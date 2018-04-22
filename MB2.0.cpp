#include<iostream>
#include<ctime>
#include<Windows.h>
#include<conio.h>

using namespace std;

bool gameOver;
int a,b,c;
int score;
int countdown;
int delay;

void tutorial() {
	system("cls");
	cout << "MIND BLAST"<< endl << endl;
	cout << "So sanh phep tinh ben trai va so ben phai" << endl << endl;
	cout << "Nhan 1: nho hon  <  " << endl;
	cout << "Nhan 2: bang  =  " << endl;
	cout << "Nhan 3: lon hon  >  " << endl << endl;
	cout << "Nhan S de bat dau" ;
	if (getch()=='s') return;
	else tutorial();
}

void reup() {
	gameOver=false;
	score=0;
	delay=1000;
}

void setup() {
	a=1+rand() % 50;
	b=1+rand() % 50;

	int temp; temp=rand() % 4;
	if (temp==3)
		c=a+b;
	else c=1+rand() % 100;

	countdown=3;
}

void draw() {
	cout << "score: " << score << "\t\t1: < \t2: = \t3: >" << endl;
	cout << a  << " + " << b << "\t\t" << c << endl;
	cout << endl << endl;
}

void control() {
	switch (getch()) {
		case '1':
			if (a+b<c) score+=10;
			else gameOver=true;
			break;
		case '2':
			if (a+b==c) score+=10;
			else gameOver=true;
			break;
		case '3':
			if (a+b>c) score+=10;
			else gameOver=true;
			break;
	}
}

void logic() {
	cout << "countdown: ";
	while (!kbhit()) {
		cout << countdown << "...";
		Sleep(delay);
		countdown--;
		if (countdown<0) return;
	}
	if (score>0 && score%100==0 && score<1000) delay-=70;
}

int main() {
	srand(time(NULL));
	tutorial();
	reup();
	while (!gameOver) {
        system("cls");
        setup();
		draw();
		logic();
		if (!kbhit()) gameOver=true;
		else control();
		if (gameOver) {
			system("cls");
			cout << "GAME OVER!!" << endl;
			cout << "score: " << score << endl;
			cout << "An R de choi lai...";
			if (getch()=='r') reup();
		}
	}
	return 0;
}
