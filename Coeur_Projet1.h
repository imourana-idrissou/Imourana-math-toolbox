#ifndef COEUR_PROJET1_H_INCLUDED
#define COEUR_PROJET1_H_INCLUDED

void vider_buffer(void);
void operations_simples_generale();
void operations_simples();
void calcul_de_factorielle();
void primalite();
void diviseurs();
void multiples();
void puissance();
void PPCM();
void PGCD();
void sigma();
void nbre_chiffres();
void inverser_nbre();
void palindrome();
void fibonacci();
void conversion_base();
void somme_des_chiffres();
void petit_grand_chiffre();
void carre_parfait();
void analyse_combinatoire();
void decomposition_facteurs_premiers();
void statistique_simple();
void addition();
void soustraction();
void multiplication();
void division();
void decimal_vers_binaire();
void decimal_vers_octal();
void decimal_vers_hexa();
void binaire_vers_decimal();
void octal_vers_decimal();
void hexa_vers_decimal();
void arrangement();
void arrangement_interactive();
void combinaison();
void combinaison_intercative();
void pause(void);
void conversion_monnaie();
void CFA_vers_USD();
void USD_vers_CFA();
void CFA_vers_CAD();
void CAD_vers_CFA();
void CFA_vers_CNY();
void CNY_vers_CFA();
void CFA_vers_MAD();
void MAD_vers_CFA();
void CFA_vers_NGN();
void NGN_vers_CFA();
void CFA_vers_Euro();
void Euro_vers_CFA();
void CFA_vers_GHS();
void GHS_vers_CFA();
void annee_bissextile();

long long decrementation(int n, int p);
long long exposant(int i, int j);
long long saisie_securisee_pour_entier(char *chaine);
int nbre_caracteres(char *chaine);
int mot_de_passe(void);
int PGCD_deux_entiers(int a, int b);
int mot_est_palyndrome(char *chaine);
int nombre_est_palyndrome(int n);
long long suite_fibonacci(int n);
int longueur_restes(int n, int base_cible);
int nbre_chiffre_entier(int n);
long long factorielle(int n);
int estBissextile(long long annee);

char saisie_securisee_pour_caractere(char *chaine);

double saisie_securisee_pour_floattant(char *chaine);


#endif // COEUR_PROJET1_H_INCLUDED
