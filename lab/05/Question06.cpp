#include<iostream>
using namespace std;

class Graphics_Rendering_Engine {
public:
    void render() {
        cout << "Rendering Graphics:" << endl << endl;
        return;
    }
};

class Input_Handler {
public:
    void handle() {
        cout << "Handling Input:" << endl << endl;
        return;
    }
};

class Physics_Engine {
public:
    void engine() {
        cout << "Physics Engine:" << endl << endl;
        return;
    }
};

class GameEngine {
private:
    Graphics_Rendering_Engine graphics_Engine;
    Input_Handler input_Handler;
    Physics_Engine physics_Engine;

public:
    void run() {
        graphics_Engine.render();
        input_Handler.handle();
        physics_Engine.engine();
        return;
    }
};

int main() {
    GameEngine ob1;
    ob1.run();

    return 0;
}
