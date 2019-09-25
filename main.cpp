#include<bits/stdc++.h>

#include <utility>

using namespace std;


class Person {
private:
    std::string name;
    int numGiven;
    int numReceived;
public:
    Person() : name{}, numGiven{0}, numReceived{0} { }
    void setName(std::string pName) {this->name = std::move(pName); }
    std::string getName() { return this->name; }
    void give(int amount) { this->numGiven = amount; }
    void receive(int amount) { this->numReceived += amount; }
    int assets() { return this->numReceived - this->numGiven; }
};

int main() {
    bool firstOutput = true;
    int input = 0;

    while (std::cin >> input) {
        if (!firstOutput) std::cout << std::endl;
        else firstOutput = false;

        std::map<std::string, Person*> personsMap;
        std::vector<Person> persons(input);

        for (auto && person: persons) {
            std::string personName;
            std::cin >> personName; person.setName(personName);
            personsMap[personName] = &person;
        }

        std::string giverName, receiverName;
        int numReceivers = 0, numGiven = 0;

        for (int i = 0; i < input; ++i)
        {
            std::cin >> giverName >> numGiven >> numReceivers;
            auto giver = personsMap[giverName];

            for (int j = 0; j != numReceivers; ++j)
            {
                std::cin >> receiverName;
                personsMap[receiverName]->receive(numGiven / numReceivers);
                giver->give(numGiven - (numGiven % numReceivers));
            }
        }

        for (auto && personN : persons)
            cout << personN.getName() << " " << personN.assets() << endl;

    }

	return 0;
}
