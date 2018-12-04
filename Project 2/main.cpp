/* File:   main.cpp
 * Author: Kevin Ortega
 * Created on December 3, 2018, 1:18 PM
 * Purpose: To play Blackjack for Project 2.
 */

//System Libraries
#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions


//Function Prototypes Here
int dlrTotl( int d_card1, int d_card2 ); //Dealers total
int plyTotl( int p_card1, int p_card2 ); //Players total

//Program Execution Begins Here
int main (){   
//Declare Here
const float value=1.5;
const int ten=10;
const int eleven=11;
const int twelve=12;
const int thirten=13;
int i;
int choices;       //How many times you'll play
char y;            //To start game
string a= "Ace";   //Name of the cards
string b= "Jack";
string c= "King";
string d= "Queen";
bool inCheck;      //Check input
ofstream myfile;   //File Object
ifstream myfile2;
float ttlWagr = 0;//Total Wager

//Random Function for cards   
srand((unsigned)time(0));

    do{
        inCheck=false;        
        //Start the game if the user inputs y (yes)
        cout << setfill('-') << "Welcome. Let's play some Blackjack! Press (y/n) to play.";
        cout << setfill('-');
        cin >> y;
        if( y == 'y' || y == 'n' ){
            inCheck=true;
        }
    }while(!inCheck);

    //Game starts here
    if( y != 'n' ){
    cout << "\nEnter the number of games you'll play.";
    cin >> choices;//Player chooses how many games they'll play
	for( i = 0; i < choices; i++ ){
            cout << "How much do you want to wager?" << endl;
            cout << setw(10) << "\n" << "Please place your wager: $";
            float wager;
            cin >> wager;	               //Wager for bidding
            int d_card1 = rand() % 13 + 1;     //Dealer card 1 value
            int d_card2 = rand() % 13 + 1;     //Dealer card 2 value
            int p_card1 = rand() % 13 + 1;     //Player card 1 value
            int p_card2 = rand() % 13 + 1;     //Player card 2 value
            cout << "\n" << "The dealer has "; //To check what cards the dealer has
            switch ( d_card1 ) {
                    case 1: cout << a; 
                            break;
                    case 11: cout << b; 
                            break;
                    case 12: cout << c;
                            break;
                    case 13: cout << d; 
                            break;
                    default: cout << d_card1 << " and ";
                            break;
            }
            switch ( d_card2 ) {
                    case 1: cout << a; 
                            break;
                    case 11: cout << b; 
                            break;
                    case 12: cout << c; 
                            break;
                    case 13: cout << d; 
                            break;
                    default: cout << d_card2 << ".";
                            break;
            }
            cout << dlrTotl( d_card1, d_card2 ); //Function dealer total
            
            cout << "\n" << "\n" << "You have "; //To check what player has
            switch ( p_card1 ){
                    case 1: cout << a; 
                            break;
                    case 11: cout << b; 
                            break;
                    case 12: cout << c; 
                            break;
                    case 13: cout << d; 
                            break;
                    default: cout << p_card1 << " and "; 
                            break;
            }
            switch ( p_card2 ){
                    case 1: cout << a; 
                            break;
                    case 11: cout << b; 
                            break;
                    case 12: cout << c; 
                            break;
                    case 13: cout << d; 
                            break;
                    default: cout << p_card2 << ".";
                            break;
            }
            cout << plyTotl( p_card1, p_card2 ); //Function player total
            
            cout << "\n";
            float d_total = d_card1 + d_card2; //Dealer total
            float p_total = p_card1 + p_card2; //Player total
            //Conditions to check who wins
            if ((p_card1 == 1) && ((p_card1 == ten || p_card1 == eleven || p_card1 == twelve ||
            p_card1 == thirten)))	 
                    cout << "Blackjack! You Win $ " << (int)(wager*value) << "!" << endl; //Dealer wins
            else 
                    if((p_card2 == 1) && ((p_card2 == ten || p_card2 == eleven || p_card2 == twelve ||
            p_card2 == thirten)))
                            cout << "Blackjack! You Win $ " << (int)(wager*value) << "!" << endl; //Dealer wins
                    else 
                            if ( p_total > d_total ){
                                    cout << "\n" << "You Win $" << (int)wager << "!" << endl; //Player wins
                                    ttlWagr += wager;
                            }else{ 
                                    cout << "\n" << "You lose." << endl;
                                    ttlWagr -= wager;
                                    //Player looses
                            } 
        }
    }
    else
	cout << setfill('-')<<"GAME OVER. " << setfill('-'); //Game over
  
    //To write the output to a file called example.txt
    myfile.open("example.txt");
    myfile << "Your total score is $" << ttlWagr << ".\n";//Keep total of earnings
    myfile.close();
    
    //open file to read
    string wonGame = "";
    myfile2.open("example.txt");
    getline(myfile2, wonGame);
    cout << wonGame << endl;
    myfile2.close(); 
    
    //Exit
    return 0;
}  

//Functions
int dlrTotl( int d_card1, int d_card2)
{
    int total = d_card1 + d_card2;
    return total;
}

int plyTotl( int p_card1, int p_card2 )
{
    int total = p_card1 + p_card2;
    return total;
}