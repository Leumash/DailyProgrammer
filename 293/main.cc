/*
To disarm the bomb you have to cut some wires. These wires are either white, black, purple, red, green or orange.
The rules for disarming are simple:

If you cut a white cable you can't cut white or black cable.
If you cut a red cable you have to cut a green one
If you cut a black cable it is not allowed to cut a white, green or orange one
If you cut a orange cable you should cut a red or black one
If you cut a green one you have to cut a orange or white one
If you cut a purple cable you can't cut a purple, green, orange or white cable
If you have anything wrong in the wrong order, the bomb will explode.

There can be multiple wires with the same colour and these instructions are for one wire at a time. Once you cut a wire you can forget about the previous ones.
*/

#include <iostream>
#include <list>

using namespace std;

list<string> readInput() {
    string wire;
    list<string> wires;
    while (cin >> wire) {
        wires.push_back(wire);
    }
    return wires;
}

bool isBoom(string previous, string current) {
    if (previous == "white") {
        if (current == "white" || current == "black") {
            return true;
        }
    } else if (previous == "red") {
        if (current != "green") {
            return true;
        }
    } else if (previous == "black") {
        if (current == "white" || current == "green" || current == "orange") {
            return true;
        }
    } else if (previous == "orange") {
        if (current != "red" && current != "black") {
            return true;
        }
    } else if (previous == "green") {
        if (current != "orange" && current != "white") {
            return true;
        }
    } else if (previous == "purple") {
        if (current == "purple" || current == "green" || current == "orange" || current == "white") {
            return true;
        }
    }

    return false;
}

bool isDefused(string cutWire, list<string> wires) {
    if (wires.size() == 0) {
        return true;
    }

    string nextWire = wires.front();
    wires.pop_front();

    if (isBoom(cutWire, nextWire)) {
        return false;
    }

    return isDefused(nextWire, wires);
}

bool isDefused(list<string> wires) {
    if (wires.size() <= 1) {
        return true;
    }

    string first_wire = wires.front();
    wires.pop_front();
    return isDefused(first_wire, wires);
}

int main() {
    list<string> wires = readInput();
    if (isDefused(wires)) {
        cout << "Bomb defused" << endl;
    } else {
        cout << "Boom" << endl;
    }
}

