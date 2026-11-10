#include "Operaciones.hpp"
#include <iostream>
#include <string>

// Muestra la ayuda de uso por consola
void mostrarAyuda(const char* nombrePrograma) {
    std::cout << "Uso: " << nombrePrograma << " -x <n> -y <n>\n\n";
    std::cout << "Calcula potencia(x, y) = x^y como funcion primitiva recursiva.\n\n";
    std::cout << "Opciones:\n";
    std::cout << "  -x <n>    Base de la potencia (numero natural >= 0)\n";
    std::cout << "  -y <n>    Exponente de la potencia (numero natural >= 0)\n";
    std::cout << "  -h        Muestra esta ayuda\n\n";
    std::cout << "Ejemplo:\n";
    std::cout << "  " << nombrePrograma << " -x 2 -y 3\n";
}

int main(int argc, char* argv[]) {
    long long base = -1;
    long long exponente = -1;
    bool tieneBase = false;
    bool tieneExponente = false;

    // Procesamos las opciones de la línea de comandos
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            mostrarAyuda(argv[0]);
            return 0;
        } else if (arg == "-x" && i + 1 < argc) {
            try {
                base = std::stoll(argv[++i]);
                tieneBase = true;
            } catch (...) {
                std::cerr << "Error: La base (-x) debe ser un numero natural valido.\n";
                return 1;
            }
        } else if (arg == "-y" && i + 1 < argc) {
            try {
                exponente = std::stoll(argv[++i]);
                tieneExponente = true;
            } catch (...) {
                std::cerr << "Error: El exponente (-y) debe ser un numero natural valido.\n";
                return 1;
            }
        }
    }

    // Validación de parámetros obligatorios y naturales (>= 0)
    if (!tieneBase || !tieneExponente || base < 0 || exponente < 0) {
        std::cerr << "Error: Debe indicar la base con -x <n> y el exponente con -y <n> (enteros >= 0).\n\n";
        mostrarAyuda(argv[0]);
        return 1;
    }

    // Instanciamos la función potencia y el contador de llamadas
    Potencia potencia;
    ContadorLlamadas contador;

    // Calculamos potencia(x, y)
    Natural resultado = potencia.calcular(static_cast<Natural>(base), static_cast<Natural>(exponente), contador);

    // Salida por pantalla requerida por la práctica
    std::cout << "============================================================\n";
    std::cout << "  PRACTICA 3: FUNCION PRIMITIVA RECURSIVA POTENCIA(X, Y)    \n";
    std::cout << "============================================================\n";
    std::cout << "Parametros de entrada:\n";
    std::cout << "  Base (x):       " << base << "\n";
    std::cout << "  Exponente (y):  " << exponente << "\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "Resultado de la operacion:\n";
    std::cout << "  potencia(" << base << ", " << exponente << ") = " << resultado << "\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "Numero de llamadas a funciones realizadas:\n";
    std::cout << "  Total de llamadas: " << contador.getTotal() << "\n";
    std::cout << "============================================================\n";

    return 0;
}
