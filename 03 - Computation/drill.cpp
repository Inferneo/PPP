#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
using namespace std;

int main(){

    constexpr double m_per_cm = 1/100;
    constexpr double m_per_inch = 2.54/100;
    constexpr double m_per_ft = (12*2.54)/100;

    vector<double> distances;
    vector<string> units;
    double smallest = 0, largest = 0, distance = 0, sum = 0;
    int i = 0;
    string unit;

    cout << "Enter a number followed by units (cm/m/in/ft)" << '\n';

    while (cin >> distance >> unit) {

        ++i;
        
        if (unit != "cm" && unit != "m" && unit != "in" && unit != "ft") {
            cout << "Illegal units, please enter valid units (cm/m/in/ft)" << '\n';
            continue;
        }

        cout << distance << ' ' << unit << '\n';

        if (unit == "cm") {
            distance = distance * m_per_cm;
        }
        else if (unit == "ft") {
            distance = distance * m_per_ft;
        }
        else if (unit == "in") {
            distance = distance * m_per_inch;
        }
        else if (unit == "m") {
            distance = distance;
        }

        sum += distance;

        distances.push_back(distance);

        if (i==1) {
            smallest = distance;
            largest = distance;
        }
        
        if (i > 1 && distance < smallest){
            cout << distance << " meters is the smallest so far" << '\n';
            smallest = distance;
        }
        else if (i > 1 && distance > largest){
             cout << distance << " meters is the largest so far" << '\n';
             largest = distance;
        }
    }

    ranges::sort(distances);

    cout << "Total number of values : " << i << '\n';
    
    for (double x:distances){
        cout << x << '\t';
    }

    cout << "\nSmallest value: " << distances[0] << "m\t" << "Largest value: " << distances[i-1] << "m" << '\n';
    
    cout << "Total distance: " << sum << " meters" << '\n';

    return 0;
}


        // if (i==1) {
        //     smallest = distances[0];
        //     largest = distances[0];
        // }
        // else if (distances[0] < smallest){
        //     cout << distances[0] << " is the smallest so far" << '\n';
        //     smallest = distances[0];
        // }
        // else if (distances[0] > largest){
        //      cout << distances[0] << " is the largest so far" << '\n';
        //      largest = distances[0];
        // }
        
        // cout << distances[0] << '\n';
    
        // if (distances[0] == distances[1]){
        //     cout << "the numbers are equal" << '\n';
        // }
        // else if (abs(distances[0]-distances[1]) < (1.0/100)){
        //     cout << "the numbers are almost equal" << '\n';
        // }

        // if (distances[0] > distances[1]){
        //     cout << "the smaller value is: " << distances[1] << '\n';
        //     cout << "the larger value is: " << distances[0] << '\n';
        // }
        // else if (distances[0] < distances[1]){
        //     cout << "the smaller value is: " << distances[0] << '\n';
        //     cout << "the larger value is: " << distances[1] << '\n';
        // }
