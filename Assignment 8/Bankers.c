#include <stdio.h>
int main() {
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int alloc[n][m], max[n][m], avail[m], f[n], ans[n], ind = 0;
    printf("Enter the Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("P%d Resource %d: ", i, j);
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the Maximum Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("P%d Resource %d: ", i, j);
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the Available Resources:\n");
    for (j = 0; j < m; j++) {
        printf("Resource %d: ", j);
        scanf("%d", &avail[j]);
    }
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) { // If process i is not finished
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1; // Need of process i is greater than available
                        break;
                    }
                }
                if (flag == 0) { // If all resources can satisfy the need
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1; // Mark process i as finished
                }
            }
        }
    }
    int flag = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) { // If any process is not finished
            flag = 0;
            printf("The system is not safe.\n");
            break;
        }
    }
    if (flag == 1) {
        printf("Following is the SAFE Sequence:\n");
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d\n", ans[n - 1]);
    }
    return 0;
}