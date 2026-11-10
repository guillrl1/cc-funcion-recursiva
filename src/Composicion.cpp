#include "Composicion.hpp"

Composicion::Composicion(std::shared_ptr<Funcion> f, std::vector<std::shared_ptr<Funcion>> g)
    : f_(f), g_(g) {}

Natural Composicion::evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const {
    // Evaluamos cada función interna g_i pasándole los argumentos de entrada
    std::vector<Natural> resultadosInternos;
    resultadosInternos.reserve(g_.size());
    for (const auto& func : g_) {
        resultadosInternos.push_back(func->evaluar(args, contador));
    }

    // Evaluamos la función externa f con la lista de resultados intermedios
    return f_->evaluar(resultadosInternos, contador);
}
