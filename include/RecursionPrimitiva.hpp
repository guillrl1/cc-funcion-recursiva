#ifndef RECURSION_PRIMITIVA_HPP
#define RECURSION_PRIMITIVA_HPP

#include "Funcion.hpp"
#include <memory>

// Operador de Recursión Primitiva:
// Caso base:       f(x, 0)     = g(x)
// Paso recursivo:  f(x, y + 1) = h(x, y, f(x, y))
// La recursión se efectúa sobre el último argumento 'y'.
class RecursionPrimitiva : public Funcion {
public:
    RecursionPrimitiva(std::shared_ptr<Funcion> g, std::shared_ptr<Funcion> h);

    Natural evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const override;

private:
    std::shared_ptr<Funcion> g_; // Función del caso base (cuando y = 0)
    std::shared_ptr<Funcion> h_; // Función del paso inductivo (cuando y > 0)
};

#endif // RECURSION_PRIMITIVA_HPP
