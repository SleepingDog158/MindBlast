#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

int main(){
srand(time(0));
int x, y ,z, t, asw, guess, p=0;
x = rand() % 50 + 1;
y = rand() % 50 + 1;
z = rand() % 100 +1;
t = x+y;
if(t<z){asw = 1;};
if(t==z){asw = 2;};
if(t>z){asw =3;};
cout << x << "  +  " << y << "     " << z << "     " << "score: " << p << endl;
cin >> guess;
if(guess != asw){ cout << "GAME OVER!!!" << endl;}
else do{
    system("cls");
    p++;
    x = rand() % 50 + 1;
    y = rand() % 50 + 1;
    z = rand() % 100 +1;
    t = x+y;
    if(t<z){asw = 1;};
    if(t==z){asw = 2;};
    if(t>z){asw =3;};
    cout << x << "  +  " << y << "     " << z << "     " << "score: " << p << endl;
    cin >> guess;
    if(guess!= asw){
        cout << "GAME OVER" << endl;
        return 0;
        }
}while(guess == asw);
}

