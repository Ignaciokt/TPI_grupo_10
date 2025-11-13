#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
const int cantDeMarcas = 10;
const int cantDeProductos = 20;

struct IDMarc
{
    char nom[50];
    int cod;
};



struct stckProduct
{
    float codDeP;
    char Nomb[50];
    float PrecDVen;
    float precDCompra;
    int stckDisp;
    int coDMarc;
};

void hola();
void MenuSlctOpcion(int opcion, bool &salir, IDMarc IDMarca[cantDeMarcas],stckProduct lot2[cantDeProductos ]);
int DarOpciones();
void subMenu(int opn, bool  &sali);
int opcSubMen();
void solLot1(IDMarc IDMarca[cantDeMarcas]);
void muestraLote1(IDMarc IDMarca[cantDeMarcas]);
void solLot2(stckProduct lot2[cantDeProductos ]);

#endif // HEAD_H_INCLUDED
