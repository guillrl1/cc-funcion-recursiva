#include "RecursionPrimitiva.hpp"

RecursionPrimitiva::RecursionPrimitiva(std::shared_ptr<Funcion> g, std::shared_ptr<Funcion> h)
    : g_(g), h_(h) {}

Natural RecursionPrimitiva::evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const {
    contador.registrar();

    // El último argumento corresponde a la variable de recursión 'y'
    Natural y = args.back();

    // Los argumentos previos corresponden a la base u otros parámetros 'x'
    std::vector<Natural> x(args.begin(), args.end() - 1);

    // Caso base: f(x, 0) = g(x)
    if (y == 0) {
        return g_->evaluar(x, contador);
    }

    // Paso recursivo: f(x, y) = h(x, y - 1, f(x, y - 1))
    std::vector<Natural> argsPrevios = args;
    argsPrevios.back() = y - 1;
    Natural resultadoPrevio = evaluar(argsPrevios, contador);

    // Preparamos los argumentos para la función de paso h: (x, y - 1, resultadoPrevio)
    std::vector<Natural> argsPaso = x;
    argsPaso.push_back(y - 1);
    argsPaso.push_back(resultadoPrevio);

    return h_->evaluar(argsPaso, contador);
}
