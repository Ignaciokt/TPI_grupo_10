#include <iostream>
#include "head.h"

using namespace std;

void hola()
{
    cout<<"hola"<<"\n";
}
//el void hola es simplemente una funcion de prueba

void MenuSlctOpcion(int opcion, bool &salir)
{
//menu para seleccionar una opcion 1. Cargar lote de marcas


    switch(opcion)
    {
    case 1:
        hola();
        //funcion
        break;

    case 2:
        //funcion
        break;

    case 3:
        {
        int opn;
        bool sali = false ;
        while (sali !=true){
        opn = opcSubMen();
        subMenu(opn,sali);
        }
        }
        //funcion
        break;
    case 4:
        //funcion
        break;
    case 5:
        //funcion
        break;
    case 0:
        salir = true;
        break;
    }
}

void subMenu(int opn, bool  &salir)
{
    switch(opn)
    {
    case 1:
        hola();
        //funcion
        break;

    case 2:
        //funcion
        break;

    case 3:
        //funcion
        break;
    case 4:
        //funcion
        break;
    case 5:
        //funcion
        break;
    case 0:
        salir = true;
        break;
    }
    //el void submenu es el sub menu que se utiliza en uno de los puntos para acceder a la lista de registros
}

int DarOpciones()
{
    //se encargar de proporcionar opciones y devolver la selecccionada
    int opcion;
    cout<< "1.opcion ";
    cout<< "||||| ";
    cout<< "2. Cargar lote de productos "<<"\n";
    cout<< "3. Cargar lote de formas de pago ";
    cout<< "||||| ";
    cout<< "4. Cargar lote de ventas "<<"\n";
    cout<< "5. Mostrar reportes "<<"\n";
    cout<< "0.salir "<<"\n";
    cin>>opcion;
    return opcion;
//este es el mensaje incial que damos para que el usuario elija la opcion
}

int opcSubMen()
{
    //se encargar de proporcionar opciones y devolver la selecccionada
    int opn;
    cout<< "1. Recaudación por producto "<<"\n";
    cout<< "2. Porcentaje de ventas por forma de pago "<<"\n";
    cout<< "3. Ventas por marca y forma de pago "<<"\n";
    cout<< "4. Cargar lote de ventas "<<"\n";
    cout<< "5. Mostrar reportes "<<"\n";
    cout<< "0.salir "<<"\n";
    cin>>opn;
    return opn;
//estes es un menu en progreso para acceder a los registros logrados
}

