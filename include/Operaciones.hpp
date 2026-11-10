#ifndef OPERACIONES_HPP
#define OPERACIONES_HPP

#include "Funcion.hpp"
#include <memory>

// Suma: suma(x, y) = x + y
class Suma : public Funcion {
public:
    Suma();
    Natural evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const override;
    Natural calcular(Natural x, Natural y, ContadorLlamadas& contador) const;

private:
    std::shared_ptr<Funcion> impl_;
};

// Multiplicación: mult(x, y) = x * y
class Multiplicacion : public Funcion {
public:
    explicit Multiplicacion(std::shared_ptr<Funcion> suma = nullptr);
    Natural evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const override;
    Natural calcular(Natural x, Natural y, ContadorLlamadas& contador) const;

private:
    std::shared_ptr<Funcion> impl_;
};

// Potencia: potencia(x, y) = x^y
class Potencia : public Funcion {
public:
    explicit Potencia(std::shared_ptr<Funcion> mult = nullptr);
    Natural evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const override;
    Natural calcular(Natural base, Natural exponente, ContadorLlamadas& contador) const;

private:
    std::shared_ptr<Funcion> impl_;
};

#endif // OPERACIONES_HPP
