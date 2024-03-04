// Michael Walker
// CSC275
// Assignment 3: Smart Pointers
// Due: 03/03/2024

// TODO:
// Implement three smart pointers: Unique Pointer (unique_ptr), Shared Pointer (shared_ptr), and Weak Pointer (weak_ptr).
// Demonstrate when the pointers go out of scope and the values are deleted.

#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Character
{
	string Name;
	string Race;
	string Class;
	int Level;

	Character(string name, string race, string cclass, int level)
	{
		Name = name;
		Race = race;
		Class = cclass;
		Level = level;
	}
};

int  DisplayMenu()
{
	int choice;

	// Menu to display the options for the user
	cout << "+----------------------+" << endl;
	cout << "|  Smart Pointer Menu  |" << endl;
	cout << "+----------------------+" << endl;
	cout << "| 1. Unique Pointer    |" << endl;
	cout << "| 2. Shared Pointer    |" << endl;
	cout << "| 3. Weak Pointer      |" << endl;
	cout << "| 4. Exit              |" << endl;
	cout << "+----------------------+" << endl;
	cout << "  Enter your choice: ";
	cin >> choice;

	return choice;
}

void DemoUniquePointer()
{
	// Unique Pointer demonstration
	cout << "+----------------------+" << endl;
	cout << "| Unique Pointer       |" << endl;
	cout << "+----------------------+" << endl;
	cout << "  Creating a unique pointer to a Character object..." << endl << endl;

	// Create a unique pointer to a Character object
	unique_ptr<Character> myCharacter(new Character("Gandalf", "Wizard", "Human", 20));
	
	cout << "  Character created: " << myCharacter->Name << " the " << myCharacter->Class << " at level " << myCharacter->Level << endl << endl;
}

void DemoSharedPointer()
{
	// Shared Pointer demonstration
	cout << "+----------------------+" << endl;
	cout << "| Shared Pointer       |" << endl;
	cout << "+----------------------+" << endl;
	cout << "  Creating a shared pointer to a Character object..." << endl << endl;

	// Create a shared pointer to a Character object
	shared_ptr<Character> myCharacter(new Character("Aragorn", "Ranger", "Human", 20));
	shared_ptr<Character> yourCharacter = myCharacter;

	cout << "  Character created: " << myCharacter->Name << " the " << myCharacter->Class << " at level " << myCharacter->Level << endl << endl;
}

void DemoWeakPointer()
{
	// Weak Pointer demonstration
	cout << "+----------------------+" << endl;
	cout << "| Weak Pointer         |" << endl;
	cout << "+----------------------+" << endl;
	cout << "  Creating a weak pointer to a Character object..." << endl << endl;

	// Create a shared pointer for the weak pointer to reference
	shared_ptr<Character> myCharacter(new Character("Legolas", "Archer", "Elf", 20));

	// Create a weak pointer to a Character object
	weak_ptr<Character> weakCharacter;

	// Display the weak pointer status
	cout << "  1 for true, 0 for false: weak pointer expired? " << weakCharacter.expired() << endl << endl;

	// Assign the weak pointer to the shared pointer
	weakCharacter = myCharacter;

	// Display the created character
	cout << "  Character created: " << myCharacter->Name << " the " << myCharacter->Class << " at level " << myCharacter->Level << endl << endl;

	// Display the weak pointer status
	cout << "  1 for true, 0 for false: weak pointer expired? " << weakCharacter.expired() << endl << endl;
}

int main()
{
	// Main function to display the menu and get the user's choice
	bool isRunning = true;
	int userChoice;

	while (isRunning)
	{
		// Display the menu and capture menu choice
		userChoice = DisplayMenu();

		switch (userChoice)
		{
			case 1:
				DemoUniquePointer();
				break;
			case 2:
				DemoSharedPointer();
				break;
			case 3:
				DemoWeakPointer();
				break;
			case 4:
				isRunning = false;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
	}

	return 0;
}