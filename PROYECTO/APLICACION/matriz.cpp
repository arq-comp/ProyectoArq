#include <iostream>
#include <string>



using namespace std;


struct Brain {

int biologico = 2; //2
int cultural = 6; //4
int emocional = 6;

}brain;


int main(){


int op;

string map [][4]={ {"____","___","___","FOOD"},
                    {"____","___","ULA","____"},
                    {"PARK","___","___","____"}
      
    };



do{


 cout<<"*************************************************************"<<endl;  
 cout<<"******************SISTEMA DE ENTORNO MICRO-BRAIN*************"<<endl;
 cout<<"*************************************************************"<<endl<<endl;
    cout<<"\t"<<"PRESIONE LA OPCION QUE DESEE:"<<endl;

    cout<<"\t"<<"1. MOSTRAR VALORES DEL TERMOMETRO"<<endl;
    cout<<"\t"<<"2. MOSTRAR MAPA INTERACTIVO"<<endl;
    cout<<"\t"<<"3. MOVER BRAIN"<<endl;
    cout<<"\t"<<"4.SALIR"<<endl;

    cin>>op;
   



switch(op){

    case 1:

        cout<<endl;
        cout<<"*******TERMOMETRO DEL BRAIN*******"<<endl<<endl;

        for (int i=6;i>3;i--){
        cout<<"|"<<i<<"| +"<<endl;
        }
        for (int i=3;i>0;i--){
        cout<<"|"<<i<<"| -"<<endl;
        }

        cout<<"\t"<<"VALORES ACTUALES"<<endl<<endl;
        cout<<"BIOLOGICO"<<"\t"<<"CULTURAL"<<"\t"<<"EMOCIONAL"<<endl;
        cout<<brain.biologico<<"\t"<<"\t"<<brain.cultural<<"\t"<<"\t"<<brain.emocional<<endl<<endl;
    break;

    case 2:
  
        cout<<"\t"<<"\t"<<"MAPA INTERACTIVO"<<endl<<endl;

    
	    for (int i=0; i <3; i++) {
		    for (int j=0; j<4; j++){

	    cout <<"\t"<<map[i][j]<<"|";
		    }
        

	    cout<<endl;

	    }

    cout<<endl;
    break;
    case 3:
 

 cout<<"POSICION DEL BRAIN  'x' "<<endl;


    if(brain.biologico <= 3){

    map [0][3] = " X  "; 
    brain.biologico = brain.biologico + 3;

}

    if(brain.cultural <=4){
    map [1][2] = " X "; 
    brain.cultural = brain.cultural + 2;
    }   

    if(brain.emocional <=3){
        map [2][0] = " X  "; 
        brain.emocional = brain.emocional + 2;
        }  
 


	for (int i=0; i <3; i++) {
		for (int j=0; j<4; j++){

	cout <<"\t"<<map[i][j]<<" | ";
		}
	cout<<endl;

	}

            cout<<"\t"<<"VALORES ACTUALES"<<endl;
        cout<<"BIOLOGICO"<<"\t"<<"CULTURAL"<<"\t"<<"EMOCIONAL"<<endl;
        cout<<brain.biologico<<"\t"<<"\t"<<brain.cultural<<"\t"<<"\t"<<brain.emocional<<endl;

cout<<endl;

    break;

    case 4:
    cout<<"SALIR"<<endl;
    exit(0);
    break;
    default:
    {}    
    break;
    
}
}
while(op= 4);

return 0;
}
