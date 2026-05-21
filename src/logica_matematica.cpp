#include <iostream>
#include "Funciones_matematicas.hpp"

// Funcion para obtener el valor absoluto
double valorAbsoluto(double numero) {
    if (numero < 0.0) {
        return numero * -1.0;
    }

    return numero;
}

// Funcion auxiliar para calcular potencias
double calcularPotencia(double base, int exponente) {
    double resultado = 1.0;

    for (int indice = 0; indice < exponente; indice++) {
        resultado = resultado * base;
    }

    return resultado;
}

// Funcion auxiliar para calcular factorial
double calcularFactorial(int numero) {
    double resultado = 1.0;

    for (int indice = 1; indice <= numero; indice++) {
        resultado = resultado * indice;
    }

    return resultado;
}

// Metodo babilonico para raiz cuadrada
double raizCuadrada(double numero) {
    if (numero < 0.0) {
        return -1.0;
    }

    if (numero == 0.0) {
        return 0.0;
    }

    double aproximacion = numero;
    double valorAnterior = 0.0;

    for (int intento = 0; intento < 20; intento++) {
        valorAnterior = aproximacion;

        aproximacion =
            (aproximacion + (numero / aproximacion)) / 2.0;

        if (valorAbsoluto(aproximacion - valorAnterior) < 0.00001) {
            break;
        }
    }

    return aproximacion;
}

// Aproximacion de la exponencial con Taylor
double exponencial(double numero) {
    double suma = 0.0;

    for (int termino = 0; termino < 18; termino++) {
        suma += calcularPotencia(numero, termino) /
                calcularFactorial(termino);
    }

    return suma;
}

// Ajusta el angulo entre -PI y PI
double ajustarAngulo(double angulo) {
    while (angulo > PI) {
        angulo = angulo - (2.0 * PI);
    }

    while (angulo < -PI) {
        angulo = angulo + (2.0 * PI);
    }

    return angulo;
}

// Escalamiento Min-Max
double normalizar(double valor, double minimo, double maximo) {
    if (minimo == maximo) {
        return 0.0;
    }

    return (valor - minimo) / (maximo - minimo);
}

// Aproximacion del seno
double seno(double angulo) {
    angulo = ajustarAngulo(angulo);

    double resultado = 0.0;
    int signo = 1;

    for (int termino = 0; termino < 10; termino++) {
        int exponente = (2 * termino) + 1;

        resultado += signo *
                     (calcularPotencia(angulo, exponente) /
                      calcularFactorial(exponente));

        signo = signo * -1;
    }

    return resultado;
}

// Aproximacion del coseno
double coseno(double angulo) {
    angulo = ajustarAngulo(angulo);

    double resultado = 0.0;
    int signo = 1;

    for (int termino = 0; termino < 10; termino++) {
        int exponente = 2 * termino;

        resultado += signo *
                     (calcularPotencia(angulo, exponente) /
                      calcularFactorial(exponente));

        signo = signo * -1;
    }

    return resultado;
}

// Funcion principal de pruebas
void run() {
    std::cout << "======= PRUEBAS MATEMATICAS =======\n\n";

    std::cout << "Valor absoluto de -12.7: "
              << valorAbsoluto(-12.7) << "\n";

    std::cout << "Raiz cuadrada de 49: "
              << raizCuadrada(49.0) << "\n";

    std::cout << "Valor aproximado de e^1: "
              << exponencial(1.0) << "\n";

    std::cout << "Normalizacion de 40 en [0,100]: "
              << normalizar(40.0, 0.0, 100.0) << "\n";

    std::cout << "\nSeno de PI/2: "
              << seno(PI / 2.0) << "\n";

    std::cout << "Coseno de PI: "
              << coseno(PI) << "\n";

    std::cout << "Seno de 0: "
              << seno(0.0) << "\n";

    std::cout << "Coseno de 0: "
              << coseno(0.0) << "\n";
}
