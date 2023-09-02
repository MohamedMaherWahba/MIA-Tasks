#include <stdio.h>
#include <unistd.h>

int main() {
    int number;

    printf("Enter the number to start the countdown from: ");
    scanf("%d", &number);

    if (number < 1) {
        printf("Invalid input. The number must be greater than 0.\n");
        return 0;
    }

    printf("Countdown:\n");

    while (number >= 1) {
        printf("%d\n", number);
        sleep(1);  // After Search
        number--;
    }

    printf("Blast off to the moon!\n");

    return 0;
}
