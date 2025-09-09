#ifndef LINKLIST_H
# define LINKLIST_H
# include "AMateria.hpp"

    typedef struct s_node {
        AMateria * material;
        s_node * next;
    } node;

#endif // !LINKLIST_H
