#include <iostream>
#include <string>

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

    std::string getState() const {
        return state;
    }

private:
    std::string state;
};

int main() {
    const int numTrafficLights = 3;
    TrafficLight trafficLights[numTrafficLights];

    for (int i = 0; i < numTrafficLights; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << "Traffic Light " << i + 1 << ": " << trafficLights[i].getState() << std::endl;
            trafficLights[i].changeState();
        }
        std::cout << std::endl;
    }

    return 0;
}