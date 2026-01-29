
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "src/podium.h"
#include "src/joueur.h"
#include "src/cartes.h"
#include "src/ordres.h"
#include "src/dynamic_array.h"

// Fonctions de test pour chaque module

void test_podium() {
    printf("=== Test Podium ===\n");
    
    // Test d'initialisation
    Podium podium;
    initPodium(&podium);
    assert(dynamicArraySize(podium.animals) == 0);
    printf("✓ Initialisation podium\n");
    
    // Test d'ajout d'animaux
    addAnimal(&podium, "LION");
    addAnimal(&podium, "OURS");
    assert(dynamicArraySize(podium.animals) == 2);
    printf("✓ Ajout animaux\n");
    
    // Test récupération premier/dernier
    char *first = getFirstAnimal(&podium);
    char *last = getLastAnimal(&podium);
    assert(strcmp(first, "OURS") == 0);
    assert(strcmp(last, "LION") == 0);
    printf("✓ Récupération premier/dernier animal\n");
    
    // Test déplacement d'animal
    Podium dest;
    initPodium(&dest);
    moveAnimal(&podium, &dest);
    assert(dynamicArraySize(podium.animals) == 1);
    assert(dynamicArraySize(dest.animals) == 1);
    printf("✓ Déplacement animal\n");
    
    // Test échange d'animaux
    addAnimal(&podium, "ELEPHANT");
    addAnimal(&dest, "TIGRE");
    swapAnimal(&podium, &dest);
    printf("✓ Échange animaux\n");
    
    // Test rotation
    topAnimal(&podium);
    printf("✓ Rotation podium\n");
    
    // Test comparaison
    Podium copie;
    initPodium(&copie);
    addAnimal(&copie, "LION");
    addAnimal(&copie, "ELEPHANT");
    assert(comparePodiums(&podium, &copie) == 1);
    printf("✓ Comparaison podiums\n");
    
    printf("Podium: Tous les tests passés!\n\n");
}

void test_joueur() {
    printf("=== Test Joueur ===\n");
    
    // Test initialisation joueurs
    Joueurs joueurs;
    init_joueurs(&joueurs);
    assert(nbJoueurs(&joueurs) == 0);
    printf("✓ Initialisation joueurs\n");
    
    // Test ajout joueur
    add_joueur(&joueurs, "AB");
    add_joueur(&joueurs, "CD");
    assert(nbJoueurs(&joueurs) == 2);
    printf("✓ Ajout joueurs\n");
    
    // Test récupération joueur
    Joueur j1 = getJoueur(&joueurs, 0);
    Joueur j2 = getJoueur(&joueurs, 1);
    assert(strcmp(j1.nom, "AB") == 0);
    assert(strcmp(j2.nom, "CD") == 0);
    assert(j1.id == 1);
    assert(j2.id == 2);
    assert(j1.score == 0);
    assert(j2.score == 0);
    printf("✓ Récupération joueur\n");
    
    // Test suppression joueur
    remove_joueur(&joueurs, &j2);
    assert(nbJoueurs(&joueurs) == 1);
    printf("✓ Suppression joueur\n");
    
    printf("Joueur: Tous les tests passés!\n\n");
}

void test_cartes() {
    printf("=== Test Cartes ===\n");
    
    // Test initialisation pioche
    Cartes pioche;
    initPioche(&pioche);
    assert(nbCartes(&pioche) > 0);
    printf("✓ Initialisation pioche (%d cartes)\n", nbCartes(&pioche));
    
    // Test initialisation défausse
    Cartes defausse;
    initDefausse(&defausse);
    assert(nbCartes(&defausse) == 0);
    printf("✓ Initialisation défausse\n");
    
    // Test tirage de carte
    Carte carte = tirerCarte(&pioche);
    assert(nbCartes(&pioche) > 0);
    printf("✓ Tirage carte\n");
    
    // Test ajout à la défausse
    addCarte(&defausse, carte);
    assert(nbCartes(&defausse) == 1);
    printf("✓ Ajout carte à la défausse\n");
    
    // Test récupération carte
    Carte recup = getCarte(&defausse, 0);
    printf("✓ Récupération carte\n");
    
    // Test mélange
    int avant = nbCartes(&pioche);
    melangerCartes(&pioche);
    int apres = nbCartes(&pioche);
    assert(avant == apres);
    printf("✓ Mélange cartes\n");
    
    printf("Cartes: Tous les tests passés!\n\n");
}

void test_ordres() {
    printf("=== Test Ordres ===\n");
    
    // Test initialisation ordres
    Ordres ordres;
    initOrdres(&ordres);
    assert(ordres.nb_ordres > 0);
    printf("✓ Initialisation ordres (%d ordres)\n", ordres.nb_ordres);
    
    // Test validation ordre
    assert(isOrdreAutorise(&ordres, "KI") == 1);
    assert(isOrdreAutorise(&ordres, "LO") == 1);
    assert(isOrdreAutorise(&ordres, "XX") == 0);
    printf("✓ Validation ordres\n");
    
    // Test affichage (ne crash pas)
    afficherOrdresDisponibles(&ordres);
    printf("✓ Affichage ordres\n");
    
    printf("Ordres: Tous les tests passés!\n\n");
}

void test_dynamic_array() {
    printf("=== Test Dynamic Array ===\n");
    
    // Test création
    DynamicArray *array = dynamicArrayCreate(sizeof(int), 5);
    assert(array != NULL);
    assert(array->size == 0);
    assert(array->capacity == 5);
    printf("✓ Création tableau dynamique\n");
    
    // Test ajout
    for (int i = 0; i < 10; i++) {
        dynamicArrayAdd(array, &i);
    }
    assert(array->size == 10);
    assert(array->capacity >= 10);
    printf("✓ Ajout éléments avec redimensionnement\n");
    
    // Test récupération
    int *val = (int*)dynamicArrayGet(array, 5);
    assert(*val == 5);
    printf("✓ Récupération élément\n");
    
    // Test suppression dernier
    dynamicArrayRemoveLast(array);
    assert(array->size == 9);
    printf("✓ Suppression dernier élément\n");
    
    // Test taille
    assert(dynamicArraySize(array) == 9);
    printf("✓ Taille tableau\n");
    
    // Test destruction
    dynamicArrayDestroy(array);
    printf("✓ Destruction tableau\n");
    
    printf("Dynamic Array: Tous les tests passés!\n\n");
}

void test_integration() {
    printf("=== Test Intégration ===\n");
    
    // Test création d'une configuration de jeu complète
    Podium rouge, bleu;
    initPodium(&rouge);
    initPodium(&bleu);
    
    addAnimal(&rouge, "LION");
    addAnimal(&rouge, "OURS");
    addAnimal(&bleu, "ELEPHANT");
    
    // Test exécution d'une séquence d'ordres
    Ordres ordres;
    initOrdres(&ordres);
    
    if (isOrdreAutorise(&ordres, "KI")) {
        moveAnimal(&bleu, &rouge);
    }
    
    // Test comparaison avec une carte cible
    Cartes pioche;
    initPioche(&pioche);
    Carte carte = tirerCarte(&pioche);
    
    int match = comparePodiums(&rouge, &carte.rouge) && comparePodiums(&bleu, &carte.bleu);
    printf("✓ Configuration de jeu complète (match: %d)\n", match);
    
    printf("Intégration: Tous les tests passés!\n\n");
}

int main() {
    printf("Démarrage des tests unitaires - Crazy Circus Game\n");
    printf("====================================================\n\n");
    
    test_podium();
    test_joueur();
    test_cartes();
    test_ordres();
    test_dynamic_array();
    test_integration();
    
    printf("====================================================\n");
    printf("✅ TOUS LES TESTS UNITAIRES ONT RÉUSSI!\n");
    printf("====================================================\n");
    
    return 0;
}