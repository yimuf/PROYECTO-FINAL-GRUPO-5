#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<windows.h>
using namespace std;
HANDLE h =GetStdHandle (STD_OUTPUT_HANDLE);
/*ESTRUCTURAS*/
//USUARIO
struct Usuario
{
    int     codUsu;
    string  nomUsu;
    string  passUsu;
    int     tipUsu;//1admin   ||   2 vendedor
};
//CLIENTE 
struct Cliente
{
    string nomCliente;
    int    numCliente;
};
//PRODUCTOS
struct Producto
{
	int		codProducto;
	string	nomProducto;
	float	preProducto;
	int		stkProducto;
};

//VENTA


/*VECTORES*/
//USUARIO
vector<Usuario> vecUsuario;
//CLIENTES
vector<Cliente> vecCliente;
//PRODUCTOS
vector<Producto> vecProducto;

/*PROTOTIPOS*/
//PERSONALIZACION
void gotoxy (int x, int y)
{
   HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD dwPos;
   dwPos.X = x;
   dwPos.Y = y;
   SetConsoleCursorPosition(hcon, dwPos);
}   
void dibujarCuadro (int x1,int y1,int x2,int y2); 
//USUARIO
void add();
void validacion();

//MENU GENERAL
void    general();
//CLIENTE
void    addCliente();
void    buscarCliente();
void    eliminarCliente();
void    modificarCliente();
void    lista();
void    cliente();
int     correlativo();
int     obtenerPosCliente(int);

//PRODUCTOS
void	addVector();
void	listOfItems();
int		getCorrelativo();
float	sumaTotal();
void	buscarProductoPorCodigo();
void	removeVector();
void	modifyVector();
int		obtenerPosArreglo(int);
void 	menuProductos();



//
int main()
{
    add();
    validacion();
    general();

  
}
/*IMPLEMENTACION*/
//PERSONALIZACION
void validacion()
{
	
	
	int intento =0;
	int ingresa = 0;
    string usuario, contrasena;
    bool flag = false;
    int pos;
    
    for (int i= 35; i<=80; i++)
	{
	system ("color 1");
	SetConsoleTextAttribute(h,10);
    gotoxy (i,1); cout<< "_"; 
    gotoxy (i,13); cout<< "_"; 
	}    
	
	for (int i= 2; i<=13; i++)
	{
	system ("color 1");
	SetConsoleTextAttribute(h,10);
	gotoxy (35,i); cout<< "|"; 
    gotoxy (80,i); cout<< "|"; 		
	}
	  do{
    system ("color 1"); 
    SetConsoleTextAttribute(h,15);
	gotoxy (50,2); cout<<"ACCESO AL SISTEMA \n";
	SetConsoleTextAttribute(h,1);
	gotoxy (38,3); cout<<"______";
    SetConsoleTextAttribute (h,15); 
	gotoxy (38,5);cout<<"Usuario: ";
	SetConsoleTextAttribute (h,7);
	cin>>usuario;
	SetConsoleTextAttribute (h,15); 
    gotoxy (38,7); cout<<"Contraseña: ";
	SetConsoleTextAttribute (h,7);
	cin>>contrasena;
    for (int i = 0; i < vecUsuario.size(); i++)
    {
        if(usuario == vecUsuario[i].nomUsu && contrasena == vecUsuario[i].passUsu)
        {
            flag = true;
            pos = i;
            break;
        }
        
    }
    
  
	     
          if(flag == true) 
          {
          	SetConsoleTextAttribute(h,15);
          	gotoxy (38, 10);
            cout<<"Acceso correcto!\n";
            ingresa = 1;
            SetConsoleTextAttribute(h,7);
            gotoxy (38, 11);
            system("pause");
            system("cls");
            switch (vecUsuario[pos].tipUsu)
            {
            case 1:cout<<"\tMENU GENERAL DE OPCIONES \n";
                   cout<<"[1]\n";
                   cout<<"[2]\n";
                   cout<<"[3]\n";
                break;
            case 2:general();
                break;
            }
          }
          else
          {
          	SetConsoleTextAttribute(h,15);
          	gotoxy (38, 10);
            cout<<"Acceso denegado :c\n";
            SetConsoleTextAttribute(h,7);
            gotoxy (38, 11);
            system ("pause");
            system("cls");
            intento++;
          }
          
	} while (intento<3);
}


//USUARIO
void add()
{
    //DATOS FIJOS
    vecUsuario.push_back({1,"piero","123",1});
    vecUsuario.push_back({2,"samuel","132",2});
}


//MENU GENERAL
void general()
{
    int opcion;
  cout<<"\tOPCIONES GENERALES:\n";
  cout<<"                          "<<endl;
  cout<<"Clientes \t[1]\n";
  cout<<"Productos \t[2]\n";
  cout<<"Venta \t\t[3]\n";
  cin>>opcion;
  switch (opcion)
  {
  case 1: 
          cliente();
          system("cls");
          break;
  case 2: 
          menuProductos();
          system("cls");
        break;  
  case 3: //venta
        break;
  default:
    break;
  }
}
//CLIENTES
void cliente()
{
int opcion;
    do
    {
        cout<<"\t\t\tMENU DE REGISTRO\n";
        cout<<"\t\tAgregar cliente.....[1]\n ";
        cout<<"\t\tBuscar cliente......[2]\n ";
        cout<<"\t\tEliminar cliente....[3]\n";
        cout<<"\t\tModificar cliente...[4]\n";
        cout<<"\t\tLista de cliente....[5]\n ";
        cout<<"\t\tSalir del cliente...[6]\n";
        cout<<"Ingrese una opcion:";
        cin>>opcion;
    
    switch (opcion)
    {
    case 1:system("cls");
           addCliente();
           break;
    case 2:system("cls");
           buscarCliente();
           break;
    case 3: system("cls");
            eliminarCliente();
            system("pause");
            system("cls");
            break;
    case 4:system("cls");
           modificarCliente();
           system("pause");
           system("cls");
           break;
    case 5:system("cls"); 
           lista();
           system("pause");
           system("cls"); 
           break;
    case 6:system("cls"); 
           cout << "Gracias por su registro :)\n";
           system("pause"); 
           system("cls");
           break;
    default:system("cls");
            cout << "Ingrese una opcion correcta[1-6]\n";
            system("pause");
            system("cls");
        break;
    }   
    } while (opcion != 6); 
}
void addCliente()
{
    string rpta;
    do
    {
        Cliente cliente;//declaracion del tipo de dato estructura
        
        cout<<"\tNumero de cliente: "<<correlativo()<<endl;
        cliente.numCliente = correlativo();
        cout<<"Cliente: "; cin>>cliente.nomCliente;
        
        
        vecCliente.push_back(cliente);
        
        cout<<"Deseas continuar agregando clientes...(S/s)"<<endl;;
        cin>>rpta;
        system("cls");
    }while(rpta=="S"||rpta=="s");
}
int  correlativo()
{
    if(vecCliente.size() == 0)//0 datos en el arreglo
    {
        return 1;
    }
    else
    {
        return vecCliente[vecCliente.size() - 1].numCliente + 1;
    }

}
void buscarCliente()
{
    string nombre;
    bool flag = false;
    int pos;
    cout<<"Ingrese un cliente a buscar: \n";
    cin>>nombre;
    for (int i=0;i<vecCliente.size();i++)
    {
        if(nombre == vecCliente[i].nomCliente)
        {
            pos= i;
            flag = true;
        }
    }
    if(flag == true)
    {
        system("cls");
        cout<<"Cliente encontrado\n";
        system("pause");
        system("cls");
        cout<<"Numero de cliente: "<<vecCliente[pos].numCliente<<endl;
        cout<<"cliente: "<<vecCliente[pos].nomCliente<<endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout<<"El cliente ingresado es incorrecto!!!!\n";
        system("pause");
        system("cls");
    }
}
void eliminarCliente()
{
    string nombre;
    bool flag = false;
    cout<<"\tIngrese un cliente a eliminar:";
    cin>>nombre;
    for (int i = 0; i < vecCliente.size(); i++)
    {
        if(nombre == vecCliente[i].nomCliente)
        {
            vecCliente.erase(vecCliente.begin() + i);
            cout<<"\tRegistro eliminado satisfactoriamente!!!\n";
            flag = true;
            break;
        }
    }
    if(flag == false)
    {
        cout<<"\tERROR::::::$%&%$&";
    }
}
void modificarCliente()
{
    string _nombre;
    int posicion,opcion,_numero,nume;
    cout<<"\tIngrese el numero de cliente a modificar: \n";
    cin>>nume;
    posicion= obtenerPosCliente(nume);
    if(posicion == -1)
    {
        cout<<"ERRO%$&#";
    }
    else
    {
        {
            cout<<"\tCliente encontrado: \n";
            cout<<"--------------------\n";
            cout<<"Numero de cliente: "<<vecCliente[posicion].numCliente<<endl;
            cout<<"Nombre de cliente: "<<vecCliente[posicion].nomCliente<<endl;
            cout<<"    \n";
            cout<<"\t MINI MENU\n";
            cout<<"Numero de cliente \t\t[1]\n";
            cout<<"Nombre de cliente \t\t[2]\n";
            cout<<"\tSeleccione una opcion [1-2]: ";
            cin>>opcion;
            cin.ignore();
            switch (opcion)
            {
            case 1:cout<<"Cambiar numero de cliente: ";
                  cin>>_numero;
                vecCliente[posicion].numCliente=_numero;
                break;
            case 2:cout<<"Cambiar nombre del cliente: ";
                   getline(cin,_nombre);
                   vecCliente[posicion].nomCliente=_nombre;
                break;
            default:cout<<"Ingrese un opcion correcta[1-2]\n";
                break;
            }
        }
    }
    
}
int  obtenerPosCliente(int num)
{
	for (int i = 0; i < vecCliente.size(); i++)
	{
		if (num == vecCliente[i].numCliente)
		{
			return i;
		}
	}
	return -1;
}
void lista()
{
    cout<<"\tCLIENTES REGISTRADOS\n";
    
    for(int i=0;i<vecCliente.size();i++)
    {
        cout<<"-------------------\n";
        cout<<"Numero de cliente: "<<vecCliente[i].numCliente<<endl;
        cout<<"Cliente: "<< vecCliente[i].nomCliente<<endl; 
        cout<<"-------------------\n";
    }
}


//PRODUCTOS
void    menuProductos()
{
	int opcion;
	do
	{
		cout << "M E N U  D E  O P C I O N E S\n";
		cout << "Agregar productos______[1]\n";
		cout << "Buscar productos_______[2]\n";
		cout << "Eliminar productos_______[3]\n";
		cout << "Modificar productos______[4]\n";
		cout << "Listar productos_______[5]\n";
		cout << "Salir__________[6]\n";
		cout << "Ingrese una opcion:";
		cin >> opcion;
		switch (opcion)
		{
		case 1:system("cls"); addVector(); break;
		case 2:system("cls"); buscarProductoPorCodigo(); break;
		case 3:	system("cls");
				removeVector();
				system("pause");
				system("cls");
				break;
		case 4:	system("cls"); 
				modifyVector();				
				system("pause");
				system("cls");
				break;
		case 5:	system("cls"); 
				listOfItems(); 
				system("pause");
				system("cls");
				break;
		case 6:system("cls"); cout << " \n"; break;
		default:system("cls"); 
				cout << "Ingrese una opcion correcta[1-6]\n";
				system("pause");
				system("cls");
		}
	} while (opcion != 6);
}
void 	addVector()
{
	string rpta;
	do
	{
		Producto producto;//Declarando el tipo de datos estructura

		cout << "Codigo:" << getCorrelativo() << endl;
		producto.codProducto = getCorrelativo();
		cin.ignore();//limpiar el buffer
		cout << "Nombre del producto:"; 
		//cin >> producto.nomProducto;
		getline(cin, producto.nomProducto);
		cout << "Precio:"; cin >> producto.preProducto;
		cout << "Stock:"; cin >> producto.stkProducto;

		vecProducto.push_back(producto);//Agregar al arreglo

		cout << "Deseas continuar registrando productos....(S/s):";
		cin >> rpta;
		system("cls");
	} while (rpta == "S" || rpta == "s");
}
void 	listOfItems()
{
	cout << "Reporte General de Productos\n";
	for (int i = 0; i < vecProducto.size(); i++)
	{
		cout << "____________\n";
		cout << "Codigo: " << vecProducto[i].codProducto << endl;
		cout << "Nombre del producto: " << vecProducto[i].nomProducto << endl;
		cout << "Precio:" << vecProducto[i].preProducto << endl;
		cout << "Stock:" << vecProducto[i].stkProducto << endl;
		cout << "____________\n";
	}
	cout << "La suma total es:" << sumaTotal() << endl;
	
}
int 	getCorrelativo()
{
	if (vecProducto.size() == 0)//No tengo datos registrados en el arreglo
	{
		return 1;
	}
	else
	{
		return vecProducto[vecProducto.size() - 1].codProducto + 1;
	}
}
float 	sumaTotal()
{
	float suma = 0;
	for (int i = 0; i < vecProducto.size(); i++)
	{
		suma += vecProducto[i].preProducto;
	}
	return suma;
}
void	buscarProductoPorCodigo()
{
	int codigo;
	bool flag = false;
	int pos;
	cout << "Ingrese codigo a buscar:";
	cin >> codigo;
	for (int i = 0; i < vecProducto.size(); i++)
	{
		if (codigo == vecProducto[i].codProducto)
		{
			pos = i;
			flag = true;
		}
	}
	if (flag == true)//Lo encontro
	{
		system("cls");
		cout << "Registro encontrado en la posicion(" << pos << ")\n";
		system("pause");
		system("cls");
		cout << "codigo" << vecProducto[pos].codProducto << endl;
		cout << "Nombre del producto:" << vecProducto[pos].nomProducto << endl;
		cout << "Precio:" << vecProducto[pos].preProducto << endl;
		cout << "Stock:" << vecProducto[pos].stkProducto << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "El codigo ingresado no existe!!!!! \n";
		system("pause");
		system("cls");
	}
}
void	removeVector()
{
	int codigo;
	bool flag = false;
	cout << "Ingrese codigo del producto a eliminar:";
	cin >> codigo;
	for (int i = 0; i < vecProducto.size(); i++)
	{
		if (codigo == vecProducto[i].codProducto)
		{
			vecProducto.erase(vecProducto.begin() + i);
			cout << "Registro eliminado satisfactoriamente!!!\n";
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		cout << "ERROR:codigo del producto no encontrado\n";
	}
}
void	modifyVector()
{
	int codigo, 
		posicion, 
		opcion;
	string _nombre;
	float  _precio;
	int    _stock;
	cout << "Ingrese un codigo a modificar:";
	cin >> codigo;
	posicion = obtenerPosArreglo(codigo);
	if (posicion == -1)
	{
		cout << "ERROR:codigo ingresado no existe!!!\n";
	}
	else
	{
		cout << "Registro encontrado\n";
		cout << "-------------------\n";
		cout << "Codigo:" << vecProducto[posicion].codProducto << endl;
		cout << "Nombre del producto:" << vecProducto[posicion].nomProducto << endl;
		cout << "Precio:" << vecProducto[posicion].preProducto << endl;
		cout << "Stock:" << vecProducto[posicion].stkProducto << endl;
		cout<< "---------------------\n";
		cout<< "                       \n";
		cout << "MINI MENU\n";
		cout << "Nombre\t\t[1]\n";
		cout << "Precio\t\t[2]\n";
		cout << "Stock\t\t[3]\n";
		cout << "Salir\t\t[4]\n";
		cout << "Seleccionar una opcion[1-4]:";
		cin >> opcion;
		cin.ignore();
		switch (opcion)
		{
		case 1: cout << "Cambiar nombre del producto:";
				getline(cin, _nombre);
				vecProducto[posicion].nomProducto = _nombre;
				break;
		case 2: cout << "Cambiar precio:";
				cin >> _precio;
				vecProducto[posicion].preProducto = _precio;
				break;
		case 3: cout << "Cambiar stock:";
				cin >> _stock;
				vecProducto[posicion].stkProducto = _stock;
				break;
		case 4:break;
		default:cout << "Ingrese una opcion correcta[1-4]\n";
		}
	}
}
int		obtenerPosArreglo(int cod)
{
	for (int i = 0; i < vecProducto.size(); i++)
	{
		if (cod == vecProducto[i].codProducto)
		{
			return i;
		}
	}
	return -1;
}