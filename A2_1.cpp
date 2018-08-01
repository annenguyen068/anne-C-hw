/*
 Written by: Anh Nguyen, August 27 2017
 Assigment 2
 Blackjack program
*/


#include <iostream>
#include <ctime>

using namespace std;

int main() {
    
    srand(static_cast<unsigned>(time(0)));
    
    while(true)
    {
        string playagain = "";
        int total = 0; //total value of all cards
        int card1 = rand() % 10 + 1; // generate 1st card randomly
        int card2 = rand() % 10 + 1; // generate 2nd card randomly
        total = card1 + card2; // calculate total
        
        cout<<"First cards: " << card1 << ", " << card2 << endl;
        cout<<"Total: " << total << endl;
        
        
        // get next card and check if the player win or bust
        while(true)
        {
            string answer = "";
            cout<<"Do you want another card? (y/n):";
            cin>>answer;
            if (answer != "y" && answer != "n") // if the player input unexpected answer, loop until get the right one
            {
                cout<<" > Wrong answer, please enter y/n" <<endl;
                continue;
            }
            
            // if yes, generate next card randomly for the player
            int nextcard = 0;// the next card
            if (answer == "y")
            {
                nextcard = rand() % 10 + 1; // 3rd card
            }
            else
            {
                break; // 'n' --> quit the game
            }
            
            total += nextcard; // calculate total again
            cout<<"Card: " << nextcard << endl;
            cout<<"Total: " << total << endl;
            
            // if win/bust
            if (total >= 21)
            {
                if (total == 21)
                    cout<<"Congratulations!" <<endl;
                else
                    cout<<"Bust" <<endl;
                
                // ask if the player want to play again
                while(true)
                {
                    cout<<"Would you like to play again? (y/n):";
                    cin>>playagain;
                    if (playagain == "y" || playagain == "n")
                    {
                        break;
                    }
                    cout<<" > Wrong answer, please enter y/n" <<endl;
                }
                break;
            }
        }
        if (playagain != "y")
            break;
    }
}


/*
----- Output ------
 First cards: 6, 2
 Total: 8
 Do you want another card? (y/n):y
 Card: 8
 Total: 16
 Do you want another card? (y/n):y
 Card: 3
 Total: 19
 Do you want another card? (y/n):y
 Card: 9
 Total: 28
 Bust
 Would you like to play again? (y/n):y
 First cards: 6, 10
 Total: 16
 Do you want another card? (y/n):y
 Card: 10
 Total: 26
 Bust
 Would you like to play again? (y/n):y
 First cards: 10, 3
 Total: 13
 Do you want another card? (y/n):y
 Card: 8
 Total: 21
 Congratulations!
 Would you like to play again? (y/n):y
 First cards: 6, 8
 Total: 14
 Do you want another card? (y/n):y
 Card: 8
 Total: 22
 Bust
 Would you like to play again? (y/n):y
 First cards: 1, 2
 Total: 3
 Do you want another card? (y/n):y
 Card: 8
 Total: 11
 Do you want another card? (y/n):y
 Card: 6
 Total: 17
 Do you want another card? (y/n):y
 Card: 3
 Total: 20
 Do you want another card? (y/n):n
 Program ended with exit code: 0
*/
