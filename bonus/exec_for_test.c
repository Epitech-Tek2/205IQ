/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-203hotline-clement.muth [WSL: Ubuntu]
** File description:
** main
*/

#include <ctype.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include "IQ.h"
#include "../library/utils/includes/index.h"

calc_t *calc = NULL;

noreturn bool help(str_const_restrict _filepath, int const _output)
{
    char *lineptr = NULL;
    size_t i = 500;
    FILE *stream = GET(FILE *, {
        my_assert(_filepath, PROTO_DATA, ASSERT_INFO("Cannot read property '_filepath' of undefined", ERR_TYPE, FAIL_EXEC), NULL);
        return (fopen(_filepath, "r"));
    });

    while (-1 != getline(&lineptr, &i, stream) && (printf("%s", lineptr)));
    free(lineptr);
    fclose(stream);
    exit(_output);
}

static double gauss(int const _mean, int const _deviantion, float const i)
{
    return ((1 / (_deviantion * sqrt(2 * M_PI)) * exp(-(pow((i - _mean), 2) / (2 * pow(_deviantion, 2))))));
}

static void export_gnu_plot()
{
    for (int i = 0; 200 >= i; i++) printf("%d %.5lf\n", i, gauss(calc->mean, calc->deviation, i));
}

static void one_iq()
{
    double res = 0;

    for (float i = 0; calc->iq.x > i; i += 0.01) res += gauss(calc->mean, calc->deviation, i);
    printf("%.1f%% of people have an IQ inferior to %d\n", res, calc->iq.x);
}

static void two_iq()
{
    double res = 0;

    for (float i = calc->iq.x; i < calc->iq.y; i += 0.01) res += gauss(calc->mean, calc->deviation, i);
    printf("%.1f%% of people have an IQ between %d and %d\n", res, calc->iq.x, calc->iq.y);
}

static void arg_handling(int const _ac, arr_const_restrict _av)
{
    if (3 > _ac || 5 < _ac) eraise();
    for (int i = 0; _av[i]; i++)
        if (!issdigit(_av[i])) eraise();
    calc->mean = atoi(*_av);
    calc->deviation = atoi(_av[1]);
    calc->iq = (vect2i){0, 0};
    if (0 >= calc->mean || 0 >= calc->deviation) eraise();
    if (3 == _ac) export_gnu_plot();
    else if (4 == _ac) {
        calc->iq.x = atoi(_av[2]);
        if (0 > calc->iq.x || 200 < calc->iq.x) eraise();
        one_iq();
    } else {
        calc->iq.x = atoi(_av[2]);
        calc->iq.y = atoi(_av[3]);
        if (0 > calc->iq.x || 0 > calc->iq.y || 200 < calc->iq.x || 200 < calc->iq.y || calc->iq.x > calc->iq.y) eraise();
        two_iq();
    }
}

void IQ(int const _ac, arr_const_restrict _av)
{
    errno = 0;
    calc = malloc(sizeof(calc_t));
    my_assert(calc != NULL, PROTO_DATA, ASSERT_INFO(strerror(errno), ERR_ALC84, FAIL_EXEC), NULL);
    ++_av;
    arg_handling(_ac, _av);
    my_free(calc, NULL);
}

// int main(int const _ac, arr_const_restrict _av)
// {
//     errno = 0;
//     calc = malloc(sizeof(calc_t));
//     my_assert(calc != NULL, PROTO_DATA, ASSERT_INFO(strerror(errno), ERR_ALC84, FAIL_EXEC), NULL);
//     if (2 == _ac && !strcmp(_av[1], "-h")) help("./help.txt", 0);
//     _av++;
//     arg_handling(_ac, _av);
//     IQ(_ac, _av);
//     return (0);
// }