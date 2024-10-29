#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if (cms <= 38) { // Include 38 in 'S' size
        sizeName = 'S';
    } else if (cms > 38 && cms <= 42) { // Include 42 in 'M' size
        sizeName = 'M';
    } else {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');
    assert(size(38) == 'S'); // New test case for edge
    assert(size(40) == 'M');
    assert(size(42) == 'M'); // New test case for edge
    assert(size(43) == 'L');
    printf("All is well (maybe!)\n");
    return 0;
}
