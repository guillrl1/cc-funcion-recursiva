#include "Operaciones.hpp"
#include "FuncionesBasicas.hpp"
#include "Composicion.hpp"
#include "RecursionPrimitiva.hpp"

// ==========================================
// Suma: suma(x, y) = x + y
// Caso base: suma(x, 0) = x = P_1(x)
// Paso:      suma(x, y + 1) = S(suma(x, y)) = S(P_3(x, y, suma(x, y)))
// ==========================================
Suma::Suma() {
    auto p1 = std::make_shared<Proyeccion>(1);
    auto p3 = std::make_shared<Proyeccion>(3);
    auto s  = std::make_shared<Sucesor>();

    // h(x, y, prev) = S(P_3(x, y, prev))
    auto paso = std::make_shared<Composicion>(s, std::vector<std::shared_ptr<Funcion>>{p3});

    impl_ = std::make_shared<RecursionPrimitiva>(p1, paso);
}

Natural Suma::evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const {
    return impl_->evaluar(args, contador);
}

Natural Suma::calcular(Natural x, Natural y, ContadorLlamadas& contador) const {
    return evaluar({x, y}, contador);
}

// ==========================================
// Multiplicación: mult(x, y) = x * y
// Caso base: mult(x, 0) = 0 = Z(x)
// Paso:      mult(x, y + 1) = x + mult(x, y) = suma(P_1, P_3)
// ==========================================
Multiplicacion::Multiplicacion(std::shared_ptr<Funcion> suma) {
    if (!suma) {
        suma = std::make_shared<Suma>();
    }

    auto cero = std::make_shared<Cero>();
    auto p1   = std::make_shared<Proyeccion>(1); // base x
    auto p3   = std::make_shared<Proyeccion>(3); // valor previo acumulado mult(x, y)

    // h(x, y, prev) = suma(P_1, P_3)
    auto paso = std::make_shared<Composicion>(suma, std::vector<std::shared_ptr<Funcion>>{p1, p3});

    impl_ = std::make_shared<RecursionPrimitiva>(cero, paso);
}

Natural Multiplicacion::evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const {
    return impl_->evaluar(args, contador);
}

Natural Multiplicacion::calcular(Natural x, Natural y, ContadorLlamadas& contador) const {
    return evaluar({x, y}, contador);
}

// ==========================================
// Potencia: potencia(x, y) = x^y
// Caso base: potencia(x, 0) = 1 = S(Z(x))
// Paso:      potencia(x, y + 1) = x * potencia(x, y) = mult(P_1, P_3)
// ==========================================
Potencia::Potencia(std::shared_ptr<Funcion> mult) {
    if (!mult) {
        mult = std::make_shared<Multiplicacion>();
    }

    // Caso base: función constante 1 = S(Z(x))
    auto cero = std::make_shared<Cero>();
    auto s    = std::make_shared<Sucesor>();
    auto base = std::make_shared<Composicion>(s, std::vector<std::shared_ptr<Funcion>>{cero});

    auto p1   = std::make_shared<Proyeccion>(1); // base x
    auto p3   = std::make_shared<Proyeccion>(3); // valor previo acumulado potencia(x, y)

    // h(x, y, prev) = mult(P_1, P_3)
    auto paso = std::make_shared<Composicion>(mult, std::vector<std::shared_ptr<Funcion>>{p1, p3});

    impl_ = std::make_shared<RecursionPrimitiva>(base, paso);
}

Natural Potencia::evaluar(const std::vector<Natural>& args, ContadorLlamadas& contador) const {
    return impl_->evaluar(args, contador);
}

Natural Potencia::calcular(Natural base, Natural exponente, ContadorLlamadas& contador) const {
    return evaluar({base, exponente}, contador);
}
