#include <iostream>
#include <string>

using namespace std;

class TrafficLight {
public:
    TrafficLight() : state("Red") {
        cout << "Traffic Light Created with state: " << state << endl;
    }

    void changeState() {
        if (this->state == "Red") {
            this->state = "Yellow";
        } else if (this->state == "Yellow") {
            this->state = "Green";
        } else {
            this->state = "Red";
        }
    }

    string getState() const {
        return this->state;
    }

    ~TrafficLight() {
        cout << "Traffic Light with state " << state << " is being destroyed." << endl;
    }

private:
    string state;
};

int main() {
    const int numTrafficLights = 3;

    TrafficLight* trafficLights = new TrafficLight[numTrafficLights];

    for (int i = 0; i < numTrafficLights; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << "Traffic Light " << i + 1 << ": " << trafficLights[i].getState() << endl;
            trafficLights[i].changeState();
        }
        cout << endl;
    }

    delete[] trafficLights;

    return 0;
}
