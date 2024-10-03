#include <stdio.h> 


float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: It's freezing outside, stay warm.\n");
    } else if (celsius <= 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius <= 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius <= 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: hot outside, drink water.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: stay cool.\n");
    }
}

int main() {
    float temp, converted_temp;
    float input_scale, converted_scale;

    // Begin the loop to get the temperature
    while (1) {
        printf("Enter the temperature: ");
        if (scanf("%f", &temp) != 1) { 
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        // Choose the input scale
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%f", &input_scale);

        // Input validation for Kelvin
        if (input_scale == 3 && temp < 0) { 
            printf("Invalid temperature! Kelvin cannot be negative.\n");
            continue;
        }

        // Ask for conversion scale
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%f", &converted_scale);

        // Check if input and converted scales are the same
        if (input_scale == converted_scale) {
            printf("Invalid conversion, they are the same scale.\n"); 
            continue;
        }
        // Perform the conversion
        if (input_scale == 1 && converted_scale == 2) {
            converted_temp = celsius_to_fahrenheit(temp);
        } else if (input_scale == 1 && converted_scale == 3) {
            converted_temp = celsius_to_kelvin(temp);
        } else if (input_scale == 2 && converted_scale == 1) {
            converted_temp = fahrenheit_to_celsius(temp);
        } else if (input_scale == 2 && converted_scale == 3) {
            converted_temp = fahrenheit_to_kelvin(temp);
        } else if (input_scale == 3 && converted_scale == 1) {
            converted_temp = kelvin_to_celsius(temp);
        } else if (input_scale == 3 && converted_scale == 2) {
            converted_temp = kelvin_to_fahrenheit(temp);
        }

        // Check for negative Kelvin after conversion
        if (converted_scale == 3 && converted_temp < 0) {
            printf("Error: Converted Kelvin temperature cannot be negative.\n");
            continue; 
        }

        // Output the converted temperature
        printf("Converted temperature: %.2f", converted_temp);
        if (converted_scale == 1) {
            printf("°C\n");
        } else if (converted_scale == 2) {
            printf("°F\n");
        } else {
            printf("K\n");
        }

        // Categorize temperature and provide advisory based on Celsius
        if (converted_scale == 1) {
            categorize_temperature(converted_temp);
        } else if (converted_scale == 2) {
            categorize_temperature(fahrenheit_to_celsius(converted_temp));
        } else {
            categorize_temperature(kelvin_to_celsius(converted_temp));
        }
        break;
    }
    return 0;
}

    
