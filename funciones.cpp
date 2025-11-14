#include <iostream>
#include "head.h"

using namespace std;

void hola()
{
    cout<<"hola"<<"\n";
//el void hola es simplemente una funcion de prueba
}


void MenuSlctOpcion(int opcion, bool &salir, IDMarc IDMarca[cantDeMarcas],stckProduct lot2[cantDeProductos ])
{
//menu para seleccionar una opcion 1. Cargar lote de marcas


    switch(opcion)
    {
    case 1:
        solLot1(IDMarca);
        muestraLote1(IDMarca);

        //funcion
        break;

    case 2:
        solLot2(lot2);
        //funcion
        break;

    case 3:
    {
        int opn;
        bool sali = false ;
        while (sali !=true)
        {
            opn = opcSubMen();
            subMenu(opn,sali);
        }
    }
        //funcion
    break;
    case 4:
        hola();
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
    cout<< "1.carga de marcas ";
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


void solLot1(IDMarc IDMarca[cantDeMarcas])
{
//solicitud del lote 1 marcas
    cin.ignore();
    for (int i=0; i < cantDeMarcas; i++)
    {
        cout << "ingrese el nombre de la de marca: " << "\n";
        cin.getline(IDMarca[i].nom, 50);
        //cin >>IDMarca[i].nom, 50;
        cout << "ingrese el codigo de marca" << "\n";
        cin >> IDMarca[i].cod;
        cin.ignore();

    }
}


void muestraLote1(IDMarc IDMarca[cantDeMarcas])
{
    //muestra el lote de marcas
    for (int i = 0; i < cantDeMarcas; i++)
    {
        cout << "Marca: " << IDMarca[i].nom << " ||| Codigo: " << IDMarca[i].cod << "\n";
    }
}


void solLot2(stckProduct lot2[cantDeProductos ])
{
//solicitud del lote de productos
    cin.ignore();
    for (int i=0; i < cantDeProductos ; i++)
    {
        cout << "ingrese el codigo del producto: " << "\n";
        cin >> lot2[i].codDeP;
        cout << "ingrese el nombre del producto: " << "\n";
        cin.getline(lot2[i].Nomb, 50);
        //cin >>lot2[i].Nomb, 50;
        cout << "ingrese el precio de venta del producto: " << "\n";
        cin >> lot2[i].PrecDVen;
        cout << "ingrese el precio de compra del producto: " << "\n";
        cin >> lot2[i].precDCompra;
        cout << "ingrese el stock del producto" << "\n";
        cin >> lot2[i].stckDisp;
        cout << "ingrese el codigo de marca" << "\n";
        cin >> lot2[i].coDMarc;
        cin.ignore();

    }
}



/*void solLot3(forDPag lot3, int suEs )
{
//solicitud del lote 1 marcas
    cin.ignore();
    for (int i=0; i < cantDeMarcas; i++)
    {
        cout << "seleccione su forma de pago:EF: Efectivo \n ● MP: Mercado Pago \n ● TR: Transferencia \n ● TC: Tarjeta de Crédito \n ● CT: Criptomoneda " << "\n";
        cin.getline(lot3[i].codDFoPago, 2);
        if( !=EF, MP, TR, TC, CT)
        {
            cout << "ingrese una forma de pago correcto" << "\n";
        }
        //cin >>lot3[i].codDFoPago, 2;
        selNomDPag( lot3 );
        cout << "ingrese su saldo" << "\n";
        lot3[i].descoInteres = suES;

        cin.ignore();



    }
}

int suES (){
    int saldo;
    cin >> saldo;
 if(saldo < 0){
    saldo = negativo
 }
else{
    saldo = positivo
}
}

void selNomDPag(forDPag lot3 )
{
    if( lot3[i].codDFoPago = EF)
    {
        lot3[i].nomDFoPago = "Efectivo"
    }
    if( lot3[i].codDFoPago = TR)
    {
        lot3[i].nomDFoPago = "Transferencia"
    }
    if (lot3[i].codDFoPago = MP )
    {
        lot3[i].nomDFoPago = "Mercado Pago"
    }
    if else( lot3[i].codDFoPago = TC)
        {
            lot3[i].nomDFoPago = "Tarjeta de credito"
        }
    else( lot3[i].codDFoPago = CP)
    {
        lot3[i].nomDFoPago = "Criptomoneda "
    }
}

int porcentLot3(forDPag lot3 ){
    cout << "ingrese el codigo de marca" << "\n";
        cin >> lot3[i].descoInteres;

}
*/
