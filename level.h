#include <iostream>
using namespace std;

class level {

public:

	level() {}

	level(int experience) {

		increaseExperience(experience);

	}

	void increaseExperience(int experience) {

		playerExperience += experience;

		if (playerExperience >= nextLevelExperienceNeeded) {

			levelUp();

		}

	}

	void printAll() {

		cout << "maxLevel = " << maxLevel
			<< "\nplayerLevel = " << playerLevel
			<< "\nplayerExperience = " << playerExperience
			<< "\nnextLevelExperienceNeeded = " << nextLevelExperienceNeeded
			<< "\nneededExperienceForCurrentLevel = " << neededExperienceForCurrentLevel;

	}

	int getPlayerExperience() { return playerExperience; }
	int getPlayerNextLevelExperience() { return nextLevelExperienceNeeded; }

	void setPlayerLevel(int newLevel) { //Sets the player level

		if (newLevel < 0) { throw invalid_argument("Number cannot be lower then 0"); }

		playerLevel = 0;
		playerExperience = 0;
		nextLevelExperienceNeeded = 100;
		neededExperienceForCurrentLevel = 100;

		int newExperience = 100;
		int neededExperienceForNewLevel = 130;

		for (int i = 1; i < newLevel; i++) {

			cout << newExperience << ", " << neededExperienceForCurrentLevel << endl;
			newExperience += neededExperienceForNewLevel;
			neededExperienceForNewLevel = (int)floor(neededExperienceForNewLevel * 1.3);
			cout << newExperience << ", " << neededExperienceForNewLevel << "\n------------------------" << endl;

		}

		increaseExperience(newExperience);

	}

	void setExperience(int NewExperience) {

		if (NewExperience < 0) { throw invalid_argument("Number cannot be lower then 0"); }

		playerLevel = 0;
		playerExperience = 0;
		nextLevelExperienceNeeded = 100;
		neededExperienceForCurrentLevel = 100;

		increaseExperience(NewExperience);

	}

private:

	int maxLevel = 5;
	int playerLevel = 0;
	int playerExperience = 0; //Shows player current XP Ex : 420
	int nextLevelExperienceNeeded = 100; //Shows players needed max xp to level up, Ex : 618
	int neededExperienceForCurrentLevel = 100; //Shows how much the current level requires (From level start), Ex : 219

	void levelUp() { //For when the player levels up

		//Just to make sure the player actually leveled upand
		//checks that the player isn't max level yet

		if (playerLevel < maxLevel) {

			while (playerExperience >= nextLevelExperienceNeeded and playerLevel < maxLevel) {
				//Loop and level up as long as need, Incase the player gained too much experience
				playerLevel += 1;

				if (playerLevel < maxLevel) {

					neededExperienceForCurrentLevel = (int)floor(neededExperienceForCurrentLevel * 1.3);
					nextLevelExperienceNeeded += neededExperienceForCurrentLevel;

				}
				else {

					playerExperience = nextLevelExperienceNeeded;
				}

				cout << "Player has leveled to level " << playerLevel << " and now has " << playerExperience <<
					" experience next level is at " << nextLevelExperienceNeeded << " experience\n";
				/*Levels the player up, Ex: 0 + 1 = 1
				Mupltiply the needexperienceforcurrent level by 1.3, Ex : 100 * 1.3 = 130
				And at the end add it to the "NextLevelExperienceNeeded", Ex : 100 + 130 = 230
				So it would be : Level 1, Next xp milestone = 230, And current level xp needed = 130*/
			}

		}
		else { //If the player is max level then

			playerExperience = nextLevelExperienceNeeded; //Sets the player XP to the max exp it can aka : the "NextLevelExperienceNeeded"

		}


	}
};