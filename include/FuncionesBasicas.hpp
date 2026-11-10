#ifndef FUNCIONES_BASICAS_HPP
#define FUNCIONES_BASICAS_HPP

#include "Funcion.hpp"

// Función Cero: Z(x) = 0
// Devuelve siempre 0, sin importar el argumento.
class Cero : public Funcion {
public:
    Natural evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const override;
};

// Función Sucesor: S(x) = x + 1
// Devuelve el siguiente número natural.
class Sucesor : public Funcion {
public:
    Natural evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const override;
};

// Función Proyección: P_i(x_1, ..., x_n) = x_i
// Extrae el elemento que está en la posición 'indice' (1 para el primero, 2 para el segundo, etc.).
class Proyeccion : public Funcion {
public:
    explicit Proyeccion(int indice);
    Natural evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const override;

private:
    int indice_;
};

#endif // FUNCIONES_BASICAS_HPP
