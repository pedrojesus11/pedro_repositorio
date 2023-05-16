#include <stdio.h>

int main() {
    // Variables para el control de ventas
    float precioBeisbol = 50.0;
    float precioTenis = 80.0;
    int numMayasBeisbol = 0;
    int numMayasTenis = 0;
    int totalClientesDescuento = 0;
    float totalDescuentos = 0.0;
    float totalCompras = 0.0;
    float ingresoTotal = 0.0;

    // Entrada de datos
    int numClientes;
    printf("Ingrese el n�mero de clientes: ");
    scanf("%d", &numClientes);

    for (int i = 1; i <= numClientes; i++) {
        int aniosBeisbol, aniosTenis;
        char tipoCompra;
        printf("\nCliente %d\n", i);
        printf("�Qu� tipo de malla deportiva desea comprar? (B para b�isbol, T para tenis): ");
        scanf(" %c", &tipoCompra);

        if (tipoCompra == 'B' || tipoCompra == 'b') {
            printf("�Hace cu�ntos a�os compra mayas para b�isbol? ");
            scanf("%d", &aniosBeisbol);

            // C�lculo del precio
            float precioCompra = precioBeisbol;
            if (aniosBeisbol > 5 && aniosBeisbol <= 15) {
                precioCompra *= 0.92; // Descuento del 8%
                totalClientesDescuento++;
                totalDescuentos += 0.08 * precioBeisbol;
            } else if (aniosBeisbol > 15) {
                precioCompra *= 0.7; // Descuento del 30%
                totalClientesDescuento++;
                totalDescuentos += 0.3 * precioBeisbol;
            }

            // Actualizaci�n de variables de control de ventas
            numMayasBeisbol++;
            totalCompras += precioCompra;
            ingresoTotal += precioCompra;
        } else if (tipoCompra == 'T' || tipoCompra == 't') {
            printf("�Hace cu�ntos a�os compra mayas para tenis? ");
            scanf("%d", &aniosTenis);

            // C�lculo del precio
            float precioCompra = precioTenis;
            if (aniosTenis > 0) {
                precioCompra *= 0.94; // Descuento del 6%
                totalClientesDescuento++;
                totalDescuentos += 0.06 * precioTenis;
            }

            // Actualizaci�n de variables de control de ventas
            numMayasTenis++;
            totalCompras += precioCompra;
            ingresoTotal += precioCompra;
        }
    }

    // Salida de datos
    printf("\nResumen de ventas:\n");
    printf("- Cantidad de mayas para b�isbol vendidas: %d\n", numMayasBeisbol);
    printf("- Cantidad de mayas para tenis vendidas: %d\n", numMayasTenis);
    printf("- Ingreso total de la empresa: %.2f$\n", ingresoTotal);
    printf("- Total de clientes que obtuvieron descuento: %d\n", totalClientesDescuento);
    printf("- Total de descuentos: %.2f$\n", totalDescuentos);
    printf("- Total de compras: %.2f$\n");
    
    return 0;
    
}
