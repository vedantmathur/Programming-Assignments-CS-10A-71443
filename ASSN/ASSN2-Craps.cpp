/*
    Vedant Mathur
    CS 10A 71443
    Programming Assignment 2: Craps
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int INTITIALIZATION = 0;
const int MIN_VAL = 1;
const int MAX_VAL = 6;
const int CUTOFF_NUM = 7;
const int PERCENT = 100;
const int PERCENTAGE_MIN = 0;
const int PRECISION = 0;

int main()
{
    
    cout << fixed << setprecision(PRECISION); // Set precision initially so that decimal remains at 0 places, but is modifiable later.
    srand(static_cast<uint>(time(NULL))); // Seed the random to ensure true randomness
    float win = INTITIALIZATION, loss = INTITIALIZATION;
    bool play = false;
    
    // Everything is in a do while loop. if the variable 'play' is still true after all, it will play the game.
    do
    {
        char answer;
        // This do while loop keeps prompting the user for a yes or no input. 'play' becomes true or false based on this.
        do
        {
            
            cout << "Would you like to play Craps? [Y/N]" << endl;
            cin >> answer;
            
            if (answer == 'y' || answer == 'Y')
            {
                play = true;
                break;
            }
            else if(answer == 'n' || answer == 'N')
            {
                cout << "Come back when you would like to play" << endl;
                play = false; // This will ensure the game doesn't run, and the program exits.
                if(win + loss > PERCENTAGE_MIN) // Display scorecard only if you've played at least one game.
                {
                    cout << win << " wins, " << loss << " losses. " << endl;
                    cout << "Win rate: "<< (((win)/(win+loss)) * PERCENT) << "%" << endl;
                }
                break;
            }
            else
            {
                cout << "Incorrect input" << endl;
                // No breaking here because we want to keep asking until they give us an input we can work with.
            }
        } while(true);
        
        //Fail Method clears the buffer.
        if (cin.fail())
        {
            cin.clear();
        }
        cin.ignore(UINT_MAX, '\n');
        
        // If play is true, this is the part that contains the game.
        while(play)
        {
            string disposableNextLine; // This string is garbage. It means nothing, its used for dumping enter presses into.
            
            cout << "Great!" << endl;
            cout << "Press enter to roll" << endl;
            getline(cin, disposableNextLine);
            
            // Roll Die
            int initialRoll;
            int dice1, dice2;
            dice1 = rand() % MAX_VAL + MIN_VAL;
            dice2 = rand() % MAX_VAL + MIN_VAL;
            initialRoll = dice1 + dice2;
            cout << dice1 << " : " << dice2 << " = " << initialRoll << endl;
            
            // Depending on how you roll, one of few things can happen, outlined here.
            switch (initialRoll)
            {
                case 7:
                case 11: // In the case of a 7 or 11, You win automatically.
                    cout << "YOU ROLLED A GOOD NUMBER, YOU WIN" << endl;
                    win++;
                    break;
                case 2:
                    cout << "Snake eyes, mate, loser" << endl;
                    loss++;
                    break;
                case 3:
                case 12: // In the case of a 2, 3, or 12, you automatically lose
                    cout << "Box car, you lose" << endl;
                    loss++;
                    break;
                default: // since there are 2 die giving 11 possibilities (0 and 1 aren't possible with 2 die), the other possible scenarios happen here. Roll the same number twice to win.
                    do
                    {
                        int subsequentRoll;
                        cout << "You didn't roll a good number, to win you must now roll another "<< initialRoll << ", if you roll a 7, you lose" << endl;
                        cout << "Press enter to roll again" << endl;
                        getline(cin, disposableNextLine);
                        
                        // Roll die
                        dice1 = rand() % MAX_VAL + MIN_VAL;
                        dice2 = rand() % MAX_VAL + MIN_VAL;
                        subsequentRoll = dice1 + dice2;
                        cout << dice1 << " : " << dice2 << " = " << subsequentRoll << endl;
                        
                        if(subsequentRoll == CUTOFF_NUM) // Check if you got a 7, you automatically lose (not to be confused with the importance of the 7 on the first roll)
                        {
                            cout << "You rolled a 7, you lost" << endl;
                            loss++;
                            break;
                        }
                        if(subsequentRoll == initialRoll) // If the two rolls match, you win
                        {
                            cout << "You win, you rolled the same number twice" << endl;
                            win++;
                            break;
                        }
                    } while(true); // Albeit its seems like an infinite loop, all possible solutions have breaks that can break out of the loop.
                    
                    break;
            }
            
            // Display the final count so far
            cout << win << " wins, " << loss << " losses. " << endl;
            if(win + loss > PERCENTAGE_MIN)
            {
                cout << "Win rate: "<< (((win)/(win+loss)) * PERCENT) << "%" << endl;
            }
            break; // End the game, go back to main menu really.
        }
        
    } while(play);
    
    return 0;
}
