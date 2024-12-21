#include <iostream>
#include "Employee.h"
#include "Agent.h"
#include "gestionnaire.h"
#include "AgGest.h"

int main()
{
    AgGest* G1 = new AgGest(10, 5, "AAAAA", "aa");
    G1->Agent::afficher();
    delete G1;
    /*
    Employee* E1 = new Employee(5, "souneini", "salma");
    E1->afficher();
    cout << endl;
    cout << endl;
    

    Agent* A1 = new Agent(10, 5, "AAAAA", "aa");
    A1->afficher();
    delete A1;
    cout << endl;
    cout << endl;

    gestionnaire* G1= new gestionnaire(5, "", "salma");
    G1->afficher();
    delete G1;


    //polymorphisme at run time 
    Employee* E2 = new Agent(20,10, "SSS", "salma");
    E2->afficher();
    cout << endl;
    cout << endl;
    */


    /*
    Employee::initializeTaux(20);
    Employee* E2 = new Employee(5, "nn", "salma");
    E2->afficher();
    delete E2;
    */
    
    //E1->afficher();
    //Agent::;

        /*
    Agent::initializeTaux(20);
    Agent* A1 = new Agent(10, 5, "hehe", "h");
    A1->afficher();
    delete A1;
    cout << endl;
    cout << endl;
    */

    //Agent::initializeTaux(20);
}
