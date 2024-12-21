/*

#include <iostream>
#include "Arith.h"
#include "Error.h"
#include "ErrorExecution.h"
#include "ErrorLogic.h"

int main()
{
    
    Arith a(4, 0);
    try
    {
        a.is_negative();
    }
    catch (ErrorLogic r)
    {
        r.afficher();
    }
    try
    {
        a.division();
    }
    catch (ErrorExecution r)
    {
        r.afficher();
    }
    try
    {
        a.is_negative();
    }
    catch (ErrorLogic r)
    {
        r.afficher();
    }
   

}
*/


#include <iostream>
#include "Arith.h"
#include "Error.h"
#include "ErrorExecution.h"
#include "ErrorLogic.h"

int main()
{
    Arith X(4, 0);
    Arith Y(-4, 0);
    try
    {
        /*
        puisque X.a est positive doc le premier exeception va etre catche ce qui dirige le programme vers
        corespondante et il va etre executer mais ici le programme va etre pas continue ce qui existe 
        dans le try
        */

        /*
        Si X.a est negative il va pas catche une error il va passe a ça est puisque X.b est egale à 0 
        la deuxieme exeception est catche il va sortie de try 
        */


       /*
       Si l'execption provoquer est de type ErrorException mais nous dans catch en fait juste Error  ça neprovoque 
       pas un probleme  car chque ErrorException est un Error  mais l'invese n'est pas correcte 
       */
        
        Y.is_negative();  // Peut lancer ErrorLogic
        X.division();     // Peut lancer ErrorExecution
        Y.is_positive();  // Peut lancer ErrorLogic
    }
    catch (ErrorLogic& r)
    {
        r.afficher();
    }
    catch (ErrorExecution& r)
    {
        r.afficher();
    }
    catch (Error& r) // Optionnel : pour capturer d'autres types d'Error non spécifiques
    {
        r.afficher();
    }

    return 0;
}



/*

#include <iostream>
#include "Arith.h"
#include "Error.h"
#include "ErrorExecution.h"
#include "ErrorLogic.h"

int main()
{
    Arith a(4, 0);
    try
    {
        a.is_negative();
    }
    catch (ErrorLogic& r)
    {
        r.afficher();
    }
    

    try
    {
        a.division();
    }
    catch (ErrorExecution& r)
    {
        r.afficher();
    }

    try
    {
        a.is_negative();
    }
    catch (ErrorLogic& r)
    {
        r.afficher();
    }

    return 0;
}
*/