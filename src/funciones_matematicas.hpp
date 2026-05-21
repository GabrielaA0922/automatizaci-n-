#pragma once

// Valor aproximado de PI
const double PI = 3.14159265358979323846;

// ===== Declaracion de funciones matematicas =====

// Retorna el valor absoluto de un numero
double valorAbsoluto(double numero);

// Calcula una aproximacion de la raiz cuadrada
// usando el metodo babilonico
double raizCuadrada(double numero);

// Calcula e^x con la serie de Taylor
double exponencial(double numero);

// Escalamiento de valores con metodo Min-Max
double normalizar(double valor, double minimo, double maximo);

// Aproximacion del seno mediante Taylor
double seno(double angulo);

// Aproximacion del coseno mediante Taylor
double coseno(double angulo);

// Funcion para ejecutar pruebas
void run();
