#include "pipex.h"
void failed(void *msg)
{
    ft_putstr_fd(msg, 2);
    exit(EXIT_FAILURE);
}
void error(void)
{
    ft_putstr_fd("error", 2);
}