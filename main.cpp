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
    TrafficLight trafficLight;

    for (int i = 0; i < 10; ++i) {
        std::cout << trafficLight.getState() << std::endl;
        trafficLight.changeState();
    }

    return 0;
}