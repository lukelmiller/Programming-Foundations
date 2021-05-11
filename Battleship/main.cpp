//@author lukelmiller

//--------------------------------------------------------
// File: hw5.cpp
//--------------------------------------------------------


#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

//SHIP SIZE
const int CARRIER_SIZE = 5;
const int BATTLESHIP_SIZE = 4;
const int NAVALSHIP_SIZE = 3;
const int SUBMARINE_SIZE = 3;
const int DESTROYER_SIZE = 2;
//SHIP NAME
const string CARRIER_NAME = "Carrier";
const string BATTLESHIP_NAME = "Battle ship";
const string NAVALSHIP_NAME = "Naval ship";
const string SUBMARINE_NAME = "Submarine";
const string DESTROYER_NAME = "Destroyer";
//SHIP CHARACTER
const char CARRIER_CHAR = 'C';
const char BATTLESHIP_CHAR = 'B';
const char NAVALSHIP_CHAR = 'N';
const char SUBMARINE_CHAR = 'S';
const char DESTROYER_CHAR = 'D';
//SPECIAL CHARACTERS
const char WATER = '.';
const char HIT = 'x';
const char MISS = '-';
//BOARD
const int BOARD_SIZE = 8;
const int TOTAL_HP = CARRIER_SIZE+BATTLESHIP_SIZE+NAVALSHIP_SIZE+SUBMARINE_SIZE+DESTROYER_SIZE;
//FILES
const string COMPUTER_SHIPS_FILE = "./computer_ships.txt"; // put back the ./
const string COMPUTER_HITS_FILE = "./computer_hits.txt";  // put back the ./
const string USER_SHIPS_FILE = "./user_ships.txt";  // put back the ./
const string USER_HITS_FILE = "./user_hits.txt";  // put back the ./-----------------------------------------------------------------------------
//OTHERS
const char NEW_GAME = '1';
const char LOAD = '2';
const char FIRE = '1';
const char SAVE = '2';
const char QUIT = '3';

// HIT status
const int A_MISS = '0';
const int NEW_HIT = '1';
const int REHIT = '2';

//----------------------------------------------------------------
// Name: init_board
// Parameters: board (char, 2-dimension array) - the board to initialize
// Returns:   nothing
// Purpose:  to initialize a board with WATER in each element
//----------------------------------------------------------------
void init_board(char board[BOARD_SIZE][BOARD_SIZE])
{

  for(int r = 0; r < BOARD_SIZE; r++)
  {   for(int c = 0; c < BOARD_SIZE; c++)
      {
           board[r][c]  = WATER;
      }
  }
}

//----------------------------------------------------------------
// Name: print_board
// Parameters:    board (char, 2-dimension array) - the board to display
//                name (string, const) - the name to display above the board
// Returns:   nothing
// Purpose:   output the board to the console
//----------------------------------------------------------------
void print_board(char board[BOARD_SIZE][BOARD_SIZE], const string name)
{
        cout << "--- " << name << " ---" << endl;
        cout << " | 0 1 2 3 4 5 6 7 |" << endl;
   for (int r= 0; r<BOARD_SIZE; r++)
        {
                cout << r << "| ";
                for(int c=0; c<BOARD_SIZE; c++)
                {
        cout << board[r][c] << " ";
                }
                cout << "|" << endl;
        }
        cout << "-------------------------" << endl;
}

//----------------------------------------------------------------
// Name: print_status
// Parameters: user_hp (int, const) - user's current hp
//             computer_hp (int, const) - the computer's current hp
// Returns:   nothing
// Purpose:  to output the user's current hp and
//           the computer's current hp to the console
//----------------------------------------------------------------
void print_status(int user_hp, int computer_hp)
{
   cout << "The users current hp: " << user_hp << endl;
   cout << "The computers current hp: " << computer_hp << endl;
}

//----------------------------------------------------------------
// Name: place_a_ship
// Parameters:    board (char, 2-dimension array) - the board to place the ship onto
//                name_ship (string, const) - the name of the ship to place
//                      ship_char (string, const) - the character used to represent the ship on the board
//                      size (int, const) - the size of the ship
//
// Returns:   nothing
// Purpose:  place a ship on the board
//----------------------------------------------------------------
void place_a_ship(char board[BOARD_SIZE][BOARD_SIZE], const string name_ship, const char ship_char, const int size)
{
        //LOCAL VARIABLES
        bool coord_valid = false;
        bool overlap = false;
        char orientation = '\0';
        int row, col;

        //GET SHIP ORIENTATION
        do{
                cout << "Please choose the orientation of the ship:\nEnter 'v' or 'V' for vertical and 'h' or 'H' for horizontal" << endl;
                cin >> orientation;
        }while(orientation != 'v' && orientation != 'V' && orientation != 'h' && orientation != 'H');
        cout << "The ship will be placed " << ((orientation=='v'||orientation=='V')?"vertically":"horizontally") << endl;

        //GET SHIP COORDINATE
        do{
                overlap = false;
                cout << "Please enter the row and column coordinates of the ship: " << endl;
                cin >> row >> col;
                //check if coordinates are in the range 0-7
                if(row<0 || row>=BOARD_SIZE || col<0 || col>=BOARD_SIZE)
                        cout << "Invalid coordinates!" << endl;
                else
                        coord_valid = true;

                //check if the ship is out of range
                if((orientation == 'h' || orientation == 'H') && (size+col>BOARD_SIZE))
                {
                        cout << "Ship is out of range!" << endl;
                        coord_valid = false;
                }
                else if((orientation == 'v' || orientation == 'V') && (size+row>BOARD_SIZE))
                {
                        cout << "Ship is out of range!" << endl;
                        coord_valid = false;
                }
                else
                        coord_valid = true;

                //CHECK FOR OVERLAPPING
                if(orientation == 'h' || orientation == 'h')
                {
                        for(int c=0;c<size;c++)
                                if(board[row][col+c] != WATER)
                                        overlap = true;
                }
                else if(orientation == 'v' || orientation == 'V')
                {
                        for(int r=0;r<size;r++)
                                if(board[row+r][col] != WATER)
                                        overlap = true;
                }
                if(overlap) cout << "Ship is overlapping another ship!" << endl;
        }while(!coord_valid || overlap);

        //PLACE THE SHIP ON THE BOARD
        if(orientation == 'h' || orientation == 'H')
                for(int c=0;c<size;c++)
                        board[row][col+c] = ship_char;
        else if(orientation == 'v' || orientation == 'V')
                for(int r=0;r<size;r++)
                        board[row+r][col] = ship_char;
}

//----------------------------------------------------------------
// Name: place_all_ships
// Parameters: board (char, 2-dimensional array) - the board onto which to place the ships
// Returns:   nothing
// Purpose:  uses place_a_ship to place all 5 ships on the board
//----------------------------------------------------------------
void place_all_ships(char board[BOARD_SIZE][BOARD_SIZE])
{
        place_a_ship(board, CARRIER_NAME , CARRIER_CHAR, CARRIER_SIZE);
        print_board(board, "USER SHIP BOARD");
/*  JUST PLACE ONE SHIP TO START SO THE GAME ENDS MORE QUICKLY
    AFTER YOUR DEBUGGING IS DONE, PLACE ALL THE SHIPS*/
        place_a_ship(board, BATTLESHIP_NAME, BATTLESHIP_CHAR, BATTLESHIP_SIZE);
        print_board(board, "USER SHIP BOARD");
        place_a_ship(board, NAVALSHIP_NAME, NAVALSHIP_CHAR, NAVALSHIP_SIZE);
        print_board(board, "USER SHIP BOARD");
        place_a_ship(board, SUBMARINE_NAME, SUBMARINE_CHAR, SUBMARINE_SIZE);
        print_board(board, "USER SHIP BOARD");
        place_a_ship(board, DESTROYER_NAME, DESTROYER_CHAR, DESTROYER_SIZE);
        print_board(board, "USER SHIP BOARD");

}

//----------------------------------------------------------------
// Name: load_hits
// Parameters: board (char, 2-dimension array) - the array that will holds the board
//             filename (string, const) - the name of the file to load
// Returns:   bool - returns whether or not the file was read succesfully
// Purpose:  to read the file that contains the board (hits)
//           and store it into the board parameter
//----------------------------------------------------------------
bool load_hits(char board[BOARD_SIZE][BOARD_SIZE],  const string filename)
{
   bool loaded = false;

   ifstream startfile;
   startfile.open(filename);
   for(int r = 0; r < BOARD_SIZE; r++)
   {
      for(int c = 0; r < BOARD_SIZE; c++)
      {
         startfile >> board[r][c];
         loaded = true;
      }
   loaded = true;
   }
   startfile.close();
   return loaded;
}

//----------------------------------------------------------------
// Name: load_ships
// Parameters: board (char, 2-dimension array) - the array that will holds the board
//             filename (string, const) - the name of the file to load
//             hp (int, ref) - the user's hp
// Returns: bool - returns whether or not the file was read succesfully
// Purpose: to read the file that contains the board (ships)
//          and store it into the board parameter.
//          Should also set the user's current hp based TOTAL_HP - number of hits
//----------------------------------------------------------------
bool load_ships(char board[BOARD_SIZE][BOARD_SIZE], const string  filename, int &hp)
{
bool loaded = false;

      ifstream openfile;
      openfile.open(filename);
      for(int r = 0; r < BOARD_SIZE; r++)
      {      for( int c = 0; c < BOARD_SIZE; c++)
             {   openfile >>  board[r][c];
                 if(board[r][c] == HIT)
                 {  hp = TOTAL_HP - 1;
                 }
                 loaded = true;
              }
      cout << endl;
      }
      openfile.close();
      return loaded;
}

//----------------------------------------------------------------
// Name:    save
// Parameters: board (char, 2-dimension array) - the board to save
//             filename (string, const) - the name of the file to save
// Returns:   bool - returns whether or not the file was written succesfully
// Purpose:  to write the board into a file
//----------------------------------------------------------------
bool save(char board[BOARD_SIZE][BOARD_SIZE], const string  filename)
{    bool saving = false;
     ofstream saveGame;
     saveGame.open(filename);
     for(int r = 0; r < BOARD_SIZE; r++)
     {    for(int c = 0; c < BOARD_SIZE; c++)
          {
             saveGame << board[r][c];
             saving  = true;
          }
    cout << endl;
    }
    saveGame.close();
    return saving;
}
//----------------------------------------------------------------
// Name:    fire
// Parameters: opponent_ship_board (char, 2-dimension array) - the board to fire at
//             row (int, const) - the row coordinate of the shot
//             col (int, const) - the column coordinate of the shot
// Returns:   bool - returns true if this is a new hit, false if it is a miss or a repeat hit
// Purpose:  given the coordinates row, col of a shot to the opponent_ship_board
//           write a message to the consol about whether it was a new hit, miss, or repeat hit
//           return NEW_HIT, REHIT, or NEW_MISS
//----------------------------------------------------------------
int fire(char opponent_ship_board[BOARD_SIZE][BOARD_SIZE], char user_hit_board[BOARD_SIZE][BOARD_SIZE], const int row, const int col)
{
    int boom;
if(opponent_ship_board[row][col] == WATER)
   { boom = 0;
     cout << "What a shame. :( You wasted an attack on that?" << endl;
     cout << "MISS!" << endl;
   }
else if(opponent_ship_board[row][col] == MISS)
   { boom = 0;
     cout << "What a shame. :( You wasted an attack on that?" << endl;
     cout << "MISS!" << endl;
   }
else if(user_hit_board[row][col] == HIT)
   { boom = 2;
     cout << "This is a rehit, you have hit this location once before." << endl;
     cout << "REHIT!" << endl;
   }
else
   { boom = 1;
     cout << "HIT!" << endl;
     cout << "Your hit was GOOD!!! Down goes one more ship." << endl;
   }
 return boom;
}
//----------------------------------------------------------------
// Name: get_choice
// Parameters:   None
// Returns: char - returns the user's choice
// Purpose:  display the menu at each round to ask the user which action
//           they want to perform. 1) Fire 2) Save  3) Quit
//----------------------------------------------------------------
char get_choice()
{
   char c;
   cout << "Main Menu" << endl;
   cout << "1. Fire" << endl;
   cout << "2. Save" << endl;
   cout << "3. Quit" << endl;

   cin >> c;
   return c;
}


//----------------------------------------------------------------
// Name: start_game
// Parameters:   None
// Returns: char - returns the user's choice
// Purpose:  display the menu at each round to ask the user which action
//           they want to perform. 1) New Game  2) Load Game  3) Quit
//----------------------------------------------------------------
char start_game()
{
   char c;
   cout << "Main Menu" << endl;
   cout << "1. New Game" << endl;
   cout << "2. Load Game" << endl;
   cout << "3. Quit" << endl;
   cin >> c;
   return c;
}



//----------------------------------------------------------------
// Name: take_turn
// Parameters: player (string, const) - whose turn it is  (COMPUTER or USER)
//             player_hit_board (char, 2-dimension array)
//                  - current player's board that keeps track of their hits and misses
//                                                                       track of the hit/miss
//             opponent_ship__board (char, 2-dimension array)
//                  - the board to fire at, i.e., the opponent's hidden board with their ships
//              opponent_hp (int, ref) - the opponent's hp to update if the shot was successful
// Returns: Nothing
// Purpose:
//    if it is the computer's turn, use rand to generate row, col of their hit
//    if it is the user's turn, ask them for a row, col
//    call "fire" to take the shot
//    depending on what fire returns,
//         if it was a hit
//            decrement the opponent's hp, update the player's hit board with HIT
//         if it was a_miss
//            update the player's hit board with MISS
//        if it was a rehit
//            nothing to do, you don't need this case at all
//----------------------------------------------------------------
void take_turn(const string player, char user_hit_board[BOARD_SIZE][BOARD_SIZE], char opponent_ship_board[BOARD_SIZE][BOARD_SIZE], int &opponent_hp)
{
   int row;
   int col;

   if (player == "COMPUTER")
   { int row = rand()%BOARD_SIZE;
     int col = rand()%BOARD_SIZE;
     int fireRetrn = fire(opponent_ship_board,user_hit_board, row, col);
       if(fireRetrn == 1)
       {user_hit_board[row][col] = HIT;
        opponent_hp = opponent_hp - 1;
       }
      else if(fireRetrn == 0)
     {  user_hit_board[row][col] = MISS;

     }
   }

   if (player == "USER")
   {
      cout << "select the coordinates that you would like to hit: Ex :[x][y] = X Y " << endl;
      cin >> row;
      cin >> col;
      cout << row;
      cout << col;
      int fireRetrn = fire(opponent_ship_board,user_hit_board,row,col);
         if(fireRetrn == 1)
         {user_hit_board[row][col] = HIT;
          opponent_hp = opponent_hp -1;
         }
         else if(fireRetrn == 0)
         { user_hit_board[row][col] = MISS;
         }
   }


}

//----------------------------------------------------------------
// Name:    check_win
// Parameters: user_hp (int, const) - The player's hp
//             computer_hp (int, const) - The computer's hp
// Returns:  bool - whether or not there is a winner
// Purpose:  If someone won, announce the winner
//           Returns true if someone has won. Returns false otherwise
//----------------------------------------------------------------
bool check_win(int user_hp, int computer_hp)
{
   bool win = false;
   if ((user_hp > computer_hp) && (computer_hp == 0))
   {
      win = true;

      cout << "Player is the winner! " << endl;
   }
   else if  ((computer_hp > user_hp) && (user_hp == 0))
   {
      win = true;
      cout << "Computer is the winner! " << endl;
   }
   else
   {
      cout << "There was no winner! " << endl;
   }
   return win;
}
//----------------------------------------------------------------
// Name: play
// Parameters: user_ship_board (char, 2-dimension array) - the user's ship board
//             user_hit_board (char, 2-dimension array) - the user's hit board
//             user_hp (int, ref) - the player's hp
//             computer_ship_board (char, 2-dimension array) - the computer's ship board
//             computer_hit_board (char, 2-dimension array) - the computer's hit board
//             computer_hp (int, ref) - the computer's hp
// Returns: Nothing
// Purpose: main function of the program that plays the game after the boards are all set up
//       - seed the random number generator
//       - loop until quit
//            - ask the user which action he wants to perform   (save, fire, quit)
//              - If the user chooses to save, save all 4 boards and keep the game going
//              - If the user chooses to fire,
//                     - have the computer take one turn
//                     - display status and user ship board
//                     - if the computer didn't win
//                           - have the user take one turn
//                           - display status and user hit board
//                           - check to see if the user won
//      - stop the loop whenever someone has won or the user selects quit
//----------------------------------------------------------------
void play(char user_ship_board[BOARD_SIZE][BOARD_SIZE], char user_hit_board[BOARD_SIZE][BOARD_SIZE], int &user_hp, char computer_ship_board[BOARD_SIZE][BOARD_SIZE], char computer_hit_board[BOARD_SIZE][BOARD_SIZE], int &computer_hp)
{
        //MAIN LOOP
        bool game_over = false;
        char user_choice;
        bool userSaveShip;
        bool userSaveHit;
        bool compSaveShip;
        bool compSaveHit;
        string player;
    srand(time(NULL));   // only need to seed the random numbers once per game

        do{
                user_choice = get_choice();
                if(user_choice == SAVE)
                {
            // save the 4 boards
                        userSaveShip = save(user_ship_board, USER_SHIPS_FILE);
                        userSaveHit = save(user_hit_board, USER_HITS_FILE);
                        compSaveShip = save(computer_ship_board, COMPUTER_SHIPS_FILE);
                        compSaveHit = save(computer_hit_board, COMPUTER_HITS_FILE);
                        if ((userSaveShip == true) && (userSaveHit == true) && (compSaveShip == true) && (compSaveHit == true))
                                cout << "Game Successfuly Saved." << endl;
                        else
                                cout << "Failed to save!" << endl;
                }
                else if(user_choice == FIRE)
                {
                /*  //    add fire for user
                const int r;
                const int c;
                cout << "enter a row " << endl;
                cin >> r;
                cout <<  "enter a row " << endl;
                cin >> c;

                fire(computer_ship_board, r, c);*/
                // add some more user messages to make it look nice
                cout << "you have selected to fire, input a slot on the board to fire on. " << endl;
                // call take_turn so that the computer can take a turn
                                take_turn("COMPUTER",computer_ship_board, user_hit_board,  user_hp);
                                print_status(user_hp, computer_hp);
// Should only print the USER SHIP BOARD; remove the extra board prints when done debugging
                                print_board(user_ship_board, "USER SHIP BOARD");
                                print_board(user_hit_board, "USER HIT BOARD");
                                print_board(computer_ship_board, "COMPUTER SHIP BOARD");
                                print_board(computer_hit_board, "COMPUTER HIT BOARD");
                {
                // did the computer win?
                // if the game is not over
                                    bool game_over = check_win(user_hp, computer_hp);
                                if (game_over== false)
                                {
                                    take_turn("USER", user_hit_board, computer_ship_board, computer_hp);
                   // add some more user messages to make it look nice
                                //cout << " the game is still in process,  there is currently no winner yet feel free to continue firing, save or quit the game. " << endl;
                   // have the user take a turn

                  // cout << endl << endl;


// Should only print the USER HIT  BOARD; remove the extra board prints when done debugging
                                   print_status(user_hp, computer_hp);
                                   print_board(user_ship_board, "USER SHIP BOARD");
                                   print_board(user_hit_board, "USER HIT BOARD");
                                   print_board(computer_ship_board, "COMPUTER SHIP BOARD");
                                   print_board(computer_hit_board, "COMPUTER HIT BOARD");
                                   game_over = check_win(user_hp, computer_hp);
                }
                }
                }

        else if (user_choice == QUIT)
           cout << "Thanks for playing!\n";
        }while(user_choice != QUIT && !game_over);

}

//----------------------------------------------------------------
// Name: Main
// Purpose:  set up the boards and play the game
//     - declare the 4 2-dimentional arrays for the 4 boards
//     - if it is a new game, load the computer ship board from a file
//          - init the other 3 boards
//          - ask the user to place ships on their board manuall
//     - if the user chooses to load a saved game
//          - load all 4 boards from a file
//     - in both above cases, call "play" to play the game
//     - if the user selects Quit, then end the program
//
//----------------------------------------------------------------
int main()
{
        // names
        cout << "Anthony Lopez-Guerra" << endl;
        cout << "010561185" << endl;
        cout << "Juan Caballero" << endl;
        cout << "010861155" << endl;
        cout << "PF1-Homework 5" << endl;

        char user_choice;
        int user_hp = TOTAL_HP;
        int computer_hp = TOTAL_HP;
        //BOARDS


        char user_ship_board[BOARD_SIZE][BOARD_SIZE];
        char user_hit_board[BOARD_SIZE][BOARD_SIZE];
        char computer_ship_board[BOARD_SIZE][BOARD_SIZE];
        char computer_hit_board[BOARD_SIZE][BOARD_SIZE];



        //NEW GAME OR LOAD
        user_choice = start_game();
        if(user_choice == NEW_GAME) // new game
        {
                //Init user_ship_board, user_hit_board, computer_hit_board to WATER
                init_board(user_ship_board);
                init_board(user_hit_board);
                init_board(computer_hit_board);

                //Load computer_ship_board from COMPUTER_SHIPS_FILE
                bool load_computer_ship = load_ships(computer_ship_board, COMPUTER_SHIPS_FILE, computer_hp);
                if(!load_computer_ship)
                {
                        cout <<"Could not load computer's board." << endl;
                        exit(-1);
                }
                //Have user place their ships on the user_ship_board
                place_all_ships(user_ship_board);
                print_board(user_ship_board, "USER SHIP BOARD");
        }
        else if(user_choice == LOAD) // load
        {
                bool load_computer_ship = load_ships(computer_ship_board, COMPUTER_SHIPS_FILE, computer_hp);
                bool load_computer_hit = load_hits(computer_hit_board, COMPUTER_HITS_FILE);
                bool load_user_ship = load_ships(user_ship_board, USER_SHIPS_FILE, user_hp);
                bool load_user_hit = load_hits(user_hit_board, USER_HITS_FILE);
                if(!load_computer_ship || !load_user_ship || !load_user_hit || !load_computer_hit)
                {
                        cerr << "Error while loading" << endl;
                        exit(-1);
                }
                else
                {
                        cout << "Boards loaded successfully!" << endl;
                        print_status(user_hp, computer_hp);
                        print_board(user_ship_board, "USER SHIP BOARD");
                        print_board(user_hit_board, "USER HIT BOARD");
                }
         cout << "Your board is loaded" << endl;
       }
       if (user_choice != QUIT)
           play(user_ship_board, user_hit_board, user_hp, computer_ship_board, computer_hit_board, computer_hp);
       else
       cout << "Thanks for playing!\n";

        return 0;
}
