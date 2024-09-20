#include <iostream>
#include <string>
using namespace<std>

class TrafficLight {
public:
    TrafficLight() : state("Red") {}

    void changeState() {
        if (state == "Red") {
            state = "Yellow";
        } else if (state == "Yellow") {
            state = "Green";
        } else {
            state = "Red";
        }
    }

    string getState() const {
        return state;
    }

private:
    string state;
};

int main() {
    TrafficLight trafficLight;

    for (int i = 0; i < 10; ++i) {
        cout << trafficLight.getState() << endl;
        trafficLight.changeState();
    }

    return 0;
}