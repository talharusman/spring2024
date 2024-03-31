#include<iostream>
#include<vector>
using namespace std;

class SecurityTool{
    string security_Level;
    int cost;
    int no_of_devices;
public:
    SecurityTool(string Level, int cost, int noOfDevices) {
        if (Level == "High" || Level == "Medium" || Level == "Low")
            security_Level = Level;
        else {
            cout << "Invalid security level. Setting to default: Low." << endl;
            security_Level = "Low";
        }

        if (cost <= 0) {
            cout << "Error! Invalid Cost Entered. Enter a cost > 0: ";
            cin >> cost;
        }
        this->cost = cost;

        no_of_devices = noOfDevices;
    }

    string getSecurity_Level() {
        return security_Level;
    }

    int getCost() {
        return cost;
    }

    int getNO_of_Devices() {
        return no_of_devices;
    }

    void performScan() {
        cout << "\nPerforming a generic security scan..." << endl;
    }

    void displayDetails() {
        cout << "Security Level: " << security_Level << endl;
        cout << "Cost: $" << cost << endl;
        cout << "Number of Devices: " << no_of_devices << endl;
    }
};

class FirewallTool : public SecurityTool {
    vector<int> ports;
    vector<string> fire_wall;
public:
    FirewallTool(string SecuityLEv, int cost, int No_Of_Devi, int studentID)
        : SecurityTool(SecuityLEv, cost, min(No_Of_Devi, 10)) {
        int startPort = studentID + 1;
        for (int i = startPort; i < startPort + 23; ++i)
            ports.push_back(i);

        // Generate protocol list
        fire_wall = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};
    }

    void generateList() {
        cout << "\nAllowed Ports:" << endl;
        for (size_t i = 0; i < ports.size(); i++)
            cout << ports[i] << " ";
        cout << "\n" << endl;
    }

    void performScan() {
        cout << "\nPerforming a firewall scan..." << endl;

        cout << "Allowed Protocols: "<<endl;
        for (string protocol : fire_wall)
            cout << protocol << " ";
        cout << endl;

        if (getSecurity_Level() == "High") {
            cout << "Only traffic from the port and protocol list will be allowed." << endl;
        } else if (getSecurity_Level() == "Medium") {
            cout << "Allowing all traffic from port and protocol list along with the next two ports in sequence." << endl;
            for (int i = 0; i < 2; ++i)
                cout << ports.back() + i + 1 << " ";
            cout << endl;
        } else if (getSecurity_Level() == "Low") {
            cout << "Allowing all traffic from port and protocol list along with the next 5 ports in sequence and from TCP and DNS protocol." << endl;
            for (int i = 0; i < 5; ++i)
                cout << ports.back() + i + 1 << " ";
            cout << " TCP DNS" << endl;
        }
    }
};

int main() {
    string level;
    int cost, devices, studentID;

    cout << "Enter security level (High/Medium/Low): ";
    cin >> level;
    cout << "Enter cost of the security tool: ";
    cin >> cost;
    cout << "Enter number of devices: ";
    cin >> devices;
    cout << "Enter your student ID: ";
    cin >> studentID;

    FirewallTool firewall(level, cost, devices, studentID);

    cout << "\nFirewall Details:\n";
    firewall.displayDetails();
    firewall.generateList();
    firewall.performScan();

    return 0;
}
