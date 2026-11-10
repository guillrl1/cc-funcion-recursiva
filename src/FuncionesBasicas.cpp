#include "FuncionesBasicas.hpp"

// Cero: Z(x) = 0
Natural Cero::evaluar(const std::vector<Natural>& /*args*/, ContadorLlamadas& contador) const {
    contador.registrar();
    return 0;
}

// Sucesor: S(x) = x + 1
Natural Sucesor::evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const {
    contador.registrar();
    return args[0] + 1;
}

// Proyección: P_i(x_1, ..., x_n) = x_i
Proyeccion::Proyeccion(int indice) : indice_(indice) {}

Natural Proyeccion::evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const {
    contador.registrar();
    return args[indice_ - 1];
}
