#include<avengers_QNS.h>  // Assumed to contain the QNS class definition
using namespace std;

// Class representing an Avenger with a Quantum Nano Suit (QNS)
class Avenger
{
private:
    string name;      // Name of the Avenger
    QNS suit;         // The Avenger's Quantum Nano Suit
    int attackStrength; // Attack strength used in combat

public:
    // Parameterized constructor to initialize the Avenger
    Avenger(string avName, QNS avSuit, int strength)
    {
        name = avName;           // Set name
        suit = avSuit;           // Assign the provided suit
        attackStrength = strength; // Set attack strength
    }

    // Attack method: damages the enemy by reducing their suit's durability
    void attack(Avenger& enemy)
    {
        enemy.suit - attackStrength; // Use overloaded '-' operator on enemy's suit
    }

    // Upgrades the Avenger's suit by absorbing the attributes of another QNS
    void upgradeSuit(QNS& q3)
    {
        suit + q3; // Use overloaded '+' operator to enhance this suit
    }

    // Repairs the Avenger's suit by improving durability and reducing heat
    void repair(int x)
    {
        suit / x; // Use overloaded '/' operator to apply the repair
    }

    // Prints the current status of the Avenger and their suit
    void printStatus()
    {
        // Output format: Name PowerLevel Durability EnergyStorage HeatLevel
        cout << name << " " 
             << suit.getpowerLevel() << " " 
             << suit.getdurability() << " " 
             << suit.getenergyStorage() << " " 
             << suit.getheatLevel() << endl;
    }
    // Getter for suit's durability
    int getsuitdurability()
    {
        return suit.getdurability();
    }
    // Getter for suit's power level
    int getsuitpowerLevel()
    {
        return suit.getpowerLevel();
    }

    // Getter for suit's heat level
    int getsuitheatlevel()
    {
        return suit.getheatLevel();
    }

    // Getter for the Avenger's name
    string getname()
    {
        return name;
    }

    // Boosts the suit's power using a percentage factor
    void boostsuitpower(int y)
    {
        suit.boostPower(y); // Uses the int version of boostPower, which applies '*'
    }

    // Boosts the suit's power using another QNS
    void boostsuitpower(QNS q1)
    {
        suit.boostPower(q1); // Uses the QNS version of boostPower, which applies '+'
    }
};
