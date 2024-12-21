#include "Client.h"

Client::Client(string cin, string n, string p, Compte* compte[100]):CIN(cin), nom(n), prenom(p)
{
    for (int i = 0; i < 20; ++i) {
        comptes[i] = compte[i];
    }
}
