#include<iostream>
using namespace std;

// Class representing a Quantum Nano Suit (QNS)
class QNS
{
private:
    int powerLevel;      // Indicates the current power level of the suit
    int durability;      // Indicates how much damage the suit can take
    int energyStorage;   // Indicates how much energy is stored
    int heatLevel;       // Indicates how much heat the suit has accumulated

public:
    // Parameterized constructor to initialize the suit with specific values
    QNS(int p, int d, int e, int h)
    {
        powerLevel = p;
        durability = d;
        energyStorage = e;
        heatLevel = h;

        // Cap the power level to a maximum of 5000
        if (powerLevel > 5000)
        {
            powerLevel = 5000;
        }
    }

    // Copy constructor to initialize a new suit with the values of another suit
    QNS(const QNS& q1)
    {
        powerLevel = q1.powerLevel;
        durability = q1.durability;
        energyStorage = q1.energyStorage;
        heatLevel = q1.heatLevel;

        // Cap the power level to a maximum of 5000
        if (powerLevel > 5000)
        {
            powerLevel = 5000;
        }
    }

    // Default constructor to initialize a suit with base values
    QNS()
    {
        powerLevel = 1000;
        durability = 500;
        energyStorage = 300;
        heatLevel = 0;
    }

    // Overloaded '+' operator: Enhance this suit using another suit's energy and durability
    void operator +(QNS &q1)
    {
        powerLevel += q1.energyStorage;   // Increase powerLevel by the other suit's energy
        durability += q1.durability;      // Add durability
        energyStorage += q1.powerLevel;   // Gain energy from the other suit's power

        // Cap the power level at 5000
        if (powerLevel > 5000)
        {
            powerLevel = 5000;
        }
    }

    // Overloaded '-' operator: Simulates damage and resulting heat increase
    void operator -(int x)
    {
        durability -= x;   // Reduce durability (damage taken)
        energyStorage += x; // Gain energy (perhaps from kinetic energy or damage reaction)
        heatLevel += x;    // Increase heat due to impact
    }

    // Overloaded '*' operator: Boost suit's power by a given percentage
    void operator *(int x)
    {
        powerLevel += ((powerLevel * x) / 100); // Increase powerLevel by x%
        energyStorage += 5 * x;                 // Gain energy
        heatLevel += x;                         // Increase heat level

        // Cap the power level at 5000
        if (powerLevel > 5000)
        {
            powerLevel = 5000;
        }
    }

    // Overloaded '/' operator: Repair durability and cool down the suit
    void operator /(int x)
    {
        durability += x;   // Increase durability
        heatLevel -= x;    // Decrease heat level

        // Ensure heat level doesn't drop below 0
        if (heatLevel < 0)
        {
            heatLevel = 0;
        }
    }

    // Boost power using a percentage factor (calls overloaded '*')
    void boostPower(int factor)
    {
        *this * factor;
    }

    // Boost power by combining with another suit (calls overloaded '+')
    void boostPower(QNS &otherSuit)
    {
        *this + otherSuit;
    }

    // Getter for powerLevel
    int getpowerLevel()
    {
        return powerLevel;
    };

    // Getter for durability
    int getdurability()
    {
        return durability;
    };

    // Getter for energyStorage
    int getenergyStorage()
    {
        return energyStorage;
    };

    // Getter for heatLevel
    int getheatLevel()
    {
        return heatLevel;
    };

    // Setter for powerLevel
    void setpowerLevel(int newvalue)
    {
        powerLevel = newvalue;
    };

    // Setter for durability
    void setdurability(int newvalue)
    {
        durability = newvalue;
    };

    // Setter for energyStorage
    void setenergyStorage(int newvalue)
    {
        energyStorage = newvalue;
    };

    // Setter for heatLevel
    void setheatLevel(int newvalue)
    {
        heatLevel = newvalue;
    };
};
