#include "Vector2.h"

// Constructor cu parametri impliciti implementat cu liste de initializare
Vector2::Vector2(float x, float y) : x(x), y(y) {}

// Implementare Getters
float Vector2::getX() const { return x; }
float Vector2::getY() const { return y; }

// Implementare Setters
void Vector2::setX(float x) { this->x = x; }
void Vector2::setY(float y) { this->y = y; }

// Adaugati pe parcurs operatorii din indrumar

// Restul metodelor si operatorilor sugerati