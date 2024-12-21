#pragma once
#include"Noeud.h"
#include<iostream>
#include<queue>

using namespace std;
class ArbreBinaire
{
	private:
		Noeud* racine;
	public:
		ArbreBinaire() :racine(nullptr){}
		ArbreBinaire(Noeud* r):racine(r){}
		void insert(string value)
		{
			Noeud* nvneoud = new Noeud(value);
			if (this->racine == nullptr) {
				this->racine = nvneoud;
				return;
			}
            queue<Noeud*> q;
            q.push(racine);

            while (!q.empty()) {
                Noeud* current = q.front();
                q.pop();

                if (current->left == nullptr) {
                    current->left = nvneoud;
                    return;
                }
                else {
                    q.push(current->left);
                }

                if (current->right == nullptr) {
                    current->right = nvneoud;
                    return;
                }
                else {
                    q.push(current->right);
                }
            }

		}


        // Parcours en largeur (BFS)
        void AffichageLargeur() const {
            if (racine == nullptr) {
                cout << "Tree is empty" << endl;
                return;
            }

            queue<Noeud*> q;
            q.push(racine);

            while (!q.empty()) {
                Noeud* current = q.front();
                q.pop();

                cout << current->value << " ";

                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }

            cout << endl;
        }


        // Recherche d'une valeur dans l'arbre binaire (BFS)
        bool rechercher(const string& valeur) const {
            if (racine == nullptr) {
                return false;  // Arbre vide
            }

            queue<Noeud*> q;
            q.push(racine);

            while (!q.empty()) {
                Noeud* current = q.front();
                q.pop();

                if (current->value == valeur) {
                    return true;  // Valeur trouvée
                }

                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }

            return false;  // Valeur non trouvée
        }


};

