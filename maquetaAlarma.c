// VARIABLE QUE HAY QUE PONER SI O SI
// VARIABLES DE ESTADO DE LOS SENSORES
//VARIABLES PARA DESGLOSAR LA HORA Y GUARDARLO AHI


// DEFINICIÓN DE CONSTANTES

typedef enum {modoReposo, caseA, alarmaActivada, sirenaActivada} estadoMEF;                                

// DECLARACIÓN DE FUNCIONES

void inicializarMEF(estadoMEF *punteroEstadoActual);
void actualizarMEF(estadoMEF *punteroEstadoActual);

estadoMEF estadoActual;

// DECLARACIÓN DE VARIABLES GLOBALES

uint16_t miliSegundos;

void setup() {
  Serial.begin(9600);
 //SENSORES INPUT
 // RELE OUTPUT
  inicializarMEF(&estadoActual);

}

void loop() {
  actualizarMEF(&estadoActual);
  delay(1);
  miliSegundos++;
}

void inicializarMEF(estadoMEF *punteroEstadoActual) {
  *punteroEstadoActual = modoReposo;
}

void actualizarMEF(estadoMEF *punteroEstadoActual) {
  switch (*punteroEstadoActual)
  {
    case modoReposo:
      //como el usuario va a tener interaccion con nuestra alarma este caso va a ser el incio de todas las ramas.
      
      //en el caso de que el usuario presione ´1´ va a ser la condicion para que pase al estado caseA.(activar alarma).
      //en el caso de que el usuario presione ´2´ va a ser la condicion para que pase al estado caseB.(cambiar contrasenia).


       // la idea de este caso es que el display este mostrando por pantalla la hora y la fecha.
      // para eso la configuracion del Real Timer Clock debe estar aca.

       
      
      


        //el rele,sensores,sirena deben estar desactivados.
      
      



        //dejo esto como ejemplo de como dedben ser las salidas de los casos a otros casos.
     if (contrasena_default == contrasena_input) {
        miliSegundos = 0;
        *punteroEstadoActual = ESTADO_ALARMA_ACTIVADA;
      }


      break;




        case caseA:
        //la funcionalidad de este caso es la de validar la contrasenian que se ingrese con la default.
        //el display debe estar diciendo ´íngresar contrasenia´'y esta debe desaparecer cuando el usuario digite.


        //el rele,sensores,sirena deben estar desactivados.
        

        //la condicion para que se pase al caso alarmaActivada es que la contrasenia ingresada sea igual a la default.


          
       

        


      if (miliSegundos >= 1000) {
        miliSegundos = 0;
        *punteroEstadoActual = ESTADO_ALARMA_DESACTIVADA;
      }

      break;



      

    case alarmaActivada:
        //la funcionalidad de este caso es encender los sensores y que estos registren movimiento.
        //el display debe estar diciendo ´CONTRASENIA CORRECTA´ ´ALARMA ACTIVADA12345 ´ por 5 segundos y desaparecer.
        //en este caso se debe hacer un registro de que la alarma se activo, a que hora se activo, y guardarlo en un memoria SD.

        //el rele debe estar desactivado.
        
        

        //la condicion para que se pase al estado de sirenaActivada debe ser que los sensores detecten movimiento
  


      if (miliSegundos >= 1000) {
        miliSegundos = 0;
        *punteroEstadoActual = ESTADO_ALARMA_DESACTIVADA;  //NOSOTROS LE TENEMOS QUE DAR AL USUARIO 5 SEGUNDOS PARA QUE SE VAYA DE LA CASA
      }

      break;

       case sirenaActivada:
      
        //basicamente este estado debe encender la sirena.
        //el display debe decir ´MOVIMIENTO DETECTADO´ durante 5 segundos
        //tambien debe hacer un registro de cuando se detecto movimiento y guardarlo en la memoria SD. distinta a la de activacion de alarma

        //ḷa sirena debe apagarse despues de 15 minutos.
        // o debe apagarse cuando reciba la contrasenia correcta.
        //por lo que 

        //la condicion para que pase al siguiente estado (alarma activada) es que se ponga la contrasenia o que pasen 15 minutos


      if (miliSegundos >= 1000) {
        miliSegundos = 0;
        *punteroEstadoActual = ESTADO_ALARMA_DESACTIVADA; 
      }

      break;

  }
}
