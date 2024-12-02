#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Abstract Light Class
class Light {
    public:
        virtual void changeState() = 0; 
        virtual string getState() const = 0; 
};

// TrafficLight Class
class TrafficLight : public Light {
    private:
        string state;
        static int totalTrafficLights;

    public:
        TrafficLight() : state("Red") {
            ++totalTrafficLights;
            cout << "Default Traffic Light Created with state: " << state << endl;
        }

        TrafficLight(const string& initialState) : state(initialState) {
            ++totalTrafficLights;
            cout << "Traffic Light Created with state: " << state << endl;
        }

        string getState() const override {
            return state;
        }

        void setState(const string& newState) {
            state = newState;
        }

        void changeState() override {
            if (state == "Red") {
                setState("Yellow");
            } else if (state == "Yellow") {
                setState("Green");
            } else {
                setState("Red");
            }
        }

        static int getTotalTrafficLights() {
            return totalTrafficLights;
        }

        ~TrafficLight() {
            --totalTrafficLights;
            cout << "Traffic Light with state " << state << " is being destroyed." << endl;
        }
};

int TrafficLight::totalTrafficLights = 0;

// PedestrianLight Class
class PedestrianLight : public TrafficLight {
    public:
        PedestrianLight() : TrafficLight("Don't Walk") {
            cout << "Pedestrian Light Created with state: Don't Walk" << endl;
        }

        void changeState() override {
            if (getState() == "Don't Walk") {
                setState("Walk");
            } else {
                setState("Don't Walk");
            }
        }
};

// SmartTrafficLight Class
class SmartTrafficLight : public TrafficLight {
    private:
        bool trafficDetected;

    public:
        SmartTrafficLight() : TrafficLight("Red"), trafficDetected(false) {
            cout << "Smart Traffic Light Created with state: Red" << endl;
        }

        void detectTraffic(bool traffic) {
            trafficDetected = traffic;
            if (trafficDetected) {
                cout << "Traffic Detected. Adjusting light state." << endl;
                changeState();
            } else {
                cout << "No Traffic Detected. Light stays the same." << endl;
            }
        }
};

// TrafficLightManager Class for SRP
class TrafficLightManager {
    private:
        vector<TrafficLight*> trafficLights;

    public:
        void addTrafficLight(TrafficLight* light) {
            trafficLights.push_back(light);
        }

        void displayTrafficLights() const {
            int i = 1;
            for (auto light : trafficLights) {
                cout << "Traffic Light " << i++ << ": " << light->getState() << endl;
            }
        }

        ~TrafficLightManager() {
            for (auto light : trafficLights) {
                delete light;
            }
        }
};

// Intersection Class
class Intersection {
    private:
        string name;
        TrafficLightManager trafficLightManager;

    public:
        Intersection(const string& intersectionName) : name(intersectionName) {
            cout << "Intersection " << name << " Created." << endl;
        }

        void addTrafficLight(TrafficLight* light) {
            trafficLightManager.addTrafficLight(light);
        }

        void displayTrafficLights() const {
            cout << "Traffic Lights at " << name << ":" << endl;
            trafficLightManager.displayTrafficLights();
        }

        ~Intersection() {
            cout << "Intersection " << name << " is being destroyed." << endl;
        }
};

// Main Function
int main() {
    TrafficLight* defaultLight = new TrafficLight();
    TrafficLight* parameterizedLight = new TrafficLight("Green");
    PedestrianLight* pedLight = new PedestrianLight();
    SmartTrafficLight* smartLight = new SmartTrafficLight();

    Intersection intersection("Main Street");
    intersection.addTrafficLight(defaultLight);
    intersection.addTrafficLight(parameterizedLight);
    intersection.addTrafficLight(pedLight);
    intersection.addTrafficLight(smartLight);

    intersection.displayTrafficLights();

    cout << "Total Traffic Lights after creation: " << TrafficLight::getTotalTrafficLights() << endl;

    return 0;
}
