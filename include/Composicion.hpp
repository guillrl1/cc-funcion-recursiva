#ifndef COMPOSICION_HPP
#define COMPOSICION_HPP

#include "Funcion.hpp"
#include <vector>
#include <memory>

// Operador de Composición: f(g_1(x), g_2(x), ..., g_m(x))
// Aplica primero las funciones internas g_i sobre los argumentos,
// y luego pasa sus resultados a la función externa f.
class Composicion : public Funcion {
public:
    Composicion(std::shared_ptr<Funcion> f, std::vector<std::shared_ptr<Funcion>> g);

    Natural evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const override;

private:
    std::shared_ptr<Funcion> f_;
    std::vector<std::shared_ptr<Funcion>> g_;
};

#endif // COMPOSICION_HPP
