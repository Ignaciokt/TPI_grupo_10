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
    //esto es un while que mantiene el archivo abierto hasta que la bandera salir seea 'true'.
    }

    return 0;
}
