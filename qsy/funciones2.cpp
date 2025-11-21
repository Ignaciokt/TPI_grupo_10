#include "cabeza.h"
#include <iostream>     // Para cin, cout, endl
#include <cstdlib>      // Para rand(), srand(), system()
#include <ctime>        // Para time()

using namespace std;



int buscarIndice(int valor, int v[], int tam) {
for (int i = 0; i < tam; i++) {
if (v[i] == valor) {
return i;
}
}
return -1;
}

int buscarIndiceString(string valor, string v[], int tam) {
for (int i = 0; i < tam; i++) {
if (v[i] == valor) {
return i;
}
}
return -1;
}

int obtenerRandom(int min, int max) {

return rand() % (max - min + 1) + min;
}



bool cargarLote1_Marcas(int vCod[], string vNom[]) {
cout << "--- Carga Lote 1: Marcas ---" << endl;
for (int i = 0; i < CANT_MARCAS; i++) {
cout << "Marca " << i + 1 << "/" << CANT_MARCAS << ":" << endl;


cout << "Ingrese Codigo (1 a 10): ";
cin >> vCod[i];
while (vCod[i] < 1 || vCod[i] > 10) {
cout << "Error. El codigo debe ser de 1 a 10. Ingrese de nuevo: ";
cin >> vCod[i];
}

if (buscarIndice(vCod[i], vCod, i) != -1) {
cout << "Error: El codigo de marca " << vCod[i] << " ya fue ingresado." << endl;
return false;
}

cout << "Ingrese Nombre: ";
cin.ignore(); // Limpiamos el 'Enter' del 'cin' anterior
getline(cin, vNom[i]);
if (vNom[i] == "") {
cout << "Error: El nombre no puede estar vacio." << endl;
return false; // Interrumpe la carga
}
}
cout << "Lote 1 cargado con exito." << endl;
system("pause");
return true; // Carga exitosa
}


bool cargarLote2_Productos(int vProdCod[], string vProdNom[], float vProdPrecioV[],
float vProdPrecioC[], int vProdStock[], int vProdCodMarca[],
int vCodMarcas[]) {
    cout << "--- Carga Lote 2: Productos ---" << endl;
    for (int i = 0; i < CANT_PROD; i++) {
        cout << "Producto " << i + 1 << "/" << CANT_PROD << ":" << endl;

        // Código Producto
        cout << "Ingrese Codigo (3 digitos): ";
        cin >> vProdCod[i];
        while (vProdCod[i] < 100 || vProdCod[i] > 999) {
            cout << "Error: El codigo debe tener 3 digitos. Ingrese de nuevo: ";
            cin >> vProdCod[i];
        }
        if (buscarIndice(vProdCod[i], vProdCod, i) != -1) {
             cout << "Error: El codigo de producto " << vProdCod[i] << " ya fue ingresado." << endl;
            return false;
        }

        // Nombre
        cout << "Ingrese Nombre: ";
        cin.ignore();
        getline(cin, vProdNom[i]);
        if (vProdNom[i] == "") {
            cout << "Error: El nombre no puede estar vacio." << endl;
            return false;
        }

        // Precio Venta
        cout << "Ingrese Precio de Venta: ";
        cin >> vProdPrecioV[i];
        if (vProdPrecioV[i] == 0) {
            cout << "Error: El precio no puede ser cero." << endl;
            return false;
        }
        // Precio Compra
        cout << "Ingrese Precio de Compra: ";
        cin >> vProdPrecioC[i];
        if (vProdPrecioC[i] == 0) {
            cout << "Error: El precio no puede ser cero." << endl;
            return false;
        }
        // Stock
        cout << "Ingrese Stock: ";
        cin >> vProdStock[i];
        if (vProdStock[i] == 0) {
            cout << "Error: El stock no puede ser cero." << endl;
            return false;
        }

        // Código Marca (Validación cruzada)
        cout << "Ingrese Codigo de Marca (1-10): ";
        cin >> vProdCodMarca[i];

        int indiceMarca = buscarIndice(vProdCodMarca[i], vCodMarcas, CANT_MARCAS);

        if (indiceMarca == -1) {
            cout << "Error: Codigo de marca " << vProdCodMarca[i] << " no encontrado en el Lote 1." << endl;
            return false; // Interrumpe la carga
        }
    }
cout << "Lote 2 cargado con exito." << endl;
system("pause");
return true; // Carga exitosa
}


bool cargarLote3_Pagos(string vPagoCod[], string vPagoNom[], int vPagoPorc[]) {
    cout << "--- Carga Lote 3: Formas de Pago ---" << endl;
    for (int i = 0; i < CANT_PAGOS; i++) {
        cout << "Forma de Pago " << i + 1 << "/" << CANT_PAGOS << ":" << endl;

        // Código Forma de Pago
        cout << "Ingrese Codigo (EF, MP, TR, TC, CT): ";
        cin >> vPagoCod[i];

        // Validamos que sea uno de los 5 códigos válidos
        if (buscarIndiceString(vPagoCod[i], CODES_PAGO, CANT_PAGOS) == -1)
            {
            cout << "Error: Codigo no valido." << endl;
            return false;
        }
        // Validamos que no esté repetido
        if (buscarIndiceString(vPagoCod[i], vPagoCod, i) != -1) {
            cout << "Error: El codigo de pago " << vPagoCod[i] << " ya fue ingresado." << endl;
            return false;
        }

        // Nombre
        cout << "Ingrese Nombre: ";
        cin.ignore();
        getline(cin, vPagoNom[i]);
        if (vPagoNom[i] == "") {
            cout << "Error: El nombre no puede estar vacio." << endl;
            return false;
        }

        // Porcentaje
        cout << "Ingrese Porcentaje (ej: -10 para 10% desc, 15 para 15% int): ";
        cin >> vPagoPorc[i];
    }
    cout << "Lote 3 cargado con exito." << endl;
    system("pause");
    return true; // Carga exitosa
}


bool cargarLote4_Ventas(
    float vReporteRecaudacionProd[],
    int vReporteVentasProd[],
    float vReporteRecaudacionPago[],
    int vReporteComprasCliente[],
    int vReporteMarcaPago[][CANT_PAGOS],
    // Vectores de consulta (Lotes 1, 2, 3)
    int vProdCod[],
    float vProdPrecioV[],
    int vProdCodMarca[],
    std::string vPagoCod[],
    int vPagoPorc[],
    int vCodMarcas[])
{
    cout << "--- Carga Lote 4: Ventas ---" << endl;

    int nroCompra, codProducto, cantVendida, codCliente, diaVenta;
    string formaPago;
    bool huboVentas = false;

    // Patrón Centinela: Pedimos el dato clave ANTES del while
    cout << "Ingrese Nro de Compra (0 para finalizar): ";
    cin >> nroCompra;

    while (nroCompra != 0) {
        huboVentas = true; // Marcamos que se cargó al menos una venta

        cout << "Ingrese Codigo de Producto: ";
        cin >> codProducto;
        cout << "Ingrese Forma de Pago (EF, MP, TR, TC, CT): ";
        cin >> formaPago;
        cout << "Ingrese Cantidad Vendida: ";
        cin >> cantVendida;
        cout << "Ingrese Codigo de Cliente (1 a 50): ";
        cin >> codCliente;
        cout << "Ingrese Dia de la Venta (1 a 30): ";
        cin >> diaVenta;

        // --- Validación y Proceso ---
        int indiceProd = buscarIndice(codProducto, vProdCod, CANT_PROD);
        int indicePago = buscarIndiceString(formaPago, vPagoCod, CANT_PAGOS);

        // Validamos que el producto y la forma de pago existan
        if (indiceProd == -1) {
            cout << "Error: Codigo de Producto " << codProducto << " no existe. Venta no registrada." << endl;
        } else if (indicePago == -1) {
            cout << "Error: Forma de Pago '" << formaPago << "' no existe. Venta no registrada." << endl;
        } else if (vProdStock[indiceProd] < cantVendida) {
            cout << "Error: Stock insuficiente para producto " << codProducto;
            cout << " (Stock: " << vProdStock[indiceProd] << "). Venta no registrada." << endl;
        } else {
            // Si todo es válido, procesamos la venta

            // 1. Calcular precio final
            float precioBase = vProdPrecioV[indiceProd];
            int porc = vPagoPorc[indicePago];
            float totalVenta = (precioBase * cantVendida) * (1 + porc / 100.0);

            // 2. Actualizar Stock
            vProdStock[indiceProd] -= cantVendida;

            // 3. Actualizar vectores de reportes
            vReporteRecaudacionProd[indiceProd] += totalVenta;
            vReporteVentasProd[indiceProd] += cantVendida;
            vReporteRecaudacionPago[indicePago] += totalVenta;
            vReporteComprasCliente[codCliente - 1]++; // Cliente 1 va a índice 0

            // 4. Actualizar Matriz Marca/Pago (Reporte 3)
            int codMarcaDelProd = vProdCodMarca[indiceProd];
            int indiceMarca = buscarIndice(codMarcaDelProd, vCodMarcas, CANT_MARCAS);
            if (indiceMarca != -1) { // (Debería encontrarla siempre si Lote 2 está bien)
                vReporteMarcaPago[indiceMarca][indicePago] += cantVendida;
            }

            cout << "Venta registrada con exito." << endl;
        }

        // Patrón Centinela: Pedimos el dato clave AL FINAL del while
        cout << "\nIngrese Nro de Compra (0 para finalizar): ";
        cin >> nroCompra;
    }

    if (huboVentas) {
        cout << "Lote 4 procesado con exito." << endl;
    } else {
        cout << "No se ingresaron ventas." << endl;
    }
    system("pause");
    return huboVentas;
}


// --- Implementación de Funciones de Reportes ---

void mostrarSubmenuReportes(
    int vCodMarcas[], string vNomMarcas[],
    int vProdCod[], string vProdNom[], int vProdStock[],
    string vPagoCod[], string vPagoNom[],
    float vReporteRecaudacionProd[],
    int vReporteVentasProd[],
    float vReporteRecaudacionPago[],
    int vReporteComprasCliente[],
    int vReporteMarcaPago[][CANT_PAGOS])
{
    int opcion;
    do {
        system("cls");
        cout << "--- Submenu de Reportes ---" << endl;
        cout << "1. Recaudacion por producto (ordenado)" << endl;
        cout << "2. Porcentaje de ventas por forma de pago" << endl;
        cout << "3. Ventas por marca y forma de pago" << endl;
        cout << "4. Productos sin ventas" << endl;
        cout << "5. Top 10 clientes y sorteo" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        system("cls");
        switch(opcion) {
            case 1:
                reporte1_Recaudacion(vProdCod, vProdNom, vProdStock, vReporteRecaudacionProd, vReporteVentasProd);
                break;
            case 2:
                reporte2_PorcentajePagos(vPagoNom, vReporteRecaudacionPago);
                break;
            case 3:
                reporte3_VentasMarcaPago(vNomMarcas, vPagoNom, vReporteMarcaPago);
                break;
            case 4:
                reporte4_SinVentas(vProdCod, vProdNom, vReporteVentasProd);
                break;
            case 5:
                reporte5_TopClientes(vReporteComprasCliente);
                break;
        }
        if (opcion != 0) {
            system("pause");
        }
    } while (opcion != 0);
}

void reporte1_Recaudacion(
    int vProdCod[], string vProdNom[], int vProdStock[],
    float vReporteRecaudacionProd[], int vReporteVentasProd[])
{
    cout << "--- Reporte 1: Recaudacion por Producto (Ordenado por Cantidad Vendida) ---" << endl;

    // Hacemos una copia de los vectores para no perder el orden original
    // (Si ordenamos los vectores de main, el índice 'n' ya no corresponderá al producto 'n')
    // Esto es más seguro.
    int vCod[CANT_PROD];
    string vNom[CANT_PROD];
    int vStock[CANT_PROD];
    float vRec[CANT_PROD];
    int vVentas[CANT_PROD];

    for (int i = 0; i < CANT_PROD; i++) {
        vCod[i] = vProdCod[i];
        vNom[i] = vProdNom[i];
        vStock[i] = vProdStock[i];
        vRec[i] = vReporteRecaudacionProd[i];
        vVentas[i] = vReporteVentasProd[i];
    }

    // Algoritmo de Ordenamiento Burbuja (Bubble Sort)
    // Ordenamos de Mayor a Menor por Cantidad Vendida (vVentas)
    for (int i = 0; i < CANT_PROD - 1; i++) {
        for (int j = 0; j < CANT_PROD - i - 1; j++) {
            // Si el actual es MENOR que el siguiente, los muevo
            if (vVentas[j] < vVentas[j+1]) {
                // Intercambiamos TODOS los vectores en paralelo
                swapInt(vVentas[j], vVentas[j+1]);
                swapInt(vCod[j], vCod[j+1]);
                swapString(vNom[j], vNom[j+1]);
                swapInt(vStock[j], vStock[j+1]);
                swapFloat(vRec[j], vRec[j+1]);
            }
        }
    }

    // Mostrar el listado ordenado
    cout << "Cod \tNombre \t\tRecaudado \tCant. Vendida \tStock Remanente" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    for (int i = 0; i < CANT_PROD; i++) {
        if (vVentas[i] > 0) { // Mostramos solo los que se vendieron
            cout << vCod[i] << "\t" << vNom[i] << "\t\t$" << vRec[i] << "\t\t" << vVentas[i] << "\t\t" << vStock[i] << endl;
        }
    }
}

void reporte2_PorcentajePagos(string vPagoNom[], float vReporteRecaudacionPago[]) {
    cout << "--- Reporte 2: Porcentaje de Ventas por Forma de Pago ---" << endl;

    float totalRecaudado = 0;
    for (int i = 0; i < CANT_PAGOS; i++) {
        totalRecaudado += vReporteRecaudacionPago[i];
    }

    if (totalRecaudado == 0) {
        cout << "No hay ventas para calcular porcentajes." << endl;
        return;
    }

    cout << "Forma de Pago \t\t Porcentaje" << endl;
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < CANT_PAGOS; i++) {
        float porcentaje = (vReporteRecaudacionPago[i] / totalRecaudado) * 100;
        cout << vPagoNom[i] << " \t\t " << porcentaje << "%" << endl;
    }
}

void reporte3_VentasMarcaPago(string vNomMarcas[], string vPagoNom[], int vReporteMarcaPago[][CANT_PAGOS]) {
    cout << "--- Reporte 3: Ventas (en unidades) por Marca y Forma de Pago ---" << endl;

    // Encabezados (Formas de Pago)
    cout << "\t\t";
    for (int j = 0; j < CANT_PAGOS; j++) {
        cout << vPagoNom[j] << "\t";
    }
    cout << endl;
    cout << "------------------------------------------------------------------------" << endl;

    // Filas (Marcas) y Datos
    for (int i = 0; i < CANT_MARCAS; i++) {
        cout << vNomMarcas[i] << "\t\t"; // Nombre de la Marca
        for (int j = 0; j < CANT_PAGOS; j++) {
            cout << vReporteMarcaPago[i][j] << "\t\t"; // Cantidad vendida
        }
        cout << endl;
    }
}

void reporte4_SinVentas(int vProdCod[], string vProdNom[], int vReporteVentasProd[]) {
    cout << "--- Reporte 4: Productos sin Ventas ---" << endl;
    bool hubo = false;

    cout << "Cod \tNombre" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < CANT_PROD; i++) {
        if (vReporteVentasProd[i] == 0) {
            cout << vProdCod[i] << "\t" << vProdNom[i] << endl;
            hubo = true;
        }
    }

    if (!hubo) {
        cout << "Todos los productos registraron ventas." << endl;
    }
}

void reporte5_TopClientes(int vReporteComprasCliente[]) {
    cout << "--- Reporte 5: Top 10 Clientes y Sorteo ---" << endl;

    // 1. Crear vectores de trabajo para ordenar
    int vCompras[CANT_CLIENTES];
    int vCodCli[CANT_CLIENTES];

    for (int i = 0; i < CANT_CLIENTES; i++) {
        vCompras[i] = vReporteComprasCliente[i];
        vCodCli[i] = i + 1; // Cliente 1, 2, 3...
    }

    // 2. Ordenar por cantidad de compras (Burbuja)
    for (int i = 0; i < CANT_CLIENTES - 1; i++) {
        for (int j = 0; j < CANT_CLIENTES - i - 1; j++) {
            if (vCompras[j] < vCompras[j+1]) { // Ordena de Mayor a Menor
                swapInt(vCompras[j], vCompras[j+1]);
                swapInt(vCodCli[j], vCodCli[j+1]);
            }
        }
    }

    // 3. Mostrar Top 10
    cout << "Top 10 Clientes (por cantidad de compras):" << endl;
    cout << "Puesto \tCliente # \tCompras" << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < 10; i++) {
        if (vCompras[i] > 0) { // Solo mostrar si compraron algo
            cout << i + 1 << " \t" << vCodCli[i] << " \t\t" << vCompras[i] << endl;
        }
    }

    // 4. Sorteo (Solo si hay al menos 3 clientes en el top 10)
    if (vCompras[2] == 0) { // Si el 3er puesto tiene 0 compras...
        cout << "\nNo hay suficientes clientes en el Top 10 para un sorteo." << endl;
        return;
    }

    cout << "\n--- Sorteo de Cupones ---" << endl;

    // Generar 3 índices aleatorios ÚNICOS entre 0 y 9
    int g1, g2, g3;

    g1 = obtenerRandom(0, 9);

    do {
        g2 = obtenerRandom(0, 9);
    } while (g2 == g1); // Repetir si es igual al primero

    do {
        g3 = obtenerRandom(0, 9);
    } while (g3 == g1 || g3 == g2); // Repetir si es igual a alguno de los anteriores

    cout << "Los 3 clientes ganadores del sorteo son:" << endl;
    cout << "1. Cliente #" << vCodCli[g1] << " (con " << vCompras[g1] << " compras)" << endl;
    cout << "2. Cliente #" << vCodCli[g2] << " (con " << vCompras[g2] << " compras)" << endl;
    cout << "3. Cliente #" << vCodCli[g3] << " (con " << vCompras[g3] << " compras)" << endl;
}


// --- Implementación de Funciones de Ordenamiento (Swap) ---

void swapInt(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}
void swapFloat(float &a, float &b) {
    float aux = a;
    a = b;
    b = aux;
}
void swapString(string &a, string &b) {
    string aux = a;
    a = b;
    b = aux;
}
