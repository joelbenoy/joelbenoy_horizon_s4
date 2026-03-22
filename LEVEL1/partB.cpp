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

    double u, a, v0; // initial velocity, acceleration, maximum velocity
    cout << "Input the initial velocity (u) in m/s: ";
    cin >> u;
    cout << "Input the acceleration (a) in m/s^2: ";
    cin >> a;
    cout << "Input the maximum allowed top speed (v0) in m/s: ";
    cin >> v0;

    // time until attaining maximum velocity
    double t_max_vel = (v0 - u) / a;

    // distance covered during acceleration phase
    double d_accel = u * t_max_vel + 0.5 * a * pow(t_max_vel, 2);

    // total distance to destination
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // distance covered at constant velocity
    double d_const_vel = distance - d_accel;

    // time at constant velocity
    double t_const_vel = d_const_vel / v0;

    // total time to destination
    double time = t_max_vel + t_const_vel;

    cout << "Total distance to destination: " << distance << "m" << endl;
    cout << "Total time to destination: " << time << "s" << endl;
    return 0;
}