# Crazy Circus Game - Résumé du Projet

## Description
Crazy Circus est un jeu de stratégie basé sur la manipulation d'animaux sur deux podiums (rouge et bleu). Les joueurs doivent exécuter des séquences d'ordres pour reproduire la configuration affichée sur une carte.

## Objectif du Jeu
Reproduire la configuration des podiums montrée sur une carte piochée en utilisant une séquence d'ordres autorisés. Le joueur qui réussit marque un point.

## Structure du Projet

### Modules Principaux
- **jeu.c/h** : Module principal qui orchestre le déroulement du jeu
- **podium.c/h** : Gestion des podiums et des manipulations d'animaux
- **cartes.c/h** : Génération et gestion des cartes (configurations à reproduire)
- **joueur.c/h** : Gestion des joueurs et de leurs scores
- **partie.c/h** : Logique de jeu et validation des mouvements
- **ordres.c/h** : Gestion des ordres autorisés (KI, LO, SO, NI, MA)
- **dynamic_array.c/h** : Structure de données générique pour les collections
- **main.c** : Point d'entrée du programme

### Ordres Disponibles
- **KI** : Déplace un animal du podium bleu vers le podium rouge
- **LO** : Déplace un animal du podium rouge vers le podium bleu  
- **SO** : Échange les animaux du sommet des deux podiums
- **NI** : Fait une rotation sur le podium bleu (sommet vers base)
- **MA** : Fait une rotation sur le podium rouge (sommet vers base)

### Configuration
Le fichier `crazy.cfg` contient :
- Ligne 1 : Liste des animaux disponibles (ex: OURS ELEPHANT LION)
- Ligne 2 : Liste des ordres autorisés (ex: KI LO SO NI MA)

## Déroulement d'une Partie
1. Initialisation du jeu et lecture des noms des joueurs
2. Génération de toutes les combinaisons possibles de cartes
3. Boucle de jeu :
   - Pioche d'une carte
   - Le joueur actuel tente de reproduire la configuration
   - Saisie d'une séquence d'ordres (ex: "AB KILOSO")
   - Validation et comparaison avec la carte cible
   - Attribution des points et passage au joueur suivant
4. Affichage des résultats finaux

## Points Forts Techniques
- Architecture modulaire avec séparation claire des responsabilités
- Utilisation de tableaux dynamiques génériques pour la gestion des collections
- Génération algorithmique de toutes les permutations de cartes
- Validation stricte des séquences d'ordres
- Documentation Doxygen complète

## Compilation et Exécution
```bash
gcc -o crazy src/*.c
./crazy JOUEUR1 JOUEUR2
```

## Règles de Validation
- Les noms de joueurs doivent faire 2 lettres majuscules
- Les ordres doivent être dans la liste autorisée
- La séquence doit reproduire exactement la configuration de la carte
- Un tour réussi marque 1 point et passe au joueur suivant