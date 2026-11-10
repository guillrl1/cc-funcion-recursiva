# Práctica 3: Implementación de Funciones Primitivas Recursivas

**Asignatura:** Complejidad Computacional (Curso 2026/27)  
**Institución:** Escuela Superior de Ingeniería y Tecnología (ESIT), Universidad de La Laguna  
**Lenguaje:** C++ (Estándar C++17)  
**Herramienta de construcción:** CMake (>= 3.16)


## Objetivo de la Práctica

Implementar un programa en consola que calcule la función:

$$\text{potencia}: \mathbb{N} \times \mathbb{N} \to \mathbb{N}$$
$$(x, y) \mapsto x^y$$

utilizando únicamente las **funciones básicas iniciales** y los **operadores de composición y recursión primitiva**.

### Salida por pantalla requerida:
1. El **resultado de la operación** $x^y$.
2. El **número total de llamadas a funciones** que se han realizado.

## Estructura del Código

El diseño sigue una estructura limpia y orientada a objetos:

```text
.
├── CMakeLists.txt
├── README.md
├── include
│   ├── Composicion.hpp
│   ├── Funcion.hpp
│   ├── FuncionesBasicas.hpp
│   ├── Operaciones.hpp
│   └── RecursionPrimitiva.hpp
├── src
│   ├── Composicion.cpp
│   ├── FuncionesBasicas.cpp
│   ├── Operaciones.cpp
│   ├── RecursionPrimitiva.cpp
│   └── main.cpp
└── tests
    ├── CMakeLists.txt
    └── test_potencia.cpp
```

### ¿Cómo funciona el conteo de llamadas?
Cada vez que se ejecuta el método `evaluar(...)` de una **función** (ya sean funciones básicas como Cero, Sucesor, Proyección, o funciones construidas por Recursión Primitiva como Suma, Multiplicación o Potencia), se invoca a:
```cpp
contador.registrar();
```

---

## Compilación y Ejecución

### Compilar el proyecto
Desde la carpeta raíz del proyecto, ejecuta en la terminal:
```bash
cmake -B build -S .
cmake --build build
```

### Ejecutar el programa principal
El programa acepta los parámetros `-x <base>` e `-y <exponente>` en consola:

```bash
# Ejemplo: 2 elevado a 1 (13 llamadas a funciones)
./build/potencia -x 2 -y 1
```

**Salida obtenida:**
```text
============================================================
  PRACTICA 3: FUNCION PRIMITIVA RECURSIVA POTENCIA(X, Y)    
============================================================
Parametros de entrada:
  Base (x):       2
  Exponente (y):  1
------------------------------------------------------------
Resultado de la operacion:
  potencia(2, 1) = 2
------------------------------------------------------------
Numero de llamadas a funciones realizadas:
  Total de llamadas: 13
============================================================
```

### Otros ejemplos:
```bash
# Caso base: 2 elevado a 0 (potencia = 1, 3 llamadas)
./build/potencia -x 2 -y 0

# 2 elevado a 2 (potencia = 4, 34 llamadas)
./build/potencia -x 2 -y 2

# 2 elevado a 3 (potencia = 8, 95 llamadas)
./build/potencia -x 2 -y 3

# Ver ayuda de uso
./build/potencia -h
```

---

## 6. Pruebas Automatizadas

Para verificar el correcto funcionamiento de todas las funciones y casos de borde:
```bash
ctest --test-dir build
# O bien ejecutando directamente:
./build/tests/unit_tests
```
