# Imourana-math-toolbox

**Imourana** est une boîte à outils en console, écrite en langage C. Elle regroupe, dans un menu interactif, 23 outils de calcul : arithmétique, nombres, bases numériques, combinatoire, statistiques et conversions de monnaies.

## Pourquoi ce projet ?

Après avoir appris le langage C en classe, j'ai voulu aller plus loin que ce qui nous avait été enseigné. J'ai donc repris depuis zéro les notions du cours : les opérations simples, les conditions, les structures itératives (les boucles) et les tableaux. Mon objectif était de les comprendre en profondeur.

Ensuite, j'ai voulu vérifier si je maîtrisais vraiment ces notions. J'ai commencé par refaire de petits exercices d'application, comme ceux de la classe. En les écrivant, de nouvelles idées me venaient : à partir d'un programme qui fait une addition et une soustraction, j'ai pensé à ajouter la multiplication et la division, puis d'autres vérifications. Chaque idée est devenue une fonction ajoutée au programme.

Au fil de l'évolution, j'ai remarqué que l'utilisateur pouvait saisir n'importe quoi. Par exemple, quand le programme attendait un entier et qu'on lui donnait du texte, il tombait dans une boucle infinie. J'ai donc écrit des fonctions de saisie sécurisée qui contrôlent ce que l'utilisateur entre.

Petit à petit, ces exercices sont devenus une boîte à outils de 23 menus, bâtie sur de nombreuses fonctions que j'ai réfléchies et écrites moi-même. Le programme a été écrit en trois jours.

## Menus disponibles

Le programme propose 23 menus :

1. Opérations simples générales (+ − × ÷)
2. Opérations simples (+ ou −)
3. Calcul de factorielle
4. Test de primalité
5. Diviseurs d'un entier
6. Multiples d'un entier
7. Calcul de puissance
8. Calcul de PPCM
9. Calcul de PGCD
10. Calcul d'une somme (Sigma)
11. Nombre de chiffres d'un nombre
12. Inverser les chiffres d'un nombre
13. Vérifier si un mot ou un nombre est un palindrome
14. Suite de Fibonacci
15. Conversion de base (système de numération)
16. Somme des chiffres d'un nombre
17. Plus grand et plus petit chiffre d'un nombre
18. Vérifier si un nombre est un carré parfait
19. Analyse combinatoire
20. Décomposition en facteurs premiers
21. Statistique simple
22. Conversion de monnaie
23. Années bissextiles

Les saisies de l'utilisateur sont contrôlées pour éviter les erreurs.

Dans le menu 21 (Statistique simple), la valeur -1 sert à arrêter la saisie : elle ne peut donc pas être utilisée comme donnée.

La conversion de monnaie (menu 22) couvre le FCFA, le dollar américain, le dollar canadien, le yuan, le dirham marocain, le naira, l'euro et le cedi ghanéen. Les taux de change sont des valeurs fixes écrites dans le code : ils sont indicatifs et doivent être mis à jour à la main.

## Structure du projet

| Fichier | Rôle |
| --- | --- |
| `main.c` | Programme principal et menus |
| `ame_projet1.c` | Implémentation de toutes les fonctions |
| `Coeur_Projet1.h` | Déclarations des fonctions |

## Compilation et exécution

### Avec Code::Blocks

1. Créez un projet « Console application » en C.
2. Ajoutez les trois fichiers du dépôt au projet.
3. Cliquez sur **Build and run**.

### Avec GCC en ligne de commande

```
gcc main.c ame_projet1.c -o Imourana -lm
```

Lancez ensuite le programme obtenu (`Imourana.exe` sous Windows).

## Utilisation

Au démarrage, le programme demande un code d'accès. Il faut le deviner : le programme indique si le nombre saisi est inférieur ou supérieur au code. Une fois le code trouvé, le menu principal s'ouvre, et chaque menu contient à son tour des sous-menus.

## Suite du projet

Mon objectif est d'en faire un logiciel complet, utilisable sur Android et sur ordinateur, et accessible aussi depuis un site web. Pour cela, j'apprends actuellement le HTML et le CSS, puis d'autres technologies.

## Auteur

**IDRISSOU Imourana**, élève ingénieur en deuxième année de Cycle Préparatoire Intégré en Informatique et Systèmes (IS), École Nationale Polytechnique Campus de Lomé (ENP-CL).
