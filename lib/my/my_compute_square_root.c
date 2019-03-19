/*
** EPITECH PROJECT, 2018
** task05
** File description:
** return the square root of a number
*/

int my_compute_square_root(int nb)
{
    int i = 1;

    if (nb < 0) {
        return (0);
    }
    while (i <= nb / 2 && i * i != nb) {
        i++;
    }
    if (i * i != nb) {
        return (0);
    }
    return (i);
}
