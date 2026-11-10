add_executable(unit_tests test_potencia.cpp)
target_link_libraries(unit_tests PRIVATE funciones_recursivas)

add_test(NAME PruebasUnitarias COMMAND unit_tests)
