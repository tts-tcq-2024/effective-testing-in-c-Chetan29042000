#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if (celcius > 200.0) {
        return 500;
    }
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5); // Should increment alertFailureCount
    alertInCelcius(303.6); // Should not increment alertFailureCount
    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount == 1); // Expecting exactly 1 failure
    printf("All is well (maybe!)\n");
    return 0;
}
