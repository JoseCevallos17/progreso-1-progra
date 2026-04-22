#include <stdio.h>

#include <string.h>

void AltBaj(float precios[10], int contProductos, char productos[10][30]);

int main (int argc, char *argv[]) {

   char productos [10][60];

   float precios [10];

   int opc1= 0, opc2=0;

   int contProductos=0;

   float precioTot=0;

   do

   {

       printf("\n\tMenu");

       printf("\n1.Ingresar productos");

       printf("\n2.Ingresar precios");

       printf("\n3.Precio total del inventario");

       printf("\n4.Producto mas caro y mas barato");

       printf("\n5.Precio promedio de los productos");

       printf("\n6.Buscar productos");

       printf("\n>> ");

       scanf("%d",&opc1);

       switch (opc1)

       {

       case 1:

           printf("Ingrese el nombre del producto %d:\n ", contProductos + 1);

           getchar();

           fgets(productos[contProductos],60,stdin);

           contProductos ++;

           break;

       case 2:

           int selP;

           printf("\nSeleccione el producto  del que desea registrar el precio:\n");

           for (int i = 0; i < contProductos; i++)

           {

               printf("%d.%s",i,productos[i]);

           }

            printf("\n>> ");

            scanf("%d",&selP);

            printf("\nIngrese el precio del producto: %s", productos[selP]);

            scanf("%f",&precios[selP]);

           break;

       case 3: 

           precioTot=0;

           for (int i = 0; i < contProductos; i++)

           {

               precioTot+=precios[i];

           }

           printf("\nEl precio total es de %.2f",precioTot);

           break;

       case 4:

           AltBaj( precios,  contProductos, productos);

           break;

       case 5:

           float precioProm=0;

           precioProm=precioTot/contProductos;

           printf("El precio promedio de los productos es de %.2f ",precioProm);

           break;

       default:

           break;

       }


       printf("\nDesea seleccionar otra opcion 1.Si/2.No ");

       scanf("%d",&opc2);

   } while (opc2==1);




   return 0;

}

void AltBaj(float precios[10], int contProductos, char productos[10][30]){

   float precioAlt =precios[0];

   float precioBaj=precios[0];

   int caro = 0;

   int barato = 0;

   for (int i = 0; i < contProductos; i++)

   {

      if (precios[i]>precioAlt)

      {

       precioAlt=precios[i];

       caro=i;

      }

      if (precios[i]<precioBaj)

      {

       precioBaj=precios[i];

       barato=i;

      }

   }

   printf("\nEl producto mas caro cuesta %.2f: %s", precioAlt, productos[caro]);

   printf("El producto mas barato cuesta %.2f: %s", precioBaj, productos[barato]);


}
 
