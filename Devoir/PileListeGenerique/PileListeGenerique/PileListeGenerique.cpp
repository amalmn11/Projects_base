using namespace std;
#include <iostream>
#include <string>
#include "PileG.h" // Inclure l'implémentation correcte de votre pile générique.



// Fonction pour vérifier si un caractère est un opérateur
bool isOperator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}



// Fonction pour obtenir la priorité des opérateurs
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


// Fonction pour vérifier la validité des parenthèses
bool checkParentheses(const string& expression) 
{
    PileG<char> parenthesesStack(expression.length());
    int i = 0;

    // Tant qu'il y a des caractères dans l'expression
    while (i < (int)expression.length()) 
    { 
        char ch = expression[i]; // Obtenir le caractère actuel

        if (ch == '(') {
            parenthesesStack.empiler(ch);
        }
        else if (ch == ')') {
            if (parenthesesStack.is_empty()) {
                return false; // Parenthèse fermante sans correspondance
            }
            parenthesesStack.depiler();
        }

        i++; // Passer au caractère suivant
    }

    return parenthesesStack.is_empty(); // Si la pile est vide, les parenthèses sont équilibrées
}



// Fonction pour convertir une expression infixe en postfixe
string infixToPostfix(const string& expression) 
{
    if (!checkParentheses(expression)) 
    {
        throw runtime_error("Parentheses mal place,expression non equilire !");
    }

    PileG<char> operators((int)expression.length());
    string postfix;

    for (int i = 0; i < (int)expression.length(); ++i) {
        char ch = expression[i];

        if (isdigit(ch)) {
            // Ajouter un nombre multi-chiffres à postfix
            while (i < expression.length() && isdigit(expression[i])) {
                postfix += expression[i];
                i++;
            }
            postfix += " ";
            i--; // Ajuster l'index
        }
        else if (ch == '(') {
            operators.empiler(ch);
        }
        else if (ch == ')') {
            while (!operators.is_empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += " ";
                operators.depiler();
            }
            if (!operators.is_empty()) {
                operators.depiler(); // Retirer '('
            }
        }
        else if (isOperator(ch)) {
            while (!operators.is_empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                postfix += " ";
                operators.depiler();
            }
            operators.empiler(ch);
        }
    }

    // Ajouter les opérateurs restants
    while (!operators.is_empty()) {
        postfix += operators.top();
        postfix += " ";
        operators.depiler();
    }

    return postfix;
}



// Fonction pour effectuer une opération arithmétique
double performOperation(double operand1, double operand2, char op) {
    switch (op) {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/':
        if (operand2 == 0) throw runtime_error("Division par zéro !");
        return operand1 / operand2;
    default: throw runtime_error("Opérateur non valide !");
    }
}



// Fonction pour évaluer une expression postfixée
double evaluatePostfix(const string& postfix) 
{
    PileG<double> stack(postfix.length());

    for (int i = 0; i < postfix.length(); ++i) 
    {
        char ch = postfix[i];

        if (isdigit(ch)) {
            // Lire un nombre entier ou flottant
            double number = 0;
            while (i < postfix.length() && isdigit(postfix[i])) 
            {
                number = number * 10 + (postfix[i] - '0');
                i++;
            }
            stack.empiler(number);
            i--; // Ajuster l'index
        }
        else if (isOperator(ch)) 
        {
            if (stack.is_empty()) throw runtime_error("Expression invalide !");

            double operand2 = stack.top(); 
            stack.depiler();

            if (stack.is_empty()) throw runtime_error("Expression invalide !");

            double operand1 = stack.top(); 
            stack.depiler();
            stack.empiler(performOperation(operand1, operand2, ch));
        }
    }

    if (stack.is_empty()) throw runtime_error("Expression invalide !");
    return stack.top();
}




// Fonction pour inverser une chaîne de caractères
string Inverser_chaine(const string & t) 
{
    PileG<char> R((int)t.length());
    string result = t;

    // Empiler les caractères de la chaîne
    for (int i = 0; i < (int)t.length(); ++i) {
        R.empiler(t[i]);
    }

    // Désempiler les caractères pour inverser la chaîne
    for (int i = 0; i < (int)t.length(); ++i) {
        result[i] = R.top();
        R.depiler();
    }
    return result;
}



// Fonction pour vérifier si une chaîne est un palindrome
bool is_palindrome(const string& t) 
{
    return Inverser_chaine(t) == t;
}



// Exemple d'utilisation des fonctions dans le programme
void palindromeTester() 
{
    cout << "Entrez une chaine pour verifier si c'est un palindrome : ";
    string input;
    cin >> input;

    if (is_palindrome(input)) {
        cout << "La chaine \"" << input << "\" est un palindrome.\n";
    }
    else {
        cout << "La chaine \"" << input << "\" n'est pas un palindrome.\n";
    }
}




// fonction qui represente nmenu de programme
void Menu() 
{
    while (true) {
        cout << "\n========== Menu de calculatrice ==========\n";
        cout << "1. Evaluer une expression arithmetique\n";
        cout << "2. Tester un palindrome\n";
        cout << "3. Quitter\n";
        cout << "=========================================\n";
        cout << "Choisissez une option : ";

        int choix;
        cin >> choix;

        switch (choix) 
        {
            case 1: {
                cout << "\nEntrez une expression infixe (par ex. : (5+3)*(2-1)) :\n";
                string expression;
                cin >> expression;

                try {
                    string postfix = infixToPostfix(expression);
                    cout << "Expression postfixee : " << postfix << endl;
                    double result = evaluatePostfix(postfix);
                    cout << "Resultat : " << result << endl;
                }
                catch (const exception& ex) {
                    cerr << "Erreur : " << ex.what() << endl;
                }
                break;
            }
            case 2: {
                palindromeTester(); // Tester le palindrome
                break;
            }
            case 3:
                cout << "\nFin du programme !\n";
                return;
            default:
                cout << "\nOption invalide. Veuillez reessayer.\n";
        }
    }
}


// Fonction principale
int main() {
    Menu();
    return 0;
}

