#include<avengers_Avenger.h> // Contains the definition of the Avenger class
#include<vector>
using namespace std;

// Class representing a battle between two groups: heroes and enemies
class Battle
{
private:
    vector<Avenger> heroes;      // Vector to store all hero Avengers
    vector<Avenger> enemies;     // Vector to store all enemy Avengers
    vector<string> battleLog;    // Log of all significant battle events

public:
    // Default constructor: initializes empty vectors
    Battle(){
        heroes.clear();      // Clear heroes list
        enemies.clear();     // Clear enemies list
        battleLog.clear();   // Clear battle log
    }

    // Starts the battle (currently empty - logic to be implemented)
    void startBattle()
    {
        // This function can be implemented to simulate turns of attacks
        // For now, it's a placeholder.
    }

    // Prints all entries in the battle log
    void printBattleLog()
    {
        for(int i = 0; i < battleLog.size(); i++){
            cout << battleLog[i] << endl; // Print each log entry
        }
    }

    // Computes and returns the result of the battle
    // Return values:
    //  -1 => enemies win
    //   1 => heroes win
    //   0 => draw
    int Result()
    {
        int x = 0, y = 0;

        // Calculate total power + durability of surviving heroes
        for(int i = 0; i < heroes.size(); i++)
        {
            if(heroes[i].getsuitdurability() > 0)
            {
                x += heroes[i].getsuitpowerLevel() + heroes[i].getsuitdurability();
            }
        }

        // Calculate total power + durability of surviving enemies
        for(int i = 0; i < enemies.size(); i++)
        {
            if(enemies[i].getsuitdurability() > 0)
            {
                y += enemies[i].getsuitpowerLevel() + enemies[i].getsuitdurability();
            }
        }

        // Compare total scores and return the result
        if(x < y)
        {
            return -1; // Enemies stronger
        }
        else if(x > y)
        {
            return 1; // Heroes stronger
        }
        else
        {
            return 0; // Equal strength
        }
    }

    // Adds a hero Avenger to the battle
    void addhero(Avenger a)
    {
        heroes.push_back(a); // Append to heroes list
    }

    // Adds an enemy Avenger to the battle
    void addenemy(Avenger a)
    {
        enemies.push_back(a); // Append to enemies list
    }

    // Finds an Avenger (hero or enemy) by name
    // Returns a pointer to the Avenger object, or nullptr if not found
    Avenger* findavenger(string s)
    {
        // Search in heroes
        for(int i = 0; i < heroes.size(); i++)
        {
            if(heroes[i].getname() == s)
            {
                return &heroes[i]; // Found hero
            }
        }
        // Search in enemies
        for(int i = 0; i < enemies.size(); i++)
        {
            if(enemies[i].getname() == s)
            {
                return &enemies[i]; // Found enemy
            }
        }
        return nullptr; // Not found
    }
    // Adds a new event/message to the battle log
    void updateBattleLog(string s)
    {
        battleLog.push_back(s); // Append message to log
    }
};
