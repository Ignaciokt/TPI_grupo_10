#include <iostream>     // Para cin, cout, endl, string
#include <cstdlib>      // Para srand(), time(), system()
#include <ctime>        // Para time()
#include "cabeza.h" // Incluimos nuestro "mapa"

using namespace std;

int main() {
    srand(time(NULL));

    int vCodMarcas[CANT_MARCAS];
    string vNomMarcas[CANT_MARCAS];

    // Lote 2: Productos
    int vProdCod[CANT_PROD];
    string vProdNom[CANT_PROD];
    float vProdPrecioV[CANT_PROD];
    float vProdPrecioC[CANT_PROD];
    int vProdStock[CANT_PROD];
    int vProdCodMarca[CANT_PROD];

    // Lote 3: Formas de Pago
    string vPagoCod[CANT_PAGOS];
    string vPagoNom[CANT_PAGOS];
    int vPagoPorc[CANT_PAGOS];

    // --- Declaración de Vectores (Resultados para Reportes) ---

    float vReporteRecaudacionProd[CANT_PROD] = {};
    int vReporteVentasProd[CANT_PROD] = {};
    float vReporteRecaudacionPago[CANT_PAGOS] = {};
    int vReporteComprasCliente[CANT_CLIENTES] = {};
    int vReporteMarcaPago[CANT_MARCAS][CANT_PAGOS] = {};

    // --- Banderas de Control de Carga ---
    bool marcasCargadas = false;
    bool productosCargados = false;
    bool pagosCargados = false;
    bool ventasCargadas = false;

    // --- Menú Principal ---
    int opcion;
    do {
        system("cls"); // Limpia la pantalla [cite: 160]
        cout << "--- Gestion de Comercio 'TREY' ---" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Cargar lote de marcas (Actual: " << (marcasCargadas ? "OK" : "NO") << ")" << endl;
        cout << "2. Cargar lote de productos (Actual: " << (productosCargados ? "OK" : "NO") << ")" << endl;
        cout << "3. Cargar lote de formas de pago (Actual: " << (pagosCargados ? "OK" : "NO") << ")" << endl;
        cout << "4. Cargar lote de ventas (Actual: " << (ventasCargadas ? "OK" : "NO") << ")" << endl;
        cout << "5. Mostrar reportes" << endl;
        cout << "------------------------------------" << endl;
        cout << "0. Salir" << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        system("cls");

        switch(opcion) {
            case 1:
                marcasCargadas = cargarLote1_Marcas(vCodMarcas, vNomMarcas);
                break;
            case 2:
                if (marcasCargadas) {
                    productosCargados = cargarLote2_Productos(
                        vProdCod, vProdNom, vProdPrecioV, vProdPrecioC, vProdStock, vProdCodMarca,
                        vCodMarcas // Se lo pasamos para que pueda validar
                    );
                } else {
                    cout << "Error: Primero debe cargar las marcas (Opcion 1)." << endl;
                    system("pause");
                }
                break;
            case 3:
                pagosCargados = cargarLote3_Pagos(vPagoCod, vPagoNom, vPagoPorc);
                break;
            case 4:
                // Validación cruzada de los 3 lotes [cite: 3774]
                if (marcasCargadas && productosCargados && pagosCargados) {
                    ventasCargadas = cargarLote4_Ventas(
                        // Vectores de reportes (para actualizar)
                        vReporteRecaudacionProd, vReporteVentasProd, vReporteRecaudacionPago,
                        vReporteComprasCliente, vReporteMarcaPago,
                        // Vectores de datos (para consultar)
                        vProdCod, vProdPrecioV, vProdCodMarca,
                        vPagoCod, vPagoPorc, vCodMarcas
                    );
                } else {
                    cout << "Error: Faltan cargar los lotes 1, 2 o 3." << endl;
                    system("pause");
                }
                break;
            case 5:
                // Validación de que todos los lotes (incluido el 4) estén cargados [cite: 3775]
                if (marcasCargadas && productosCargados && pagosCargados && ventasCargadas) {
                    mostrarSubmenuReportes(
                        // Pasamos TODOS los vectores que los reportes puedan necesitar
                        vCodMarcas, vNomMarcas, vProdCod, vProdNom, vProdStock,
                        vPagoCod, vPagoNom, vReporteRecaudacionProd, vReporteVentasProd,
                        vReporteRecaudacionPago, vReporteComprasCliente, vReporteMarcaPago
                    );
                } else {
                    cout << "Error: Faltan cargar todos los lotes de datos (1, 2, 3 y 4)." << endl;
                    system("pause");
                }
                break;
            case 0:
                cout << "Gracias por usar el sistema." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                system("pause");
                break;
        }

    } while (opcion != 0);

    return 0;
}

