#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
//#include <stdio.h>
//#include <conio.h>
//#include <dos.h>
#include <unistd.h>
#include <fstream>

using namespace std;

// These are global variables that are needed for the AI
int myFakeLoop = 0;
bool imDone = false;
// ----------------------------------------------------
void printHeader()
{
    cout<< "     " << "Turn" << "     " << "Total" << setw(14) << " " << setw(5) << "Turn" <<  "    " << "Total" << endl << endl;
}
// Prints the first two columns
void printMyTurn(int turn, int loopI)
{
    cout << setw(5);
    if(loopI ==75){
    cout << "YOU";
    } else
    {
        cout << "";
    }

    if(turn>=loopI&&turn<loopI+5){cout << setw(3) << turn << "> ";} else {cout << setw(5) << ""; }

    return;
}
// ----------------------------------------------------

// Prints the third column
void printNumberP(int loopI)
{

    cout << setw(3) << left;
    cout << loopI;
    cout << right;

    return;
}
// ----------------------------------------------------

// prints next column
void printMyTotal(int total, int loopI)
{
    if(total>=loopI&&total<loopI+5){cout<<" <" << setw(3)<< total;}else{cout<<setw(5)<<"";}

    return;
}
// ----------------------------------------------------

// prints next column and the die
void printDialog(int loopI, int d)
{
    cout << setw(15);
    if(loopI==80)
    {
        cout << "     -----     ";
    }else if(loopI==75)
    {
        cout << "    /     \\    ";
    } else if (loopI==70)
    {
        cout << setw(7) << "    |  " << setw(1) << d << setw(7) << "  |    ";
    } else if(loopI==65)
    {
        cout << setw(15) << "    \\     /    ";
    }
    else if (loopI==60)
    {
        cout << setw(15) << "     -----     ";
    } else {
        cout << "";
    }
    return;
}
// -----------------------------------------------------------

// These functions print devil information
void printYourTurn(int sTurn, int loopI)
{
    if(sTurn>=loopI&&sTurn<loopI+5){cout << setw(3) << sTurn << "> ";} else {cout << setw(5) << ""; }
    return;
}
void printNumberS(int loopI )
{
    cout << setw(3);
    cout << loopI;
    return;
}
void printYourTotal(int sTotal, int loopI)
{
     if(sTotal>=loopI&&sTotal<loopI+5){cout<<" <" << setw(3)<< sTotal;}else{cout<<setw(5)<<"";}
     if (loopI == 75) cout << "SATAN";
     cout << endl;
     return;
}
// ---------------------------------------------------------

// This function loops all the printing function and passes the arguments
void printAll(int pTurn, int pTotal, int sTurn, int sTotal, int die)
{
    cout << endl;
    printHeader();
    for(int i=100; i >-1; i-=5){
    printMyTurn(pTurn,i);
    printNumberP(i);
    printMyTotal(pTotal,i);
    printDialog(i,die);
    printYourTurn(sTurn,i);
    printNumberS(i);
    printYourTotal(sTotal,i);
    }

    return;
}
// -------------------------------------------------------

// rolls the die
int rollDie()
{
    return rand()%6+1;
}
//--------------------------------------------------------

// AI
char satanAI(int plr, int pt, int ht)
{


    if(pt-ht<0)
    {

        if(myFakeLoop == 2){
            myFakeLoop = 0;
            return 'p';
        }
        myFakeLoop++;
        return 'r';

    }

    if(pt-ht>=0)
    {


        if(myFakeLoop==3)
        {
           if(plr>4&&!imDone)
           {
               imDone = true;
               return 'r';

           } else
           {
               imDone = false;
               myFakeLoop = 0;
               return 'p';
           }


        }
        myFakeLoop++;
        return 'r';
    }
    return 'f';
}
//------------------------------------------------------------
int main()
{
    srand(time(0));
    ifstream scoreIn;
    ofstream scoreOut;




    bool youWin = false;

    bool rematch = true;
    int lastRoll;
    int myTurnTotal = 0;
    int myTotal = 0;
    int hisTurnTotal = 0;
    int hisTotal = 0;
    int die = 6;
    bool yourTurn = true;
    bool keepPlaying =  true;
    char response = 'x';
    char resTwo = 'x';
while(rematch){
    scoreIn.open("score.txt");

    int win;
    int loss;
    if(!scoreIn){ win = 0, loss =0;}
    else {scoreIn >> win;
    scoreIn >> loss;}

    cout << "WINS: " << win << " LOSSES: " << loss;
    scoreIn.close();
// THIS IS THE GAME  LOOP --------------------------------------------------------
    while(keepPlaying){
        die=6;
        // PLAYER TURN
        while(keepPlaying&&yourTurn){
            printAll(myTurnTotal, myTotal, hisTurnTotal, hisTotal, die);
            cout << "CHOOSE WISELY: Roll[r], Pass[p], Forfeit[f]: ";
            cin >> response;

            if(response == 'f'){
                keepPlaying = false;
            } else if (response == 'r')
            {
                // do something for my turn
                die = rollDie();
                if(die!=1){
                    myTurnTotal+=die;
                    lastRoll = die;
                    if (myTurnTotal >= 100){
                        keepPlaying=false;
                        youWin = true;
                        myTurnTotal = 100;
                        myTotal = 100;
                        break;

                    }
                } else
                {
                    myTurnTotal = myTotal;
                    yourTurn =  false;
                    printAll(myTurnTotal, myTotal, hisTurnTotal, hisTotal, die);
                }

            } else if (response == 'p')
            {
               myTotal += myTurnTotal-myTotal;
               myTurnTotal = myTotal;
               yourTurn = false;

            }
        }
        if(response=='r'&&!youWin)
        {
            cout << "Too bad, you rolled a one! MUAHAHAHAHA" << endl;
        }
        else
        {
            cout << "Hmmm, good turn..." << endl;
        }
        die=6;

        sleep(1.5);

        //SATANS TURN
        while(die!=1&&keepPlaying&&!yourTurn)
        {
            printAll(myTurnTotal, myTotal, hisTurnTotal, hisTotal, die);
            sleep(.8);
            response = satanAI(lastRoll, myTotal, hisTotal);
            if(response == 'r')
            {
                die = rollDie();
                if(die!=1){
                    hisTurnTotal+=die;
                    if(hisTurnTotal>=100){
                        keepPlaying=false;
                        youWin = false;
                        hisTurnTotal = 100;
                        hisTotal = 100;
                        break;
                    }
                } else
                {
                    hisTurnTotal = hisTotal;
                    yourTurn =  true;
                    myFakeLoop = 0;
                    printAll(myTurnTotal, myTotal, hisTurnTotal, hisTotal, die);
                }
            } else
            {
                hisTotal += hisTurnTotal-hisTotal;
                hisTurnTotal = hisTotal;
                yourTurn = true;
            }

        }

        if(response=='r'&&yourTurn)
        {
            cout << "Garrrr..." << endl;
        }
        else
        {
            cout << "Your soul will be mine!" << endl;
        }
        sleep(1.5);
    }
// END OF GAME ---------------------------------------------------------------
    printAll(myTurnTotal, myTotal, hisTurnTotal, hisTotal, die);
    if(youWin)
    {
        cout << endl << endl;
        cout << "You have saved your soul. \n";
        cout << "You will not be so lucky next time we play..." << endl;
        ++win;
        cout << "WINS: " << win << " LOSSES: " << loss << endl;
        scoreOut.open("score.txt");
        scoreOut << win << endl;
        scoreOut << loss << endl;
        scoreOut.close();

    } else
    {
        cout << endl << endl;
        cout << "The devil ate your soul. \n";
        cout << "Game Over" << endl;
        ++loss;
        cout << "WINS: " << win << " LOSSES: " << loss << endl;
        scoreOut.open("score.txt");
        scoreOut << win << endl;
        scoreOut << loss << endl;
        scoreOut.close();
    }
    cout << "Would you like to keep playing?[n] for 'no' or any other key for yes: >" << endl;
    cin >> resTwo;
    if(resTwo == 'n')
    {
        rematch = false;

    } else
    {
        keepPlaying = true;
        myTurnTotal = 0;
        myTotal = 0;
        hisTotal = 0;
        hisTurnTotal = 0;

    }
}
    return 0;
}

