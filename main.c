#include "Coeur_Projet1.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long choix_menu;
    int trouve = mot_de_passe();
    if (trouve) {
    do {
        puts("======================================================");
        puts("                MENUS DISPONIBLES");
        puts("======================================================");
        puts("0- Quitter");
        puts("1- Operations simples generales (+ - x /)");
        puts("2- Operations simples (+ ou -)");
        puts("3- Calcul de factorielle");
        puts("4- Test de primalite");
        puts("5- Diviseurs d'un entier");
        puts("6- Multiples d'un entier");
        puts("7- Calcul de puissance");
        puts("8- Calcul de PPCM");
        puts("9- Calcul de PGCD");
        puts("10- Calcul d'une somme (Sigma)");
        puts("11- Nombre de chiffres d'un nombre");
        puts("12- Inverser les chiffres d'un nombre");
        puts("13- Verifier si un mot ou un nombre est un palindrome");
        puts("14- Suite de Fibonacci");
        puts("15- Conversion de base (systeme de numeration)");
        puts("16- Somme des chiffres qui composent un nombre");
        puts("17- Plus grand et plus petit chiffre d'un nombre");
        puts("18- Verifier si un nombre est un carre parfait");
        puts("19- Analyse combinatoire");
        puts("20- Decomposition en facteurs premiers");
        puts("21- Statistique simple");
        puts("22- Conversion de monnaie");
        puts("23- Annees bissextiles");
        puts("======================================================");
        choix_menu = saisie_securisee_pour_entier("Entrez votre choix : ");
        switch (choix_menu) {
            case 0 :
                puts("Fermeture du programme...");
                break;
            case 1 :
                operations_simples_generale();
                break;
            case 2 :
                operations_simples();
                pause();
                break;
            case 3 :
                calcul_de_factorielle();
                pause();
                break;
            case 4 :
                primalite();
                pause();
                break;
            case 5 :
                diviseurs();
                pause();
                break;
            case 6 :
                multiples();
                pause();
                break;
            case 7 :
                puissance();
                pause();
                break;
            case 8 :
                PPCM();
                pause();
                break;
            case 9 :
                PGCD();
                pause();
                break;
            case 10 :
                sigma();
                pause();
                break;
            case 11 :
                nbre_chiffres();
                pause();
                printf("\n");
                break;
            case 12 :
                inverser_nbre();
                pause();
                break;
            case 13 :
                palindrome();
                pause();
                break;
            case 14 :
                fibonacci();
                pause();
                break;
            case 15 :
                conversion_base();
                pause();
                break;
            case 16 :
                somme_des_chiffres();
                pause();
                break;
            case 17 :
                petit_grand_chiffre();
                pause();
                break;
            case 18 :
                carre_parfait();
                pause();
                break;
            case 19 :
                analyse_combinatoire();
                pause();
                break;
            case 20 :
                decomposition_facteurs_premiers();
                pause();
                break;
            case 21 :
                statistique_simple();
                pause();
                break;
            case 22 :
                conversion_monnaie();
                pause();
                break;
            case 23 :
                annee_bissextile();
                break;
            default :
                 puts("Choix invalide !");
                 pause();
        }
    } while (choix_menu != 0);
    }
    printf("Appuyer sur entree pour quitter...");
    getchar();
    return 0;
}
