// shape.cpp : Définit les fonctions de la bibliothèque statique.
//

#include "pch.h"
#include "framework.h"
#include "Shape.h"


int Shape::compt = 0;


// TODO: Il s'agit d'un exemple de fonction de bibliothèque
void fnshape()
{

}

Shape::Shape():id_shape(++compt)
{
}

