#include <iostream>
#include <vector>
#include <cmath>
#include <locale> // Incluir la librería para manejar la localización

class RegresionLineal {
private:
    std::vector<double> x;
    std::vector<double> y;
    double pendiente;
    double ordenadaEnElOrigen;
    double correlacion;

public:
    RegresionLineal(const std::vector<double>& x_values, const std::vector<double>& y_values)
        : x(x_values), y(y_values) {
        calcularRegresionLineal();
        calcularCoeficienteCorrelacion();
    }

    // Función para calcular la pendiente y la ordenada en el origen
    void calcularRegresionLineal() {
        double sumX = 0.0;
        double sumY = 0.0;
        double sumXY = 0.0;
        double sumX2 = 0.0;

        // Calcular las sumas necesarias
        for (size_t i = 0; i < x.size(); ++i) {
            sumX += x[i];
            sumY += y[i];
            sumXY += x[i] * y[i];
            sumX2 += x[i] * x[i];
        }

        // Calcular la pendiente (coeficiente)
        pendiente = (x.size() * sumXY - sumX * sumY) / (x.size() * sumX2 - sumX * sumX);

        // Calcular la ordenada en el origen
        ordenadaEnElOrigen = (sumY - pendiente * sumX) / x.size();
    }

    // Función para calcular el coeficiente de correlación
    void calcularCoeficienteCorrelacion() {
        double sumX = 0.0;
        double sumY = 0.0;
        double sumXY = 0.0;
        double sumX2 = 0.0;
        double sumY2 = 0.0;

        // Calcular las sumas necesarias
        for (size_t i = 0; i < x.size(); ++i) {
            sumX += x[i];
            sumY += y[i];
            sumXY += x[i] * y[i];
            sumX2 += x[i] * x[i];
            sumY2 += y[i] * y[i];
        }

        // Calcular el coeficiente de correlación
        correlacion = (x.size() * sumXY - sumX * sumY) / (sqrt((x.size() * sumX2 - sumX * sumX) * (x.size() * sumY2 - sumY * sumY)));
    }

    // Función para calcular el coeficiente de determinación (R²)
    double calcularCoeficienteDeterminacion() const {
        return correlacion * correlacion;
    }

    // Función para imprimir la ecuación de regresión lineal y el coeficiente de correlación
    void imprimirResultados() const {
        std::cout << "Beta0: " << ordenadaEnElOrigen << " + Beta1: " << pendiente  << std::endl;
        std::cout << "\nCoeficiente de correlación: " << correlacion << std::endl;
        std::cout << "Coeficiente de determinación (R²): " << calcularCoeficienteDeterminacion() << std::endl;
    }

    // Función para realizar predicciones con datos nuevos
    void predecirDatosNuevos(const std::vector<double>& nuevos_x) const {
        std::cout << "\nPredicciones para nuevos datos:" << std::endl;
        for (size_t i = 0; i < nuevos_x.size(); ++i) {
            double prediccion = pendiente * nuevos_x[i] + ordenadaEnElOrigen;
            std::cout << "Para x = " << nuevos_x[i] << ", la predicción es y = " << prediccion << std::endl;
        }
    }
};

int main() {
    // Configurar la localización para permitir la impresión de caracteres especiales
    setlocale(LC_ALL, "spanish");

    // Dataset
    std::vector<double> x = {23, 26, 30, 34, 43, 48, 52, 57, 58};
    std::vector<double> y = {651, 762, 856, 1063, 1190, 1298, 1421, 1440, 1518};

    // Crear un objeto RegresionLineal y calcular la regresión lineal
    RegresionLineal regresion(x, y);

    // Imprimir la ecuación de regresión lineal, el coeficiente de correlación y el coeficiente de determinación
    regresion.imprimirResultados();

    // Datos nuevos para predecir
    std::vector<double> nuevos_x = {31, 35, 40, 45, 50};
    regresion.predecirDatosNuevos(nuevos_x);

    return 0;
}
