#include "Operaciones.hpp"
#include "FuncionesBasicas.hpp"
#include <iostream>
#include <cassert>

int main() {
    std::cout << "[TEST] Iniciando comprobaciones de funciones recursivas y conteo de llamadas (sin operador Composicion)...\n";

    // 1. Probar funciones básicas
    {
        ContadorLlamadas c;
        Cero cero;
        assert(cero.evaluar({10}, c) == 0);
        assert(c.getTotal() == 1);

        Sucesor suc;
        assert(suc.evaluar({5}, c) == 6);
        assert(c.getTotal() == 2);

        Proyeccion p1(1);
        assert(p1.evaluar({8, 2}, c) == 8);
        assert(c.getTotal() == 3);

        Proyeccion p2(2);
        assert(p2.evaluar({8, 2}, c) == 2);
        assert(c.getTotal() == 4);
    }

    // 2. Probar Suma (resultado y llamadas)
    {
        Suma suma;
        ContadorLlamadas c;
        // suma(2, 0) = 2 (Rec Suma [y=0] + P1 = 2 llamadas)
        assert(suma.calcular(2, 0, c) == 2);
        assert(c.getTotal() == 2);

        c.reiniciar();
        // suma(3, 4) = 7
        assert(suma.calcular(3, 4, c) == 7);
        assert(c.getTotal() > 0);
    }

    // 3. Probar Multiplicación (resultado y llamadas)
    {
        Multiplicacion mult;
        ContadorLlamadas c;
        // mult(2, 0) = 0 (Rec Mult [y=0] + Cero = 2 llamadas)
        assert(mult.calcular(2, 0, c) == 0);
        assert(c.getTotal() == 2);

        c.reiniciar();
        // mult(2, 1) = 2 (sin contar operador composicion: 7 llamadas)
        assert(mult.calcular(2, 1, c) == 2);
        assert(c.getTotal() == 7);
    }

    // 4. Probar Potencia: verificación de resultados y conteo exacto sin el operador composición
    {
        Potencia pot;

        // Caso base: potencia(2, 0) = 1 -> 3 llamadas (Rec Pot [y=0], Cero, Sucesor)
        {
            ContadorLlamadas c;
            Natural res = pot.calcular(2, 0, c);
            assert(res == 1);
            assert(c.getTotal() == 3);
            std::cout << "  - pot(2, 0) = " << res << " con " << c.getTotal() << " llamadas a funciones [OK]\n";
        }

        // Caso: potencia(2, 1) = 2 -> 13 llamadas a funciones (al no ser la composicion una funcion)
        {
            ContadorLlamadas c;
            Natural res = pot.calcular(2, 1, c);
            assert(res == 2);
            assert(c.getTotal() == 13);
            std::cout << "  - pot(2, 1) = " << res << " con " << c.getTotal() << " llamadas a funciones [OK]\n";
        }

        // Caso: potencia(2, 2) = 4 -> 34 llamadas a funciones
        {
            ContadorLlamadas c;
            Natural res = pot.calcular(2, 2, c);
            assert(res == 4);
            assert(c.getTotal() == 34);
            std::cout << "  - pot(2, 2) = " << res << " con " << c.getTotal() << " llamadas a funciones [OK]\n";
        }

        // Caso: potencia(2, 3) = 8 -> 95 llamadas a funciones
        {
            ContadorLlamadas c;
            Natural res = pot.calcular(2, 3, c);
            assert(res == 8);
            assert(c.getTotal() == 95);
            std::cout << "  - pot(2, 3) = " << res << " con " << c.getTotal() << " llamadas a funciones [OK]\n";
        }

        // Casos de borde
        {
            ContadorLlamadas c;
            assert(pot.calcular(0, 0, c) == 1); // 0^0 = 1 en Peano
            assert(c.getTotal() == 3);

            c.reiniciar();
            assert(pot.calcular(0, 1, c) == 0); // 0^1 = 0
            assert(c.getTotal() == 13);

            c.reiniciar();
            assert(pot.calcular(5, 0, c) == 1); // 5^0 = 1
            assert(c.getTotal() == 3);

            c.reiniciar();
            assert(pot.calcular(3, 2, c) == 9); // 3^2 = 9
            assert(c.getTotal() == 60);
        }
    }

    std::cout << "[TEST] Todas las comprobaciones de resultados y llamadas fueron superadas con exito.\n";
    return 0;
}
