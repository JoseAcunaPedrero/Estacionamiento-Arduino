#include <iostream>

using namespace std;

int main(){
	int SensorEntrada,SensorSalida,Total,c;
	char resp='s';
	
	cout<<"Este programa verifica el funcionamiento del estacionamiento"<<endl<<endl;
	
	while(resp=='s'){
		cout<<"Debe ingresar '1' para ecendido o '0' para apagado "<<endl<<endl;
		regresar:
		cout<<"Estado del sensor 1 de entrada: ";cin>>SensorEntrada;cout<<endl;
		cout<<"Estado del sensor 2 de salida: ";cin>>SensorSalida;cout<<endl;

		Total=Total+(SensorEntrada-SensorSalida);
		
		
		if((SensorEntrada==1||SensorEntrada==0)&&(SensorSalida==1||SensorSalida==0)){	
		//verifica que los valores ingresados sean entre 1 y 0
			if(Total<=-1){
				cout<<"!!Error, no pueden salir autos invisibles, intente nuevamente "<<endl<<endl;
				Total=0;	//es para que el mínimo sea 0 vehículos 
				goto regresar;
			}
			if(Total>=6){
				cout<<"!!Error, no pueden ingresar más vehículos, intente nuevamente "<<endl<<endl;
				Total=5;	//es para que el máximo sea siempre 5 vehículos.
				goto regresar;
			}
			if(Total==5){	//si llega a su máximo de capacidad dirá que el estacionamiento está lleno.
				cout<<"Estacionamiento lleno"<<endl;
				cout<<"Luz Roja 1"<<endl;
				cout<<"Luz Verde 0"<<endl;
				cout<<"Barrera 1"<<endl;	// la barrera bajará si el estacionamiento está lleno.
			}
			if(Total==0){	//avisará si el estacionamiento esta vacio 
				cout<<"Estacionamiento vacio"<<endl;
				cout<<"Luz Roja 0"<<endl;
				cout<<"Luz Verde 1"<<endl;
				cout<<"Barrera 0"<<endl;	
				//si al estacionamiento le queda espacio para mas vehículos, la barrera se mantendra abierta.
			}
			cout<<"Total vehiculos en el estacionamiento: "<<Total<<endl<<endl;			
		}else{		
			cout<<"!!Error, debe ingresar '1' para ecendido o '0' para apagado "<<endl<<endl;
			Total=Total-SensorEntrada+SensorSalida;		// para que sume o reste los valores mal imgresados
			goto regresar;
		}
		regresar2:	
		cout<<"Desea reportar otro movimiento de vehiculo? [s/n]: ";cin>>resp;cout<<endl;
		if(resp!='s'&&resp!='n'){
			cout<<"!!Error, debe ingresar 's' para continuar o 'n' para salir"<<endl<<endl;
			goto regresar2;
		}	
	}
	
	system("pause");
	return 0;
}
