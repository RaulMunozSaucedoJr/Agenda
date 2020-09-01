//Programa: Agenda.

//Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Funciones utilizadas en este programa
strcpy: Funcion incluida dentro del archivo /biblioteca string.h la cual copia la cadena apuntada por origen en la cadena apuntada por destino.
struct: Palabra reservada que define una estructura. 
int: Representa n�meros enteros con o sin signo, que estar�n compuestos por los d�gitos del 0 al 9, pudiendo ser precedidos por los signos + o -.
void: Se utiliza para decir que dicha funcion no regresa nada.
fflush: Funcion para limpiar el buffer de entrada del teclado.
aux: auxiliar es aquella variable que servir� para calculos intermedios o de ayuda.
gets: La funci�n gets() recibe como �nico argumento la variable en la que debe almacenarse una entrada de usuario que va a ser considerada como una cadena de caracteres.
system("pause"); Sirve para detener el programa o pausarlo hasta que no se presione una tecla.
system("cls");Funcion para limpiar la pantalla*/


//Se utiliza struct para definir tipos de datos personalizados o utilizados en el programa.

struct agenda { //Defnimos struct agenda
	char Nombre[40]; //Declaramos la variable Nombre con su espacio de memoria reservado
	int Telefono_Fijo; //Declaramos la variable Telefono_Fijo como int, ya que solo seran numeros enteros los que se utilzaran para esta variable.
	int Telefono_Movil; //Declaramos la variable Telefono_Movil como int, ya que solo seran numeros enteros los que se utilzaran para esta variable.
	char Direccion[40]; //Declaramos la variable Direccion
	char Email[30]; //Declaramos la variable Email 
	char Grupo[20]; //Declaramos la variable Grupo. Esta se utilizara para diferenciar en que grupo esta cada uno de nuestros contactos.
} control[130];
int cont=0; //Contador inicializa en 0

void Agregar(); //Funcion Agregar
void Buscar(); //Funcion Buscar
void Contactos(); //Funcion Contactos

main(){ //Inicia el programa
	int opc; //Declaracmos opc, como Opcion

	do{ //Inicia el do
		system("cls"); //Funcion para limpiar la pantalla

		printf("MENU\n"); //Se imprime en pantalla titulo con nombre MENU
		printf("1.Agregar\n"); //Se imprime la opcion Agregar de nuestro Menu
		printf("2.Buscar\n"); //Se imprime la opcion Buscar de nuestro Menu
		printf("3.Ver todos los contactos\n"); //Se imprime la opcion de Ver todos los Contactos de nuestro Menu
		printf("4.Salir\n"); //Se imprime en pantalla la opcion salir de nuestro Menu.

		scanf("%d", &opc); 

		//Inicia el switch para elegir la accion que deseamos realizar.
		switch(opc){ 
		case 1: //Inicia Case 1, que es Agregar 
			Agregar();
			system("pause"); 
			break;

		case 2: //Inicia Case 2, que es Buscar
			Buscar();
			system("pause");
			break;

		case 3:
			Contactos(); //Inicia Case 3, que es Contactos
			system("pause");
			break;
		}
	}while(opc!=4); //Opcion  es igual o diferente de 4 salimos

	return 0;
} //Cierra el Main

//Declaramos la opcion Agregar
void Agregar(){ //Abre void
	system("cls"); //Funcion para limpiar pantalla

	fflush(stdin); //Funcion para limpiar el buffer de entrada del teclado
	printf("\nNombre de contacto:", (cont+1)); //Se imprime en pantalla la accion de introducir Nombre de Contacto
	gets(control[cont].Nombre);

	fflush(stdin);
	printf("\nTelefonoFijo:"); //Se imprime en pantalla la accion de introducir Telefono Fijo del Contacto
	scanf("%d", &control[cont].Telefono_Fijo);

	fflush(stdin);
	printf("\nTelefonoMovil:"); //Se imprime en pantalla la accion de introducir Telefono Movil del Contacto
	scanf("%d", &control[cont].Telefono_Movil);

	fflush(stdin);
	printf("\nDireccion:"); //Se imprime en pantalla la accion de introducir la Direccion del Contacto
	gets(control[cont].Direccion);

	fflush(stdin);
	printf("\nE-mail:"); //Se imprime en pantalla la accion de introducir Email del Contacto.
	gets(control[cont].Email);

	fflush(stdin);
	printf("\nGrupo:"); //Se imprime en pantalla la accion de introducir el Grupo al que pertenece nuestro Contacto
	gets(control[cont].Grupo);

	cont++;

} //Cierra void

//Funcion Buscar Contacto
void Buscar(){ //Abre void
	char busca[30]; //Numero maximo de caracteres con los que podemos buscar a un contacto en especifico.
	int i;

	system("cls"); //Funcion para limpiar pantalla.

	fflush(stdin);
	printf("\nBuscar contacto\nIngrese el nombre del contacto:"); //Se imprime en pantalla la accion de Buscar Contacto y a la vez nos da la opcion de Buscar por Nombre a nuestro Contacto.
	gets(busca);

	for(i=0;i<cont;i++){ //Abre for comparativo
		if(strcmpi(busca,control[i].Nombre)==0){ //Abre if
			printf("\nNombre: %s\n", control[i].Nombre); //Se muestra en pantalla el-los nombre(s) de nuestro Contacto
			printf("\nTelefonoFijo: %d\n", control[i].Telefono_Fijo); //Se muestra en pantalla el Telefono fijo de nuestro Contacto
			printf("\nTelefonoMovil: %d\n", control[i].Telefono_Movil); //Se muestra en pantalla el Telefono Movil de nuestro Contacto
			printf("\nDireccion %s\n", control[i].Direccion); //Se muestra en pantalla la Direccion de nuestro Contacto.
			printf("\nE-mail: %s\n", control[i].Email); //Se muestra en pantalla el Email de nuestro Contacto
			printf("\nGrupo: %s\n", control[i].Grupo); //Se muestra en pantalla el Grupo al que pertenece nuestro Contacto
		} //cierra if
	} //Cierra for

} //Cierra void

void Contactos(){ //Abre void contactos
	int aux, i, j;
	char auxc[50];

	system("cls"); //Funcion para limpiar pantalla.

//Fors para comprar si los caracteres de Nombre, Telefono Fijo, Telefono Movil, Direccion, Email y Grupo son dierentes de 0. Si es asi, entonces aumentan.
	for(i=0;i<cont-1;i++){
		for(j=0;j<cont-1-i;j++){
			if(strcmp(control[j].Nombre,control[j+1].Nombre)>0){
				
				strcpy(auxc,control[j].Nombre);
				strcpy(control[j].Nombre,control[j+1].Nombre);
				strcpy(control[j+1].Nombre,auxc);

				aux = control[j].Telefono_Fijo;
				control[j].Telefono_Fijo = control[j+1].Telefono_Fijo;
				control[j+1].Telefono_Fijo = aux;

				aux = control[j].Telefono_Movil;
				control[j].Telefono_Movil = control[j+1].Telefono_Movil;
				control[j+1].Telefono_Movil = aux;

				strcpy(auxc,control[j].Direccion);
				strcpy(control[j].Direccion,control[j+1].Direccion);
				strcpy(control[j+1].Direccion,auxc);

				strcpy(auxc,control[j].Email);
				strcpy(control[j].Email,control[j+1].Email);
				strcpy(control[j+1].Email,auxc);

				strcpy(auxc,control[j].Grupo);
				strcpy(control[j].Grupo,control[j+1].Grupo);
				strcpy(control[j+1].Grupo,auxc);
			}
		}
	}

	printf("\nAgenda.\n"); //Se imprime en pantalla en dado caso que no introduzcamos nada en ninguna de las opciones mencionadas anteriormente

	for(i=0;i<cont;i++){ //Abre for
		printf("\n%d.Nombre: %s\n",(i+1), control[i].Nombre);
		printf("Tel\202fono fijo: %d\n", control[i].Telefono_Fijo);
		printf("Tel\202fono m\242vil: %d\n", control[i].Telefono_Movil);
		printf("Direcci\242n: %s\n", control[i].Direccion);
		printf("E-mail: %s\n", control[i].Email);
		printf("Grupo: %s\n", control[i].Grupo);
	} //Cierra for

} //Cierra void contactos
