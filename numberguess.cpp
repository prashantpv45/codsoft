#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int answer=5;
    int guess;
    int health=0;
    int chances=3;
    bool gameover=false;
    while(answer != guess && ! gameover)

        if(health<chances)
        {
            cout<<"enter your number:";
            cin>>guess;
            health++;
        }
    else
    {
    gameover=true;
    }
    if(gameover){
        cout<<"you lost"<<endl;
    }else{
    cout<<"you win"<<endl;
    }
    getch();
    }







