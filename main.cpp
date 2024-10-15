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

        string getState() const {
            return state;
        }

        void setState(const string& newState) {
            state = newState;
        }

        void changeState() {
            if (state == "Red") {
                setState("Yellow");
            } else if (state == "Yellow") {
                setState("Green");
            } else {
                setState("Red");
            }
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

class Intersection {
    private:
        string name;
        TrafficLight* trafficLights;
        int numTrafficLights;

    public:
        Intersection(const string& name, int numLights) : name(name), numTrafficLights(numLights) {
            trafficLights = new TrafficLight[numTrafficLights];
        }

        string getName() const {
            return name;
        }

        void setName(const string& newName) {
            name = newName;
        }

        int getNumTrafficLights() const {
            return numTrafficLights;
        }

        void displayTrafficLights() const {
            for (int i = 0; i < numTrafficLights; ++i) {
                cout << "Traffic Light " << i + 1 << " at " << name << ": " << trafficLights[i].getState() << endl;
            }
        }

        ~Intersection() {
            delete[] trafficLights;
            cout << "Intersection " << name << " is being destroyed." << endl;
        }
};

int main() {
    const int numTrafficLights = 3;

    Intersection intersection("Main Street", numTrafficLights);

    intersection.displayTrafficLights();

    for (int i = 0; i < numTrafficLights; ++i) {
        for (int j = 0; j < 10; ++j) {
            intersection.displayTrafficLights();
        }
        cout << endl;
    }

    cout << "Total Traffic Lights after creation: " << TrafficLight::getTotalTrafficLights() << endl;

    cout << "Total Traffic Lights after destruction: " << TrafficLight::getTotalTrafficLights() << endl;

    return 0;
}
