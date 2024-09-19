#include <iostream>
#include <string>

class TrafficLight {
public:
    TrafficLight() : state("Red") {}

    void changeState() {
        if (this->state == "Red") {
            this->state = "Yellow";
        } else if (this->state == "Yellow") {
            this->state = "Green";
        } else {
            this->state = "Red";
        }
    }

    std::string getState() const {
        return this->state;
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