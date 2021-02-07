//10. Write a program that plays the game “Rock, Paper, Scissors.” If you are not
//familiar with the game do some research(e.g., on the web using Google).
//Research is a common task for programmers.Use a switch - statement to
//solve this exercise.Also, the machine should give random answers(i.e.,
//	select the next rock, paper, or scissors randomly).Real randomness is too
//	hard to provide just now, so just build a vector with a sequence of values
//	to be used as “the next value.” If you build the vector into the program,
//	it will always play the same game, so maybe you should let the user enter
//	some values.Try variations to make it less easy for the user to guess
//	which move the machine will make next.

#include "std_lib_facilities.h"

string you_win("You win.\n");
string i_win("I win!\n");
string again("Let's go again!\n");

int player_score = 0;
int machine_score = 0;

vector<char>sequence = { 's','p','s','r','s','p','s','p','s' };

void instructions() {
	cout << "------------------------------------------------------------------------------------------------------\n";
	cout << "******************************INFORMATION - HOW TO PLAY***********************************************\n";
	cout << "------------------------------------------------------------------------------------------------------\n";
	cout << '\n';
	cout << "\t\tTo play this game, each player simultaneously chooses one of three items.\n"
		<< "\t\tThese items are \"Rock,\" \"Paper,\" and \"scissors\"\n"
		<< "\t\tA player who decides to play rock will beat another player who has chosen \n"
		<< "\t\tscissors (\"rock crushes scissors\" or sometimes \"blunts scissors\"), \n"
		<< "\t\tbut will lose to one who has played paper (\"paper covers rock\"); \n"
		<< "\t\ta play of paper will lose to a play of scissors (\"scissors cuts paper\").\n";
	cout << '\n';
	cout << "------------------------------------------------------------------------------------------------------\n";
	cout << "------------------------------------------------------------------------------------------------------\n";
	cout << '\n';
	cout << "Choose one to start: (R)ock, (P)aper, (S)cissors, or (q) to quit.\n";

}

string machine_play(int i) {
	if (sequence[i] == 'r')
	{
		return "Rock.";
	}
	else if (sequence[i] == 'p')
	{
		return "Paper.";
	}
	else if (sequence[i] == 's')
	{
		return "Scissors.";

	}

}

void score() {
	cout<<"Score:\tComputer: " << machine_score << '\t' << "Player: " << player_score << '\n';
}

int main()
{
	char player_item;
	char machine_item{};

	int machine_play_num = 0;
	bool valid_input = true;

	cout << "Let's play Rock, Paper, Scissors!\n";
	cout << "For instructions on how to play, press (i).\n";
	cout << '\n';
	cout << "Choose one to start: (R)ock, (P)aper, (S)cissors, or (q) to quit.\n";

	while (cin >> player_item) {

		if (player_item != 'r' && player_item != 'p' && player_item != 's' && player_item != 'q' && player_item != 'i' && player_item != 'v') {
			cout << "Sorry, I don't recognise your choice. Please choose one of the following items: (R)ock, (P)aper, or (S)cissors.\n";
		}
		else if (player_item == 'r' || player_item == 'p' || player_item == 's') { // validate input to be pushed back into vector

			sequence.push_back(player_item);
			machine_item = sequence[machine_play_num];
			cout << "I played " << machine_play(machine_play_num) << '\n';
			if (player_item == machine_item)
			{
				cout << "It's a draw!\n";
				score();
				cout << again;
				machine_play_num += 1;
				continue;
			}
			switch (player_item) {

			case'r':
				cout << "You played Rock!\n";
				if (machine_item == 'p')
				{
					machine_score += 1;
					cout << i_win;
				}
				else {
					player_score += 1;
					cout << you_win;
				}
				score();
				cout << again;
				machine_play_num += 1;
				break;

			case'p':
				cout << "You played Paper!\n";
				if (machine_item == 's')
				{
					machine_score += 1;
					cout << i_win;
					
				}
				else {
					player_score += 1;
					cout << you_win;
				}
				score();
				cout << again;
				machine_play_num += 1;
				break;
			case's':
				cout << "You played Scissors!\n";
				if (machine_item == 'r')
				{
					machine_score += 1;
					cout << i_win;
				}
				else {
					player_score += 1;
					cout << you_win;
				}
				score();
				cout << again;
				machine_play_num += 1;
				break;

			}

		}
		else {
			switch (player_item) {
			case'q':
				cout << "Oh too bad. But thanks for playing!\n";
				exit(1);
				break;
			case'i':
				instructions();
				break;
			case'v':  //prints out Vector values
				for (int i = 0; i < sequence.size(); ++i) {
					cout << i << ":" << sequence[i] << " ";
				}
				break;
			default:
				cout << "Sorry, I don't recognise your choice. Please choose one of the following items: (R)ock, (P)aper, or (S)cissors.\n";
				break;
			}
		}
	}
}