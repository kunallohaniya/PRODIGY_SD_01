#include<iostream>
using namespace std;

// Fctn. to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius*9/5)+32;
}

// Fctn to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius+273.15;
}

// Fctn to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit-32)*5/9;
}

// Fctn to convert Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit-32)*5/9 + 273.15;
}

// Fctn to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Fctn to convert Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15)*9/5 + 32;
}

int main() {
    double temperature;
    char unit;
    cout << "Enter the value of temperature: ";
    cin >> temperature;

    cout << "Enter unit of measurement (C for Celsius, F for Fahrenheit, K for Kelvin): ";
    cin >> unit;

        if (unit == 'C' || unit == 'c') {
            double fahrenheit = celsiusToFahrenheit(temperature);
            double kelvin = celsiusToKelvin(temperature);
            cout << "Temperature in Fahrenheit: " << fahrenheit << "°F" << endl;
            cout << "Temperature in Kelvin: " << kelvin << "K" << endl;
        } 
        else if (unit == 'F' || unit == 'f') {
            double celsius = fahrenheitToCelsius(temperature);
            double kelvin = fahrenheitToKelvin(temperature);
            cout << "Temperature in Celsius: " << celsius << "°C" << endl;
            cout << "Temperature in Kelvin: " << kelvin << "K" << endl;
        } 
        else if (unit == 'K' || unit == 'k') {
            double celsius = kelvinToCelsius(temperature);
            double fahrenheit = kelvinToFahrenheit(temperature);
            cout << "Temperature in Celsius: " << celsius << "°C" << endl;
            cout << "Temperature in Fahrenheit: " << fahrenheit << "°F" << endl;
        } else {
            cout << "Invalid unit of measurement!" << endl;
        }

    return 0;
}