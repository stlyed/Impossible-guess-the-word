#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


bool running = true;
char userInputChar;
//total number of guesses
const unsigned short int WRONG_GUESS = 5;
unsigned short int userInputInt, numGuessLeft = WRONG_GUESS;
//what they wrote
string userInputWord;

void Setup() {
    //clear terminal
    system("clear");
    
    //welcome message
    cout << "Welcome to hangman by Smyvens" << endl;
    cout << " It is literally impossible" << endl;
    cout << "Press any number to play or any letter to quit " << endl;

    // start or quit
    cin >> userInputInt;
    if (!cin) {
        running = !running;
        cout << "good bye";
    }
    system("clear");
}

void Input() {
    cout << "" << endl;
    cout << "(one character at a time; no numbers; no symbols; capital or not)  -  ";
    cout << "More than one character breaks the system" << endl << endl;
    cout << "Guess '______' 6 characters" << endl;
    
    cin.clear();
    cin >> userInputChar; //get the user's input
}

void Logic() {
    //covert letter to lowercase
    if(toupper(userInputChar) == true)
        userInputChar = tolower(userInputChar);

    //make sure your not inputing illegal characters
    if (isalpha(userInputChar) == false) {
        cout << "Invalid input" << endl;
    } else{
        cout << "'" << userInputChar <<  "'" << " is a wrong guess" << endl;
        //number of guesses left
        numGuessLeft -= 1;
    }

    //see what they spelled
    userInputWord.push_back(userInputChar);
}

void Update() {
    //tell you that your wrong
    cout << numGuessLeft << " incorrect more guesses and your out" << endl;
    cout << "                                                wait..." << endl;
    sleep(3);
    system("clear");
}

void Results() {
    const unsigned short int NUM_WORDS = 5;
    string correctWord;

    string banana = "banana"; bool Banana = false;
    string excess = "excess"; bool Excess = false;
    string giggit = "giggit"; bool Giggit = false;
    string voodoo = "voodoo"; bool Voodoo = false;
    string pullup = "pullup"; bool Pullup = false;
    string myrrhy = "myrrhy"; bool Murrhy = false;

    for (int i = 0; i < NUM_WORDS; i++) {
        if (userInputWord.at(i) == banana.at(i)) {
            Banana = true;
            break;
        }
    }
    if(Banana == false) correctWord = banana;

    for (int i = 0; i < NUM_WORDS; i++) {
        if (userInputWord.at(i) == excess.at(i)) {
            Excess = true;
            break;
        }
    }
    if(Excess == false) correctWord = excess;

    for (int i = 0; i < NUM_WORDS; i++) {
        if (userInputWord.at(i) == giggit.at(i)) {
            Giggit = true;
            break;
        }
    }
    if(Giggit == false) correctWord = giggit;

    for (int i = 0; i < NUM_WORDS; i++) {
        if (userInputWord.at(i) == voodoo.at(i)) {
            Voodoo = true;
            break;
        }
    }
    if(Voodoo == false) correctWord = voodoo;

    for (int i = 0; i < NUM_WORDS; i++) {
        if (userInputWord.at(i) == pullup.at(i)) {
            Pullup = true;
            break;
        }
    }
    if(Pullup == false) correctWord = pullup;
    
    for (int i = 0; i < NUM_WORDS; i++) {
        if (userInputWord.at(i) == myrrhy.at(i)) {
            Murrhy = true;
            break;
        }
    }
    if(Murrhy == false) correctWord = myrrhy;

    system("clear");
    cout << "The word you failed to spell is: " << correctWord << endl;
}

int main() {
    //initial setup
    Setup();

    //game loop
    while (running) {
        //illegal characters does not affected number of guesses
        while(!(numGuessLeft < 1)) {
            Input();
            Logic();
            Update();
        }
        //by how much did they fail
        Results();

        //play again
        cout << "press 1 to play again or 0 to quit" << endl;
        cin >> userInputInt;
        if (userInputInt == 0) {
            running = !running;
        }

    }
    return 0;
}