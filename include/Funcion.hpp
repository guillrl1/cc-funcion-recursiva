#ifndef FUNCION_HPP
#define FUNCION_HPP

#include <vector>
#include <memory>

// Tipo de dato para números naturales: 0, 1, 2, ...
using Natural = unsigned long long;

// Contador simple para registrar el número de llamadas a funciones
class ContadorLlamadas {
public:
    void registrar() { ++total_; }
    Natural getTotal() const { return total_; }
    void reiniciar() { total_ = 0; }

private:
    Natural total_ = 0;
};

// Clase base para cualquier función primitiva recursiva
class Funcion {
public:
    virtual ~Funcion() = default;

    // Evalúa la función para una lista de argumentos y registra las llamadas en el contador
    virtual Natural evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const = 0;
};

#endif // FUNCION_HPP
