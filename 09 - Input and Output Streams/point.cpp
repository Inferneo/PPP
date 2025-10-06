#include <exception>
#include <fstream>
#include <istream>
#include <ostream>
#include <iostream>
#include <stdexcept>
#include <vector>

struct Point {
    int x = 0, y = 0;
};

std::vector<Point> original_points;
std::vector<Point> processed_points;

std::istream& operator>>(std::istream& is, Point& p) {
    return is >> p.x >> p.y;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << p.x << ' ' << p.y; 
}

int main() {

    try {
        
        std::cout << "Enter the X and Y coordinates of Points:\n";

        for (Point p; std::cin >> p;){
            original_points.push_back(p);
        }

        {
            std::ofstream ost {"mydata.txt"};

            for (Point p : original_points) {
                ost << p << '\n';
            }
        }

        std::ifstream ist {"mydata.txt"};

        if (!ist) {
            throw std::runtime_error("can't open input file!");
        }

        for (Point p; ist >> p;){
            processed_points.push_back(p);
        }

        std::cout << "vector original_points:\n";
        for (Point p : original_points) {
            std::cout << p << '\n';
        }

        std::cout << "vector processed_points:\n";
        for (Point p : processed_points) {
            std::cout << p << '\n';
        }    
    } 
    
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}