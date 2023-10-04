#include <stdio.h>
int n1, n2, gc, lc;

int gcd() {
    for (int i = 1; i <= n1 && i <= n2; ++i) {
        if (n1 % i == 0 && n2 % i == 0)
            gc = i;
    }
    return 0;
}

int lcm() {
    lc = (n1 * n2) / gc;
    printf("The LCM of %d and %d is %d", n1, n2, lc);
    return 0;
}

int main() {
    printf("Enter the numbers you want to find the LCM of:\n");
    scanf("%d %d", &n1, &n2);
    gcd();
    lcm();
    return 0;
}
