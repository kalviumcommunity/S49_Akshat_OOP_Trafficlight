#include <iostream>
#include <string>

using namespace std;

class TrafficLight {
    private:
    string state;

    static int totalTrafficLights;

    public:
        TrafficLight() : state("Red") {
            ++totalTrafficLights;  
            cout << "Traffic Light Created with state: " << state << endl;
            cout << "Total Traffic Lights: " << totalTrafficLights << endl;
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
        --totalTrafficLights;  
        cout << "Traffic Light with state " << state << " is being destroyed." << endl;
        cout << "Total Traffic Lights: " << totalTrafficLights << endl;
    }

    static int getTotalTrafficLights() {
        return totalTrafficLights;
    }

};

int TrafficLight::totalTrafficLights = 0;

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

    cout << "Total Traffic Lights after creation: " << TrafficLight::getTotalTrafficLights() << endl;

    delete[] trafficLights;

    cout << "Total Traffic Lights after deletion: " << TrafficLight::getTotalTrafficLights() << endl;

    return 0;
}
