#include <iostream>

// Forward declarations
double calculateDistance(double tower_height, int seconds, int planetChoice);
double calculatePlanetGravity(int planet_choice);

void outputHeight(double tower_height, int planetChoice)
// Outputs the height of the ball throughout the 5 second interval.
{
	for (int seconds = 0; seconds < 6; seconds++) // From 0-5 seconds
	{
		std::cout << "At " << seconds << " seconds, the ball is at height: " << calculateDistance(tower_height, seconds, planetChoice) << '\n'; // Subtract distance_fallen from tower height.
	}
}

double calculateDistance(double tower_height, int seconds, int planetChoice)
// Returns the current distance of the ball for any given second.
{

	double distance_fallen = (calculatePlanetGravity(planetChoice) * (seconds * seconds)) / 2.0; // Store distance_fallen formula

	if ((tower_height - distance_fallen) > 0)
	{
		return tower_height - distance_fallen;
	}
	else
	{
		return 0.0;
	}
}

double calculatePlanetGravity(int planet_choice)
// Returns the gravity constant based on the given planet
{
	if (planet_choice == 1) // Jupiter
	{
		return 24.79;
	}
	else if (planet_choice == 2) // Neptune
	{
		return 11.0;
	}
	else if (planet_choice == 3) // Saturn
	{
		return 10.44;
	}
	else if (planet_choice == 4) // Earth
	{
		return 9.8;
	}
	else if (planet_choice == 5) // Uranus
	{
		return 8.69;
	}
	else if (planet_choice == 6) // Venus
	{
		return 8.87;
	}
	else if (planet_choice == 7) // Mars
	{
		return 3.711;
	}
	else if (planet_choice == 8) // Mercury
	{
		return 3.7;
	}
	else
	{
		return 0;
	}
}

void userPrompt()
// Prompts user to choose a tower height as well as a valid planet.
{
	std::cout << "In this experiment, we will be simulating dropping a ball off a tower with a given height. For each second, we will calculate the height of the ball based off the gravity of the chosen planet." << '\n' << '\n';
	// Prompt the user to enter the height of their tower
	std::cout << "Enter the height of your tower in meters: " << '\n';
	double tower_height{};
	std::cin >> tower_height;

	// Prompts user of choice on Jupiter, Neptune, Saturn, Earth, Uranus, Venus, Mars, and Mercury
	std::cout << "Enter your desired planet: " << '\n' << "\t1) Jupiter" << '\n' << "\t2) Neptune" << '\n' << "\t3) Saturn" << '\n' << "\t4) Earth" << '\n' << "\t5) Uranus" << '\n' << "\t6) Venus" << '\n' << "\t7) Mars" << '\n' << "\t8) Mercury" << '\n';
	int planet_choice{};
	std::cin >> planet_choice;


	// Constraints, must be a planet 1-8.
	if (planet_choice < 1 || planet_choice > 8)
	{
		std::cout << "Invalid. Please select a planet 1-8." << '\n';
		int new_planet_choice{};
		std::cin >> new_planet_choice;
		calculatePlanetGravity(new_planet_choice);
	}
	// If valid planet, output the height.
	else
	{
		outputHeight(tower_height, planet_choice);
	}
}

int main()
{
	userPrompt();

	return 0;
}