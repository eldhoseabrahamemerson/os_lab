#include <stdio.h>

int main() {
    int pages[50], frame[10], time[10];
    int n, f, i, j, pos, page_faults = 0;
    int counter = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        found = 0;

        // Check for page hit
        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                counter++;
                time[j] = counter; // update usage time
                found = 1;
                break;
            }
        }

        // Page fault
        if(!found) {
            // Find least recently used page
            pos = 0;
            for(j = 1; j < f; j++) {
                if(time[j] < time[pos]) {
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            counter++;
            time[pos] = counter;
            page_faults++;
        }

        // Print frames
        printf("\nPage %d: ", pages[i]);
        for(j = 0; j < f; j++) {
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
    }

    printf("\n\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
