#include "Coeur_Projet1.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>

#define MOT_DE_PASSE 6739
#define LIMITE 10


void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void pause() {
    printf("Appuyer sur Entree pour continuer...");
    while (getchar() != '\n');
    getchar();
    printf("\n");
}


int nbre_caracteres(char *chaine) {
    int compteur = 0;
    for (int i = 0; chaine[i] != '\0'; i++) {
        compteur++;
    }
    return compteur;
}

char saisie_securisee_pour_caractere(char *chaine) {
    char choix;
    char saisi[30];
    int valide = 0;
    while (valide != 1) {
        printf("%s", chaine);
        if (fgets(saisi, sizeof(saisi), stdin) == NULL) {
            printf("Saisie invalide !\n");
            printf("Veuillez reessayer encore : ");
            continue;
        } else {
            saisi[strcspn(saisi, "\n")] = '\0';
            if (nbre_caracteres(saisi) != 1) {
                puts("Saisie invalide !");
                vider_buffer();
                printf("Veuillez reessayer encore.\n");
            } else {
                choix = saisi[0];
                valide = 1;
            }
        }
    }
    return choix;
}



long long saisie_securisee_pour_entier(char *chaine) {
    char saisi[30];
    char *fin;
    int valide = 0;
    long long entier_saisi;
    while (valide != 1) {
        errno = 0;
        printf("%s", chaine);
        fgets(saisi, sizeof(saisi), stdin);
        if (strchr(saisi, '\n') == NULL) {
            puts("Saisie tres longue !");
            puts("Veuillez reessayer encore !");
            printf("\n");
            vider_buffer();
            continue;
        }
        saisi[strcspn(saisi, "\n")] = '\0';
        entier_saisi = strtoll(saisi, &fin, 10);
        if (fin == saisi)
            puts("Saisie invalide !");
        else if (*fin != '\0')
            puts("Saisie invalide !");
        else if (errno == ERANGE) {
            puts("Tres longue saisie !");
            vider_buffer();
        }
        else
            valide = 1;
        if (!valide)
            printf("Veuillez reessayer encore.\n\n");
    }
    return entier_saisi;
}



double saisie_securisee_pour_floattant(char *chaine) {
    char saisi[30];
    char *fin;
    int valide = 0;
    double flottant_saisi;
    while (valide != 1) {
        errno = 0;
        printf("%s", chaine);
        fgets(saisi, sizeof(saisi), stdin);
        if (strchr(saisi, '\n') == NULL) {
            puts("Saisie tres longue !");
            puts("Veuillez reessayer encore !");
            printf("\n");
            vider_buffer();
            continue;
        }
        saisi[strcspn(saisi, "\n")] = '\0';
        flottant_saisi = strtod(saisi, &fin);
        if (fin == saisi)
            puts("Saisie invalide !");
        else if (*fin != '\0')
            puts("Saisie invalide !");
        else if (errno == ERANGE) {
            puts("Tres longue saisie !");
            vider_buffer();
        }
        else
            valide = 1;
        if (!valide)
            printf("Veuillez reessayer encore.\n");
    }
    return flottant_saisi;
}


int mot_de_passe() {
    int compteur = 0;
    char saisi[30];
    char *fin;
    int trouve = 0;
    errno = 0;
    puts("Avant de faire quoique ce soit, vous devez entrez le mot de passe !");
    while (trouve != 1 && compteur < LIMITE) {
        printf("Entrez le mot de passe (Tentative %d/%d) : ", compteur+1, LIMITE);
        fgets(saisi, sizeof(saisi), stdin);
        if (strchr(saisi, '\n') == NULL) {
            puts("Tres longue saisie !");
            printf("Veuillez reessayer encore.\n\n");
            compteur++;
            vider_buffer();
            continue;
        }
        saisi[strcspn(saisi, "\n")] = '\0';
        compteur++;
        long code_saisi = strtol(saisi, &fin, 10);
        if (fin == saisi)
            puts("Saisie invalide !");
        else if (*fin != '\0')
            puts("Saisie invalide !");
        else if (errno == ERANGE) {
            puts("Tres longue saisie et donc invalide !");
            vider_buffer();
        }
        else if (code_saisi == MOT_DE_PASSE)
            trouve = 1;
        else {
            if (code_saisi < MOT_DE_PASSE)
                puts("Ce que vous venez de saisir est inferieur au mot de passe !");
            else
                puts("Ce que vous venez de saisir est superieur au mot de passe !");
        }
        if (!trouve) {
            printf("Veuillez reessayer encore.\n");
        }
        printf("\n");
    }
    if (trouve) {
        printf("Bravo ! Vous avez trouve le mot de passe en %d tentative(s).\n", compteur);
        puts("Vous pouvez utiliser les differents menus en toute quietude.");
        printf("\n");
        return 1;
    }
    else {
        puts("Vous avez atteint le maximum de tentatives !");
        puts("Veuillez ressayer plutard !");
        printf("\n");
        return 0;
    }
}


void addition() {
    float valeur;
    double somme = 0.0;
    do {
        valeur = saisie_securisee_pour_floattant("Entrez un nombre (-1 pour arreter et voir le resultat) : ");
        if (valeur == -1)
            continue;
        else
            somme += valeur;
    } while (valeur != -1);
    printf("Resultat = %.2lf\n", somme);
}


void soustraction() {
    double a, b, resultat;
    puts("Vous allez entrez successivement les deux nombres sur lesquels vous voulez faire l'operation de soustraction.");
    a = saisie_securisee_pour_floattant("Entrez le premier nombre : ");
    b = saisie_securisee_pour_floattant("Entrez le second : ");
    resultat = a - b;
    printf("Resultat : %.2f\n", resultat);
}


void multiplication() {
    int compteur;
    float valeur;
    double produit = 1.0;
    compteur = 0;
    do {
        valeur = saisie_securisee_pour_floattant("Entrez un nombre (0 pour arreter la saisie et voir le resultat) : ");
        compteur++;
        if (valeur == 0.0)
            continue;
        else
            produit *= valeur;
    } while (valeur != 0);
    if (compteur == 1 && valeur == 0.0)
        produit = 0.0;
    printf("Resultat : %.2lf\n", produit);
}


void division() {
    double dividende, diviseur, resultat;
    puts("Vous allez entrez successivement les deux nombres (dividende ensuite diviseur) sur lesquesls vous voulez effectuer l'operation de division.");
    dividende = saisie_securisee_pour_floattant("Entrez le dividende : ");
    do {
        diviseur = saisie_securisee_pour_floattant("Entrez le diviseur : ");
        if (diviseur == 0)
            puts("Division par 0 impossible !");
    } while (diviseur == 0);
    resultat = dividende / diviseur;
    printf("Resultat : %.2lf\n", resultat);
}


void operations_simples_generale() {
    char choix;
    do {
        printf("\n");
        puts("-------------------------");
        puts("   OPTIONS DISPONIBLES");
        puts("-------------------------");
        puts("A- Addition");
        puts("S- Soustraction");
        puts("M- Multiplication");
        puts("D- Division");
        printf("Q- Quitter les operations \nsimples et continuer \navec les grands menus\n");
        puts("-------------------------");
        choix = toupper(saisie_securisee_pour_caractere("Entrez votre choix : "));
        printf("\n");
        switch (choix) {
            case 'A' :
                addition();
                break;
            case 'S' :
                soustraction();
                break;
            case 'M' :
                multiplication();
                break;
            case 'D' :
                division();
                break;
            case 'Q' :
                puts("Retour aux grands menus...");
                break;
            default :
                puts("Choix invalide !");
       }
    printf("\n");
    } while (choix != 'Q');
    printf("\n");
}



void operations_simples() {
    double nbre, resultat;
    char operation = '+';
    resultat = 0.0;
    printf("\n");
    puts("NB : Lorsque vous finissez de saisir les nombres et que vous voulez voir le resultat, \nil suffit de saisir 'S' pour Stopper a la place de l'operation !");
    do {
        nbre = saisie_securisee_pour_floattant("Entrez un nombre : ");
        if (operation == '+')
            resultat += nbre;
        else
            resultat -= nbre;
        operation = saisie_securisee_pour_caractere("Entrez une operation (+ ou -) : ");
        while (operation != '+' && operation != '-' && operation != 'S' && operation != 's') {
            puts("Operation invalide !");
            operation = saisie_securisee_pour_caractere("Veuillez reessayer le choix de l'operation : ");
        }
    } while (operation != 'S' && operation != 's');
    printf("Resultat : %.2f\n\n", resultat);
}



void calcul_de_factorielle() {
    long long resultat = 1;
    printf("\n");
    int valeur = saisie_securisee_pour_entier("Entrez l'entier dont vous voulez calculer sa factorielle : ");
    while (valeur > 20) {
        //vider_buffer();
        puts("Veuillez saisir un entier qui ne depasse pas 20 !");
        valeur = saisie_securisee_pour_entier("Entrez l'entier dont vous voulez calculer sa factorielle : ");
    }
    while (valeur < 0) {
        puts("Le calcul de factorielle concerne les entiers positifs !");
        valeur = saisie_securisee_pour_entier("Veuillez reessayer encore : ");
    }
    for (int i = 2; i <= valeur; i++) {
        resultat *= i;
    }
    printf("%d! = %lld\n\n", valeur, resultat);
}



void primalite() {
    long long valeur;
    int estPremier = 1;
    printf("\n");
    valeur = saisie_securisee_pour_entier("Entrez l'entier dont vous voulez verifier sa primalite : ");
    while (valeur <= 1) {
        puts("Le test de primalite concerne les entiers naturels superieur a 1 !");
        valeur = saisie_securisee_pour_entier("Veuillez reessayer encore : ");
    }
    for (long long i = 2; i*i <= valeur; i++) {
        if (valeur % i == 0) {
            estPremier = 0;
            break;
        }
    }
    if (estPremier)
        printf("%lld est un nombre premier.", valeur);
    else
        printf("%lld n'est pas un nombre premier.", valeur);
    printf("\n\n");
}


void diviseurs() {
    int compteur = 0;
    long long valeur;
    printf("\n");
    valeur = saisie_securisee_pour_entier("Entrez l'entier : ");
    while (valeur <= 0) {
        if (valeur < 0)
            puts("Les diviseurs d'entiers negatifs ou nuls ne sont pas pris en compte par ce programme !");
        else {
            puts("Tout element de l'ensemble Z est un divieur de 0.");
            return;
        }
        valeur = saisie_securisee_pour_entier("Entrez un entier strictement positif : ");
    }
    printf("Les diviseurs positifs de %lld sont : ", valeur);
    for (long long i = 1; i <= valeur; i++) {
        if (valeur % i == 0) {
            printf("%lld ", i);
            compteur++;
        }
    }
    printf("\nNombre de diviseurs : %d\n\n", compteur);
}


void multiples() {
    long long valeur;
    printf("\n");
    valeur = saisie_securisee_pour_entier("Entrez l'entier : ");
    while (valeur <= 0) {
        if (valeur < 0)
            puts("Les multiples d'entiers negatifs ne sont pas pris en compte par ce programme !");
        else {
            puts("0 n'a pas de multiples ou est lui-meme son propre mutiple.");
            return;
        }
        valeur = saisie_securisee_pour_entier("Entrez un entier strictement positif : ");
    }
    int nbre_de_multiples = saisie_securisee_pour_entier("Combien de multiples voulez-vous voir ? : ");
    while (nbre_de_multiples < 0) {
        vider_buffer();
        puts("Ca doit etre une valeur strictement positif !");
        nbre_de_multiples = saisie_securisee_pour_entier("Veuillez reessayer encore : ");
    }
    printf("Les %d premiers multiples positifs de %lld sont : ", nbre_de_multiples, valeur);
    for (int i = 1; i <= nbre_de_multiples; i++) {
        printf("%lld ", valeur*i);
    }
    printf("\n\n");
}


void puissance() {
    double resultat = 1.0;
    printf("\n");
    puts("Pour vous permettre de calculer n exposant p, vous allez d'abord saisir le n ensuite le p !");
    double base = saisie_securisee_pour_entier("Entrez le n (la base) : ");
    int expo = saisie_securisee_pour_entier("Entrez le p (l'exposant) : ");
    if (expo < 0) {
        for (int i = 1; i <= -expo; i++) {
            resultat *= base;
        }
        resultat = 1 / resultat;
        printf("Resultat : %.2lf\n", resultat);
    }
    else {
        for (int i = 1; i <= expo; i++) {
            resultat *= base;
        }
        printf("Resultat : %.2lf\n", resultat);
    }
}



long long exposant(int i, int j) {
    long long resultat = 1;
    for (int k = 1; k <= j; k++) {
        resultat *= i;
    }
    return resultat;
}



void decomposition_facteurs_premiers() {
    long long n;
    int exposant;
    int estPremier = 1;
    puts("\nVous allez saisir l'entier dont vous voulez voir sa decomposition en facteurs premiers.");
    puts("NB : En cas de saisie d'un entier negatif (n = -12 par exemple), vous verez la \ndecomposition de 12 et il vous suffira d'ajouter le signe moins (-) au debut de la serie du produit !");
    printf("\n");
    n = saisie_securisee_pour_entier("Entrez l'entier : ");
    if (n == 0)
        puts("0 n'a pas de decomposition en produit de facteurs premier !");
    else if (n == 1)
        puts("1 n'a pas de decomposition en produit de facteurs premiers !");
    else {
        if (n < 0) {n = -n;}
        printf("%lld = ", n);
        if (n % 2 == 0) {
            exposant = 0;
            while (n % 2 == 0) {
                n /= 2;
                exposant++;
            }
            printf("2^%d", exposant);
            estPremier = 0;
        }
        long long diviseur = 3;
        while (diviseur * diviseur <= n) {
            if (n % diviseur == 0) {
                exposant = 0;
                while (n % diviseur == 0) {
                    n /= diviseur;
                    exposant++;
                }
                if (!estPremier) printf(" x ");
                printf("%lld^%d", diviseur, exposant);
                estPremier = 0;
            }
            diviseur += 2;
        }
        if (n > 1) {
            if (!estPremier) printf(" x ");
            printf("%lld^1", n);
        }
    }
    printf("\n\n");
}


int PGCD_deux_entiers(int a, int b) {
    if (b == 0)
        return a;
    int reste = a % b;
    while (reste != 0) {
        a = b;
        b = reste;
        reste = a % b;
    }
    return b;
}


void PPCM() {
    long long nbre_entiers, entier, resultat;
    printf("\n");
    nbre_entiers = saisie_securisee_pour_entier("Vous voulez calculer le PPCM de combien d'entiers ? : ");
    while (nbre_entiers <= 0) {
        puts("Saisie inalide !");
        puts("Veuillez reessayer encore.");
        nbre_entiers = saisie_securisee_pour_entier("Vous voulez calculer le PPCM de combien d'entiers ? : ");
    }
    resultat = saisie_securisee_pour_entier("Entrez l'entier 1 : ");
    for (long long i = 2; i <= nbre_entiers; i++) {
        printf("Entrez l'entier %lld : ", i);
        scanf("%lld", &entier);
        if (resultat == 0 || entier == 0)
            resultat = 0;
        else
            resultat = (resultat * entier) / PGCD_deux_entiers(resultat, entier);
    }
    vider_buffer();
    printf("Resultat : %lld\n\n", resultat);
}



void PGCD() {
    long long nbre_entiers, entier, resultat;
    printf("\n");
    nbre_entiers = saisie_securisee_pour_entier("Vous voulez calculer le PGCD de combien d'entiers ? : ");
    while (nbre_entiers <= 0) {
        puts("Saisie inalide !");
        puts("Veuillez reessayer encore.");
        nbre_entiers = saisie_securisee_pour_entier("Vous voulez calculer le PGCD de combien d'entiers ? : ");
    }
    resultat = saisie_securisee_pour_entier("Entrez l'entier 1 : ");
    for (long long i = 2; i <= nbre_entiers; i++) {
        printf("Entrez l'entier %lld : ", i);
        scanf("%lld", &entier);
        resultat = PGCD_deux_entiers(resultat, entier);
    }
    vider_buffer();
    printf("Resultat : %lld\n\n", resultat);
}



void sigma() {
    int choix, n, m, a, b, c, t, i, j;
    long long somme = 0;
    double somme_rationnelle = 0.0;
    puts("\nVoici la liste des fonctions disponibles pour le calcul de la somme :");
    puts("---------------------------------");
    puts("    FONCTIONS DISPONIBLES");
    puts("---------------------------------");
    puts("'''''FONCTIONS POLYNOMIALES'''''");
    puts("1. f(k) = ak^n + b");
    puts("2. f(k) = ak^n + bk^m + c");
    puts("3. f(k) = (ak^n + bk^m + c)^t");
    printf("\n");
    puts("'''''FONCTIONS AVEC PUISSANCE'''''");
    puts("4. f(k) = k^n");
    printf("\n");
    puts("'''''FONCTIONS EXPONENTIELLES'''''");
    puts("5. f(k) = a^k");
    printf("\n");
    puts("'''''FONCTIONS RATIONNELLES'''''");
    puts("6. f(k) = 1 / k^n");
    puts("7. f(k) = 1 / ak^n + b");
    puts("8. f(k) = 1 / (ak^n + bk^m + c)^t");
    printf("\n");
    puts("'''''AUTRES FONCTIONS'''''");
    puts("9. f(k) = k.(-1)^k");
    puts("10. f(k) = (-1)^k / k");
    puts("---------------------------------");
    choix = saisie_securisee_pour_entier("Entrez votre choix de fonction : ");
    printf("\n");
    switch (choix) {
        case 1 :
            puts("Fonction choisie : f(k) = ak^n + b");
            puts("Pour vous permettre de calculer la somme sur k allant de i a j de cette fonction, vous allez devoir fournir les informations ci-dessous.");
            i = saisie_securisee_pour_entier("Entrez la valeur de i : ");
            j = saisie_securisee_pour_entier("Entrez la valeur de j : ");
            printf("\n");
            n = saisie_securisee_pour_entier("Entrez la valeur de n : ");
            a = saisie_securisee_pour_entier("Entrez la valeur de a : ");
            b = saisie_securisee_pour_entier("Entrez la valeur de b : ");
            for (int k = i; k <= j; k++) {
                somme += a*exposant(k, n) + b;
            }
            printf("Resultat : %lld\n", somme);
            break;
        case 2 :
            puts("Fonction choisie : f(k) = ak^n + bk^m + c");
            puts("Pour vous permettre de calculer la somme sur k allant de i a j de cette fonction, vous allez devoir fournir les informations ci-dessous.");
            i = saisie_securisee_pour_entier("Entrez la valeur de i : ");
            j = saisie_securisee_pour_entier("Entrez la valeur de j : ");
            printf("\n");
            n = saisie_securisee_pour_entier("Entrez la valeur de n : ");
            m = saisie_securisee_pour_entier("Entrez la valeur de m : ");
            a = saisie_securisee_pour_entier("Entrez la valeur de a : ");
            b = saisie_securisee_pour_entier("Entrez la valeur de b : ");
            c = saisie_securisee_pour_entier("Entrez la valeur de c : ");
            for (int k = i; k <= j; k++) {
                somme += a*exposant(k, n) + b*exposant(k, m) + c;
            }
            printf("Resultat : %lld\n", somme);
            break;
        case 3 :
            puts("Fonction choisie : f(k) = (ak^n + bk^m + c)^t");
            puts("Pour vous permettre de calculer la somme sur k allant de i a j de cette fonction, vous allez devoir fournir les informations ci-dessous.");
            i = saisie_securisee_pour_entier("Entrez la valeur de i : ");
            j = saisie_securisee_pour_entier("Entrez la valeur de j : ");
            printf("\n");
            n = saisie_securisee_pour_entier("Entrez la valeur de n : ");
            m = saisie_securisee_pour_entier("Entrez la valeur de m : ");
            t = saisie_securisee_pour_entier("Entrez la valeur de t : ");
            a = saisie_securisee_pour_entier("Entrez la valeur de a : ");
            b = saisie_securisee_pour_entier("Entrez la valeur de b : ");
            c = saisie_securisee_pour_entier("Entrez la valeur de c : ");
            for (int k = i; k <= j; k++) {
                somme += a*exposant(k, n) + b*exposant(k, m) + c;
            }
            printf("Resultat : %lld\n", somme);
            break;
        case 4 :
            puts("Fonction choisie : f(k) = k^n");
            puts("Pour vous permettre de calculer la somme sur k allant de i a j de cette fonction, vous allez devoir fournir les informations ci-dessous.");
            n = saisie_securisee_pour_entier("Entrez la valeur de n : ");
            i = saisie_securisee_pour_entier("Entrez la valeur de i : ");
            j = saisie_securisee_pour_entier("Entrez la valeur de j : ");
            for (int k = i; k <= j; k++) {
                somme += exposant(k, n);
            }
            printf("Resultat : %lld\n", somme);
            break;
        case 5 :
            puts("Fonction choisie : f(k) = a^k");
            puts("Pour vous permettre de calculer la somme sur k allant de i a j de cette fonction, vous allez devoir fournir les informations ci-dessous.");
            a = saisie_securisee_pour_entier("Entrez la valeur de a : ");
            i = saisie_securisee_pour_entier("Entrez la valeur de i : ");
            j = saisie_securisee_pour_entier("Entrez la valeur de j : ");
            for (int k = i; k <= j; k++) {
                somme += exposant(a, k);
            }
            printf("Resultat : %lld\n", somme);
            break;
        case 6 :
            puts("Fonction choisie : f(k) = 1 / k^n");
            puts("Pour vous permettre de calculer la somme sur k allant de i a j de cette fonction, vous allez devoir fournir les informations ci-dessous.");
            n = saisie_securisee_pour_entier("Entrez la valeur de n : ");
            i = saisie_securisee_pour_entier("Entrez la valeur de i : ");
            while (i == 0) {
                puts("Aucun terme ne doit s'annuler au denominateur !");
                i = saisie_securisee_pour_entier("Veuillez reessyer la saisie de i : ");
            }
            j = saisie_securisee_pour_entier("Entrez la valeur de j : ");
            for (int k = i; k <= j; k++) {
                somme_rationnelle += 1.0 / exposant(k, n);
            }
            printf("Resultat : %.2lf\n", somme_rationnelle);
            break;
        case 7 :
            puts("Fonction choisie : f(k) = 1 / ak^n + b");
            puts("Pour vous permettre de calculer la somme sur k allant de i a j de cette fonction, vous allez devoir fournir les informations ci-dessous.");
            i = saisie_securisee_pour_entier("Entrez la valeur de i : ");
            j = saisie_securisee_pour_entier("Entrez la valeur de j : ");
            printf("\n");
            n = saisie_securisee_pour_entier("Entrez la valeur de n : ");
            a = saisie_securisee_pour_entier("Entrez la valeur de a : ");
            b = saisie_securisee_pour_entier("Entrez la valeur de b : ");
            while (b == 0 && i == 0) {
                puts("Aucun terme ne doit s'annuler au denominateur !");
                puts("Veuillez reessayer les saisies de i et de b.");
                i = saisie_securisee_pour_entier("Entrez la valeur de i : ");
                b = saisie_securisee_pour_entier("Entrez la valeur de b : ");
            }
            for (int k = i; k <= j; k++) {
                somme_rationnelle += 1.0 / (a*exposant(k, n) + b);
            }
            printf("Resultat : %.2lf\n", somme_rationnelle);
            break;
        case 8 :
            puts("Fonction choisie : f(k) = (ak^n + bk^m + c)^t");
            puts("Pour vous permettre de calculer la somme sur k allant de i a j de cette fonction, vous allez devoir fournir les informations ci-dessous.");
            i = saisie_securisee_pour_entier("Entrez la valeur de i : ");
            j = saisie_securisee_pour_entier("Entrez la valeur de j : ");
            printf("\n");
            n = saisie_securisee_pour_entier("Entrez la valeur de n : ");
            m = saisie_securisee_pour_entier("Entrez la valeur de m : ");
            t = saisie_securisee_pour_entier("Entrez la valeur de t : ");
            a = saisie_securisee_pour_entier("Entrez la valeur de a : ");
            b = saisie_securisee_pour_entier("Entrez la valeur de b : ");
            c = saisie_securisee_pour_entier("Entrez la valeur de c : ");
            for (int k = i; k <= j; k++) {
                somme_rationnelle += 1.0 / exposant((a*exposant(k, n) + b*exposant(k, m) + c), t);
            }
            printf("Resultat : %.2lf\n", somme_rationnelle);
            break;
        case 9 :
            puts("Fonction choisie : f(k) = k.(-1)^k");
            puts("Pour vous permettre de calculer la somme sur k allant de i a j de cette fonction, vous allez devoir fournir les informations ci-dessous.");
            i = saisie_securisee_pour_entier("Entrez la valeur de i : ");
            j = saisie_securisee_pour_entier("Entrez la valeur de j : ");
            for (int k = i; k <= j; k++) {
                somme += k*exposant(-1, k);
            }
            printf("Resultat : %lld\n", somme);
            break;
        case 10 :
            puts("Fonction choisie : f(k) = (-1)^k / k");
            puts("Pour vous permettre de calculer la somme sur k allant de i a j de cette fonction, vous allez devoir fournir les informations ci-dessous.");
            i = saisie_securisee_pour_entier("Entrez la valeur de i : ");
            j = saisie_securisee_pour_entier("Entrez la valeur de j : ");
            for (int k = i; k <= j; k++) {
                somme_rationnelle += (float)exposant(-1, k) / k;
            }
            printf("Resultat : %.2lf\n", somme_rationnelle);
            break;
        default :
            puts("Saisie inavlide !");
    }
    printf("\n");
}



void nbre_chiffres() {
    long long entier, sauvegarde;
    int compteur = 0;
    printf("\n");
    entier = saisie_securisee_pour_entier("Entrez le nombre entier dont vous souhaitez compter le nombre de chiffres qui le composent : ");
    sauvegarde = entier;
    while (entier != 0) {
        entier /= 10;
        compteur++;
    }
    printf("%lld compte %d chiffres.\n\n", sauvegarde, compteur);
}



void inverser_nbre() {
    int entier, inverse;
    printf("\n");
    entier = saisie_securisee_pour_entier("Veuillez saisir l'entier : ");
    inverse = 0;
    while (entier != 0) {
        inverse = inverse*10 + entier%10;
        entier /= 10;
    }
    printf("Apres inversion des positions des ciffres, on obtient : %d\n\n", inverse);
}



int mot_est_palyndrome(char *chaine) {
    int debut = 0;
    int fin = strlen(chaine)-1;
    while (debut < fin) {
        if (chaine[debut] != chaine[fin])
            return 0;
        debut++;
        fin--;
    }
    return 1;
}



int nombre_est_palyndrome(int n) {
    int inverse, sauvegarde;
    sauvegarde = n;
    inverse = 0;
    while (n != 0) {
        inverse = inverse*10 + n%10;
        n /= 10;
    }
    if (inverse == sauvegarde)
        return 1;
    return 0;
}



void palindrome() {
    int choix, nombre;
    char mot[15];
    puts("\nChoix disponibles pour verifier le palyndrome :");
    puts("1- Mot");
    puts("2- Nombre");
    choix = saisie_securisee_pour_entier("Entrez votre choix : ");
    switch (choix) {
        case 1 :
            printf("Entrez le mot : ");
            scanf("%14s", mot);
            vider_buffer();
            if (mot_est_palyndrome(mot))
                printf("%s est un palyndrome.\n", mot);
            else
                printf("%s n'est pas un palyndrome.\n", mot);
            break;
        case 2 :
            nombre = saisie_securisee_pour_entier("Entrez le nombre : ");
            if (nombre_est_palyndrome(nombre))
                printf("%d est un palyndrome.\n", nombre);
            else
                printf("%d n'est pas un palyndrome.\n", nombre);
            break;
        default :
            puts("Choix invalide !");
            printf("Les choix possibles sont : 1, 2 !");
    }
    printf("\n");
}



long long suite_fibonacci(int n) {
    if (n <= 1)
        return n;
    return suite_fibonacci(n-2)+suite_fibonacci(n-1);
}


void fibonacci() {
    int choix, n, p;
    long long a, b, temp;
    printf("\n");
    puts("Options disponible :");
    puts("1- Afficher les n premiers termes de la suite de fibonacci");
    puts("2- Afficher le terme au rang p");
    choix = saisie_securisee_pour_entier("Entrez votre choix : ");
    printf("\n");
    switch (choix) {
        case 1 :
            n = saisie_securisee_pour_entier("Entrez la valeur de n : ");
            while (n > 50) {
                puts("Vous ne pouvez pas afficher plus que les 50 premiers termes !");
                n = saisie_securisee_pour_entier("Entrez la valeur de n : ");
            }
            a = 0;
            b = 1;
            printf("Les %d premiers termes de la suite de Fibonacci sont : ", n);
            for (int i = 1; i <= n; i++) {
                printf("%lld ", a);
                temp = a+b;
                a = b;
                b = temp;
            }
            break;
        case 2 :
            p = saisie_securisee_pour_entier("Entrez le rang du terme que vous souhaitez voir : ");
            while (p > 50) {
                puts("Vous ne pouvez pas afficher plus que le terme au rang 50 !");
                p = saisie_securisee_pour_entier("Entrez la valeur de p : ");
            }
            printf("Le terme au rang %d est : %lld\n", p, suite_fibonacci(p));
            break;
        default :
            puts("Choix invalide !");
            puts("Les choix possibles sont : 1, 2");
    }
    printf("\n\n");
}



int longueur_restes(int n, int base_cible) {
    int compteur = 0;
    if (n == 0) return 1;
    if (n < 0) n = -n;
    while (n != 0) {
        n /= base_cible;
        compteur++;
    }
    return compteur;
}


void decimal_vers_binaire() {
    int n, compteur, taille;
    n = saisie_securisee_pour_entier("Entrez le nombre en decimal que vous voulez convertir en binaire : ");
    printf("%d = ", n);
    taille = longueur_restes(n, 2);
    int restes[taille];
    compteur = 0;
    while (n != 0) {
        restes[compteur] = n % 2;
        n /= 2;
        compteur++;
    }
    for (int i = compteur-1; i >= 0; i--) {
        printf("%d", restes[i]);
    }
}


void decimal_vers_octal() {
    int n, compteur;
    printf("\n");
    n = saisie_securisee_pour_entier("Entrez le nombre en decimal que vous voulez convertir en octal : ");
    printf("%d = ", n);
    int restes[longueur_restes(n, 8)];
    compteur = 0;
    while (n != 0) {
        restes[compteur] = n % 8;
        n /= 8;
        compteur++;
    }
    for (int i = compteur-1; i >= 0; i--) {
        printf("%d", restes[i]);
    }
}


void decimal_vers_hexa() {
    int n, reste, compteur;
    char symboles[] = "0123456789ABCDEF";
    printf("\n");
    n = saisie_securisee_pour_entier("Entrez le nombre en decimal que vous voulez convertir en hexadecimale : ");
    if (n == 0) {printf("0"); return;}
    printf("%d = ", n);
    char restes[longueur_restes(n, 16)];
    compteur = 0;
    while (n != 0) {
        reste = n % 16;
        restes[compteur] = symboles[reste];
        n /= 16;
        compteur++;
    }
    for (int i = compteur-1; i >= 0; i--) {
        printf("%c", restes[i]);
    }
}


int nbre_chiffre_entier(int n) {
    int compteur = 0;
    while (n != 0) {
        n /= 10;
        compteur++;
    }
    return compteur;
}


void binaire_vers_decimal() {
    int entier, i;
    long long somme;
    printf("\n");
    entier = saisie_securisee_pour_entier("Entrez le nombre en binaire que vous voulez convertir en decimal : ");
    somme = i = 0;
    printf("%d = ", entier);
    while (entier != 0) {
        somme += (entier%10) * exposant(2, i);
        entier /= 10;
        i++;
    }
    printf("%lld", somme);
}


void octal_vers_decimal() {
    int entier, i;
    long long somme;
    printf("\n");
    entier = saisie_securisee_pour_entier("Entrez le nombre en octal que vous voulez convertir en decimal : ");
    somme = i = 0;
    printf("%d = ", entier);
    while (entier != 0) {
        somme += (entier%10) * exposant(8, i);
        entier /= 10;
        i++;
    }
    printf("%lld", somme);
}


void hexa_vers_decimal() {
    int valide;
    long nombre;
    char saisi[30];
    char *fin;
    errno = 0;
    valide = 0;
    printf("\n");
    while (valide != 1) {
    printf("Entrez le nombre en hexadecimal que vous voulez convertir en decimal : ");
    scanf("%s", saisi);
    vider_buffer();
    nombre = strtol(saisi, &fin, 16);
    if (fin == saisi) {
        printf("Saisie invalide !");
        puts("Veuillez reessayer encore.");
    }
    else if (*fin != '\0') {
        printf("Saisie invalide !");
        puts("Veuillez reessayer encore.");
    }
    else if (errno == ERANGE) {
        printf("Tres longue saisie !");
        puts("Veuillez reessayer.");
    }
    else
        valide = 1;
    }
    printf("%s = %ld", saisi, nombre);
}


void conversion_base() {
    int choix;
    printf("\n");
    puts("--------------------------");
    puts("    OPTIONS DISPONIBLES");
    puts("--------------------------");
    puts("1- Decimal vers bianire");
    puts("2- Decimal vers octal");
    puts("3- Decimal vers hexadecimal");
    puts("---------------------------");
    puts("4- Binaire vers decimal");
    puts("5- Octal vers decimal");
    puts("6- Hexadecimal vers decimal");
    puts("---------------------------");
    choix = saisie_securisee_pour_entier("Veuillez saisir votre choix : ");
    switch (choix) {
        case 1 :
            decimal_vers_binaire();
            break;
        case 2 :
            decimal_vers_octal();
            break;
        case 3 :
            decimal_vers_hexa();
            break;
        case 4 :
            binaire_vers_decimal();
            break;
        case 5 :
            octal_vers_decimal();
            break;
        case 6 :
            hexa_vers_decimal();
            break;
        default :
            puts("Choix invalide !");
    }
    printf("\n\n");
}



void somme_des_chiffres() {
    long long nombre, sauvegarde;
    int somme;
    printf("\n");
    nombre = saisie_securisee_pour_entier("Veuillez saisir l'entier : ");
    sauvegarde = nombre;
    somme = 0;
    while (nombre != 0) {
        somme += nombre%10;
        nombre /= 10;
    }
    printf("La somme des chiffres qui composent %lld est : %d\n", sauvegarde, somme);
}



void petit_grand_chiffre() {
    long long saisi, sauvegarde;
    int chiffre, max, min;
    printf("\n");
    saisi = saisie_securisee_pour_entier("Saisissez l'entier : ");
    sauvegarde = saisi;
    if (saisi < 0)
        saisi = -saisi;
    max = min = saisi % 10;
    saisi /= 10;
    while (saisi != 0) {
        chiffre = saisi % 10;
        if (chiffre > max)
            max = chiffre;
        if (chiffre < min)
            min = chiffre;
        saisi /= 10;
    }
    printf("Le plus petit des chifres qui composent %lld est : %d\n", sauvegarde, min);
    printf("Le plus grand des chiffres qui composent %lld est : %d\n", sauvegarde, max);
    printf("\n");
}



void carre_parfait() {
    int est_carre_parfait;
    long long n, i;
    printf("\n");
    n = saisie_securisee_pour_entier("Entrez l'entier : ");
    i = est_carre_parfait = 0;
    while (i*i <= n) {
        if (i*i == n)
            est_carre_parfait = 1;
        i++;
    }
    if (est_carre_parfait)
        printf("%lld est un carre parfait.\n", n);
    else
        printf("%lld n'est pas un carre parfait.\n", n);
    printf("\n");
}


long long factorielle(int n) {
    long long resultat = 1;
    for (long long i = 2; i <= n; i++) {
        resultat *= i;
    }
    return resultat;
}


long long decrementation(int n, int p) {
    int compteur = 1;
    long long resultat = 1;
    int i = n;
    while (compteur <= p) {
        resultat *= i;
        compteur++;
        i--;
    }
    return resultat;
}



void arrangement() {
    int p, n;
    long long resultat;
    puts("Pour vous permettre de calculer arrangement de p dans n, vous allez d'abord saisir le p ensuite le n !");
    p = saisie_securisee_pour_entier("Entrez le p : ");
    n = saisie_securisee_pour_entier("Entrez le n : ");
    while (p > n) {
        puts("Le p ne doit pas depasser le n !");
        puts("Veuillez reprendre les saisies !");
        p = saisie_securisee_pour_entier("Entrez le p : ");
        n = saisie_securisee_pour_entier("Entrez le n : ");
    }
    if (n == p)
        resultat = 1;
    else
        resultat = decrementation(n, p);
    printf("Arrangement de %d dans %d = %lld\n", p, n, resultat);
}


void arrangement_interactive() {
    long long n, p, resultat_final, resultat;
    char operation = 'x';
    puts("NB : Lorsque vous finissez et que vous voulez voir le resultat, \nil suffit de saisir 'S' pour Stopper a la place de l'operation !\n");
    puts("Pour vous permettre de calculer Arrangement de p dans n, vous allez d'abord saisir le p ensuite le n !");
    resultat_final = 1;
    do {
        p = saisie_securisee_pour_entier("Entrez le p : ");
        n = saisie_securisee_pour_entier("Entrez le n : ");
        while (p > n) {
           puts("Le p ne doit pas depasser le n !");
           puts("Veuillez reprendre les saisies !");
           p = saisie_securisee_pour_entier("Entrez le p : ");
           n = saisie_securisee_pour_entier("Entrez le n : ");
        }
        if (n == p)
            resultat = 1;
        else
            resultat = decrementation(n, p);

        if (operation == 'x')
            resultat_final *= resultat;
        else
            resultat_final /= resultat;
        operation = saisie_securisee_pour_caractere("Entrez une operation (x ou /) : ");
        while (operation != 'x' && operation != '/' && operation != 'S' && operation != 's') {
            puts("Operation invalide !");
            operation = saisie_securisee_pour_caractere("Veuillez reessayer le choix de l'operation : ");
        }
    } while (operation != 'S' && operation != 's');
    printf("Resultat : %lld\n\n", resultat_final);
}



void combinaison() {
    int p, n;
    long long resultat;
    puts("Pour vous permettre de calculer combinaison de p dans n, vous allez d'abord saisir le p ensuite le n !");
    p = saisie_securisee_pour_entier("Entrez le p : ");
    n = saisie_securisee_pour_entier("Entrez le n : ");
    while (p > n) {
        puts("Le p ne doit pas depasser le n !");
        puts("Veuillez reprendre les saisies !");
        p = saisie_securisee_pour_entier("Entrez le p : ");
        n = saisie_securisee_pour_entier("Entrez le n : ");
    }
    if (n == p)
        resultat = 1;
    else
        resultat = decrementation(n, p) / factorielle(p);
    printf("Combinaison de %d dans %d = %lld\n", p, n, resultat);
}


void combinaison_intercative() {
    long long n, p, resultat_final, resultat;
    char operation = 'x';
    puts("NB : Lorsque vous finissez et que vous voulez voir le resultat, \nil suffit de saisir 'S' pour Stopper a la place de l'operation !\n");
    puts("Pour vous permettre de calculer combinaison de p dans n, vous allez d'abord saisir le p ensuite le n !");
    resultat_final = 1;
    do {
        p = saisie_securisee_pour_entier("Entrez le p : ");
        n = saisie_securisee_pour_entier("Entrez le n : ");
        while (p > n) {
           puts("Le p ne doit pas depasser le n !");
           puts("Veuillez reprendre les saisies !");
           p = saisie_securisee_pour_entier("Entrez le p : ");
           n = saisie_securisee_pour_entier("Entrez le n : ");
        }
        if (n == p)
            resultat = 1;
        else
            resultat = decrementation(n, p) / factorielle(p);

        if (operation == 'x')
            resultat_final *= resultat;
        else
            resultat_final /= resultat;
        operation = saisie_securisee_pour_caractere("Entrez une operation (x ou /) : ");
        while (operation != 'x' && operation != '/' && operation != 'S' && operation != 's') {
            puts("Operation invalide !");
            operation = saisie_securisee_pour_caractere("Veuillez reessayer le choix de l'operation : ");
        }
    } while (operation != 'S' && operation != 's');
    printf("Resultat : %lld\n\n", resultat_final);
}



void analyse_combinatoire() {
    int choix;
    printf("\n");
    do {
    puts("-------------------------------------------------------");
    puts("                 CHOIX DISPONIBLES");
    puts("-------------------------------------------------------");
    puts("1- Outils de denombrement");
    puts("2- p-uplet");
    puts("3- Arrangement");
    puts("4- Combinaison");
    puts("5- Composition du jeu de 32 cartes");
    puts("--------------------------------------------------------");
    puts("6- Quitter le combinatoire et retourner aux grands menus");
    puts("--------------------------------------------------------");
    choix = saisie_securisee_pour_entier("Entrez votre choix : ");
    printf("\n");
    switch(choix) {
        case 1 :
            puts("-------------------------------------------------------------------");
            printf("%-25s %-25s %-25s\n", "Outil de denombrement", "Repetition possible", "Ordre important");
            printf("%-25s %-25s %-25s\n", "---------------------", "-------------------", "---------------");
            printf("%-25s %-25s %-25s\n", "p-uplet", "Oui", "Oui");
            printf("%-25s %-25s %-25s\n", "Arrangement", "Non", "Oui");
            printf("%-25s %-25s %-25s\n", "Combinaison", "Non", "Non");
            puts("-------------------------------------------------------------------");
            printf("\n\n");
            break;
        case 2 :
            puissance();
            printf("\n\n");
            break;
        case 3 :
            arrangement_interactive();
            printf("\n\n");
            break;
        case 4 :
            combinaison_intercative();
            printf("\n\n");
            break;
        case 5 :
            puts("Le jeu de 32 cartes est compose de 4 couleurs :");
            puts("8 trefles  (7, 8, 9, 10, as, dame, roi, valet)");
            puts("8 coeurs   (7, 8, 9, 10, as, dame, roi, valet)");
            puts("8 piques   (7, 8, 9, 10, as, dame, roi, valet)");
            puts("8 carreaux (7, 8, 9, 10, as, dame, roi, valet)");
            printf("\n\n");
            break;
        case 6 :
            puts("Retour aux grands menus...");
            break;
        default :
            puts("Choix invalide !");
    }
    } while (choix != 6);
}


void statistique_simple() {
    long long n, somme, max, min;
    int compteur = 0;
    double moyenne;
    somme = min = max = 0;
    do {
        n = saisie_securisee_pour_entier("Entrez un nombre (-1 pour arreter) : ");
        if (n == -1)
            continue;
        compteur++;
        somme += n;
        if (compteur == 1) {
            min = n;
            max = n;
        } else {
            if (n > max)
                max = n;
            if (n < min)
                min = n;
        }
    } while (n != -1);
    if (compteur == 0) {
        puts("Aucun nombre n'a ete saisi !");
        printf("\n");
        return;
    }
    moyenne = (double)somme / compteur;
    printf("\n");
    puts("--------------------");
    puts("    STATISTIQUE");
    puts("--------------------");
    printf("Somme   : %lld\n", somme);
    printf("Minimum : %lld\n", min);
    printf("Maximum : %lld\n", max);
    printf("Moyenne : %.2lf\n", moyenne);
    puts("--------------------");
    printf("\n");
}



void CFA_vers_USD() {
    double monnaie_CFA, monnaie_USD;
    monnaie_CFA = saisie_securisee_pour_floattant("Entrez la somme en CFA que vous voulez convertir en USD : ");
    monnaie_USD = monnaie_CFA / 566;
    printf("%.2lf CFA = %.3lf USD\n", monnaie_CFA, monnaie_USD);
}



void USD_vers_CFA() {
    double monnaie_CFA, monnaie_USD;
    monnaie_USD = saisie_securisee_pour_floattant("Entrez la somme en USD que vous voulez convertir en CFA : ");
    monnaie_CFA = monnaie_USD * 566;
    printf("%.2lf USD = %.3lf CFA\n", monnaie_USD, monnaie_CFA);
}



void CFA_vers_CAD() {
    double monnaie_CFA, monnaie_CAD;
    monnaie_CFA = saisie_securisee_pour_floattant("Entrez la somme en CFA que vous voulez convertir en CAD : ");
    monnaie_CAD = monnaie_CFA * 0.0024;
    printf("%.2lf CFA = %.3lf CAD\n", monnaie_CFA, monnaie_CAD);
}



void CAD_vers_CFA() {
    double monnaie_CFA, monnaie_CAD;
    monnaie_CAD = saisie_securisee_pour_floattant("Entrez la somme en CAD que vous voulez convertir en CFA : ");
    monnaie_CFA = monnaie_CAD / 0.0024;
    printf("%.2lf USD = %.3lf CFA\n", monnaie_CAD, monnaie_CFA);
}



void CFA_vers_CNY() {
    double monnaie_CFA, monnaie_CNY;
    monnaie_CFA = saisie_securisee_pour_floattant("Entrez la somme en CFA que vous voulez convertir en CNY : ");
    monnaie_CNY = monnaie_CFA * 0.012;
    printf("%.2lf CFA = %.3lf CNY\n", monnaie_CFA, monnaie_CNY);
}



void CNY_vers_CFA() {
    double monnaie_CFA, monnaie_CNY;
    monnaie_CNY = saisie_securisee_pour_floattant("Entrez la somme en CNY que vous voulez convertir en CFA : ");
    monnaie_CFA = monnaie_CNY / 0.012;
    printf("%.2lf CNY = %.3lf CFA\n", monnaie_CNY, monnaie_CFA);
}



void CFA_vers_MAD() {
    double monnaie_CFA, monnaie_MAD;
    monnaie_CFA = saisie_securisee_pour_floattant("Entrez la somme en CFA que vous voulez convertir en MAD : ");
    monnaie_MAD = monnaie_CFA * 0.0162;
    printf("%.2lf CFA = %.3lf MAD\n", monnaie_CFA, monnaie_MAD);
}



void MAD_vers_CFA() {
    double monnaie_CFA, monnaie_MAD;
    monnaie_MAD = saisie_securisee_pour_floattant("Entrez la somme en MAD que vous voulez convertir en CFA : ");
    monnaie_CFA = monnaie_MAD / 0.0162;
    printf("%.2lf MAD = %.3lf CFA\n", monnaie_MAD, monnaie_CFA);
}



void CFA_vers_NGN() {
    double monnaie_CFA, monnaie_NGN;
    monnaie_CFA = saisie_securisee_pour_floattant("Entrez la somme en CFA que vous voulez convertir en NGN : ");
    monnaie_NGN = monnaie_CFA * 2.39;
    printf("%lf CFA = %.3lf NGN\n", monnaie_CFA, monnaie_NGN);
}



void NGN_vers_CFA() {
    double monnaie_CFA, monnaie_NGN;
    monnaie_NGN = saisie_securisee_pour_floattant("Entrez la somme en NGN que vous voulez convertir en CFA : ");
    monnaie_CFA = monnaie_NGN / 2.39;
    printf("%.2lf NGN = %.3lf CFA\n", monnaie_NGN, monnaie_CFA);
}



void CFA_vers_Euro() {
    double monnaie_CFA, monnaie_Euro;
    monnaie_CFA = saisie_securisee_pour_floattant("Entrez la somme en CFA que vous voulez convertir en Euro : ");
    monnaie_Euro = monnaie_CFA / 655.957;
    printf("%.2lf CFA = %.3lf Euro\n", monnaie_CFA, monnaie_Euro);
}



void Euro_vers_CFA() {
    double monnaie_CFA, monnaie_Euro;
    monnaie_Euro = saisie_securisee_pour_floattant("Entrez la somme en Euro que vous voulez convertir en CFA : ");
    monnaie_CFA = monnaie_Euro * 655.957;
    printf("%.2lf Euro = %.3lf CFA\n", monnaie_Euro, monnaie_CFA);
}



void CFA_vers_GHS() {
    double monnaie_CFA, monnaie_GHS;
    monnaie_CFA = saisie_securisee_pour_floattant("Entrez la somme en CFA que vous voulez convertir en GHS : ");
    monnaie_GHS = monnaie_CFA * 0.0197;
    printf("%.2lf CFA = %.3lf GHS\n", monnaie_CFA, monnaie_GHS);
}



void GHS_vers_CFA() {
    double monnaie_CFA, monnaie_GHS;
    monnaie_GHS = saisie_securisee_pour_floattant("Entrez la somme en GHS que vous voulez convertir en CFA : ");
    monnaie_CFA = monnaie_GHS / 0.0197;
    printf("%.2lf GHS = %.3lf CFA\n", monnaie_GHS, monnaie_CFA);
}



void conversion_monnaie() {
    long long choix;
    printf("\n");
    do {
        puts("*********************************************");
        puts("         CONVERSIONS DISPONIBLES");
        puts("*********************************************");
        puts("1- CFA vers USD (Dollar Americain)");
        puts("2- USD vers CFA");
        puts(".............................................");
        puts("3- CFA vers CAD (Dollar Canadien)");
        puts("4- CAD vers CFA");
        puts(".............................................");
        puts("5- CFA vers CNY (Yuan Chinois)");
        puts("6- CNY vers CFA");
        puts(".............................................");
        puts("7- CFA vers MAD (Dirham Marocain)");
        puts("8- MAD vers CFA");
        puts(".............................................");
        puts("9- CFA vers NGN (Naira Nigerian)");
        puts("10- NGN vers CFA");
        puts(".............................................");
        puts("11- CFA vers Euro");
        puts("12- Euro vers CFA");
        puts(".............................................");
        puts("13- CFA vers GHS (Cedi Ghaneen)");
        puts("14- GHS vers CFA");
        puts(".............................................");
        puts("0- Quitter et continer avec les grands menus");
        puts("*********************************************");
        choix = saisie_securisee_pour_entier("Entrez votre choix : ");
        switch (choix) {
            case 0 :
                puts("Retout aux grands menus...");
                break;
            case 1 :
                CFA_vers_USD();
                break;
            case 2 :
                USD_vers_CFA();
                break;
            case 3 :
                CFA_vers_CAD();
                break;
            case 4 :
                CAD_vers_CFA();
                break;
            case 5 :
                CFA_vers_CNY();
                break;
            case 6 :
                CNY_vers_CFA();
                break;
            case 7 :
                CFA_vers_MAD();
                break;
            case 8 :
                MAD_vers_CFA();
                break;
            case 9 :
                CFA_vers_NGN();
                break;
            case 10 :
                NGN_vers_CFA();
                break;
            case 11 :
                CFA_vers_Euro();
                break;
            case 12 :
                Euro_vers_CFA();
                break;
            case 13 :
                CFA_vers_GHS();
                break;
            case 14 :
                GHS_vers_CFA();
                break;
            default :
                puts("Choix invalide !");
        }
        printf("\n\n");
    } while (choix != 0);
}




int estBissextile(long long annee) {
    if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0)
        return 1;
    return 0;
}



void annee_bissextile() {
    long long choix, annee, n, i;
    int compteur;
    printf("\n");
    do {
        puts("----------------------------------------------");
        puts("             CHOIX DISPONIBLES");
        puts("----------------------------------------------");
        puts("1- Verifier si une annee est bissextile");
        puts("2- Afficher les n dernieres annees bissextiles");
        puts("3- Afficher les n suivantes annee bissextiles");
        puts("----------------------------------------------");
        puts("0- Retouner au grands menus");
        puts("----------------------------------------------");
        choix = saisie_securisee_pour_entier("Veuillez saisir votre choix : ");
        switch (choix) {
            case 0 :
                puts("Retour aux grands menus");
                break;
            case 1 :
                annee = saisie_securisee_pour_entier("Veuillez saisir l'annee : ");
                if(estBissextile(annee))
                    printf("%lld est une annee bissextile.", annee);
                else
                    printf("%lld n'est pas une annee bissextile.", annee);
                break;
            case 2 :
                n = saisie_securisee_pour_entier("Entrez la valeur de n : ");
                printf("Les %lld dernieres annees bissextiles sont :\n", n);
                i = 2026;
                compteur = 0;
                while (compteur < n) {
                    if (estBissextile(i)) {
                        printf("%lld ", i);
                        compteur++;
                    }
                    i--;
                }
                break;
            case 3 :
                n = saisie_securisee_pour_entier("Entrez la valeur de n : ");
                if (n > 15)
                    puts("Tu veux afficher plus des 15 annees bissextiles suivantes.\nTu es sur d'etre vivant dans ces annees la ?!");
                else {
                    printf("Les %lld suivantes annees bissextiles sont :\n", n);
                    i = 2026;
                    compteur = 0;
                    while (compteur < n) {
                        if (estBissextile(i)) {
                            printf("%lld ", i);
                            compteur++;
                        }
                        i++;
                     }
                }
                break;
            default :
                puts("Choix inavlide !");
        }
        printf("\n\n");
    } while (choix != 0);
}
