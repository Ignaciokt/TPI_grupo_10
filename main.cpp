#include <iostream>

using namespace std;

#include "head.h"




int main()
{
    int opcion;
    bool salir = false ;
    IDMarc IDMarca[cantDeMarcas];
    //con el tipo de dato struc se genera un vector con una variable constante
    stckProduct lot2[cantDeProductos];


    while (salir !=true)
    {
        opcion = DarOpciones();
        MenuSlctOpcion(opcion, salir, IDMarca, lot2);
        //esto es un while que mantiene el archivo abierto hasta que la bandera salir seea 'true'.
    }

    return 0;
}
