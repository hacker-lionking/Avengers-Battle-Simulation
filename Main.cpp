#include<avengers_Battle.h>
#include<queue>
using namespace std;

int main()
{   
    Battle battleground; // Create a battle instance
    int k, n, m;
    cin >> k >> n >> m; // k suits, n heroes, m enemies

    queue<QNS> suits;
    int p, d, e, h;

    // Read QNS suits and push into queue
    for(int i = 0; i < k; i++)
    {
        cin >> p >> d >> e >> h;
        QNS q1(p, d, e, h);
        suits.push(q1);
    }

    string name;
    int strength;

    // Assign suits to heroes
    for(int i = 0; i < n; i++)
    {
        cin >> name >> strength;
        if(!suits.empty())
        {
            Avenger hero(name, suits.front(), strength);
            battleground.addhero(hero);
            suits.pop();
        }
        else
        {
            cout << name << " is out of fight" << endl; // No suit available
        }
    }

    // Assign suits to enemies
    for(int i = 0; i < m; i++)
    {
        cin >> name >> strength;
        if(!suits.empty())
        {
            Avenger enemy(name, suits.front(), strength);
            battleground.addenemy(enemy);
            suits.pop();
        }
        else
        {
            cout << name << " is out of fight" << endl; // No suit available
        }
    }

    string begin;
    cin >> begin; // Read start keyword (not used further)

    string command;
    for(;;)
    {
        cin >> command;
        if(command == "Attack")
        {
            string attackerName, defenderName;
            cin >> attackerName >> defenderName;
            Avenger* attacker = battleground.findavenger(attackerName);
            Avenger* defender = battleground.findavenger(defenderName);
            
            // Check if attacker and defender are valid and functional
            if(attacker->getsuitdurability() > 0 && attacker->getsuitheatlevel() <= 500 && defender->getsuitdurability() > 0)
            {
                battleground.updateBattleLog(attackerName + " attacks " + defenderName);
                attacker->attack(*defender);

                // Log destruction or overheating
                if(defender->getsuitdurability() <= 0)
                {
                    battleground.updateBattleLog(defenderName + " suit destroyed");
                }
                else if(defender->getsuitheatlevel() > 500)
                {
                    battleground.updateBattleLog(defenderName + " suit overheated");
                }
            }
        }
        else if(command == "Repair")
        {
            string repairName;
            cin >> repairName;
            int repairAmount;
            cin >> repairAmount;
            Avenger* repairAvenger = battleground.findavenger(repairName);
            repairAvenger->repair(repairAmount);
            battleground.updateBattleLog(repairName + " repaired");
        }
        else if(command == "BoostPowerByFactor")
        {
            string boostName;
            int factor;
            cin >> boostName >> factor;
            Avenger* boostAvenger = battleground.findavenger(boostName);
            boostAvenger->boostsuitpower(factor);
            battleground.updateBattleLog(boostName + " boosted");

            // Check if boost caused overheating
            if(boostAvenger->getsuitheatlevel() > 500)
            {
                battleground.updateBattleLog(boostName + " suit overheated");
            }
        }
        else if(command == "BoostPower")
        {
            string boostName;
            int p1, d1, e1, h1;
            cin >> boostName >> p1 >> d1 >> e1 >> h1;
            QNS q2(p1, d1, e1, h1);
            Avenger* boostAvenger = battleground.findavenger(boostName);
            boostAvenger->boostsuitpower(q2);
            battleground.updateBattleLog(boostName + " boosted");

            if(boostAvenger->getsuitheatlevel() > 500)
            {
                battleground.updateBattleLog(boostName + " suit overheated");
            }
        }
        else if(command == "AvengerStatus")
        {
            string statusName;
            cin >> statusName;
            Avenger* statusAvenger = battleground.findavenger(statusName);
            statusAvenger->printStatus(); // Display current status
        }
        else if(command == "Upgrade")
        {
            string upgradeName;
            cin >> upgradeName;
            Avenger* upgradeAvenger = battleground.findavenger(upgradeName);
            if(!suits.empty())
            {
                upgradeAvenger->upgradeSuit(suits.front()); // Use front suit for upgrade
                suits.pop();
                battleground.updateBattleLog(upgradeName + " upgraded");
            }
            else
            {
                battleground.updateBattleLog(upgradeName + " upgrade Fail");
            }
        }
        else if(command == "PrintBattleLog")
        {
            battleground.printBattleLog(); // Print all events
        }
        else if(command == "BattleStatus")
        {
            // Compare team strength and print result
            if(battleground.Result() == 0)
            {
                cout << "tie" << endl;
            }
            else if(battleground.Result() == 1)
            {
                cout << "heroes are winning" << endl;
            }
            else if(battleground.Result() == -1)
            {
                cout << "enemies are winning" << endl;
            }
        }
        else if(command == "End")
        {
            break; // Exit command loop
        }
    }
}
