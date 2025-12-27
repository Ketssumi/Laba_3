#include "../include/Array.h"
#include "../include/Triangle.h"
#include "../include/Square.h"
#include "../include/Octagon.h"
#include <iostream>
#include <memory>

void printMenu() {
    std::cout << "\n=== Figure Management System ===\n";
    std::cout << "1. Add Triangle\n";
    std::cout << "2. Add Square\n";
    std::cout << "3. Add Octagon\n";
    std::cout << "4. Remove Figure by Index\n";
    std::cout << "5. Print All Figures\n";
    std::cout << "6. Print Centers and Areas\n";
    std::cout << "7. Calculate Total Area\n";
    std::cout << "8. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Array figures;
    int choice;
    
    while (true) {
        printMenu();
        std::cin >> choice;
        
        try {
            switch (choice) {
                case 1: {
                    std::cout << "Enter 3 points for Triangle (x1 y1 x2 y2 x3 y3): ";
                    Triangle* triangle = new Triangle();
                    std::cin >> *triangle;
                    figures.add(triangle);
                    std::cout << "Triangle added successfully.\n";
                    break;
                }
                case 2: {
                    std::cout << "Enter 4 points for Square (x1 y1 x2 y2 x3 y3 x4 y4): ";
                    Square* square = new Square();
                    std::cin >> *square;
                    figures.add(square);
                    std::cout << "Square added successfully.\n";
                    break;
                }
                case 3: {
                    std::cout << "Enter 8 points for Octagon (x1 y1 ... x8 y8): ";
                    Octagon* octagon = new Octagon();
                    std::cin >> *octagon;
                    figures.add(octagon);
                    std::cout << "Octagon added successfully.\n";
                    break;
                }
                case 4: {
                    std::cout << "Enter index to remove: ";
                    size_t index;
                    std::cin >> index;
                    figures.remove(index);
                    std::cout << "Figure removed successfully.\n";
                    break;
                }
                case 5: {
                    std::cout << "\nAll Figures:\n";
                    figures.printAll();
                    break;
                }
                case 6: {
                    std::cout << "\nCenters and Areas:\n";
                    figures.printCentersAndAreas();
                    break;
                }
                case 7: {
                    double total = figures.totalArea();
                    std::cout << "Total area of all figures: " << total << std::endl;
                    break;
                }
                case 8: {
                    std::cout << "Goodbye!\n";
                    return 0;
                }
                default: {
                    std::cout << "Invalid option. Please try again.\n";
                    break;
                }
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
    
    return 0;
}