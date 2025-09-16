// project 1  stone _ papper_scissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum engamechoise { stone = 1, paper = 2, cissors = 3 };
enum enwinner { player = 1, computer = 2, draw = 3 };
struct stroundinfo
{
	short round_numper;
	engamechoise player_choise;
	engamechoise computer_choise;
	enwinner winner;
	string winner_name;
};
struct stgameresult
{
	short game_rounds = 0;
	short player_win_time = 0;
	short computer_win_time = 0;
	short draw_time = 0;
	enwinner winner;
	string winner_name;
};
int Random_numper(int from, int to)
{
	return (rand() % (to - from + 1) + from);
}

engamechoise get_computer_choise()
{
	return (engamechoise)Random_numper(1, 3);
}
engamechoise read_player_choise()
{
	short choise;
	do

	{

		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
		cin >> choise;
	} while (choise > 3 || choise < 1);
	return (engamechoise)choise;
}

short how_many_rounds()
{
	short numper = 0;
	do
	{

		cout << "how many round 1 : 10  : ";
		cin >> numper;
	} while (numper < 1 || numper>10);
	return numper;
}
enwinner who_winner_the_round(stroundinfo round_info)
{
	if (round_info.player_choise == round_info.computer_choise)
		return enwinner::draw;
	else if ((round_info.player_choise == engamechoise::cissors && round_info.computer_choise == engamechoise::paper) || (round_info.player_choise == engamechoise::paper && round_info.computer_choise == engamechoise::stone) || (round_info.player_choise == engamechoise::stone && round_info.computer_choise == engamechoise::cissors))
		return enwinner::player;
	else
		return enwinner::computer;
}
string winner_name(enwinner winner)
{
	string arrwin[3] = { "player","computer","draw" };
	return arrwin[winner - 1];
}
string choice_name(engamechoise choice)
{
	string arrchoice[3] = { "stone","papper","scissors" };
	return arrchoice[choice - 1];
}

enwinner who_won_the_game(short player_times, short computer_times)
{
	if (player_times > computer_times)
		return enwinner::player;
	else if (computer_times > player_times)
		return enwinner::computer;
	else
		return enwinner::draw;
}
stgameresult fill_game_result(int game_rounds, short player_win_times, short computer_win_times, short draws_times)
{
	stgameresult game_result;
	game_result.game_rounds = game_rounds;
	game_result.player_win_time = player_win_times;
	game_result.computer_win_time = computer_win_times;
	game_result.draw_time = draws_times;
	game_result.winner = who_won_the_game(player_win_times, computer_win_times);
	game_result.winner_name = winner_name(game_result.winner);
	return game_result;
}
void set_screen_color(enwinner winner)
{
	switch (winner)
	{
	case player:
		system("color 2F");
		break;
	case computer:
		system("color 4F");
		cout << "\a";
		break;
	case draw:
		system("color 6F");
		break;
	default:
		break;
	}
}

void print_round_result(stroundinfo roundinfo)
{
	cout << "\n----------------- Round[" << roundinfo.round_numper << "]-----------------\n";
	cout << "player choice   : " << choice_name(roundinfo.player_choise) << "\n";
	cout << "computer choice : " << choice_name(roundinfo.computer_choise) << "\n";
	cout << "Round winner    : " << roundinfo.winner_name << "\n";

	cout << "----------------------------------------------\n\n";



}
stgameresult play_game(int how_many_round)
{
	stroundinfo round_info;
	short player_win_time = 0, computer_win_time = 0, draws_time = 0;
	for (short game_round = 1;game_round <= how_many_round;game_round++)
	{
		cout << "\n Round [" << game_round << "] ";
		round_info.round_numper = game_round;
		round_info.player_choise = read_player_choise();
		round_info.computer_choise = get_computer_choise();
		round_info.winner = who_winner_the_round(round_info);
		round_info.winner_name = winner_name(round_info.winner);
		if (round_info.winner == enwinner::player)
			player_win_time++;
		else if (round_info.winner == enwinner::computer)
			computer_win_time++;
		else
			draws_time++;

		print_round_result(round_info);
	}
	return fill_game_result(how_many_round, player_win_time, computer_win_time, draws_time);
}

void show_game_over()
{
	cout << "\t\t---------------------------------------\n\n";
	cout << "\t\t             +++ Game Over +++         \n\n";
	cout << "\t\t---------------------------------------\n\n";
}
void reset_screen()
{
	system("cls");
	system("color 0F");
}



void print_final_game_result(stgameresult game_result)
{
	cout << "\t\t-----------------------[ Game Result ]-----------------------\n\n";
	cout << "\t\tGame rounds         : " << game_result.game_rounds << "\n";
	cout << "\t\tPlayer won times    : " << game_result.player_win_time << "\n";
	cout << "\t\tComputer won times  : " << game_result.computer_win_time << "\n";
	cout << "\t\tDraws times         : " << game_result.draw_time << "\n";
	cout << "\t\tFinal winner        : " << game_result.winner_name << "\n";
	cout << "-------------------------------------------------------------\n\n";
	set_screen_color(game_result.winner);
}
void start_game()
{
	char play_again = 'y';
	do
	{
		reset_screen();
		stgameresult game_result = play_game(how_many_rounds());
		show_game_over();
		print_final_game_result(game_result);
		cout << "\n\n Do you want play again [Y - N] : ";
		cin >> play_again;
	} while (play_again == 'Y' || play_again == 'y');
}



int main()
{
	srand((unsigned)time(NULL));
	start_game();

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
