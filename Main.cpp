#include <iostream>
#include "Level.h"
#include <vector>
#include <string>
using namespace std;

bool tryParse(std::string& input, int& output) {
	try {
		output = stoi(input);
	}
	catch (invalid_argument) {
		return false;
	}
	return true;
}

string stringToLowercase(string str) {

	string newStr = "";
	for (int i = 0; i < (int)str.length(); i++) { //Runs through the whole string and each letter lowercase

		newStr += tolower(str[i]);
	}
	return newStr;
}


int main() {

	vector<pair<string, level>> levels;
	string choice;
	bool found = false;
	int num = 0;

	do {
		
		cout << "Currently there are " << levels.size() << endl;
		cout << "What do you want to do?\nCreate new / show all / Edit / Delete / Exit\n";
		
		getline(cin, choice);
		choice = stringToLowercase(choice); //Changes to lower case just if the user types it in all caps or something

		if (choice == "create new" or choice == "create" or choice == "new") {
			
			string name;

			cout << "Type a name or leave empty for default:\n";
			getline(cin, name);

			if (name == "") { name = "Profile " + to_string(num); num++; }

			level newLevel;
			levels.push_back(make_pair(name, newLevel));

		} else if (choice == "show all" or choice == "show" or choice == "all") {

			for (int i = 0; i < (int)levels.size(); i++) {

				cout << levels[i].first << endl;
				levels[i].second.printAll();
				cout << "\n\n";
			}

		}else if (choice == "edit") {

			if (levels.size() == 0) { cout << "There are no profiles! create one using 'create new'\n"; }

			while (choice != "n" and levels.size() > 0) { // For repeating the same action

				found = false;

				for (int i = 0; i < (int)levels.size() - 1; i++) {

					cout << levels[i].first << " / ";
				}
				cout << levels[levels.size() - 1].first << "\nWhich Profile would you like to edit?\n";

				getline(cin, choice);
				choice = stringToLowercase(choice);

				for (int i = 0; i < (int)levels.size(); i++) {
					
					if (stringToLowercase(levels[i].first) == choice) {

						found = true;
						do {

							cout << "What would you like to edit?\nAdd experience / Set experience / Set level\nType 'done' if you're done editing" << endl;

							getline(cin, choice);
							choice = stringToLowercase(choice);

							if (choice == "add experience" or choice == "add exp" or choice == "add") {

								string input;
								int x;

								cout << "Input number: ";
								getline(cin, input);

								while (!tryParse(input, x) and input != "back") { // Loop through if the input wasn't a number and repeat till the user goes back or inputs an number
									
									cout << "Not a number, try again or type 'back' go back" << endl;
									getline(cin, input);
								}	
								
								if (input == "back") { continue; }

								levels[i].second.increaseExperience(x);
								cout << "Experience added!" << endl;
								cout << x << endl;
							}
							else if (choice == "set experience" or choice == "set exp") {

								string input;
								int x;

								cout << "Input number: ";
								getline(cin, input);

								while (!tryParse(input, x) and input != "back") { // Loop through if the input wasn't a number and repeat till the user goes back or inputs an number

									cout << "Not a number, try again or type 'back' go back" << endl;
									getline(cin, input);
								}

								if (input == "back") { continue; }

								levels[i].second.setExperience(x);
								cout << "Experience set!" << endl;
								cout << x << endl;

							}
							else if (choice == "set level") {

								string input;
								int x;

								cout << "Input number: ";
								getline(cin, input);

								while (!tryParse(input, x) and input != "back") { // Loop through if the input wasn't a number and repeat till the user goes back or inputs an number

									cout << "Not a number, try again or type 'back' go back" << endl;
									getline(cin, input);
								}

								if (input == "back") { continue; }

								levels[i].second.setPlayerLevel(x);
								cout << "level set!" << endl;
								cout << x << endl;

							}

						} while (choice != "done");

						break;
					}
				}

				if (found) {

					cout << "Do you want to edit another profile? [y/n]\n";
					getline(cin, choice);

				} else {

					cout << "That name couldn't be found, do you want to try again? [y/n]";
					getline(cin, choice);

				}
				
			}

		}
		else if (choice == "delete") {
			
			if (levels.size() == 0) { cout << "There are no profiles! create one using 'create new'\n"; }
			
			while (choice != "n" and levels.size() > 0) { // For repeating the same action
				found = false;

				for (int i = 0; i < (int)levels.size() - 1; i++) {

					cout << levels[i].first << " / ";
				}

				cout << levels[levels.size() - 1].first << "\nWhich Profile would you like to delete?\n";

				getline(cin, choice);
				choice = stringToLowercase(choice);

				for (int i = 0; i < (int)levels.size(); i++) {
					
					if (stringToLowercase(levels[i].first) == choice) {

						found = true;

						levels.erase(levels.begin() + i);

						break;
					}
				}

				if (levels.size() == 0) { continue; }
				if (found) {

					cout << "Do you want to delete another profile? [y/n]\n";
					getline(cin, choice);

				}
				else {

					cout << "That name couldn't be found, do you want to try again? [y/n]";
					getline(cin, choice);

				}

			}

		} else if (choice == "mass create") { // Just for quickly creating 

			for (int i = 0; i < 5; i++) {

				level newLevel;
				levels.push_back(make_pair("Profile " + to_string(num), newLevel));
				
				num++;
			}

		}

	} while (choice != "exit" and choice != "e");

	return 0;
}


