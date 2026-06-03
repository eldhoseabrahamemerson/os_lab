#include <stdio.h>

int main() {
    int pages[50], frame[10];
    int n, f, i, j, k, pos, page_faults = 0;
    int found, farthest, index;

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
    }

    for(i = 0; i < n; i++) {
        found = 0;

        // Check if page is already in frame (HIT)
        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If page fault
        if(!found) {
            // Find page to replace
            pos = -1;
            farthest = i + 1;

            for(j = 0; j < f; j++) {
                for(k = i + 1; k < n; k++) {
                    if(frame[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        break;
                    }
                }

                // If page not found in future
                if(k == n) {
                    pos = j;
                    break;
                }
            }

            // If all pages found, replace farthest
            if(pos == -1)
                pos = 0;

            frame[pos] = pages[i];
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
