#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x1, y1; // origin coordinates
    double x2, y2; // destination coordinates
    cout << "Enter the Origin Coordinates (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the Destination Coordinates (x2, y2): ";
    cin >> x2 >> y2;
    
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "Distance to destination: " << distance  << "m" << endl;
    
    return 0;
}