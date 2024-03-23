#include<iostream>
using namespace std;

class Character {
    int health, damage;
public:
    Character(int health, int damage) {
        this->damage = damage;
        this->health = health;
    }

    void display() {
        cout << "Health is: " << health << endl;
        cout << "Damage is: " << damage << endl;
    }
};

class Enemy : public Character {
public:
    Enemy(int health, int damage) : Character(health, damage) {}

    void display() {
        Character::display();
    }

};

class Player : public Character {
public:
    Player(int health, int damage) : Character(health, damage) {}

    void display() {
        Character::display();
    }
};

class Wizard : public Player {
    int magic_power;
    string spells;
public:
    Wizard(int health, int damage, int magic_power, string spells) : Player(health, damage) {
        this->magic_power = magic_power;
        this->spells = spells;
    }

    void display() {
        Player::display();
        cout << "Magic Power: " << magic_power << endl;
        cout << "Spells: " << spells << endl;
        return;
    }
};


int main(int argc, char const *argv[]) {
    Wizard obj(5, 3, 7, "Fireball");
    obj.display();
    return 0;
}
