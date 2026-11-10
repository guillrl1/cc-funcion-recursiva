cmake_minimum_required(VERSION 3.16)

project(PotenciaRecursiva
    VERSION 1.0.0
    DESCRIPTION "Implementacion de la funcion potencia como funcion primitiva recursiva"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Opciones de compilación
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra)
endif()

# Biblioteca con las funciones primitivas recursivas
add_library(funciones_recursivas STATIC
    src/FuncionesBasicas.cpp
    src/Composicion.cpp
    src/RecursionPrimitiva.cpp
    src/Operaciones.cpp
)

target_include_directories(funciones_recursivas PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Ejecutable principal
add_executable(potencia src/main.cpp)
target_link_libraries(potencia PRIVATE funciones_recursivas)

# Pruebas automatizadas
enable_testing()
add_subdirectory(tests)
