#ifndef VECTOR_2_H_
#define VECTOR_2_H_
#include <iostream>

class Vector2 {
private:
    float x;
    float y;
public:
    // Constructor cu parametri impliciti 
    Vector2(float x = 0.0f, float y = 0.0f);
    // Getters
    float getX() const;
    float getY() const;
    // Setters
    void setX(float x);
    void setY(float y);

    // Supraincarcarea operatorului << pentru afisare
    friend std::ostream& operator<<(std::ostream& os, const Vector2& v);
    // Supraincarcarea operatorului >> pentru citire
    friend std::istream& operator>>(std::istream& is, Vector2& v);

    // In continuare: Exemple de supraincarcare a altor operatori cu sens
    // pentru clasa Vector2

    // Supraincarcarea operatorului + pentru adunarea a doi Vector2
    // si a salva rezultatul intr-un alt Vector2
    // Exemplu: Vector2 v = v1 + v2;
    Vector2 operator+(const Vector2& other) const;
    // Supraincarcarea operatorului += pentru a aduna un vector la 
    // vectorul curent
    // Exemplu: v1 += v2;
    Vector2& operator+=(const Vector2& other);
    // Supraincarcarea operator- unar pentru a schimba semnul vectorului
    // Exemplu: Vector2 v = -v2;
    Vector2 operator-();
    
    // Alte definitii adaugate de voi din indrumar si din exercitii
};

#endif /* VECTOR_2_H_ */