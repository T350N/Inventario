#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<iostream>
#include<ctime>
#include<vector>

using namespace std;
void gotoxy (short x, short y){
	  HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
struct Artic
{
	int cod;
	char descrip[20];
	float precio;
	int	cantidad;
};
void menu_principal();
//Opciones del menú
void Manto_artic();
void ventas();
void Reportes();
//funciones de Manto_artic
void consultar();
void Agregar();
void modificar();
void borrar();
//funciones de ventas
void factura();

//funciones de reportes
void Reportear();
void Reporpant();

//***** Formato para el cuadro *****//
void frame(){

    // ESQUINAS //
    gotoxy(0,0);
    cout<<"*";
    gotoxy(0,24);
    cout<<"*";
    gotoxy(79,0);
    cout<<"*";
    gotoxy(79,24);
    cout<<"*";

    // A a B //
    for(int i=1;i<79;i++){
        gotoxy(i,0);
        cout<<"-";
    }
    for(int i=1;i<79;i++){
        gotoxy(i,3);
        cout<<"-";
    }
    // TITULO //
    gotoxy(2,2);
    cout<<"I . C . C";

    // B a D //
        for(int l=1;l<24;l++){
        gotoxy(79,l);
        cout<<"|";
    }
        // C a D //
    for(int j=1;j<79;j++){
        gotoxy(j,24);
        cout<<"=";
    }
    for(int j=1;j<79;j++){
        gotoxy(j,22);
        cout<<"=";
    }
        // A a C //

    for(int k=1;k<24;k++){
        gotoxy(0,k);
        cout<<"|";
    }

    // FOOTER //
        gotoxy(2,23);
        cout<<"Ing.Cesar Herrera";
        
        gotoxy(56,23);
        cout<<"Ing. Pablo Emilio R.";


    /* fecha/hora actual basado en el sistema actual */
time_t now = time(0);

    /* Objeto de una estructura tm con fecha/hora local */
tm * time = localtime(&now);

vector<string> mes;
mes.push_back("01");
mes.push_back("02");
mes.push_back("03");
mes.push_back("04");
mes.push_back("05");
mes.push_back("06");
mes.push_back("07");
mes.push_back("08");
mes.push_back("09");
mes.push_back("10");
mes.push_back("11");
mes.push_back("12");

int year = 1900 + time->tm_year;

    //Formato=DIA, NUMERO de MES del AÑO
    gotoxy(68,1);
    cout << time->tm_mday << "/" << mes[time->tm_mon] << "/" << year << endl;
    // HORA //
    gotoxy(70,2);
    cout << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;



    system("pause>nul");
}//fin de frame

int main(){
    
    
     menu_principal();
	
	 return 0;

}//fin del main
void menu_principal(){
	int op; 
     bool repite= true;
	 do{
	 system("cls");
	 	system("color 1A");
	 	
	 	
	 	printf("\n\n\t     ******** BIENVENIDO AL MENU DE PRINCIPAL ***********\n");
		 frame();
		printf("\n\n\t\t\tQue desea Hacer?");
		//-----------opciones del Menú-------------
		printf("\n\t\t\t1.)Mantenimiento de Articulos");
		printf("\n\t\t\t2.)Ventas");
		printf("\n\t\t\t3.)Reportes");
		printf("\n\n\t\t\t4.) Salir");
		//-----------leer la opcion elegida
		printf("\n\t\t\tOpcion: ");
		scanf("%d",&op);
		
		//Estruct. seleccion switch
	 	switch(op){
		case 1:
			Manto_artic();
			break;
		case 2:
			ventas();
		 	break;	
		case 3:
			Reportes();
		 	break;
		case 4:
			repite=false;
			break;	  	
		 	
		}
	
	 } while(repite);
	
}//fin del menu

void Manto_artic(){
	int op;
	bool repite= true;
	
	
	 do{
	 	system("cls");
 		system("color 0A");
	 	printf("\n\n\t\t*********** Menu Mantenimiento de articulos***********\n");
		 frame();
	
		//-----------opciones del Menú-------------
		printf("\n\t\t\t1.)Consultar");
		printf("\n\t\t\t2.)Agregar");
		printf("\n\t\t\t3.)Modificar");
		printf("\n\t\t\t4.)Borrar");
		printf("\n\t\t\t5.)Regresar");
		//-----------leer la opcion elegida
		printf("\n\t\t\tOpcion: ");
		scanf("%d",&op);
		//Estruct. seleccion switch
	 	switch(op){
		case 1:
			consultar();
			break;
			
		case 2:
			Agregar();
		 	break;	
		case 3:
			modificar();
		 	break;
		/*case 4:
			borrar();
		 	break;*/
		case 5:
			repite=false;
			break;	  	
		 	
		}//switch
		
	 } while(repite);
	
}//mantenimiento de articulos
void ventas(){
	int op;
	char cliente[25];
	bool repite= true;
	 do{
	 	system("cls");
        system("color 4f");
	 	printf("\n\n\t\t*********** Menu Ventas***********\n");
	 	frame();
		printf("\n\t\t\tQue desea hacer?\n");
	 	printf("\n\n\t\t1.)Generar factura\n");
	 	printf("\n\n\t Presione 0 para regresar: ");
	
		//---Leer la opcion elegida---
		printf("\n\t\t\tOpcion: ");
		scanf("%d",&op);
		//Estruct. seleccion switch
	 	switch(op){
		case 1:
			factura();
			break;
		/*case 2:
			Agregar();
		 	break;	
		case 3:
			modificar();
		 	break;
		case 4:
			borrar();
		 	break;
		*/case 0:
			repite=false;
			break;	  	
		 	
		}//switch
		
	 } while(repite);
	
}//Ventas
void Reportes(){
	int op;
	bool repite= true;
	 do{
	 	system("cls");

	 	printf("\n\n\t\t*********** Menu de Reportes***********\n");
	
		//-----------opciones del Menú-------------
		printf("\n\t\t\t1.)Crear reporte De inventario en archivo de texto");
		printf("\n\t\t\t2.)Reporte en Pantalla");
		
		printf("\n\n\t\t\t5.)Regresar");
		//-----------leer la opcion elegida
		printf("\n\t\t\tOpcion: ");
		scanf("%d",&op);
		//Estruct. seleccion switch
	 	switch(op){
		case 1:
			Reportear();
			break;
		 case 2:
			Reporpant();
		 	break;	
		/*case 3:
			modificar();
		 	break;
		case 4:
			borrar();
		 	break;*/
		case 5:
			repite=false;
			break;	  	
		 	
		}//switch
		
	
	 } while(repite);

	
}//Reportes

//------------------------- Funciones ---------------------------------
//----------------------- De los menus ---------------------------------

void consultar(){//Detalles de articulo ingresando el codigo
	FILE *ArchO;
	bool encontrado=0,repite=true;
	Artic Artmp;
	int codB,op;
	system("cls");

	printf("\n\n\t\t*********** CONSULTAR ************\n");
	frame();
	if(!(ArchO=fopen("c:\\cesar\\structArticulo(2).txt","r")))
	{
		printf("El archivo no se pudo abrir");
		exit(1);
	}
	
	printf("\n\n\tIngrese el codigo a buscar:");
	scanf("%d",&codB);
	
	
	while((!feof(ArchO))&&(!encontrado))
	{
		fread(&Artmp,sizeof(Artic),1,ArchO);
		if(Artmp.cod==codB)
		{
			printf("\n\n\tcodigo: %d\n\tdescripcion:%s\n\tprecio:%0.2f\n\tExistencia:%d",Artmp.cod,Artmp.descrip,Artmp.precio,Artmp.cantidad);
			encontrado=1;
		}
	}
	if(!encontrado)
		printf("\n\nEse articulo no existe...!");
	
	printf("\n\n\t\tPresione 0 para regresar");
	switch(op){
		
		case 0:
			repite=false;
			break;	  	
		 	
		}//switch	
        getch();
        
}//fin de consultar

void Agregar(){//Agregar articulo a inventario
	FILE *ArchO;
	int N,op;
	bool repite= true;
	
	Artic Artmp;
	system("cls");
	
	printf("\n\n\t\t******* AGREGAR *********\n");
	if(!(ArchO=fopen("c:\\cesar\\structArticulo(2).txt","a+")))
	{
		printf("El archivo no se pudo abrir");
		exit(1);
	}
	printf("\n\n\t\t presione 0 para regresar");
	printf("\n\n\t\tcuantos articulos se van a ingresar:");
	scanf("%d",&N);
	
	
	for(int x=0; x<N;x++){
		
		printf("Articulo %d:\n",x);
		printf("\nCODIGO:");
		scanf("%d",&Artmp.cod);
		printf("\nDESCRIPCION:");
		fflush(stdin);
		gets(Artmp.descrip);
		printf("\nPRECIO:");
		scanf("%f",&Artmp.precio);
		printf("\nEXISTENCIA:");
		scanf("%d",&Artmp.cantidad);
		
		fwrite(&Artmp,sizeof(Artic),1,ArchO);
		printf("\n\n");
	}
	fclose(ArchO);
    switch(op){
		
		case 0:
			repite=false;
			break;	  	
		 	
	}//switch
	
}//fin de agregar

void modificar(){//****Menos el codigo****
	
	FILE *arch01;
	int cod02,opcion,resultado,aux;
	float aux01;
	char data[20];
	bool repite=true;
	Artic Artmp;
	
	system("cls");
	printf("\n\n\t\t******* MODIFICAR *********\n");
	
	if(!(arch01=fopen("c:\\cesar\\structArticulo(2).txt","r+")))
	{
		printf("El archivo no se pudo abrir");
		exit(1);
	}
	printf("\n\n\tpresione 0 para regresar");
	printf("\n\n\tIngrese el Codigo del Articulo a Modificar: ");
	scanf("%d",&cod02);
	
	printf("\n\n\tDETALLES DEL ARTICULO\n");
	resultado=fseek(arch01,sizeof(Artmp)*(cod02-1),0);
	fread(&Artmp,sizeof(Artmp),1,arch01);
	printf("\tCodigo: %d\n\tDescripcion: %s\n\tPrecio: %.2f\n\tExistencia: %d\n",Artmp.cod,Artmp.descrip,Artmp.precio,Artmp.cantidad);

	if(!resultado)
	{	
		do
		{
			system("COLOR 1F");
			cout<<"\n\t\tQue desea hacer?";
			printf("\n\n\t 1.)DESCRIPCION");
			printf("\n\t 2.)PRECIO");
			printf("\n\t 3.)CANTIDAD EXISTENTE");
			printf("\n\t 4.)REGRESAR");
			
				
			printf("\n\t\tOPCION: ");
			fflush(stdin);
			scanf("%d",&opcion);
				
			switch(opcion)
			{
				case 0:
		    	repite=false;
			    break;
				case 1:
				{
					fseek(arch01,sizeof(Artmp)*(cod02-1),0);
					printf("Ingrese la Nueva Descripcion: ");
					fflush(stdin);
					gets(data);
					strcpy(Artmp.descrip,data);
					fwrite(&Artmp,sizeof(Artmp),1,arch01);
					break;
				}
				case 2:
				{
					fseek(arch01,sizeof(Artmp)*(cod02-1),0);
					printf("Ingrese el Nuevo Precio: ");
					scanf("%f",&aux01);
					Artmp.precio=aux01;
					fwrite(&Artmp,sizeof(Artmp),1,arch01);
					break;
				}
				case 3:
				{
					fseek(arch01,sizeof(Artmp)*(cod02-1),0);
					printf("Ingrese la Nueva cantidad: ");
					scanf("%d",&aux);
					Artmp.cantidad=aux;
					fwrite(&Artmp,sizeof(Artmp),1,arch01);
					break;
				}
			}	
		}while(opcion!=4);
	}
	fclose(arch01);
}//modificar datos de articulos 

/*void borrar(){
	FILE *ArchO;
	bool encontrado=0,repite=true;
	Artic Artmp;
	int codB,cborrar,op;
	system("cls");

	printf("\n\n\t\t*********** Menu borrar ************\n");
	printf("\n\n\tIngrese el codigo del articulo que desea borrar: ");
	scanf("%d",&cborrar);
	if(!(ArchO=fopen("c:\\cesar\\structArticulo.txt","r")))
	{
		printf("El archivo no se pudo abrir");
		exit(1);
	}
	
	
	while((!feof(ArchO))&&(!encontrado))
	{
		fread(&Artmp,sizeof(Artic),1,ArchO);
		if(Artmp.cod==codB)
		{
			printf("\n\ncodigo: %d\ndescripcion:%s\nprecio:%0.2f\nExistencia:%d",Artmp.cod,Artmp.descrip,Artmp.precio,Artmp.cantidad);
			encontrado=1;
		}
	}
	if(!encontrado)
		printf("\n\nEse articulo no existe...!");
	
	printf("\n\n\t\tPresione 0 para regresar");
	switch(op){
		
		case 0:
			repite=false;
			break;	  	
		 	
		}//switch	
        getch();
}//fin de Borrar*/

void factura(){
	char cliente[50];
	int fact,op,n,codigo;
	FILE* ArchO;
	bool repite= true;
	Artic Artmp;
	
	if(!(ArchO=fopen("c:\\cesar\\structArticulo(2).txt","a+")))
	{
		printf("El archivo no se pudo abrir");
		exit(1);
	}

	system("cls");
	printf("\n\n\t*********** FACTURA*************\n");
	frame();
	
	printf("\n\tNombre del cliente: ");
	 	scanf("%s",&cliente);
	 	fflush(stdin);//limpiamos el buffer (lo que esta guardado en este caso en scanf)
	printf("\t\t No. de factura: ");
	 	scanf("%d",&fact);
	printf("\tcuantos articulos desea llevar:");
	fflush(stdin);
	scanf("%d",&n);
	printf("\n\t\t presione 0 para regresar");
	
     for(int x=1;x<n;x++){
     	printf("\n\t-------------------------------------------------------");
     	printf("\n\tIngrese codigo de articulo [%d]: \n",x);
     	scanf("%d",&codigo);
		//consultar();
     	
     	
     	getch();
	 }//for x
     
    switch(op){
		
		case 0:
			repite=false;
			break;	  	
		 	
	}//switch
	
	
	fclose(ArchO);
	getch();
}//fin de factura
void Reportear(){//Crear un reporte de inventario en un archivo de texto
	FILE *ArchO,*ArchR;
		
	Artic Artmp;
	system("cls");
	if(!(ArchO=fopen("c:\\cesar\\structArticulo(2).txt","a+")))
	{
		printf("El archivo no se pudo abrir");
		exit(1);
	}
	
	if(!(ArchR=fopen("c:\\cesar\\structreporte(2).txt","w")))
	{
		printf("El archivo reporte no se pudo crear");
		fclose(ArchO);
		exit(1);
	}
	
	rewind(ArchO);
	fprintf(ArchR,"%8s %25s %8s %5s\n","Codigo","Descripcion  ","Precio  ","Cantidad");
	fprintf(ArchR,"-------------------------------------------------------------\n");
	while(!feof(ArchO))
	{
		fread(&Artmp,sizeof(Artic),1,ArchO);
		if(!feof(ArchO))
		fprintf(ArchR,"%8d  %25s  %9.2f  %5d\n",Artmp.cod,Artmp.descrip,Artmp.precio,Artmp.cantidad);
	}
	
	fclose(ArchO);
	fclose(ArchR);
	
}//fin de Reportear

void Reporpant(){//realizar un reporte de inventario en pantalla 
		FILE *Arch01;
		Artic Artmp;
		bool repite=true;
		int op;
		system("cls");
	if(!(Arch01=fopen("c:\\cesar\\structArticulo(2).txt","r+")))
	{
		printf("El archivo no se pudo abrir");
		exit(1);
	}
	
	
   	printf("\n\n\t\t*********** Reporte en Pantalla ************\n");
	 printf("--------------------------------------------------------------------------------------\n");
     printf("\tCODIGO \t\t DESCRIPCION \t\t\t PRECIO \t CANTIDAD");
 	 printf("\n-------------------------------------------------------------------------------------\n");

	
	while(!feof(Arch01))
	{
		fread(&Artmp,sizeof(Artic),1,Arch01);
		if(!feof(Arch01))
		 printf("\t%d \t\t%5s \t\t%8.2f \t%d\n",Artmp.cod,Artmp.descrip,Artmp.precio,Artmp.cantidad);
	}
	printf("\n\n\tPresione 0 para regresar");
	
	switch(op){
		
		case 0:
			repite=false;
			break;	  	
		 	
		}//switch	
		
	fclose(Arch01);
	
	getch();
}//imprimir inventario en pantalla

