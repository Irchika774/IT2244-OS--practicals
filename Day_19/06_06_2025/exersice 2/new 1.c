#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <sys/wait.h>

// Function to calculate area
float calculateArea(char shape[], float a, float b) {
    if (strcmp(shape, "circle") == 0)
        return M_PI * a * a; // a = radius
    else if (strcmp(shape, "rectangle") == 0)
        return a * b;      
    else if (strcmp(shape, "triangle") == 0)
        return 0.5 * a * b; 
    else if (strcmp(shape, "square") == 0)
        return a * a;        
    else
        return -1; // Invalid shape
}

int main() {
    int ptc[2]; // Parent to Child pipe
    int ctp[2]; // Child to Parent pipe

    if (pipe(ptc) == -1 || pipe(ctp) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {
        // ===== PARENT PROCESS =====

        close(ptc[0]); // Close read end of ptc
        close(ctp[1]); // Close write end of ctp

        // Step 1: Get input from user
        char shape[20];
        float val1, val2;

        printf("Enter shape (circle, rectangle, triangle, square): ");
        scanf("%s", shape);

        if (strcmp(shape, "circle") == 0 || strcmp(shape, "square") == 0) {
            printf("Enter 1 value (radius or side): ");
            scanf("%f", &val1);
            val2 = 0; // not needed
        } else {
            printf("Enter 2 values (length & width, base & height): ");
            scanf("%f %f", &val1, &val2);
        }

        // Step 2: Send inputs to child
        write(ptc[1], shape, sizeof(shape));
        write(ptc[1], &val1, sizeof(float));
        write(ptc[1], &val2, sizeof(float));

        // Step 5: Read result from child
        float area;
        read(ctp[0], &area, sizeof(float));
        printf("\n[Parent] Area received from child: %.2f\n", area);

        close(ptc[1]);
        close(ctp[0]);

        wait(NULL); // Wait for child to finish

    } else {
        // ===== CHILD PROCESS =====

        close(ptc[1]); // Close write end of ptc
        close(ctp[0]); // Close read end of ctp

        // Step 3: Read input from parent
        char shape[20];
        float a, b;

        read(ptc[0], shape, sizeof(shape));
        read(ptc[0], &a, sizeof(float));
        read(ptc[0], &b, sizeof(float));

        // Step 4: Perform calculation
        float result = calculateArea(shape, a, b);

        // Send result back to parent
        write(ctp[1], &result, sizeof(float));

        close(ptc[0]);
        close(ctp[1]);
    }

    return 0;
}
