#include <stdio.h>
#include <math.h>

#define OBLIQUITY 0.000001

struct float_mark {
    float x1;
    float x2;
};

struct float_mark float_point_system(float delta) {
    struct float_mark solv;
    solv.x2 = (0.0001f + delta) / 0.0001f;
    solv.x1 = 2 - solv.x2;
    return solv;
}

struct double_mark {
    double x1;
    double x2;
};

struct double_mark double_point_system(double delta) {
    struct double_mark solv;
    solv.x2 = (0.0001 + delta) / 0.0001;
    solv.x1 = 2 - solv.x2;
    return solv;
}

void float_solve() {
    int estim = 0;
    float frst_x1, scnd_x1, frst_x2, scnd_x2;
    float max_err = 1;
    float delta = 0;
    struct float_mark solv;
    solv = float_point_system(delta);
    delta = 0.0001f;
    frst_x1 = solv.x1;
    frst_x2 = solv.x2;
    while (max_err > OBLIQUITY) {
        solv = float_point_system(delta);
        scnd_x1 = solv.x1;
        scnd_x2 = solv.x2;
        delta /= 2.0f;
        float count_x1 = frst_x1 - scnd_x1;
        float count_x2 = frst_x2 - scnd_x2;
        max_err = sqrtf(count_x1 * count_x1 + count_x2 * count_x2);
        printf("In floats (delta = %.11f): \n", delta);
        printf("x1: %.11f \n", frst_x1);
        printf("x1 with delta: %.11f \n", scnd_x1);
        printf("x2: %.11f \n", frst_x2);
        printf("x2 with delta: %.11f \n", scnd_x2);
        printf("Distance: %.11f \n\n", max_err);
        estim++;
    }
    printf("%d раз(а) успели поделить float с delta(10^-4) на 2^%d", estim, estim);
}

void double_solve() {
    int estim = 0;
    double frst_x1, scnd_x1, frst_x2, scnd_x2;
    double max_err = 1;
    double delta = 0;
    struct double_mark solv;
    solv = double_point_system(delta);
    delta = 0.0001;
    frst_x1 = solv.x1;
    frst_x2 = solv.x2;
    while (max_err > OBLIQUITY) {
        solv = double_point_system(delta);
        scnd_x1 = solv.x1;
        scnd_x2 = solv.x2;
        delta /= 2.0;
        double count_x1 = frst_x1 - scnd_x1;
        double count_x2 = frst_x2 - scnd_x2;
        max_err = sqrt(count_x1 * count_x1 + count_x2 * count_x2);
        printf("In doubles (delta = %.16lf): \n", delta);
        printf("x1: %.16lf \n", frst_x1);
        printf("x1 with delta: %.16lf \n", scnd_x1);
        printf("x2: %.16lf \n", frst_x2);
        printf("x2 with delta: %.16lf \n", scnd_x2);
        printf("Distance: %.16lf \n\n", max_err);
        estim++;
    }
    printf("%d раз(а) успели поделить double с delta(10^-4) на 2^%d", estim, estim);
}

int main() {
    printf("----------Print float solving----------\n\n");
    float_solve();
    printf("\n\n----------Print double solving----------\n\n");
    double_solve();
    return 0;
}
