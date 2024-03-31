#include <iostream>
#include <vector>
using namespace std;

class Player {
private:
    int PlayerID;
    string Name;
    int Health;

public:
    Player(int PlayerID, string Name, int Health) : PlayerID(PlayerID), Name(Name), Health(Health) {}

    void setHealth(int health) {
        Health = health;
    }

    int getHealth() const {
        return Health;
    }
};

class Weapon {
private:
    vector<string> weaponsList;

public:
    Weapon() {
        // Initialize the weapons list with some weapons
        weaponsList = {"Sword", "Bow", "Dagger", "Mace", "Crossbow"};
    }

    void use() {
        cout << "\nList of Weapons:" << endl;
        for (size_t i = 0; i < weaponsList.size(); i++) {
            cout << "Weapon ID: " << i + 1 << " - " << weaponsList[i] << endl;
        }
        string choice;
        cout << "Enter which weapon you want to choose: ";
        cin >> choice;
        bool found = false;

        for (int i = 0; i < weaponsList.size(); i++) {
            if (weaponsList[i] == choice) {
                cout << "The weapon that is chosen is: " << choice << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Error! Invalid weapon, it is not available." << endl;
        }
    }
};

class Enemy : public Player {
private:
    int damage;

public:
    Enemy(int id, string Name, int Health, int damage) : Player(id, Name, Health), damage(damage) {}

    void attack(Player& target) {
        int newHealth = target.getHealth() - damage;
        target.setHealth(newHealth);
    }
};

class Character : public Player {
private:
    int Level;
    string Experience;
    int Points;

public:
    Character(int PlayerID, string Name, int Health, int Level, string Experience, int Points)
        : Player(PlayerID, Name, Health), Level(Level), Experience(Experience), Points(Points) {}

    void levelUp(int points) {
        if (points >= 0 && points <= 10) {
            Level = 1;
            Experience = "Beginner";
        } else if (points > 10 && points <= 20) {
            Level = 2;
            Experience = "Intermediate";
        } else if (points > 20 && points <= 30) {
            Level = 3;
            Experience = "Advanced";
        } else if (points > 20 && points <= 30) {
            Level = 4;
            Experience = "Extra";
        }
        Points = points;
    }

    void playGame(Enemy& enemy, Weapon& weapon) {
        weapon.use();
        Points += 10;
        enemy.attack(*this);
    }
};

int main() {
    Player player(1, "Player1", 100);
    Weapon weapon;
    Character character(2, "Character1", 100, 0, "Beginner", 0);
    Enemy enemy(3, "Enemy1", 100, 5);

    cout << "Initial Player Health: " << player.getHealth() << endl;
    cout << "Initial Character Health: " << character.getHealth() << endl;
    cout<<"\n\n";

    // Testing the use function of the weapon class
    weapon.use();
    cout << "Character Points after using weapon: " << character.getHealth() << endl;

    enemy.attack(player);
    cout << "Player Health after enemy attack: " << player.getHealth() << endl;

    character.playGame(enemy, weapon);
    cout << "Character Health after enemy attack during gameplay: " << character.getHealth() << endl;

    return 0;
}
