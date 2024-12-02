#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract Light Class
class Light {
    public:
        virtual void changeState() = 0;
        virtual string getState() const = 0;
        virtual ~Light() {} // Virtual destructor for polymorphism
};

// TrafficLight Class
class TrafficLight : public Light {
    private:
        string state;

    public:
        TrafficLight() : state("Red") {
            cout << "Traffic Light Created with state: Red" << endl;
        }

        string getState() const override {
            return state;
        }

        void changeState() override {
            if (state == "Red")
                state = "Yellow";
            else if (state == "Yellow")
                state = "Green";
            else
                state = "Red";
        }

        ~TrafficLight() {
            cout << "Traffic Light Destroyed." << endl;
        }
};

// PedestrianLight Class
class PedestrianLight : public Light {
    private:
        string state;

    public:
        PedestrianLight() : state("Don't Walk") {
            cout << "Pedestrian Light Created with state: Don't Walk" << endl;
        }

        string getState() const override {
            return state;
        }

        void changeState() override {
            if (state == "Don't Walk")
                state = "Walk";
            else
                state = "Don't Walk";
        }

        ~PedestrianLight() {
            cout << "Pedestrian Light Destroyed." << endl;
        }
};

// TimerControlledLight Class
class TimerControlledLight : public TrafficLight {
    private:
        int timer;

    public:
        TimerControlledLight(int duration) : timer(duration) {
            cout << "Timer-Controlled Light Created with timer: " << timer << " seconds" << endl;
        }

        void changeState() override {
            TrafficLight::changeState();
            cout << "State changed with timer duration: " << timer << " seconds." << endl;
        }

        ~TimerControlledLight() {
            cout << "Timer-Controlled Light Destroyed." << endl;
        }
};

// TrafficLightManager Class
class TrafficLightManager {
    private:
        vector<Light*> lights;

    public:
        void addLight(Light* light) {
            lights.push_back(light);
        }

        void displayLights() const {
            for (size_t i = 0; i < lights.size(); ++i) {
                cout << "Light " << i + 1 << ": " << lights[i]->getState() << endl;
            }
        }

        void changeAllLights() {
            for (auto& light : lights) {
                light->changeState();
            }
        }

        ~TrafficLightManager() {
            for (auto light : lights) {
                delete light;
            }
        }
};

// Main Function
int main() {
    // Create Lights
    TrafficLight* trafficLight = new TrafficLight();
    PedestrianLight* pedestrianLight = new PedestrianLight();
    TimerControlledLight* timerLight = new TimerControlledLight(30);

    // Manage Lights
    TrafficLightManager manager;
    manager.addLight(trafficLight);
    manager.addLight(pedestrianLight);
    manager.addLight(timerLight);

    // Display Initial States
    cout << "\nInitial States:" << endl;
    manager.displayLights();

    // Change States
    cout << "\nChanging States:" << endl;
    manager.changeAllLights();
    manager.displayLights();

    return 0;
}
