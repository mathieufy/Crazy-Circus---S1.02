# Crazy Circus Game - Archive Complète

## 📋 Résumé du Projet

Crazy Circus est un jeu de stratégie basé sur la manipulation d'animaux sur deux podiums (rouge et bleu). Les joueurs doivent exécuter des séquences d'ordres pour reproduire la configuration affichée sur une carte.

### 🎯 Objectif du Jeu
Reproduire la configuration des podiums montrée sur une carte piochée en utilisant une séquence d'ordres autorisés. Le joueur qui réussit marque un point.

### 🏗️ Structure du Projet

#### Modules Principaux
- **jeu.c/h** : Module principal qui orchestre le déroulement du jeu
- **podium.c/h** : Gestion des podiums et des manipulations d'animaux
- **cartes.c/h** : Génération et gestion des cartes (configurations à reproduire)
- **joueur.c/h** : Gestion des joueurs et de leurs scores
- **partie.c/h** : Logique de jeu et validation des mouvements
- **ordres.c/h** : Gestion des ordres autorisés (KI, LO, SO, NI, MA)
- **dynamic_array.c/h** : Structure de données générique pour les collections
- **main.c** : Point d'entrée du programme

#### 🎮 Ordres Disponibles
- **KI** : Déplace un animal du podium bleu vers le podium rouge
- **LO** : Déplace un animal du podium rouge vers le podium bleu  
- **SO** : Échange les animaux du sommet des deux podiums
- **NI** : Fait une rotation sur le podium bleu (sommet vers base)
- **MA** : Fait une rotation sur le podium rouge (sommet vers base)

#### ⚙️ Configuration
Le fichier `crazy.cfg` contient :
- Ligne 1 : Liste des animaux disponibles (ex: OURS ELEPHANT LION)
- Ligne 2 : Liste des ordres autorisés (ex: KI LO SO NI MA)

### 🔄 Déroulement d'une Partie
1. Initialisation du jeu et lecture des noms des joueurs
2. Génération de toutes les combinaisons possibles de cartes
3. Boucle de jeu :
   - Pioche d'une carte
   - Le joueur actuel tente de reproduire la configuration
   - Saisie d'une séquence d'ordres (ex: "AB KILOSO")
   - Validation et comparaison avec la carte cible
   - Attribution des points et passage au joueur suivant
4. Affichage des résultats finaux

### 💪 Points Forts Techniques
- Architecture modulaire avec séparation claire des responsabilités
- Utilisation de tableaux dynamiques génériques pour la gestion des collections
- Génération algorithmique de toutes les permutations de cartes
- Validation stricte des séquences d'ordres
- Documentation Doxygen complète

### 🔧 Compilation et Exécution
```bash
gcc -o crazy src/*.c
./crazy JOUEUR1 JOUEUR2
```

### 📜 Règles de Validation
- Les noms de joueurs doivent faire 2 lettres majuscules
- Les ordres doivent être dans la liste autorisée
- La séquence doit reproduire exactement la configuration de la carte
- Un tour réussi marque 1 point et passe au joueur suivant

---

## 🧪 Tests Unitaires

Le fichier `test_unitaire.c` contient une suite complète de tests unitaires validant tous les modules du projet :

### 📊 Tests par Module

#### 1. Test Podium
- ✅ Initialisation d'un podium vide
- ✅ Ajout d'animaux
- ✅ Récupération premier/dernier animal
- ✅ Déplacement d'animaux entre podiums
- ✅ Échange d'animaux
- ✅ Rotation des podiums
- ✅ Comparaison de configurations

#### 2. Test Joueur
- ✅ Initialisation de la collection de joueurs
- ✅ Ajout de joueurs avec validation des noms
- ✅ Récupération des informations joueur
- ✅ Suppression de joueurs
- ✅ Gestion des scores

#### 3. Test Cartes
- ✅ Initialisation de la pioche et défausse
- ✅ Génération automatique de toutes les permutations
- ✅ Tirage de cartes
- ✅ Ajout à la défausse
- ✅ Mélange aléatoire des cartes
- ✅ Récupération des cartes par index

#### 4. Test Ordres
- ✅ Chargement depuis le fichier de configuration
- ✅ Validation des ordres autorisés
- ✅ Affichage des ordres disponibles
- ✅ Gestion des erreurs pour ordres invalides

#### 5. Test Dynamic Array
- ✅ Création avec capacité initiale
- ✅ Ajout d'éléments avec redimensionnement automatique
- ✅ Récupération d'éléments par index
- ✅ Suppression du dernier élément
- ✅ Gestion de la mémoire (allocation/libération)

#### 6. Test d'Intégration
- ✅ Scénario de jeu complet
- ✅ Interaction entre tous les modules
- ✅ Validation d'une séquence d'ordres complète
- ✅ Comparaison avec configuration cible

### 🚀 Exécution des Tests
```bash
gcc -o test test_unitaire.c src/*.c
./test
```

### 📈 Résultats Attendus
Les tests doivent afficher :
```
=== Test Podium ===
✓ Initialisation podium
✓ Ajout animaux
✓ Récupération premier/dernier animal
✓ Déplacement animal
✓ Échange animaux
✓ Rotation podium
✓ Comparaison podiums
Podium: Tous les tests passés!

=== Test Joueur ===
✓ Initialisation joueurs
✓ Ajout joueurs
✓ Récupération joueur
✓ Suppression joueur
Joueur: Tous les tests passés!

=== Test Cartes ===
✓ Initialisation pioche (XX cartes)
✓ Initialisation défausse
✓ Tirage carte
✓ Ajout carte à la défausse
✓ Récupération carte
✓ Mélange cartes
Cartes: Tous les tests passés!

=== Test Ordres ===
✓ Initialisation ordres (XX ordres)
✓ Validation ordres
✓ Affichage ordres
Ordres: Tous les tests passés!

=== Test Dynamic Array ===
✓ Création tableau dynamique
✓ Ajout éléments avec redimensionnement
✓ Récupération élément
✓ Suppression dernier élément
✓ Taille tableau
✓ Destruction tableau
Dynamic Array: Tous les tests passés!

=== Test Intégration ===
✓ Configuration de jeu complète (match: X)
Intégration: Tous les tests passés!

====================================================
✅ TOUS LES TESTS UNITAIRES ONT RÉUSSI!
====================================================
```

---

## 📁 Structure des Fichiers

```
s1_02_but1/
├── src/
│   ├── jeu.c/h              # Module principal
│   ├── podium.c/h           # Gestion des podiums
│   ├── cartes.c/h           # Gestion des cartes
│   ├── joueur.c/h           # Gestion des joueurs
│   ├── partie.c/h           # Logique de jeu
│   ├── ordres.c/h           # Gestion des ordres
│   ├── dynamic_array.c/h    # Structure de données
│   └── main.c               # Point d'entrée
├── crazy.cfg                # Configuration du jeu
├── test_unitaire.c          # Tests unitaires complets
├── README.md               # Documentation complète
└── ARCHIVE.md              # Ce fichier archive
```

---

## 🎯 Conclusion

Ce projet Crazy Circus Game démontre une excellente architecture logicielle avec :
- **Code modulaire et maintenable**
- **Tests unitaires complets**
- **Documentation détaillée**
- **Gestion robuste des erreurs**
- **Algorithmes efficaces de génération de permutations**

Le projet est prêt pour la production et peut être facilement étendu avec de nouvelles fonctionnalités.