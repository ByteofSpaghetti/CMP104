#include <chrono>    //Sleep function
#include <Windows.h> //Sleep function
#include <cstdlib>   //Sleep function
#include <stdio.h>   //random number   
#include <time.h>   //Time for seeding random number
#include <iostream> //random number

void feed(int*, int*, int*, std::string*); //Prototypes feed function
void nap(int*, int*, int*, std::string*);  //Prototypes nap function
void state1(int*, int*, int*, std::string*);//Prototypes function to display state of pet
void main_menu(int*, int*, int*, std::string*); //Prototypes main menu function
void play(int*, int*, int*, std::string*); //Prototypes roulette function
void show(); //Prototypes pet image function
void death(); //Prototypes dead pet image function


int main() {


	std::string pname = "Your pet"; //Declare variables
	int hunger_counter = 5; //Add time to minus the hunger level	
	int sleep_counter = 5; //Add time to minus sleep level
	int happiness = 0; //Happiness counter
	char name_option; //Lets user decide whether or not to choose a name

	//Creates variables to point at variables to pass along function parameters
	std::string* name = &pname; //Creates variable to point at name
	int* hunger = &hunger_counter; //Creates variable to point at the hunger counter
	int* sleep = &sleep_counter; //Creates variable to point at sleep counter
	int* happy = &happiness; //Creates variable to point at happiness counter

	show(); //Displays image of uni student
	std::cout << "Would you like to name your uni student? if you do not select a name, it will be called 'uni student' Please enter Y/N:  " << std::endl; //Asks for user input to give name or stay with default name
	std::cin >> name_option; //Puts name option in
	//Took liberty with changing default from your pet to uni student as seemed more fitting

	switch (toupper(name_option)) { //declaring with with expression and forcing name option into upper case
	case 'Y': // if user wants to name student
		std::cout << "Please enter the name for your uni student: " << std::endl;
		std::cin >> pname; // enters name
		break; //breaks out of loop of code

	case 'N':
		pname = "uni student"; // gives default name
		break;
	default:
		std::cout << "error" << std::endl; //outputs error message if user input wrong
	}

	main_menu(hunger, sleep, happy, name); //Calls main menu function to display main menu passing hunger, sleep, happy and name to be used in later functions

}

void main_menu(int* hunger, int* sleep, int* happy, std::string* name) { //Declares function and parameters
	char option = 'l';//variable to call next function dependant on user input

	do { //Executes following code once then checks the while statement
		std::cout << "**************************************************" << std::endl; // Displays menu with options
		std::cout << "Enter F to feed " << *name << std::endl; 
		std::cout << "N to send " << *name << " to bed" << std::endl;
		std::cout << "D to see " << *name << "'s feelings" << std::endl;
		std::cout << "Press P to play roulette with " << *name << std::endl;
		std::cout << "and D to die" << std::endl;
		std::cout << "**************************************************" << std::endl;
		std::cin >> option; //Choose options

		switch (toupper(option)) { //switch statement, forcing option into upper case
		case 'F':
			feed(hunger, sleep, happy, name); //Calls feed function, passing parameters
			break;

		case 'N':
			nap(hunger, sleep, happy, name); //Calls nap function, passing parameters

			break;

		case 'D':
			state1(hunger, sleep, happy, name); //Calls function to display state of uni student, passing parameters

			break;

		case 'P':
			play(hunger, sleep, happy, name); //Calls function play to play roulette, passing paramters
		} 
		
	} while ((*hunger >= 0) && (*sleep >= 0) && (toupper(option) != 'D')); //executes code until user chooses to exit or uni student dies
	
		death(); //Shows dead uni student
		std::cout << "You died! Better luck next time!" << std::endl;
}


	void feed(int* hunger, int* sleep, int* happy, std::string* name) {

		char foodchoice;

		if (*hunger >= 10) { //if hunger more than 10 program outputs uni student full
			std::cout << *name << " Is full! Maybe try sleeping?" << std::endl;
		}
		else if (*hunger < 10) { 
			std::cout << "What food would you like to feed " << *name << " C for curry, P for pot noodle, L for leftovers, D for donner kebab: " << std::endl;
			std::cin >> foodchoice; //Food choice
			//forceupper
			switch (toupper(foodchoice)) {

			case 'C': // feeds uni student curry
				std::cout << " " << *name << " ate the curry! They have been fed :)" << std::endl;
				(*hunger)++; //adds to hunger counter, uni student less hungry
				(*sleep)--; //makes uni student more sleepy
				break;


			case 'P': //Feeds uni student a pot noodle
				std::cout << " " << *name << " ate the pot noodle! They have been fed :)" << std::endl;
				(*hunger)++;
				(*sleep)--;
				break;


			case 'L': //Feeds student 'left overs'
				std::cout << " " << *name << " ate the leftovers! They have been fed :)" << std::endl;
				(*hunger)++;
				(*sleep)--;
				break;


			case 'D': //Feeds uni student donner kebab
				std::cout << " " << *name << " ate the donner kebab! They have been fed :)" << std::endl;
				(*hunger)++;
				(*sleep)--;
				break;

			

			}
		}

	}
	void nap(int* hunger, int* sleep, int* happy, std::string* name) { //nap function

		char sleep_time;
		if (*sleep >= 10) {
			std::cout << *name << " is very well rested, try giving " << name << " something to eat, or play roulette! " << std::endl;
		}
		else {
			//Gives user option on how long to send student to sleep for
			std::cout << *name << " Is about to sleep. How long shall " << *name << " sleep for? " << std::endl;
			std::cout << "A: 1 Minute" << std::endl;
			std::cout << "B: 2 Minutes" << std::endl;
			std::cout << "C: 3 Minutes" << std::endl;
			std::cout << "D: 4 Minutes" << std::endl;
			std::cout << "E: 5 Minutes" << std::endl;
			std::cin >> sleep_time;

			switch (toupper(sleep_time)) {
			case 'A': //Sends uni student to sleep for 1 minute
				std::cout << *name << " Is going to sleep for 1 minute." << std::endl;
				Sleep(60000); //Sleep function pauses program 
				show(); //Shows image of uni student
				std::cout << *name << " Has woken up!" << std::endl;
				(*sleep)++; //adds 1 to sleep counter
				(*hunger)--; //Takes 1 from hunger counter
				break;

			case 'B': //Sends student to sleep for 2 minutes
				std::cout << *name << " Is going to sleep for 2 minutes." << std::endl;
				Sleep(120000);
				show();
				std::cout << *name << " Has woken up!" << std::endl;
				*sleep = *sleep + 2;
				*hunger = *hunger - 2;
				break;

			case 'C': //Sends student to sleep for 3 minutes
				std::cout << *name << " Is going to sleep for 3 Minutes" << std::endl;
				Sleep(180000);
				show();
				std::cout << *name << " Has woken up!" << std::endl;
				*sleep = *sleep + 3;
				*hunger = *hunger - 3;
				break;

			case 'D': //Sends student to sleep for 4 minutes
				std::cout << *name << " Is going to sleep for 4 minutes" << std::endl;
				Sleep(240000);
				show();
				std::cout << *name << " Has woken up!" << std::endl;
				*sleep = *sleep + 4;
				*hunger = *hunger - 4;
				break;

			case 'E': //Sends student to sleep for 5 minutes
				std::cout << *name << " Is going to sleep for 5 minutes" << std::endl;
				Sleep(300000);
				show();
				std::cout << *name << " Has woken up!" << std::endl;
				*sleep = *sleep + 5;
				*hunger = *hunger - 5;
				break;
			}
		}
	}

	void show() { //Function to show image of uni student
		std::cout << R"(
      ////\\\\
      |      |
     @  O  O  @
      |  ~   |         \__
       \ -- /          |\ |
     ___|  |___        | \|
    /          \      /|__|
   /            \    / /
  /  /| .  . |\  \  / /
 /  / |      | \  \/ /
<  <  |      |  \   /
 \  \ |  .   |   \_/
  \  \|______|
    \_|______|
      |      |
      |  |   |
      |  |   |
      |__|___|
      |  |  |
      (  (  |
      |  |  |
      |  |  |
     _|  |  |
 cccC_Cccc___)
)" << std::endl;
	}

	void state1(int* hunger, int* sleep, int* happy, std::string * name) { //function for calculating and displaying state
		
		std::string hungerstatus; //Declare variables
		std::string sleepstatus;
		std::string happystatus;
		int happy1 = 0;
		happy1 = 0;
		happy1 = *happy + *sleep + *hunger; //Calculates happiness using sleep and hunger level

		//Works out happiness using if else statements

		if (happy1 >= 20) {
			happystatus = "Euphoric";
		}
		else if (happy1 < 20 && happy1 >= 15) {
			happystatus = "Happy";
		}
		else if (happy1 < 15 && happy1 >= 10) {
			happystatus = "Meh";
		}
		else if (happy1 < 10 && happy1 >= 5) {
			happystatus = "Sad";
		}
		else if (happy1 < 5 && happy1 >= 0) {
			happystatus = "Depressed";
		}
		else if (happy1 <= 0) {
			happystatus = " Very Depressed";
		}


		//Calculates output of hunger using if else statements

		if (*hunger <= 10 && *hunger >= 8) {
			hungerstatus = "Well fed";
		}
		else if (*hunger < 8 && *hunger >= 6) {
			hungerstatus = "Slightly peckish";
		}
		else if (*hunger < 6 && *hunger >= 4) {
			hungerstatus = "Rather hungry";
		}
		else if (*hunger < 4 && *hunger >= 1) {
			hungerstatus = "Starving";
		}
		else if (*hunger <= 0) {
			hungerstatus = "Dead";
		}

		//Calculates output of sleep using if else statements

		if (*sleep <= 10 && *sleep >= 8) {
			sleepstatus = "Wide Awake";
		}
		else if (*sleep < 8 && *sleep >= 6) {
			sleepstatus = "Awake";
		}
		else if (*sleep < 6 && *sleep >= 4) {
			sleepstatus = "Tired";
		}
		else if (*sleep < 4 && *sleep >= 1) {
			sleepstatus = "Falling Asleep";
		}
		else if (*sleep <= 0) {
			sleepstatus = "Collapsed";
		}

		//Outputs status to the screen
		std::cout << "**************************************************" << std::endl;

		std::cout << *name << " is " << *hunger << "/10 " << hungerstatus << std::endl;

		std::cout << *name << " is " << *sleep << "/10 " << sleepstatus << std::endl;

		std::cout << *name << " is " << happy1 << "/20 " << happystatus << std::endl;

		std::cout << "**************************************************" << std::endl;
	}

	void play(int* hunger, int* sleep, int* happy, std::string * name) { //calls play function
		srand(time(NULL)); //seeds random number generator
		
		//Declares variables
		char optionhl = 't';
		char colourchoice = 't';
		char option2 = 't';
		char oddeven = 't';
		char winoddeven = 't';
		char wincolour = 't';
		int winnum = 0;
		char colour = 't';
		char winhl = 't';
		int num = 0;

		//if uni students happiness equal to or more than 20, asks user to do another activity
		if (*happy >= 20) {
			std::cout << *name << "is already happy, try doing something else and coming back later!" << std::endl;
		}

		else {

			std::cout << "What would you like to bet on? If the number is odd or even (Press E), the colour (Press C), or if the number is High or Low (Press H): " << std::endl;
			std::cin >> option2; //Stores option for game to play


			winnum = rand() % 36 + 1; //Rolls a random number between 1 and 36

			
			if (toupper(option2) == 'E') { //if optioin is E following code executed

				std::cout << "Do you choose odd or even? " << std::endl;
				std::cin >> oddeven; //asks user to choose odd or even

				switch (winnum % 2) //divides rolled number by 2 and uses the remainder in the switch 
				{
				case 0:
					winoddeven = 'E'; //If remainder is 0 rolled number is even
					break;
				case 1:
					winoddeven = 'O'; //If remainder is not 0 rolled number is odd
					break;
				}


				if (toupper(oddeven) == winoddeven) { //outputs wining message
					std::cout << "You win! Well done!" << *name << " Is happy now! " << std::endl;

					*sleep = *sleep - 1; //takes one from sleep
					*hunger = *hunger - 1;  //takes one from hunger
					*happy = *happy + 3; //adds one to happiness
				}
				else if (toupper(oddeven) != winoddeven) { // outputs you lose message
					std::cout << "You lose, better luck next time! " << std::endl;
					*sleep = *sleep - 1;
					*hunger = *hunger - 1;
					*happy = *happy - 1;
				}
			}
			if (toupper(option2) == 'C') { //if option is C
				std::cout << "Please select a colour, black (B) or red (R): " << std::endl;
				std::cin >> colourchoice; //user chooses red or black to bet on

				switch (winnum) { //sets winning colour according to actual roulette table
				case 32:
					colour = 'R';
					break;

				case 15:
					colour = 'B';
					break;

				case 19:
					colour = 'R';
					break;

				case 4:
					colour = 'B';
					break;

				case 21:
					colour = 'R';
					break;

				case 2:
					colour = 'B';
					break;

				case 25:
					colour = 'R';
					break;

				case 17:
					colour = 'B';
					break;

				case 34:
					colour = 'R';
					break;

				case 6:
					colour = 'B';
					break;

				case 27:
					colour = 'R';
					break;

				case 13:
					colour = 'B';
					break;

				case 36:
					colour = 'R';
					break;

				case 11:
					colour = 'B';
					break;

				case 30:
					colour = 'R';
					break;

				case 8:
					colour = 'B';
					break;

				case 23:
					colour = 'R';
					break;

				case 10:
					colour = 'B';
					break;

				case 5:
					colour = 'R';
					break;

				case 24:
					colour = 'B';
					break;

				case 16:
					colour = 'R';
					break;

				case 33:
					colour = 'B';
					break;

				case 1:
					colour = 'R';
					break;

				case 20:
					colour = 'B';
					break;

				case 14:
					colour = 'R';
					break;

				case 31:
					colour = 'B';
					break;

				case 9:
					colour = 'R';
					break;

				case 22:
					colour = 'B';
					break;

				case 18:
					colour = 'R';
					break;

				case 29:
					colour = 'B';
					break;

				case 7:
					colour = 'R';
					break;

				case 28:
					colour = 'B';
					break;

				case 12:
					colour = 'R';
					break;

				case 35:
					colour = 'B';
					break;

				case 3:
					colour = 'R';
					break;

				case 26:
					colour = 'B';
					break;

				}


				if (toupper(colourchoice) == colour) { //You win message and addition to happiness, subtractin from sleep and hunger
					std::cout << "Well done! You won!" << std::endl;

					*sleep = *sleep - 1;
					*hunger = *hunger - 1;
					*happy = *happy + 3;
				}

				else if (toupper(colourchoice) != colour) { //You lose messssge, subtraction from all stats
					std::cout << "You lose, better luck next time!" << std::endl;
					*sleep = *sleep - 1;
					*hunger = *hunger - 1;
					*happy = *happy - 1;
				}

			}

			if (toupper(option2) == 'H') { 
				std::cout << "Would you like to bet high (Press H) or low (Press L)? " << std::endl; 
				std::cin >> optionhl; //User chooses to bet a high number or a low number

				if (winnum >= 19) { //if rolled number more than 19 a high number rolled
					winhl = 'H';
				}

				else if (winnum < 19) { // if number lower than 19 number rolled is low
					winhl = 'L';
				}

				if (toupper(optionhl) == winhl) { //winning message and addition to happubess, subtraction from sleep and hunger
					std::cout << "You guessed right! Well done!" << std::endl;
					*sleep = *sleep - 1;
					*hunger = *hunger - 1;
					*happy = *happy + 3;
				}

				else if (toupper(optionhl) != winhl) { //losing message and subtraction from all stats
					std::cout << "You lose, better luck next time!" << std::endl;
					*sleep = *sleep - 1;
					*hunger = *hunger - 1;
					*happy = *happy - 1;
				}
			}
		}
	}

	void death() { //Death function, to show when uni student has died
		std::cout << R"(
      ////\\\\
      |      |
     @  X  X  @
      |  ~   |         \__
       \ -- /          |\ |
     ___|  |___        | \|
    /          \      /|__|
   /            \    / /
  /  /| .  . |\  \  / /
 /  / |      | \  \/ /
<  <  |      |  \   /
 \  \ |  .   |   \_/
  \  \|______|
    \_|______|
      |      |
      |  |   |
      |  |   |
      |__|___|
      |  |  |
      (  (  |
      |  |  |
      |  |  |
     _|  |  |
 cccC_Cccc___)
)" << std::endl;
	}