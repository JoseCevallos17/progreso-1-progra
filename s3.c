#include <stdio.h>
void notaAsig (float cal[5][3][3], int materia, int contAlumnos);
void aprobado (float cal[5][3][3], int selAsig, int contAlumnos);
int main (int argc, char *argv[]) {

    float cal[5][3][3]={0};
    char nombres[5][20];
    char asignaturas[3][20] = {"Matematicas",
                               "Fisica",
                               "Quimica"};
    int opc=0, opc2=0;

    float promedios[5][3];
    float promAsig[3];

    int contAlumnos=0;
    int Alumno=0;

    do{
        printf("Seleccione una opcion\n");
        printf("1.Registrar alumno\n");
        printf("2.Registrar calificaciones\n");
        printf("3.Promedio por alumno\n");
        printf("4.Promedio por asignatura\n");
        printf("5.Calificacion mas alta y baja por estudiante\n");
        printf("6.Calificacion mas alta y baja por asignatura\n");
        printf("7.Estudiantes aprobados y reprobados por asginatura\n");
        printf(">> ");
        scanf("%d",&opc);

        switch (opc)
        {
            case 1:
                printf("Ingrese el nombre del alumno %d\n",contAlumnos+1);
                getchar();
                fgets(nombres[contAlumnos],20,stdin);
                contAlumnos++;
                break;
            case 2:
                int selA = 0;
                printf("Seleccione el alumno del que desee regitrar las calificaciones:\n");
                for (int i = 0; i < contAlumnos; i++)
                {
                    printf("%d.%s",i,nombres[i]);
                }
                printf(">> ");
                scanf("%d",&selA);

                for (int i = 0; i < 3; i++)
                {
                    printf("Ingrese las notas de la materia: %s\n",asignaturas[i]);
                    for (int j = 0; j < 3; j++)
                    {
                        printf("Nota %d: ",j+1);
                        scanf("%f",&cal[selA][i][j]);
                        promedios[selA][i]+=cal[selA][i][j];
                    }
                    promedios[selA][i]/=3;
                }
                break;
            case 3:
                printf("--------------Calificaciones----------------\n");
                printf("%s\t\t%s\t\t%s\t\tNombre\n",asignaturas[0],asignaturas[1],asignaturas[2]);

                for (int i = 0; i < contAlumnos; i++)
                {
                    printf("%.2f\t\t%.2f\t\t%.2f\t\t%s",promedios[i][0],
                                                        promedios[i][1],
                                                        promedios[i][2],
                                                        nombres[i]);
                }

                break;
            case 4:
                float promediosAsig[3];
                printf("\tPromedio\n");
                    
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < contAlumnos; j++) {
                        promAsig[i] += promedios[j][i];
                    }
                    promAsig[i] /= contAlumnos;
                    printf("Promedio de %s: %.2f\n", asignaturas[i], promAsig[i]);
                }
                break;

            case 5:
                int selAlu = 0;
                printf("Seleccione el alumno del que desee ver las nota mas alta y la mas baja:\n");
                for (int i = 0; i < contAlumnos; i++)
                {
                    printf("%d.%s", i, nombres[i]);
                }
                printf(">> ");
                scanf("%d", &selAlu);

                float notaAlt = cal[selAlu][0][0];
                float notaBaj = cal[selAlu][0][0];

                for (int j = 0; j < 3; j++)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        if (cal[selAlu][j][i] > notaAlt)
                        {
                            notaAlt = cal[selAlu][j][i];
                        }
                        if (cal[selAlu][j][i] < notaBaj)
                        {
                            notaBaj = cal[selAlu][j][i];
                        }
                    }
                }
                for (int i = 0; i < contAlumnos; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if ((cal[selAlu][i][j]) > (notaAlt))
                        {
                            notaAlt = cal[selAlu][i][j];
                        }
                        if ((cal[selAlu][i][j]) < (notaBaj))
                        {
                            notaBaj = cal[selAlu][i][j];
                        }
                    }
                }
                printf("Nota mas alta: %.2f\n", notaAlt);
                printf("Nota mas baja: %.2f\n", notaBaj);

                break;

            case 6:
                int selM = 0;
                printf("Seleccione la materia de la que desee ver las nota mas alta y la mas baja:\n");
                for (int i = 0; i < 3; i++)
                {
                    printf("\n%d.%s",i,asignaturas[i]);
                }
                printf("\n>> ");
                scanf("%d",&selM);
                notaAsig(cal, selM, contAlumnos);




            break;

            case 7:
                int selAsig = 0;
                printf("Seleccione la materia de la que desee ver los estudiantes reprobados y aprobados:\n");
                for (int i = 0; i < 3; i++)
                {
                    printf("\n%d.%s",i,asignaturas[i]);
                }
                printf("\n>> ");
                scanf("%d",&selAsig);
                aprobado (cal, selAsig, contAlumnos);

                break;
            
            default:
                break;
        }
        
        printf("Desea seleccionar otra opcion 1.Si/2.No: ");
        scanf("%d",&opc2);
    }while(opc2==1);
    





    return 0;
}

void notaAsig (float cal[5][3][3], int selM,int contAlumnos) {
float notAlt = cal[0][selM][0];
float notBaj = cal[0][selM][0];

for (int i = 0; i < contAlumnos; i++){
    for (int j = 0; j < 3; j++){
        if ((cal[i][selM][j]) > (notAlt)){
            notAlt=cal[i][selM][j];
        }
        if ((cal[i][selM][j]) < (notBaj)){
            notBaj=cal[i][selM][j];
        }
    }
}
    printf("Nota mas alta: %.2f\n", notAlt);
    printf("Nota mas baja: %.2f\n", notBaj);
}

void aprobado (float cal[5][3][3], int selAsig, int contAlumnos){

int aprobados=0, reprobados=0;
float total=0; 
float promedio[3];

for (int i = 0; i < contAlumnos; i++)

{
    total= 0;
    for (int j = 0; j < 3; j++)
    {
        total+=cal[i][selAsig][j];
    }

    
   promedio[selAsig]=total/3;
   
   if (promedio[selAsig]>=6){
    aprobados++;
   }else{
    reprobados++;
   }
   
}
    printf("\tEstudiantes aprobados\n");
    printf("Aprobados: %d\n", aprobados);
    printf("Reprobados: %d\n", reprobados);
    

}
