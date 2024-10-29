#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f Celsius.\n", celcius);
    // If Celsius temperature is above 200.0, simulate a failure
    if (celcius > 200.0) {
        printf("Returning 500 (Alert Failed)\n");
        return 500;
    }
    printf("Returning 200 (Alert Succeeded)\n");
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    printf("Converted: %.1f Fahrenheit to %.1f Celsius\n", farenheit, celcius);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        alertFailureCount += 1;
        printf("Incrementing failure count. Current count: %d\n", alertFailureCount);
    } else {
        printf("No increment to failure count.\n");
    }
}

int main() {
    alertFailureCount = 0;  // Resetting to ensure fresh start for tests
    alertInCelcius(400.5);  // Should fail (increment alertFailureCount)
    alertInCelcius(303.6);  // Should succeed (no increment to alertFailureCount)
    
    printf("Total failed alerts: %d\n", alertFailureCount);
    assert(alertFailureCount == 1); // Expecting exactly 1 failure
    printf("All is well (maybe!)\n");
    return 0;
}
