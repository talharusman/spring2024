#include <iostream>
#include <string>
using namespace std;

class Platform; 

class Server {
protected:
    string serverName;
public:
    Server(string name) : serverName(name) {}

    virtual void display(const Platform& platform) const = 0;
};

class Logo {
protected:
   string logoName;
public:
    Logo(string name) : logoName(name) {}
};

class Platform : public Logo {
public:
    Platform(string logoName) : Logo(logoName) {}

    void changeLogo(Logo newLogo) {
        logoName = newLogo.logoName;
    }

    void display(const Server& server) const {
        cout << "Server Name: " << server.serverName << endl;
        cout << "Logo: " << logoName <<endl;
    }
};

class TwitterServer : public Server {
public:
    TwitterServer(string name) : Server(name) {}

    void display(const Platform& platform) const override {
        cout << "Twitter Server Name: " << serverName << endl;
        platform.display(*this);
    }
};

int main() {
    Platform twitter("Blue Bird");
    TwitterServer originalServer("Twitter");
    cout << "Original Twitter Platform:\n";
    originalServer.display(twitter);

   
    Logo newLogo("Doge Coin");
    twitter.changeLogo(newLogo);

    TwitterServer modifiedServer("Twitter");
    cout << "\nTwitter Platform with Doge Coin Logo:\n";
    modifiedServer.display(twitter);

    return 0;
}
