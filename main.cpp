/***********************************************************************************************************************
Author: Jason Coffer

Copyright: Jason Coffer

Date:

Description: This is my virtual assistant CORE. My virtual assistant will solve any problems down below on the menu
efficiently. This is a constantly evolving machine so be on the lookout for updates! :)


************************************************************************************************************************/


#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
#include <random>
#include <ctime>
#include <fstream>
#include <random>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

class RockPaperScissors {
private:
    const char rock = 'R';
    const char scissor = 'S';
    const char paper = 'P';
public:
    char player = ' ';
    char computer = ' ';
    string name;
    //const string player2;

    bool checkDraw() {
        if (player == computer) {
            cout << "This match ends in a draw! Play again!" << endl;
            return true;
        }
        return false;
    }

    bool checkWin() {
        if ((player == 'R' && computer == 'S') || (player == 'P' && computer == 'R') || (player == 'S' && computer == 'P')) {
            cout << "\n" << name << " wins" << endl;
            return true;
        } else if ((player == 'S' && computer == 'R') || (player == 'P' && computer == 'S') || (player == 'R' && computer == 'P')) {
            cout << "\nComputer wins!" << endl;
            return true;
        }
        return false;
    }

    bool computerMove() {
        srand(time(0));
        int randNum = rand() % 3;
        if (randNum == 0) {
            computer = 'R';
            cout << "Computer chose Rock!" << endl;
        } else if (randNum == 1) {
            computer = 'P';
            cout << "Computer chose Paper!" << endl;
        } else if (randNum == 2) {
            computer = 'S';
            cout << "Computer chose Scissor!" << endl;
        }
        return false;
    }
    bool makeMove() {
        //int r, s, p;
        int response;
        cout << "Make your move." << endl;
        cout << "1.) Rock\n2.) Paper\n3.) Scissors\n";
        cout << "Your choice: ";
        cin >> response;
        computerMove();
        if (response == 1) {
            player = 'R';
            cout << "You chose Rock" << endl;
        } else if (response == 2) {
            player = 'P';
            cout << "You chose Paper" << endl;
        } else if (response == 3) {
            player = 'S';
            cout << "You chose Scissors" << endl;
        } else {
            cout << "Invalid response" << endl;
        }


        if (checkWin() || checkDraw()) {
            return true;
        }
        return false;


    }
};

// Define the Virtual Medical Assistant class
class vma {
public:
    int score = 0; // Holds the user's cumulative stress score

    // This function asks the user 10 stress-related questions and updates their score
    void questions() {
        int response;
        string questions[10] = {
            "1. I feel overwhelmed by the number of tasks I need to complete.",
            "2. I experience physical symptoms like headaches, muscle tension, or stomach issues without a clear medical cause.",
            "3. I have difficulty concentrating or making decisions.",
            "4. I feel anxious or worried about things I cannot control.",
            "5. I notice changes in my sleep patterns, such as trouble falling or staying asleep.",
            "6. I feel less motivated or find less enjoyment in activities I usually like.",
            "7. I experience changes in appetite, such as eating more or less than usual.",
            "8. I feel fatigued or lack energy even after adequate rest.",
            "9. I use substances like caffeine, alcohol, or nicotine to cope with stress.",
            "10. I feel irritable or short-tempered with others."
        };

        for (int i = 0; i < 10; i++) {
            cout << questions[i] << endl;
            cout << "1 - Rarely or Never\n2 - Sometimes\n3 - Often or Always\n";
            cout << "Your response: ";
            // Input validation to ensure response is 1, 2, or 3
            while (!(cin >> response) || response < 1 || response > 3) {
                cout << "Invalid input. Please enter 1, 2, or 3: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            score += response; // Add valid response to the total score
        }
    }

    // Classifies the user's stress level based on their score
    void scoreClassification(string name) {
        cout << endl;
        if (score >= 10 && score <= 15) {
            cout << "Level A - Low Stress" << endl;
            cout << "Your score is " << score << ". You're handling stress well and maintaining healthy balance." << endl;
            cout << "\nGreat job, " << name << "! You're doing an excellent job managing your stress levels." << endl;
        } else if (score > 15 && score <= 22) {
            cout << "Level B - Moderate Stress" << endl;
            cout << "Your score is " << score << ". Stress may be starting to impact your health." << endl;
            cout << "\nYou're doing okay, " << name << ", but there's room to reduce some of that tension." << endl;
        } else if (score > 22 && score <= 30) {
            cout << "Level C - High Stress" << endl;
            cout << "Your score is " << score << ". High stress is likely affecting your body and mind." << endl;
            cout << "\nYou're under a lot of stress, " << name << ". Consider prioritizing your well-being." << endl;
        } else {
            cout << "Invalid score. Please make sure your total is between 10 and 30." << endl;
        }
    }

    // Provides health-based recommendations depending on the user's stress level
    void personalRecommendation() {
        cout << endl;
        cout << "Here are some recommendations based on your results:" << endl;
        if (score >= 10 && score <= 15) {
            cout << "Recommendations (based on Harvard Health & Mayo Clinic):" << endl;
            cout << "- Continue practicing deep breathing or meditation daily" << endl;
            cout << "- Maintain regular physical activity to stabilize mood and sleep" << endl;
            cout << "- Stay connected to supportive people and maintain a healthy routine" << endl;
            cout << "\nSources:\n";
            cout << "Harvard Health - https://www.health.harvard.edu/staying-healthy/understanding-the-stress-response\n";
            cout << "Mayo Clinic - https://www.mayoclinic.org/healthy-lifestyle/stress-management/in-depth/stress/art-20046037\n";
        } else if (score > 15 && score <= 22) {
            cout << "Recommendations (based on Mayo Clinic & WebMD):" << endl;
            cout << "- Start mindfulness techniques like yoga or journaling" << endl;
            cout << "- Set boundaries with work/school and prioritize sleep" << endl;
            cout << "- Recognize stress triggers and use relaxation techniques (e.g., visualization, calm music)" << endl;
            cout << "\nSources:\n";
            cout << "Mayo Clinic - https://www.mayoclinic.org/healthy-lifestyle/stress-management/in-depth/stress/art-20046037\n";
            cout << "WebMD - https://www.webmd.com/balance/stress-management/stress-level-too-high" << endl;
        } else if (score > 22 && score <= 30) {
            cout << "Recommendations (based on Harvard Health & WebMD):" << endl;
            cout << "- Consider speaking with a mental health professional or counselor" << endl;
            cout << "- Practice the relaxation response (deep breathing, calming words, or guided imagery)" << endl;
            cout << "- Avoid unhealthy coping like overeating, caffeine, or alcohol" << endl;
            cout << "- Engage in regular aerobic exercise to reduce cortisol levels" << endl;
            cout << "\nSources:\n";
            cout << "Harvard Health - https://www.health.harvard.edu/staying-healthy/understanding-the-stress-response\n";
            cout << "WebMD - https://www.webmd.com/balance/stress-management/stress-level-too-high" << endl;
        } else {
            cout << "Invalid Score." << endl;
        }
    }
};

class TicTacToe {
private:
    char board[3][3];
public:
    const char player1 = 'X';
    const char player2 = 'O';

    bool checkDraw() {
        if (!checkWin()) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        return false; // Game still in progress
                    }
                }
            }
            cout << "This game ends in a draw. Play again to declare a winner!" << endl;
            return true;
        }
        return false;
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player1 && board[i][1] == player1 && board[i][2] == player1) {
                cout << "Player 1 (X) wins!" << endl;
                return true;
            } else if (board[i][0] == player2 && board[i][1] == player2 && board[i][2] == player2) {
                cout << "Player 2 (O) wins!" << endl;
                return true;
            }

            if (board[0][i] == player1 && board[1][i] == player1 && board[2][i] == player1) {
                cout << "Player 1 (X) wins!" << endl;
                return true;
            } else if (board[0][i] == player2 && board[1][i] == player2 && board[2][i] == player2) {
                cout << "Player 2 (O) wins!" << endl;
                return true;
            }
        }

        if (board[0][0] == player1 && board[1][1] == player1 && board[2][2] == player1) {
            cout << "Player 1 (X) wins!" << endl;
            return true;
        } else if (board[0][0] == player2 && board[1][1] == player2 && board[2][2] == player2) {
            cout << "Player 2 (O) wins!" << endl;
            return true;
        }

        if (board[0][2] == player1 && board[1][1] == player1 && board[2][0] == player1) {
            cout << "Player 1 (X) wins!" << endl;
            return true;
        } else if (board[0][2] == player2 && board[1][1] == player2 && board[2][0] == player2) {
            cout << "Player 2 (O) wins!" << endl;
            return true;
        }

        return false;
    }

    void getValidMove(string move, int& rowOrCol) {
        while (!(cin >> rowOrCol) || rowOrCol < 0 || rowOrCol > 2) {
            cout << "Invalid Input. Please enter 0, 1, or 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    bool makeMove() {
        int row, col;
        for (int i = 1; i <= 9; i++) {
            char currentPlayer = (i % 2 == 1) ? player1 : player2;
            cout << "Player " << ((i % 2 == 1) ? "1" : "2") << ", it is your move. Enter the space to place '" << currentPlayer << "':\n";

            cout << "Enter the row (0-2): ";
            getValidMove("row", row);
            cout << "Enter the column (0-2): ";
            getValidMove("col", col);

            while (board[row][col] != ' ') {
                cout << "That spot is taken. Please make a different move.\n";
                cout << "Enter the row (0-2): ";
                getValidMove("row", row);
                cout << "Enter the column (0-2): ";
                getValidMove("col", col);
                displayBoard();
            }

            board[row][col] = currentPlayer;
            displayBoard();

            if (checkWin() || checkDraw()) {
                return true; // Game ended
            }
        }
        return false; // Shouldn't reach here if draw/win is caught correctly
    }

    void initializeBoard() {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                board[row][col] = ' ';
            }
        }
    }

    void displayBoard() {
        cout << "   0   1   2\n";
        for (int row = 0; row < 3; row++) {
            cout << row << "  ";
            for (int col = 0; col < 3; col++) {
                cout << board[row][col];
                if (col < 2) cout << " | ";
            }
            cout << endl;
            if (row < 2) cout << "  ---+---+---\n";
        }
    }
};

class Game {
private:
    string name;

public:
    Game() {
        cout << "Welcome to the game lobby!" << endl;
    }

    void setGame() {
        cout << "Enter the name of the game: ";
        getline(cin, name);
    }

    void play() {
        cout << "Playing " << name << " now... Have Fun!" << endl;
    }
};

class Movie {
private:
    string title;
    string genre;

public:
    Movie() {
        cout << "Movie system ready." << endl;
    }

    void setMovie() {
        cout << "Enter movie title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter genre: ";
        getline(cin, genre);
    }

    void displayMovie() {
        cout << "Now Showing: " << title << " [" << genre << "]" << endl;
    }
};

class Employee {
private:
    string name;
    int id;

public:
    Employee() {
        cout << "New employee record being created." << endl;
    }

    void setInfo() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
    }

    void displayInfo() {
        cout << "Employee: " << name << ", ID: " << id << endl;
    }
};

class BankAccount {
private:
    double balance;

public:
    BankAccount() : balance(0.0) {
        cout << "Bank account created with $0 balance." << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
        }
    }
};

class Treasure {
public:
    string name;
    Treasure() {
        cout << "You've discovered a hidden treasure!" << endl;
    }
    void captainName() {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Aye Aye Captain " << name << endl;
    }

    void openChest() {
        cout << "You found gold coins and jewels! Congrats Captain " << name << "!" << endl;
    }
};

class Monster {
public:
    Monster() {
        cout << "A wild monster appears!" << endl;
    }

    void roar() {
        cout << "ROAAARRR!!!" << endl;
    }
};

class Superhero {
private:
    string name;

public:
    Superhero() {
        cout << "Superhero is ready to save the day!" << endl;
    }

    void setName() {
        cout << "Enter superhero name: ";
        cin >> name;
        cout << name << " to the rescue!" << endl;
    }

    void usePower() {
        cout << name << " uses their superpower!" << endl;
    }
};

class DancingRobot {
public:
    DancingRobot() {
        cout << "Dancing Robot activated!" << endl;
    }

    void dance() {
        cout << "*robot does a spin and moonwalks*" << endl;
    }
};

class Rectangle {
private:
    double length, width;

public:
    Rectangle() {
        cout << "Lets make a rectangle!" << endl;
    }

    void setDimensions() {
        cout << "Enter length and width: ";
        cin >> length >> width;
    }

    void displayArea() {
        cout << "Area: " << length * width << endl;
    }
};

class FastFood {
public:
    FastFood() {
        cout << "Welcome to FastFood Express!" << endl;
    }

    void orderMeal() {
        string meal;
        cout << "Enter your meal choice: ";
        cin >> meal;
        cout << "Your " << meal << " is being prepared!" << endl;
    }
};

class Dog {
public:
    Dog() {
        cout << "A dog is born! 🐶" << endl;
    }

    void bark() {
        cout << "Woof! Woof!" << endl;
    }

    void fetch() {
        cout << "The dog fetches the ball!" << endl;
    }
};

class Taco {
private:
    vector<string> ingredients;

public:
    Taco() {
        cout << "Welcome to the Taco Bar!" << endl;
    }

    void addIngredients() {
        string ingredient;
        int choice;
        while (true) {
            cout << "Add an ingredient? (1: Yes | 2: No): ";
            cin >> choice;
            if (choice == 1) {
                cout << "Ingredient: ";
                cin.ignore();
                getline(cin, ingredient);
                ingredients.push_back(ingredient);
            } else if (choice == 2) {
                break;
            }
        }
    }

    void serveTaco() {
        cout << "Taco with ";
        for (const auto& ing : ingredients) {
            cout << ing << " ";
        }
        cout << "is ready!" << endl;
    }
};

class VirtualPet {
private:
    string name;

public:
    VirtualPet() {
        cout << "Adopt your Virtual Pet!" << endl;
    }

    void namePet() {
        cout << "Give your pet a name: ";
        cin >> name;
        cout << name << " is happy to meet you!" << endl;
    }

    void feedPet() {
        cout << name << " is eating... Yum!" << endl;
    }
};

class TimeMachine {
public:
    TimeMachine() {
        cout << "Welcome to the Time Machine!" << endl;
    }

    void travel() {
        int year;
        cout << "Enter a year you'd like to travel to: ";
        cin >> year;
        cout << "Zooming to year " << year << "... Buckle up!" << endl;
    }
};

class People {
public:
    People() {
        cout << "Welcome Person!" << endl;
    }

    void introduce() {
        string name;
        cout << "What's your name: ";
        cin >> name;
        cout << "Hello, " << name << "! Nice to meet you!" << endl;
    }
};

map<string, string> loadFlashCards() {
    map<string, string> fc;
    ifstream myfile("FlashCards.txt");
    ifstream myfile2("Answers.txt");
    string question, answer;

    while (getline(myfile, question) && getline(myfile2, answer)) {
        fc[question] = answer;
    }

    myfile.close();
    myfile2.close();
    return fc;
}

void practiceFlashCards() {
    map<string, string> flashcards = loadFlashCards();

    if (flashcards.empty()) {
        cout << "No flashcards available. Please add some first." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer once

    int score = 0;
    int totalScore = 0;
    string ans;

    cout << "\n--- Practice Mode ---" << endl;
    cout << "Type 'exit' anytime to stop practicing.\n" << endl;

    // Shuffle the flashcards
    vector<pair<string, string>> items(flashcards.begin(), flashcards.end());
    random_device rd;
    mt19937 g(rd());
    shuffle(items.begin(), items.end(), g);

    for (const auto& pair : items) {
        cout << pair.first << " | ";
        getline(cin, ans);

        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
        if (ans == "exit") {
            cout << "\nExiting practice early.\n";
            break;
        }

        string correctAnsLower = pair.second;
        transform(correctAnsLower.begin(), correctAnsLower.end(), correctAnsLower.begin(), ::tolower);

        if (ans == correctAnsLower) {
            score += 10;
            cout << "Correct!\n";
        } else {
            cout << "Wrong! Correct Answer: " << pair.second << endl;
        }
        totalScore += 10;
        cout << endl;
    }

    cout << "\nFinal Score: " << score << " out of " << totalScore << endl;
}

void addFlashCard() {
    ofstream myfile("FlashCards.txt", ios::app); // <-- append mode!
    ofstream myfile2("Answers.txt", ios::app);

    if (!myfile.is_open() || !myfile2.is_open()) {
        cout << "Error opening flashcard files." << endl;
        return;
    }

    cin.ignore(); // Clear buffer after menu choice

    while (true) {
        string q, a;
        int choice;
        cout << "Enter the question: ";
        getline(cin, q);
        cout << "Enter the answer: ";
        getline(cin, a);

        myfile << q << endl;
        myfile2 << a << endl;

        cout << "Would you like to create another card? (1-Yes, 2-No): ";
        cin >> choice;
        cin.ignore();

        if (choice == 2) {
            cout << "Returning to menu...\n";
            break;
        }
    }

    myfile.close();
    myfile2.close();
}

void shuffleFlashCards() {
    map<string, string> fc = loadFlashCards();

    if (fc.empty()) {
        cout << "You don't have any flashcards. Go back to the menu to create some!" << endl;
        return;
    }

    vector<pair<string, string>> items(fc.begin(), fc.end());
    random_device rd;
    mt19937 g(rd());
    shuffle(items.begin(), items.end(), g);

    ofstream myfile("FlashCards.txt");
    ofstream myfile2("Answers.txt");

    for (const auto& pair : items) {
        myfile << pair.first << endl;
        myfile2 << pair.second << endl;
    }

    myfile.close();
    myfile2.close();

    cout << "Flashcards shuffled and saved.\n\n";
}

void deleteFlashCards() {
    map<string, string> fc = loadFlashCards();
    if (fc.empty()) {
        cout << "You don't have any flashcards. Go back to menu to create some!" << endl;
        return;
    }

    int choice;
    cout << "Enter 1 to delete all flashcards, or 0 to delete by answer: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        fc.clear();
        cout << "All flashcards deleted!\n";
    } else if (choice == 0) {
        string valueToRemove;
        cout << "Enter the answer you'd like to remove: ";
        getline(cin, valueToRemove);

        for (auto it = fc.begin(); it != fc.end();) {
            if (it->second == valueToRemove) {
                it = fc.erase(it);
            } else {
                ++it;
            }
        }
        cout << "Flashcard deleted (if existed).\n";
    } else {
        cout << "Invalid choice.\n";
    }

    // Save updated list
    ofstream myfile("FlashCards.txt");
    ofstream myfile2("Answers.txt");

    for (const auto& pair : fc) {
        myfile << pair.first << endl;
        myfile2 << pair.second << endl;
    }

    myfile.close();
    myfile2.close();
}

void studyFlashCards() {
    map<string, string> fc = loadFlashCards();
    if (fc.empty()) {
        cout << "No flashcards available. Please add some first." << endl;
        return;
    }

    cin.ignore(); // Only ignore once here

    for (const auto& pair : fc) {
        cout << pair.first << endl;
        cout << "Press ENTER to see the answer...";
        cin.get(); // just wait for ENTER
        cout << "Answer: " << pair.second << endl << endl;
    }
}


void converter(string currency) {
    double dollar, pesos;
    cout << fixed << setprecision(2);
    if (currency == "Dollars") {
        cout << "Please enter the amount of Pesos you have: ";
        cin >> pesos;
        dollar = pesos * 0.048;
        cout << pesos << " pesos converted to " << currency << " would be $" << dollar << endl;
    } else if (currency == "Pesos") {
        cout << "Please enter the amount of Dollars you have: ";
        cin >> dollar;
        pesos = dollar * 20.82;
        cout << "$" << dollar << " converted to " << currency << " would be " << pesos << " pesos." << endl;
    }

}

void addToCart(vector<string>& cart, vector<double>& cartVal) {
    string item;
    double itemVal;
    int i = 0;
    cout << "You have chose to add items to your cart." << endl;
    while (i != 2) {
        cout << "Enter 1 to move forward or enter 2 to go back: ";
        cin >> i;
        cin.ignore();

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input" << endl;
            continue;
        }

        if (i == 1) {
            cout << "You may now move forward with you shopping." << endl;

            cout << "Please enter the item you would like to add to your cart: " << endl;
            getline(cin, item);
            //cin.clear();
            cart.push_back(item);

            cout << "Now enter the price of the item you just added to the cart: " << endl;
            cin >> itemVal;
            cin.ignore();
            cartVal.push_back(itemVal);
        } else if (i == 2) {
            cout << "You have chose to stop shopping." << endl;
            break;
        } else {
            cout << "Invalid input. Enter 1 or 2." << endl;
        }


    }

}

// Exercise 46-47: Dollars to Yen
#include <iostream>
#include <iomanip>
using namespace std;

void converterYen(string currency) {
    double dollar, yen;
    cout << fixed << setprecision(2);
    if (currency == "Dollars") {
        cout << "Please enter the amount of Yen you have: ";
        cin >> yen;
        dollar = yen * 0.0069;
        cout << yen << " yen converted to " << currency << " would be $" << dollar << endl;
    } else if (currency == "Yen") {
        cout << "Please enter the amount of Dollars you have: ";
        cin >> dollar;
        yen = dollar * 144.89;
        cout << "$" << dollar << " converted to " << currency << " would be " << yen << " yen." << endl;
    }

}

void converterRu(string currency) {
    double dollar, rupees;
    cout << fixed << setprecision(2);
    if (currency == "Dollars") {
        cout << "Please enter the amount of Rupees you have: ";
        cin >> rupees;
        dollar = rupees * 0.012;
        cout << rupees << " rupees converted to " << currency << " would be $" << dollar << endl;
    } else if (currency == "Rupees") {
        cout << "Please enter the amount of Dollars you have: ";
        cin >> dollar;
        rupees = dollar * 86.65;
        cout << "$" << dollar << " converted to " << currency << " would be " << rupees << " rupees." << endl;
    }

}

void totalCost(vector<double>& cartVal) {
    double total = 0;
    for (int i = 0; i < cartVal.size(); i++) {
        total += cartVal[i];
    }

    if (cartVal.size() >= 5) {
        double discount = 0.15;
        double savings = total * discount;
        cout << "You saved: $" << savings << " with a 15% discount!" << endl;
        total -= savings;
    }

    cout << "Total cost of your cart is: $" << total << endl;
}


// creates a 2 row matric with two columns
// elements entered by the user
// adds the elements and put them in an array called add
void twoRowTwoColMatrixAdd() {
    int matrix[2][2];
    int add[2][2];

    cout << "Enter matrix elements" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Enter matrix value matrix[" << i << "][" << j << "] --> ";
            cin >> matrix[i][j];
        }
    }
    cout << "Add the matrix elements now." << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            add[i][j] = matrix[i][j] + matrix[i][j];
        }
    }

    cout << "Results: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << add[i][j] << " ";
        }
        cout << endl;
    }
}
// Perform the multiplication of an array by N
void mulOfArrByN() {
    vector<int> a, product;
    int size = 5; // size of array
    int n;

    // takes values for the vector
    cout << "Enter the values for the vector:" << endl;
    for (int i = 0; i < size; i++) {
        int val;
        cout << "Enter value for a[" << i << "] --> ";
        cin >> val;
        a.push_back(val);
    }

    // user inputs a num to multiply with the nums in the vector
    cout << "Enter the value for the factor: ";
    cin >> n;

    // grows vector and updates memory
    product.resize(size);
    for (int i = 0; i < size; i++) {
        product[i] = a[i] * n;
    }
    cout << "The product is: ";
    for (int i = 0; i < size; i++) {
        cout << product[i] << " ";
    }
}
// Creates a 2 row matrix with two columns
// add, subtract, multiply elements
void mathOpMatrix() {
    int matrix[2][2];
    int add[2][2], sub[2][2], mul[2][2];

    cout << "Enter matrix elements" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Enter matrix value matrix[" << i << "][" << j << "] --> ";
            cin >> matrix[i][j];
        }
    }
    cout << "Add the matrix elements now." << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            add[i][j] = matrix[i][j] + matrix[i][j];
            sub[i][j] = matrix[i][j] - matrix[i][j];
            mul[i][j] = matrix[i][j] * matrix[i][j];
        }
    }

    cout << "Results: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << add[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Subtraction Results: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Multiplication Results: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << mul[i][j] << " ";
        }
        cout << endl;
    }
}

// Returns the sum of an array entered by a user
void sumOfArr() {
    int a1[5];
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        cout << "Enter a[" << i << "] --> ";
        cin >> a1[i];
    }
    for (int i = 0; i < 5; i++) {
        sum += a1[i];
    }
    cout << "The sum of the array a1 is: " << sum << endl;
}

void choose_your_style(string clothing_style) {
    int response;
    string color, print, graphic, size, type;

    cout << "Now select the size of the " << clothing_style << "." << endl;
    cout << "1.) Small\n";
    cout << "2.) Medium\n";
    cout << "3.) Large\n";
    cout << "Your choice: ";
    cin >> response;
    if (response == 1) {
        cout << "You chose a small " << clothing_style << "." << endl;
        size = "Small";
    } else if (response == 2) {
        cout << "Your chose a medium " << clothing_style << "." << endl;
        size = "Medium";
    } else if (response == 3) {
        cout << "Your chose a large " << clothing_style << "." << endl;
        size = "Large";
    }

    // Type of style
    cout << "Select the type of " << clothing_style << " you want." << endl;
    cout << "1.) Cropped " << clothing_style << endl;
    cout << "2.) No Sleeves " << clothing_style << endl;
    cout << "3.) Short-Sleeve " << clothing_style << endl;
    cout << "4.) Long-Sleeve " << clothing_style << endl;
    cout << "5.) Choose Your Own type of " << clothing_style << endl;
    cout << "Your choice: ";
    cin >> response;
    cin.ignore();
    if (response == 1) {
        cout << "You chose a cropped " << clothing_style << "." << endl;
        type = "Cropped";
    } else if (response == 2) {
        cout << "You chose no sleeves on your " << clothing_style << "." << endl;
        type = "No Sleeves";
    } else if (response == 3) {
        cout << "You chose a short-sleeved " << clothing_style << "." << endl;
        type = "Short-Sleeved";
    } else if (response == 4) {
        cout << "You chose a long-sleeved " << clothing_style << "." << endl;
        type = "Long-Sleeved";
    } else if (response == 5) {
        cout << "You chose to choose your own type of " << clothing_style << "." << endl;
        getline(cin, type);
    }

    // Choose color
    cout << "\nNow choose a color!" << endl;
    cout << "1.) Blue\n";
    cout << "2.) Green\n";
    cout << "3.) Red\n";
    cout << "4.) Purple\n";
    cout << "5.) Choose Your Own\n";
    cout << "Enter a number 1-5 to choose a color: ";
    cin >> response;
    cin.ignore();

    if (response == 1) {
        cout << "You chose the color blue!" << endl;
        color = "Blue";
    } else if (response == 2) {
        cout << "You chose the color green!" << endl;
        color = "Green";
    } else if (response == 3) {
        cout << "You chose the color red!" << endl;
        color = "Red";
    } else if (response == 4) {
        cout << "You chose the color purple!" << endl;
        color = "Purple";
    } else if (response == 5) {
        cout << "Choose your own color for your " << clothing_style << ":";
        getline(cin, color);
    }

    // Choose print
    cout << "\nWould you like print on the shirt or no print?" << endl;
    cout << "1.) Yes\n";
    cout << "2.) No\n";
    cout << "Type 1 for Yes and 2 for No." << endl;
    cout << "Your choice: ";
    cin >> response;
    cin.ignore();

    if (response == 1) {
        cout << "You chose to have print on your " << clothing_style << "." << endl;
        cout << "Please type in what you want your " << clothing_style << " to say: ";
        getline(cin, print);
    } else if (response == 2) {
        cout << "You chose to have no print on your " << clothing_style << "." << endl;
        print = "No print";
    }

    // Choose design
    cout << "\nFinally choose your design, if you'd like to have one!" << endl;
    cout << "1.) Basketball\n";
    cout << "2.) Philly Skyline\n";
    cout << "3.) No Graphic\n";
    cout << "4) Animal\n";
    cout << "5.) Pick Your Own\n";
    cout << "Your choice: ";
    cin >> response;
    cin.ignore();

    if (response == 1) {
        graphic = "Basketball";
    } else if (response == 2) {
        graphic = "Philly Skyline";
    } else if (response == 3) {
        graphic = "No Graphic";
    } else if (response == 4) {
        cout << "Enter the type of animal you want as your graphic: ";
        getline(cin, graphic);
    } else if (response == 5) {
        cout << "Enter the type of graphic you'd like: ";
        getline(cin, graphic);
    }
    cout << "Your " << clothing_style << ":" << endl;
    cout << "Size: " << size << endl;
    cout << "Type: " << type << endl;
    cout << "Color: " << color << endl;
    cout << "Print: " << print << endl;
    cout << "Design: " << graphic << endl;

    if (print == "No print") {
        cout << "\nThe user wants a " << color << ", " << type << " " << clothing_style  << ", size " << size << ", with " << print << "." << endl;
    } else {
        cout << "\nThe user wants a " << color << ", " << type << " " << clothing_style  << ", size " << size << ", with '" << print << "' printed on it." << endl;
    }

    if (graphic == "No Graphic") {
        cout << "The user also chose to have " << graphic << " on the " << clothing_style << "." << endl;
    } else {
        cout << "The user also chose to have a(n) " << graphic << " on the " << clothing_style << "." << endl;
    }

}

void mult_div_arr() {
    cout << setprecision(2);
    double a1[5] = {};
    double b1[5] = {};
    double d1[5] = {};
    double e1[5] = {};

    // Array 1 Values
    for (int i = 0; i < 5; i++) {
        cout << "Enter number of elements for array 1:[" << i << "]" << endl;
        cin >> a1[i];
    }
    // Array 2
    for (int j = 0; j < 5; j++) {
        cout << "Enter the number of elements for array 2:[" << j << "]" << endl;
        cin >> b1[j];
    }
    // Prints out Array 1
    cout << "Array 1:[";
    for (int i = 0; i < 5; i++) {
        cout << a1[i] << ' ';
    }
    cout << "]" << endl;

    // Prints out Array 2
    cout << "Array 2:[";
    for (int j = 0; j < 5; j++) {
        cout << b1[j] << ' ';
    }
    cout << "]" << endl;

    cout << "\nMultiplication: [";
    for (int i = 0; i < 5; i++) {
        d1[i] = a1[i] * b1[i];
        cout << d1[i] << ' ';
    }
    cout << "]" << endl;

    cout << endl;
    cout << "Division: [";
    for (int j = 0; j < 5; j++) {
        e1[j] = b1[j] / a1[j];
        cout << e1[j] << ' ';
    }
    cout << "]" << endl;
    cout << endl;

}

// Create two arrays of integers, add each element to a third array
void addTwoArrToThird() {
    int a1[5] = {2, 4, 6, 8, 10};
    int b1[5] = {20, 40, 60, 80, 100};
    int c1[5];

    cout << "c1: ";
    for (int i = 0; i < 5; i++) {
        c1[i] = a1[i] + b1[i];
        cout << c1[i] << " ";
    }
}

// Takes two user input arrays and then adds, subtracts, and multiplies them in separate arrays
void arrsOf5Elements() {
    int a[5], b[5];
    int add[5], sub[5], mul[5], div[5];
    cout << "Enter values for array 5:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Enter value for a[" << i << "] --> ";
        cin >> a[i];
    }
    cout << "Now enter values for array b: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Enter value for b[" << i << "] --> ";
        cin >> b[i];
    }
    for (int i = 0; i < 5; i++) {
        add[i] = a[i] + b[i];
    }
    for (int i = 0; i < 5; i++) {
        sub[i] = a[i] - b[i];
    }
    for (int i = 0; i < 5; i++) {
        mul[i] = a[i] * b[i];
    }
    for (int i = 0; i < 5; i++) {
        if (b[i] != 0)
            div[i] = a[i] / b[i]; // integer division
        else
            div[i] = 0; // or handle division by zero as needed
    }
    cout << "Addition: ";
    for (int i = 0; i < 5; i++) {
        cout << add[i] << " ";
    }
    cout << endl;
    cout << "Subtraction: ";
    for (int i = 0; i < 5; i++) {
        cout << sub[i] << " ";
    }
    cout << endl;
    cout << "Multiplication: ";
    for (int i = 0; i < 5; i++) {
        cout << mul[i] << " ";
    }
    cout << endl;
    cout << "Division: ";
    for (int i = 0; i < 5; i++) {
        cout << div[i] << " ";
    }
    cout << endl;
}

void converterEu(string currency) {
    double dollar, euros;
    cout << fixed << setprecision(2);
    if (currency == "Dollars") {
        cout << "Please enter the amount of Euros you have: ";
        cin >> euros;
        dollar = euros * 1.14;
        cout << euros << " euros converted to " << currency << " would be $" << dollar << endl;
    } else if (currency == "Euros") {
        cout << "Please enter the amount of Dollars you have: ";
        cin >> dollar;
        euros = dollar * 0.88;
        cout << "$" << dollar << " converted to " << currency << " would be " << euros << " euros." << endl;
    }

}

void tipConverter() {
    double total_price = 0, tip, new_price = 0, tip_percentage = 0.0;
    int response;

    do {
        cout << "This calculator is meant to calculate the tip you should pay at a restaurant." << endl;
        cout << "Please select the tip percentage you'd like: " << endl;
        cout << "1.) 15%\n2.) 18%\n3.) 22%\n";
        cout << "Please enter your response: ";
        cin >> response;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input. Try again!\n";
            continue; // Go back to top of loop
        }

        cout << fixed << setprecision(2);

        if (response == 1) {
            tip_percentage = 0.15;
        } else if (response == 2) {
            tip_percentage = 0.18;
        } else if (response == 3) {
            tip_percentage = 0.22;
        } else {
            cout << "Invalid response." << endl;
            continue; // Go back to top of loop
        }

        cout << "You selected to tip " << tip_percentage * 100 << "% of the total order." << endl;
        cout << "Enter the total for your order: ";
        cin >> total_price;

        tip = total_price * tip_percentage;
        new_price = total_price + tip;

        cout << "The recommended tip for your order is $" << tip << endl;
        cout << "The total price for your order will be $" << new_price << endl;
        cout << endl;

        break; // Exit loop after one successful calculation

    } while (true);
}

void wordCounter() {
    string text, new_text;
    vector<string> v;

    cout << "This program will count how many words you have in a paragraph or sentence." << endl;
    cout << "Please enter the text you'd wish to count: " << endl;
    getline(cin, text);
    stringstream ss(text);
    while (getline(ss, new_text, ' ')) {
        if (new_text != "," && new_text != "." && new_text != "!" && new_text != "?" && !new_text.empty()) {
            v.push_back(new_text); // Only push valid words
        }
    }
    cout << "There are " << v.size() << " words." << endl;
}

void unitConverter() {
    int choice;
    double value;

    cout << "\n--- Unit Converter ---" << endl;
    cout << "Select what you would like to convert:" << endl;
    cout << "1.) Inches to Centimeters" << endl;
    cout << "2.) Centimeters to Inches" << endl;
    cout << "3.) Feet to Meters" << endl;
    cout << "4.) Meters to Feet" << endl;
    cout << "5.) Miles to Kilometers" << endl;
    cout << "6.) Kilometers to Miles" << endl;
    cout << "Your choice: ";
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Input" << endl;
    }

    cout << fixed << setprecision(2);

    switch (choice) {
        case 1:
            cout << "Enter inches: ";
            cin >> value;
            cout << value << " inches = " << value * 2.54 << " centimeters" << endl;
            break;
        case 2:
            cout << "Enter centimeters: ";
            cin >> value;
            cout << value << " centimeters = " << value / 2.54 << " inches" << endl;
            break;
        case 3:
            cout << "Enter feet: ";
            cin >> value;
            cout << value << " feet = " << value * 0.3048 << " meters" << endl;
            break;
        case 4:
            cout << "Enter meters: ";
            cin >> value;
            cout << value << " meters = " << value / 0.3048 << " feet" << endl;
            break;
        case 5:
            cout << "Enter miles: ";
            cin >> value;
            cout << value << " miles = " << value * 1.60934 << " kilometers" << endl;
            break;
        case 6:
            cout << "Enter kilometers: ";
            cin >> value;
            cout << value << " kilometers = " << value / 1.60934 << " miles" << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }
}

void guessingGame() {
    int guess, count = 1;
    srand(time(0));
    int randNum = rand() % 101;

    cout << "\nYour guess is: ";
    cin >> guess;

    while (guess != randNum && count <= 5) {
        if (guess > randNum) {
            cout << "Too high!" << endl;
            cout << "Try again: ";
            //cin >> guess;
        } else if (guess < randNum) {
            cout << "Too low!" << endl;
            cout << "Try again: ";
            //cin >> guess;
        }
        if (count == 5) {
            break; // no more tries
        }
        cin >> guess;
        count++;
    }
    if (guess == randNum) {
        cout << "CORRECT!" << endl;
    } else {
        cout << "Unfortunately you ran out of chances. Try again." << endl;
        cout << "The correct number was: " << randNum << endl;
    }
}

void coinFlip() {
    srand(time(0)); // Seed random number generator
    int randCoin = rand() % 2;

    cout << "\nThis program will flip a coin and return Heads or Tails." << endl;
    cout << "Press 'ENTER' to flip the coin.";
    cin.ignore();  // Wait for user to press ENTER

    if (randCoin == 0) {
        cout << "\nResult: HEADS\n" << endl;
    } else {
        cout << "\nResult: TAILS\n" << endl;
    }
}

void blackjackGame() {
    char playAgain;

    do {
        srand(time(0));
        int playerTotal = 0;
        int dealerTotal = rand() % 6 + 16; // Dealer between 16–21
        char choice;

        cout << "\nWelcome to Blackjack!" << endl;
        cout << "Try to get as close to 21 as possible without going over!" << endl;

        // First two cards for player
        playerTotal += rand() % 10 + 1;
        playerTotal += rand() % 10 + 1;
        cout << "Your starting total: " << playerTotal << endl;

        do {
            cout << "\nDo you want to (H)it or (S)tand? ";
            cin >> choice;
            choice = tolower(choice);

            if (choice == 'h') {
                int newCard = rand() % 10 + 1;
                cout << "You drew a " << newCard << "!" << endl;
                playerTotal += newCard;
                cout << "Your new total is: " << playerTotal << endl;

                if (playerTotal > 21) {
                    cout << "Busted! You went over 21." << endl;
                    break; // Busted, end player's turn
                }
            } else if (choice == 's') {
                cout << "\nYou chose to stand with " << playerTotal << " points." << endl;
                break; // Stand ends player's turn
            } else {
                cout << "Invalid choice. Please type 'H' to hit or 'S' to stand." << endl;
            }

        } while (true);

        if (playerTotal <= 21) {
            cout << "\nDealer's total: " << dealerTotal << endl;

            if (dealerTotal > 21 || playerTotal > dealerTotal) {
                cout << "You win!" << endl;
            } else if (playerTotal < dealerTotal) {
                cout << "Dealer wins!" << endl;
            } else {
                cout << "It's a tie!" << endl;
            }
        }

        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (tolower(playAgain) == 'y');

    cout << "Thanks for playing Blackjack!\n";
}

void addTwo2DArrays() {
    int matrix_a[2][2];
    int matrix_b[2][2];
    int add[2][2] = {0};

    cout << "This program will add two 2x2 matrices." << endl;

    cout << "Enter the values for Matrix A: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Enter A[" << i << "][" << j << "]: ";
            cin >> matrix_a[i][j];
        }
    }

    cout << "Enter the values for Matrix B: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Enter B[" << i << "][" << j << "]: ";
            cin >> matrix_b[i][j];
        }
    }

    // Add matrices
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            add[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }

    // Display the result
    cout << "\nSum of the two matrices (A + B):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << add[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void letterGradeCalc() {
    string grade, user_Class, name;
    double user_grade;
    char lgc_choice;

    cout << fixed << setprecision(1);

    do {
        cout << "This program will return the grade you have for a class." << endl;
        cout << "Please enter your name: ";
        getline(cin, name);
        cout << "Now enter the class you are concerned about: ";
        getline(cin, user_Class);
        cout << "Lastly, enter the nummber grade for this class: ";
        cin >> user_grade;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        cout << "----- Class Info -----";
        cout << "\nStudent Name: " << name;
        if (user_grade >= 90) {
            cout << "\nClass: " << user_Class << "\nGrade: A";
        } else if (user_grade >= 80 && user_grade <= 89) {
            cout << "\nClass: " << user_Class << "\nGrade: B";
        } else if (user_grade >= 70 && user_grade <= 79) {
            cout << "\nClass: " << user_Class << "\nGrade: C";
        } else if (user_grade >= 60 && user_grade <= 69) {
            cout << "\nClass: " << user_Class << "\nGrade: D";
        } else if (user_grade >= 40 && user_grade <= 69) {
            cout << "\nClass: " << user_Class << "\nGrade: F";
        }

        cout << "\nWould you like to enter another class? (y/n): ";
        cin >> lgc_choice;

    } while (lgc_choice != 'n');
}

// Mathematics section that allows users to select different mathematical operations
void mathematics() {
    int math_choice;
    do {
        cout << "\nMathematics Menu:\n";
        cout << "1. Basic Arithmetic (Addition, Subtraction, Multiplication, Division)\n";
        cout << "2. Average of Two Numbers\n";
        cout << "3. Even or Odd Number Check\n";
        cout << "4. Positive, Negative, or Zero\n";
        cout << "5. Square Root\n";
        cout << "6. Absolute Value\n";
        cout << "7. Perimeter and Area of a Square\n";
        cout << "8. Multiplication Table\n";
        cout << "9. Hypotenuse of Right-Triangle\n";
        cout << "10. Currency Exchange\n";
        cout << "11. Quadratic Formula\n";
        cout << "12. Back to Main Menu\n";
        cout << "Your choice: ";
        cin >> math_choice;
        cout << endl;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input" << endl;
            continue;
        }

        switch (math_choice) {
            case 1: {
                double num1, num2;
                cout << setprecision(2) << fixed;
                cout << "Enter two numbers: \n";
                cout << "Num1: "; cin >> num1;
                cout << "Num2: "; cin >> num2;
                cout << "Addition: " << num1 + num2 << endl;
                cout << "Subtraction: " << num1 - num2 << endl;
                cout << "Multiplication: " << num1 * num2 << endl;
                cout << "Division: " << num1 / num2 << endl;
                break;
            }
            case 2: {
                double num1, num2;
                cout << "Enter two numbers: \n";
                cout << "Num1: "; cin >> num1;
                cout << "Num2: "; cin >> num2;
                cout << "Average: " << (num1 + num2) / 2 << endl;
                break;
            }
            case 3: {
                int num;
                cout << "Enter a whole number: ";
                cin >> num;
                cout << "The number " << num << " is " << (num % 2 == 0 ? "even." : "odd.") << endl;
                break;
            }
            case 4: {
                double num;
                cout << "Enter a number: ";
                cin >> num;
                if (num > 0)
                    cout << "The number is positive.\n";
                else if (num < 0)
                    cout << "The number is negative.\n";
                else
                    cout << "The number is zero.\n";

                break;
            }
            case 5: {
                double num;
                cout << "Enter a number: ";
                cin >> num;
                cout << "Square root: " << sqrt(num) << endl;
                break;
            }
            case 6: {
                double num;
                cout << "Enter a number: ";
                cin >> num;
                cout << "Absolute value: " << abs(num) << endl;
                break;
            }
            case 7: {
                double side;
                cout << "Enter the length of a square's side: ";
                cin >> side;
                cout << "Perimeter: " << 4 * side << " units\n";
                cout << "Area: " << side * side << " square units\n";
                break;
            }
            case 8: {
                int num;
                cout << "Enter a number for the multiplication table: ";
                cin >> num;
                for (int i = 1; i <= 12; i++) {
                    cout << i << " x " << num << " = " << i * num << endl;
                }
                break;
            }
            case 9: {
                double a, b;
                cout << "Enter the two sides of a right triangle:\n";
                cout << "Side a: "; cin >> a;
                cout << "Side b: "; cin >> b;
                cout << "Hypotenuse: " << sqrt(a * a + b * b) << endl;
                break;
            }
            case 10: {
                int response;
                cout << "Currency Exchange Options:\n";
                cout << "1. Dollars to Euros\n";
                cout << "2. Euros to Dollars\n";
                cout << "Choice: ";
                cin >> response;
                if (response == 1) {
                    double dollars;
                    cout << "Enter dollars: ";
                    cin >> dollars;
                    cout << "Equivalent in euros: " << dollars * 0.92 << endl;
                } else if (response == 2) {
                    double euros;
                    cout << "Enter euros: ";
                    cin >> euros;
                    cout << "Equivalent in dollars: " << euros * 1.09 << endl;
                }
                break;
            }
            case 11: {
                double a, b, c, x1, x2;

                // Enter the values
                cout << "Enter value for a: ";
                cin >> a;
                cout << "Enter value for b: ";
                cin >> b;
                cout << "Enter value for c: ";
                cin >> c;

                // Prevent division by zero
                if (a == 0) {
                    cout << "a cannot be zero." << endl;
                    return;
                }

                // Calculate discriminant
                double discriminant = (b * b) - (4 * a * c);

                // Solve
                cout << fixed << setprecision(2);
                if (discriminant > 0) { // Two real roots
                    x1 = (-b + sqrt(discriminant)) / (2 * a);
                    x2 = (-b - sqrt(discriminant)) / (2 * a);
                    cout << "x1 = " << x1 << endl;
                    cout << "x2 = " << x2 << endl;
                } else if (discriminant == 0) { // One real root
                    x1 = -b / (2 * a);
                    cout << "x1 = x2 = " << x1 << endl;
                } else { // Complex solutions
                    cout << "No real solutions." << endl;
                    double real = -b / (2 * a);
                    double imag = sqrt(-discriminant) / (2 * a);
                    cout << "x1 = " << real << " + " << imag << "i" << endl;
                    cout << "x2 = " << real << " - " << imag << "i" << endl;
                }
                break;
            }
            case 12:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
        cout << endl;
    } while (math_choice != 12);
}

void conversions() {
    int con_choice;
    do {
        cout << "\nConversions Menu:\n";
        cout << "1. Dollars to Pesos (or vice versa)\n";
        cout << "2. Dollars to Yen (or vice versa)\n";
        cout << "3. Dollars to Rupees (or vice versa)\n";
        cout << "4. Dollars to Euros (or vice versa)\n";
        cout << "5. Unit Converter\n";
        cout << "6. Back to Main Menu\n";
        cout << "Your choice: ";
        cin >> con_choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input" << endl;
            continue;
        }

        switch (con_choice) {
            case 1:
                int response;
                cout << "This program will convert pesos to dollars and vice versa." << endl;
                cout << "Enter 1 for Pesos to Dollars | 2 for Dollars to Pesos: ";
                cin >> response;
                if (response == 1) {
                    converter("Dollars");
                } else if (response == 2) {
                    converter("Pesos");
                } else {
                    cout << "Invalid Input." << endl;
                }
                break;
            case 2:
                int response2;
                cout << "This program will convert yen to dollars and vice versa." << endl;
                cout << "Enter 1 for Yen to Dollars | 2 for Dollars to Yen: ";
                cin >> response2;
                if (response2 == 1) {
                    converterYen("Dollars");
                } else if (response2 == 2) {
                    converterYen("Yen");
                } else {
                    cout << "Invalid Input." << endl;
                }
                break;
            case 3:
                int response3;
                cout << "This program will convert rupees to dollars and vice versa." << endl;
                cout << "Enter 1 for Rupees to Dollars | 2 for Dollars to Rupees: ";
                cin >> response3;
                if (response3 == 1) {
                    converterRu("Dollars");
                } else if (response3 == 2) {
                    converterRu("Rupees");
                } else {
                    cout << "Invalid Input." << endl;
                }
            case 4:
                int responseEu;
                cout << "This program will convert Euros to dollars and vice versa." << endl;
                cout << "Enter 1 for Euros to Dollars | 2 for Dollars to Euros: ";
                cin >> responseEu;
                if (responseEu == 1) {
                    converterEu("Dollars");
                } else if (responseEu == 2) {
                    converterEu("Euros");
                } else {
                    cout << "Invalid Input." << endl;
                }
                break;
            case 5:
                unitConverter();
                break;
            case 6:
                cout << "Going back to main menu...\n";
                break;
            default:
                cout << "Invalid choice." << endl;
        }
        cout << endl;

    } while (con_choice != 6);
}

// Placeholder for the Arrays section
void arrays() {
    int arr_choice;
    do {
        cout << "\nArrays Menu:\n";
        cout << "1. Multiply & Divide Arrays\n";
        cout << "2. Add Two Arrays to a Third Array\n";
        cout << "3. Add, Subtract, & Multiply Array\n";
        cout << "4. Sum of Array\n";
        cout << "5. Multiplication of an Array by N\n";
        cout << "6. Back to Main Menu\n";
        cout << "Your choice: ";
        cin >> arr_choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input" << endl;
            continue;
        }

        switch (arr_choice) {
            case 1:
                mult_div_arr();
                break;
            case 2:
                addTwoArrToThird();
                break;
            case 3:
                arrsOf5Elements();
                break;
            case 4:
                sumOfArr();
                break;
            case 5:
                mulOfArrByN();
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
        cout << endl;
    } while (arr_choice != 6);
}

// 2D Array section
void twoD_Arr() {
    int arr2D_choice;
    do {
        cout << "\n2D Arrays Menu:\n";
        cout << "1. 2D Array - Math Operations\n";
        cout << "2. 2D Array - Addition\n";
        cout << "3. Back to Main Menu\n";
        cout << "Your choice: ";
        cin >> arr2D_choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input" << endl;
            continue;
        }

        switch (arr2D_choice) {
            case 1:
                mathOpMatrix();
                break;
            case 2:
                addTwo2DArrays();
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
        cout << endl;
    } while (arr2D_choice != 3);
}

// Placeholder for the Games section
void games() {
    int games_choice;
    do {
        cout << "\nGames Menu:\n";
        cout << "1. NBA Quiz Game\n";
        cout << "2. NBA Quiz Game 2\n";
        cout << "3. Personalization Game: What TO Wear?\n";
        cout << "4. Tic-Tac-Toe\n";
        cout << "5. Rock, Paper, Scissors\n";
        cout << "6. Number Guessing Game\n";
        cout << "7. Blackjack\n";
        cout << "8. Back to Main Menu\n";
        cout << "Your choice: ";
        cin >> games_choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input" << endl;
            continue;
        }

        cout << endl;
        int score = 0, ans;

        switch (games_choice) {
            case 1:
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid Input" << endl;
                    continue;
                }
                cout << "Welcome to the NBA Quiz Game!\n";
                cout << "Answer the following questions by selecting 1 or 2.\n";

                // Question 1
                cout << "1. Which team has the most NBA titles?\n";
                cout << "1) Los Angeles Lakers\n";
                cout << "2) Boston Celtics\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 2) {  // Corrected: Boston Celtics have more
                    score += 20;
                }

                // Question 2
                cout << "2. How many championships does Kobe Bryant have?\n";
                cout << "1) 4\n";
                cout << "2) 5\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 2) {
                    score += 20;
                }

                // Question 3
                cout << "3. What are the New Orleans Pelicans team colors?\n";
                cout << "1) Blue/Navy/Yellow\n";
                cout << "2) Navy/Gold/Red\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 2) {
                    score += 20;
                }

                // Question 4
                cout << "4. What is the name of the Philadelphia 76ers mascot?\n";
                cout << "1) Franklin the Dog\n";
                cout << "2) Big Shot\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 1) {
                    score += 20;
                }

                // Question 5
                cout << "5. Which player won MVP for the 2016-2017 NBA Season?\n";
                cout << "1) Stephen Curry\n";
                cout << "2) Russell Westbrook\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 2) {
                    score += 20;
                }

                // Display final result
                cout << "\nYour final score is: " << score << "/100\n";
                if (score > 80) {
                    cout << "You are a champion!!!\n";
                } else {
                    cout << "You are almost a champion. Try again to become a champion.\n";
                }
                break;

            case 2:
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid Input" << endl;
                    continue;
                }
                score = 0;  // Reset score for game 2
                cout << "Welcome to NBA Quiz Game 2!\n";
                cout << "Answer the following questions by selecting 1, 2, 3, or 4.\n";

                // Question 1
                cout << "1. Which team has the most NBA titles?\n";
                cout << "1) Los Angeles Lakers\n";
                cout << "2) Boston Celtics\n";
                cout << "3) Golden State Warriors\n";
                cout << "4) Detroit Pistons\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 2) { // Correct answer: Celtics
                    score += 10;
                }

                // Question 2
                cout << "2. How many championships does Kobe Bryant have?\n";
                cout << "1) 4\n";
                cout << "2) 3\n";
                cout << "3) 6\n";
                cout << "4) 5\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 4) {
                    score += 10;
                }

                // Question 3
                cout << "3. What are the New Orleans Pelicans' team colors?\n";
                cout << "1) Blue/Navy/Yellow\n";
                cout << "2) Navy/Gold/Red/Royal\n";
                cout << "3) Navy/Gold/Red\n";
                cout << "4) Red/Blue/Silver/Black\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 3) {
                    score += 10;
                }

                // Question 4
                cout << "4. What is the name of the Philadelphia 76ers mascot?\n";
                cout << "1) Franklin the Dog\n";
                cout << "2) Big Shot\n";
                cout << "3) Phillie Phanatic\n";
                cout << "4) Swoop\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 1) {
                    score += 10;
                }

                // Question 5
                cout << "5. Which player won MVP for the 2016-2017 NBA Season?\n";
                cout << "1) Stephen Curry\n";
                cout << "2) Russell Westbrook\n";
                cout << "3) James Harden\n";
                cout << "4) LeBron James\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 2) {
                    score += 10;
                }

                //Question 6
                cout << "6. Who was 1st overall pick in the 2024 NBA Draft?\n";
                cout << "1.) Victor Wembanyama\n";
                cout << "2.) Zach Edey\n";
                cout << "3.) Zaccharie Risacher\n";
                cout << "4.) Rob Dillingham\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 3) {
                    score += 10;
                }

                //Question 7
                cout << "7. In what year did Allen Iverson carry the sixers to the finals?\n";
                cout << "1.) 2000\n";
                cout << "2.) 2004\n";
                cout << "3.) 1999\n";
                cout << "4.) 2001\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 4) {
                    score += 10;
                }

                //Question 8
                cout << "8. Out of the names below, which name won a championship as a player and as a coach?\n";
                cout << "1.) Greg Popovich\n";
                cout << "2.) Steve Kerr\n";
                cout << "3.) Nick Sirianni\n";
                cout << "4.) JJ Reddick\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 2) {
                    score += 10;
                }

                //Question 9
                cout << "9. Which NBA Team holds the record for most wins in a single season?\n";
                cout << "1.) Chicago Bulls\n";
                cout << "2.) Philadelphia 76ers\n";
                cout << "3.) Golden State Warriors\n";
                cout << "4.) Boston Celtics\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans ==3) {
                    score += 10;
                }

                //Question 10
                cout << "10. Who is the GOAT (Greatest player of all time)?\n";
                cout << "1.) LeBron James\n";
                cout << "2.) Michael Jordan\n";
                cout << "3.) Kareem Abdul-Jabbar\n";
                cout << "4.) Kobe Bryant\n";
                cout << "Your answer: ";
                cin >> ans;
                if (ans == 1) {
                    score += 10;
                }

                // Display final result
                cout << "\nYour final score is: " << score << "/100\n";
                if (score > 80) {
                    cout << "You are a champion!!!\n";
                } else if (score > 50 && score <= 80) {
                    cout << "You are almost a champion. Try again to become a champion.\n";
                } else {
                    cout << "Try again" << endl;
                }
                break;

            case 3:
                cout << "CORE: I kind of like to think of myself as a fashion Guru! Let me help you decide..." << endl;
                cout << "What to Wear?" << endl;
                cout << "Decide what you would like to wear." << endl;
                cout << endl;

                int response;
                do {
                    cout << "Would you like to wear a hoodie or a shirt?" << endl;
                    cout << "1.) Hoodie\n";
                    cout << "2.) Shirt\n";
                    cout << "3.) Exit\n";
                    cout << "4.) Return to Main Menu\n";
                    cout << "Your choice: ";
                    cin >> response;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Input" << endl;
                        continue;
                    }

                    if (response == 1) {
                        cout << "You selected to wear a hoodie!" << endl;
                        choose_your_style("Hoodie");
                    } else if (response == 2) {
                        cout << "You selected to wear a shirt!" << endl;
                        choose_your_style("Shirt");
                    } else if (response == 3) {
                        cout << "Exiting Program.";
                        exit(0);
                    } else if (response == 4) {
                        break;
                    } else {
                        cout << "Invalid choice." << endl;
                    }
                    cout << endl;

                } while (response != 3 || response != 4);
                break;
            case 4:
                char playAgain;
                do {
                    TicTacToe game;
                    game.initializeBoard();
                    game.displayBoard();
                    game.makeMove();

                    cout << "Would you like to play again? (y/n): ";
                    cin >> playAgain;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } while (tolower(playAgain) == 'y');

                cout << "Thanks for playing!" << endl;
                break;
            case 5: {
                RockPaperScissors rps;
                char response_rps;
                string name;
                cout << "Welcome to Rock-Paper-Scissors!" << endl;
                cout << "Please enter your name: ";
                getline(cin, name);
                rps.name = name;
                do {
                    rps.makeMove();
                    cout << "\nWould you like to play again? (y/n): ";
                    cin >> response_rps;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } while (tolower(response_rps) == 'y');
                break;
            }
            case 6:
                char nggChoice;
                cout << "Welcome to the Guessing Game!" << endl;
                cout << "The goal is to guess a random number between 0-100!" << endl;
                cout << "You only have 5 chances to guess correctly." << endl;
                cout << "Good Luck Guessing!" << endl;
                do {
                    guessingGame();
                    cout << "\nWould you like to play again? (y/n): ";
                    cin >> nggChoice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Good Luck Guessing!" << endl;
                } while (tolower(nggChoice) == 'y');
                break;
            case 7:
                blackjackGame();
                break;
            case 8:
                cout << "Returning to Main Menu..." << endl;
                break;
            default:
                cout << "Invalid input. Please enter 1, 2, or 3.\n";
        }
        cout << endl;

    } while (games_choice != 8);  // Corrected exit condition

}
void classes() {
    int classes_choice;
    do {
        cout << "\nClasses Menu:\n";
        cout << "1. People Class\n";
        cout << "2. Time Machine Class\n";
        cout << "3. Virtual Pet Class\n";
        cout << "4. Taco Class\n";
        cout << "5. Dog Class\n";
        cout << "6. Fastfood Class\n";
        cout << "7. Rectangle Class\n";
        cout << "8. Dancing Robot Class\n";
        cout << "9. Superhero Class\n";
        cout << "10. Monster Class\n";
        cout << "11. Treasure Class\n";
        cout << "12. Bank Account Class\n";
        cout << "13. Employee Class\n";
        cout << "14. Movie Class\n";
        cout << "15. Game Class\n";
        cout << "16. Return to Main Menu\n";
        cout << "Your choice: ";
        cin >> classes_choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input" << endl;
            continue;
        }

        switch (classes_choice) {
            case 1: {
                People person;
                person.introduce();
                break;
            }
            case 2: {
                TimeMachine tm;
                tm.travel();
                break;
            }
            case 3: {
                VirtualPet pet;
                pet.namePet();
                pet.feedPet();
                break;
            }
            case 4: {
                Taco taco;
                taco.addIngredients();
                taco.serveTaco();
                break;
            }
            case 5: {
                Dog dog;
                dog.bark();
                dog.fetch();
                break;
            }
            case 6: {
                FastFood ff;
                ff.orderMeal();
                break;
            }
            case 7: {
                Rectangle rect;
                rect.setDimensions();
                rect.displayArea();
                break;
            }
            case 8: {
                DancingRobot dr;
                dr.dance();
                break;
            }
            case 9: {
                Superhero hero;
                hero.setName();
                hero.usePower();
                break;
            }
            case 10: {
                Monster m;
                m.roar();
                break;
            }
            case 11: {
                Treasure t;
                t.captainName();
                t.openChest();
                break;
            }
            case 12: {
                BankAccount ba;
                ba.deposit(100);
                ba.withdraw(30);
                break;
            }
            case 13: {
                Employee emp;
                emp.setInfo();
                emp.displayInfo();
                break;
            }
            case 14: {
                Movie movie;
                movie.setMovie();
                movie.displayMovie();
                break;
            }
            case 15: {
                Game game;
                game.setGame();
                game.play();
                break;
            }
            case 16:
                cout << "Returning to Main Menu..." << endl;
                break;
            default:
                cout << "Invalid input." << endl;
        }
    } while (classes_choice != 16);
}

void miscellaneous() {
    int misChoice;
    do {
        cout << "\nMiscellaneous Menu:\n";
        cout << "1.) Tip Calculator\n";
        cout << "2.) Word Counter\n";
        cout << "3.) Letter Grade Calculator\n";
        cout << "4.) Coin FLip\n";
        cout << "5.) Return To Menu\n";
        cout << "Your choice: ";
        cin >> misChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input" << endl;
            continue;
        }

        switch (misChoice) {
            case 1:
                tipConverter();
                break;
            case 2:
                wordCounter();
                break;
            case 3:
                letterGradeCalc();
                break;
            case 4:
                coinFlip();
                break;
            case 5:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid input." << endl;
        }
        cout << endl;

    } while (misChoice != 5);
}

// Main Function
int main() {
    cout << "Hello, I am CORE, your Virtual Assistant!\n";
    cout << "I am here to help you with any problem you choose from the menu.\n\n";

    int choice;
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Mathematics\n";
        cout << "2. Arrays\n";
        cout << "3. 2D Arrays\n";
        cout << "4. Games\n";
        cout << "5. Virtual Shopping Cart\n";
        cout << "6. Flashcard App\n";
        cout << "7. Classes\n";
        cout << "8. Conversions\n";
        cout << "9. Virtual Medical Assistant\n";
        cout << "10. Miscellaneous\n";
        cout << "11. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input" << endl;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "CORE: Hello, I am your own personal math tutor! What can I assist you with?" << endl;
                mathematics();
                break;
            case 2:
                cout << "CORE: I think you will enjoy this section!" << endl;
                arrays();
                break;
            case 3:
                cout << "CORE: Feel free to test out the 2D Arrays we have to offer!" << endl;
                twoD_Arr();
                break;
            case 4:
                cout << "CORE: Welcome to the Games section!" << endl;
                games();
                break;
            case 5: {
                cout << "CORE: I wonder what you plan to buy..." << endl;
                vector<string> cart;
                vector<double> cartVal;
                int cartChoice;

                do {
                    cout << "Virtual Cart Menu\n";
                    cout << "1. Add to cart\n";
                    cout << "2. Show Items in cart\n";
                    cout << "3. Checkout\n";
                    cout << "4. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> cartChoice;
                    cout << endl;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Input" << endl;
                        continue;
                    }

                    switch (cartChoice) {
                        case 1:
                            addToCart(cart, cartVal);
                            break;
                        case 2:
                            if (!cart.empty()) {
                                cout << "Cart Items: " << endl;
                                for (size_t j = 0; j < cart.size(); j++) {
                                    cout << "- " << cart[j] << ": $" << cartVal[j] << endl;
                                }
                                cout << endl;
                            } else {
                                cout << "No items in cart." << endl;
                                cout << endl;
                            }
                            break;
                        case 3:
                            totalCost(cartVal);
                            break;
                        case 4:
                            cout << "Exiting Virtual Cart...\n";
                            break;
                        default:
                            cout << "Please enter a valid choice: " << endl;
                            break;
                    }

                } while (cartChoice != 4);
                break;
            }
            case 6:
                cout << "\nI'm proud of you for trying to study!\n";
                int choice;
                do {
                    cout << "\n--- Flashcard Menu ---\n";
                    cout << "1. Practice FlashCards\n";
                    cout << "2. Add FlashCard\n";
                    cout << "3. Shuffle FlashCards\n";
                    cout << "4. Delete FlashCards\n";
                    cout << "5. Study FlashCards\n";
                    cout << "6. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> choice;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input. Try again!\n";
                        continue; // <--- prevent bad choice from running switch
                    }

                    switch (choice) {
                        case 1:
                            practiceFlashCards();
                        break;
                        case 2:
                            cout << "--- Add Mode ---" << endl;
                        addFlashCard();
                        break;
                        case 3:
                            cout << "--- Shuffle Mode ---" << endl;
                        shuffleFlashCards();
                        break;
                        case 4:
                            cout << "--- Delete Mode ---" << endl;
                        deleteFlashCards();
                        break;
                        case 5:
                            cout << "--- Study Mode ---" << endl;
                        studyFlashCards();
                        break;
                        case 6:
                            cout << "Goodbye!" << endl;
                        break;
                        default:
                            cout << "Invalid Choice" << endl;
                    }
                } while (choice != 6);
                break;
            case 7:
                cout << "\nWelcome the Classes Menu\n";
                classes();
                break;
            case 8:
                cout << "\nWelcome to the Conversions Side\n";
                conversions();
                break;
            case 9: {
                cout << "\nBeen feeling stressed? I'm here to help with that.\n";
                string name;

                // Velma's intro
                cout << "Hi! I'm Velma - your Virtual Emotional & Lifestyle Medical Assistant.\n"
                     << "I stem from CORE - a constantly evolving system built to support your mind and body.\n"
                     << "While CORE tackles everyday challenges, I focus on *you* — your wellness, your emotions, and your peace of mind.\n"
                     << "Ready to check in?\n";

                // Ask for name
                cout << "\nPlease enter your full name so I can further assist you today: ";
                cin.ignore();
                getline(cin, name);

                // Greeting and assessment intro
                cout << "\nHello, " << name << "! I'm so glad you're here.\n"
                     << "I'll be asking you a short series of questions to better understand your current stress levels.\n"
                     << "Don't worry - your answers are completely private and won't be stored or shared.\n";

                // Likert scale explanation
                cout << "\nWe'll be using the Likert scale to assess your responses:\n";
                cout << "|-----------------------------------|\n";
                cout << "|     Option      ||      Score     |\n";
                cout << "|-----------------------------------|\n";
                cout << "| Rarely or Never ||        1       |\n";
                cout << "| Sometimes       ||        2       |\n";
                cout << "| Often or Always ||        3       |\n";
                cout << "|-----------------------------------|\n";

                // Start questions
                cout << "\nLet's begin, " << name << "!\n" << endl;

                // Run Velma
                vma q;
                q.questions();
                q.scoreClassification(name);
                q.personalRecommendation();

                cout << "\nThank you for checking in with me today, " << name << ". Take care of yourself - your well-being matters.\n";
                break;
            }

            case 10:
                cout << "Can't put a title on everything you know." << endl;
                miscellaneous();
                break;
            case 11:
                cout << "Goodbye! Exiting program...\n";
                break;
            default:
                cout << "Please enter a valid choice.\n";
                break;
        }

    } while (choice != 11);

    return 0;
}

