#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//My Name ... purpose of prog.
//This is a hangman program
//One player creates a phrase
//and the next guesses the
//characters

//MAX represents the maximum
//number of elements for a
//phrase (20 characters plus 1 for '\0')
const int MAX = 21;

//Prototypes
void welcome(); //tell the user the rules
int read_phrase(char phrase[]); //length is returned
void clear_screen();
void underscorer(char orig[], char result[],int num);
void display(char [], int);
char guess();
bool ismatch(char orig[], int & location, int len,
             char single_character_guess);

//Get the player's guess
char guess()
{
   char letter;
   cout <<"Please enter your guess: ";
   cin >> letter;
   cin.ignore(100,'\n');
   return letter;
}

//find if there is a match in the original
//array and return true if there is, and false
//otherwise. The location is the first index
//where a match is found. Of course there could
//be others
bool ismatch(char array[], int & found_location,
             int length, char guess)
{
    int i;
    for (i = 0; i < length && array[i]!= guess;
         ++i);
    if (i >= length)
       return false;
    found_location = i;
    return true;
}

//Display an array
void display(char array[], int len)
{
   for(int i = 0; i < len; ++i)
     cout <<array[i] <<" ";
   cout <<"\n\n";
}

//Load underscores for each character in the orig.
//array up to num characters
void underscorer(char orig[], char result[],int num)
{
   for (int i = 0; i < num; ++i)
   {
     /* if (orig[i] >= 'a' && orig[i] <= 'z' ||
          orig[i] >= 'A' && orig[i] <= 'Z')  */
     if (' '  != orig[i] && '\t' != orig[i])
        result[i] = '_';
     else result[i] = ' ';
   }
   result[num] = '\0';
}

//header comment...purpose of the function and args
//The welcome function will display the rules for
//the hangman program if the user desires
void welcome()
{
   char response;
   cout <<"Welcome to the CS Hangman game!\n";
   cout <<"\nWould you like the rules? Y or N ";
   cin >> response;
   cin.ignore(100,'\n');
   response = toupper(response);
   if ('Y' == response)
   {
        cout <<"The first player enters a phrase "
             <<"of at most " <<(MAX-1)
             <<" characters and the "
             <<"other participants guess until they "
             <<"know the word. You will guess "
             <<"single letters (A-Z) only! "
             <<"\nLet's have fun!!" <<"\n\n\n\n";
   }

}

//Read phrase will get a phrase from the user
//and return the length of it
int read_phrase(char phrase[])
{
     //Prompt the user
     cout <<"Please enter the secret phrase....";

     //Removed extra newlines at the beginning
     while (cin.peek() == '\n')
        cin.ignore();

     //Read in the phrase, clearing the screen ASAP
     cin.get(phrase, MAX, '\n');
     cin.ignore(100,'\n');
     clear_screen();
     return strlen(phrase);
}

//Sends out lots of newlines! It will feel like
//clearing the screen
void clear_screen()
{
    for (int i=0; i<100; ++i)
       cout <<'\n';
}

int main()
{
  char original_phrase[MAX];
  char guess_phrase[MAX]; //start as underscores
  char a_guess;//single character being guessed
  int length; //how long is the phrase
  int found; //representing the found location

  welcome(); //function call.....
  length = read_phrase(original_phrase);
  underscorer(original_phrase, guess_phrase, length);
  display(guess_phrase, length);
  a_guess = guess();
  if (ismatch(original_phrase, found, length, a_guess))
      cout <<"CONGRADULATIONS!!!! MATCH\n\n";
  else cout <<"SORRY...maybe next time!\n\n";

  return 0;
}
