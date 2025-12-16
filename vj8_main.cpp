#include <iostream>
#include <vector>
#include "Warrior.h"
#include "Mage.h"
#include "Gnome.h"
#include "Boss.h"

using namespace std;

int main() {
    vector<Gamecharacter*> characters;

    Warrior* conan = new Warrior("Conan");
    Mage* merlin = new Mage("Merlin");
    Gnome* gnomeo = new Gnome("Gnomeo");
    Gnome* sneaky = new Gnome("Sneaky");
    Boss* dragon = new Boss("Dragon");

    characters = { conan, merlin, gnomeo, sneaky, dragon };

    conan->attackEnemy(gnomeo);
    conan->displayStatus();
    gnomeo->displayStatus();

    merlin->attackEnemy(sneaky);
    merlin->displayStatus();
    sneaky->displayStatus();

    gnomeo->attackPlayer(conan);
    conan->displayStatus();
    gnomeo->displayStatus();

    merlin->attackEnemy(gnomeo);
    dragon->attackPlayer(merlin);
    merlin->attackEnemy(gnomeo);

    conan->attackEnemy(dragon);
    merlin->attackEnemy(dragon);

    cout << "\n--- Special abilities ---\n";
    for (auto c : characters)
        c->specialAbility();

    cout << "\n--- Survivors ---\n";
    Gamecharacter* healthiest = nullptr;

    for (auto c : characters) {
        if (c->isAlive()) {
            c->displayStatus();
            if (!healthiest || c->getHealth() > healthiest->getHealth())
                healthiest = c;
        }
    }

    cout << "\nMost health: " << healthiest->getName() << endl;

    for (auto c : characters)
        delete c;

    return 0;
}
