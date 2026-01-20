#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Generate digits of pi using Rabinowitz & Wagon's spigot algorithm in base 10.
 * Writes exactly `digits` digits (starting from the leading 3) into `out`.
 * Returns 0 on success, -1 on allocation failure or size mismatch.
 */
int generate_pi_spigot(int digits, char *out, size_t out_size) {
    if (digits <= 0 || out_size < (size_t)digits + 1) {
        return -1;
    }

    int len = digits * 10 / 3 + 2;
    int *a = (int *)calloc((size_t)len, sizeof(int));
    if (!a) {
        return -1;
    }

    for (int i = 0; i < len; i++) {
        a[i] = 2;
    }

    int carry = 0;
    for (int i = 0; i < digits; i++) {
        carry = 0;
        for (int j = len - 1; j >= 0; j--) {
            int numerator = a[j] * 10 + carry * (j + 1);
            a[j] = numerator % (2 * j + 1);
            carry = numerator / (2 * j + 1);
        }
        a[0] = carry % 10;
        out[i] = (char)('0' + carry / 10);
    }

    out[digits] = '\0';
    free(a);
    return 0;
}
