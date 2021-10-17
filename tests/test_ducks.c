/*
** EPITECH PROJECT, 2021
** 205IQ [WSL: Ubuntu]
** File description:
** test_IQ
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "IQ.h"

Test(basic_test, IQ_exit, .exit_code=0)
{
    char **arr = malloc(sizeof(char *) * 4);

    arr[0] = "./205IQ";
    arr[1] = "100";
    arr[2] = "15";
    arr[3] = NULL;
    IQ(3, (arr_const_restrict)arr);
}

Test(number_with_too_many_decimals, IQ_exit, .exit_code=0)
{
    char **arr = malloc(sizeof(char *) * 5);

    arr[0] = "./205IQ";
    arr[1] = "100";
    arr[2] = "24";
    arr[3] = "90";
    arr[4] = NULL;
    IQ(4, (arr_const_restrict)arr);
}

Test(iq_between, IQ_exit, .exit_code=0)
{
    char **arr = malloc(sizeof(char *) * 6);

    arr[0] = "./205IQ";
    arr[1] = "100";
    arr[2] = "24";
    arr[3] = "90";
    arr[4] = "95";
    arr[5] = NULL;
    IQ(5, (arr_const_restrict)arr);
}

Test(negative_number_test, IQ_exit, .exit_code=84)
{
    char **arr = malloc(sizeof(char *) * 3);

    arr[0] = "./205IQ";
    arr[1] = "-1";
    arr[2] = NULL;
    IQ(2, (arr_const_restrict)arr);
}

Test(too_height_number_test, IQ_exit, .exit_code=84)
{
    char **arr = malloc(sizeof(char *) * 3);

    arr[0] = "./205IQ";
    arr[1] = "10";
    arr[2] = NULL;
    IQ(2, (arr_const_restrict)arr);
}