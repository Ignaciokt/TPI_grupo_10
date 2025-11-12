#include <iostream>

using namespace std;

#include "head.h"




int main()
{
    int opcion;
    bool salir = false ;
    while (salir !=true)
    {
        opcion = DarOpciones();
        MenuSlctOpcion(opcion, salir);
    }
    return 0;
}
