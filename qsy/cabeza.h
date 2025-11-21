#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// Para que el .h reconozca el tipo de dato 'string'
#include <iostream>

// --- Constantes Globales ---
// Las declaramos aquí para que main.cpp y funciones.cpp las conozcan
const int CANT_MARCAS = 10;
const int CANT_PROD = 20;
const int CANT_PAGOS = 5;
const int CANT_CLIENTES = 50;

// Códigos de pago válidos
const std::string CODES_PAGO[CANT_PAGOS] = {"EF", "MP", "TR", "TC", "CT"};

// --- Prototipos de Funciones Auxiliares ---

/**
 * @brief Busca un valor entero en un vector de enteros.
 * @param valor El número a buscar.
 * @param v El vector donde buscar.
 * @param tam El tamaño del vector.
 * @return El índice (0 a tam-1) si lo encuentra. -1 si no lo encuentra.
*/
int buscarIndice(int valor, int v[], int tam);

/**
 * @brief Busca un valor string en un vector de strings.
 * @param valor El texto a buscar.
 * @param v El vector donde buscar.
 * @param tam El tamaño del vector.
 * @return El índice (0 a tam-1) si lo encuentra. -1 si no lo encuentra.
*/
int buscarIndiceString(std::string valor, std::string v[], int tam);

/**
 * @brief Genera un número entero aleatorio dentro de un rango.
 * @param min El valor mínimo (inclusive).
 * @param max El valor máximo (inclusive).
 * @return Un número aleatorio entre min y max.
*/
int obtenerRandom(int min, int max);

// --- Prototipos de Funciones de Lotes ---

/**
 * @brief Carga el Lote 1 de 10 Marcas.
 * @param vCod Vector de códigos de marca (se carga aquí).
 * @param vNom Vector de nombres de marca (se carga aquí).
 * @return true si la carga fue exitosa, false si se interrumpió por error.
*/
bool cargarLote1_Marcas(int vCod[], std::string vNom[]);

/**
 * @brief Carga el Lote 2 de 20 Productos.
 * @param vProdCod Vector de códigos de producto (se carga aquí).
 * @param vProdNom Vector de nombres de producto (se carga aquí).
 * @param vProdPrecioV Vector de precios de venta (se carga aquí).
 * @param vProdPrecioC Vector de precios de compra (se carga aquí).
 * @param vProdStock Vector de stock (se carga aquí).
 * @param vProdCodMarca Vector de códigos de marca del producto (se carga aquí).
 * @param vCodMarcas Vector de códigos de marca (Lote 1) para validación.
 * @return true si la carga fue exitosa, false si se interrumpió por error.
*/
bool cargarLote2_Productos(int vProdCod[], std::string vProdNom[], float vProdPrecioV[],
                            float vProdPrecioC[], int vProdStock[], int vProdCodMarca[],
                            int vCodMarcas[]);

/**
 * @brief Carga el Lote 3 de 5 Formas de Pago.
 * @param vPagoCod Vector de códigos de pago (se carga aquí).
 * @param vPagoNom Vector de nombres de pago (se carga aquí).
 * @param vPagoPorc Vector de porcentajes (se carga aquí).
 * @return true si la carga fue exitosa, false si se interrumpió por error.
*/
bool cargarLote3_Pagos(std::string vPagoCod[], std::string vPagoNom[], int vPagoPorc[]);

/**
 * @brief Carga el Lote 4 de Ventas (Centinela).
 * @param vReporteRecaudacionProd Vector de recaudación por producto (se actualiza).
 * @param vReporteVentasProd Vector de ventas por producto (se actualiza).
 * @param vReporteRecaudacionPago Vector de recaudación por pago (se actualiza).
 * @param vReporteComprasCliente Vector de compras por cliente (se actualiza).
 * @param vReporteMarcaPago Matriz de ventas Marca vs Pago (se actualiza).
 * @param vProdCod Vector de códigos de producto (Lote 2) para consulta.
 * @param vProdPrecioV Vector de precios de venta (Lote 2) para consulta.
 * @param vProdCodMarca Vector de códigos de marca del producto (Lote 2) para consulta.
 * @param vPagoCod Vector de códigos de pago (Lote 3) para consulta.
 * @param vPagoPorc Vector de porcentajes (Lote 3) para consulta.
 * @param vCodMarcas Vector de códigos de marca (Lote 1) para consulta.
 * @return true si se cargó al menos una venta, false si no.
*/
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
    int vCodMarcas[]
);


// --- Prototipos de Funciones de Reportes ---

/**
 * @brief Muestra el submenú de reportes.
*/
void mostrarSubmenuReportes(
    // Vectores de datos
    int vCodMarcas[], std::string vNomMarcas[],
    int vProdCod[], std::string vProdNom[], int vProdStock[],
    std::string vPagoCod[], std::string vPagoNom[],
    // Vectores de resultados
    float vReporteRecaudacionProd[],
    int vReporteVentasProd[],
    float vReporteRecaudacionPago[],
    int vReporteComprasCliente[],
    int vReporteMarcaPago[][CANT_PAGOS]
);

/**
 * @brief Reporte 1: Recaudación por producto, ordenado.
*/
void reporte1_Recaudacion(
    int vProdCod[], std::string vProdNom[], int vProdStock[],
    float vReporteRecaudacionProd[], int vReporteVentasProd[]
);

/**
 * @brief Reporte 2: Porcentaje por forma de pago.
*/
void reporte2_PorcentajePagos(std::string vPagoNom[], float vReporteRecaudacionPago[]);

/**
 * @brief Reporte 3: Ventas por marca y forma de pago.
*/
void reporte3_VentasMarcaPago(std::string vNomMarcas[], std::string vPagoNom[], int vReporteMarcaPago[][CANT_PAGOS]);

/**
 * @brief Reporte 4: Productos sin ventas.
*/
void reporte4_SinVentas(int vProdCod[], std::string vProdNom[], int vReporteVentasProd[]);

/**
 * @brief Reporte 5: Top 10 clientes y sorteo.
*/
void reporte5_TopClientes(int vReporteComprasCliente[]);


// --- Prototipos de Funciones de Ordenamiento (Swap) ---

void swapInt(int &a, int &b);
void swapFloat(float &a, float &b);
void swapString(std::string &a, std::string &b);


#endif // FUNCIONES_H_INCLUDED
