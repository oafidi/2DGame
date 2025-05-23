# so\_long

## Description

Le projet **so\_long** consiste à créer un jeu en 2D simple en utilisant la bibliothèque **MiniLibX** sur **macOS**. L'objectif est de manipuler des interfaces graphiques, gérer des fenêtres avec **X11**, et apprendre à afficher des textures tout en respectant des contraintes de gestion de mémoire et de contrôle des événements clavier.

Ce projet a été une excellente opportunité pour découvrir la programmation graphique et comprendre le fonctionnement des systèmes de fenêtrage sous Unix !



<img width="634" alt="ScreenShot" src="https://github.com/user-attachments/assets/82b8275d-933e-4833-bcc5-f35dd57e2ab8" />

## Fonctionnalités

- Chargement et affichage d'une carte à partir d'un fichier `.ber`.
- Déplacement du personnage avec les touches directionnelles.
- Gestion des collisions avec les murs.
- Collecte d'objets pour atteindre la sortie.
- Affichage des mouvements en temps réel.
- Version bonus avec :
  - Animations.
  - Affichage du nombre de pas.
  - Ennemis qui bougent sur la carte.

## Compilation

Pour compiler le projet, utilisez la commande suivante :

```bash
make bonus
```

Si tout est bien compilé, vous verrez :

```bash
make: Nothing to be done for `bonus'.
```

## Exécution

Pour lancer le jeu avec la carte bonus :

```bash
./so_long_bonus maps/map2_bonus.ber
```

## Commandes du jeu

- **Flèches directionnelles** : Déplacer le personnage.
- **Échap** : Fermer la fenêtre et quitter le jeu.

## Gestion des erreurs

- Vérification de la validité de la carte (format rectangulaire, bordures fermées).
- Vérification du nombre d'éléments obligatoires (1 joueur, 1 sortie, au moins 1 collectible).
- Gestion des erreurs de chargement de fichier.

## Technologies utilisées

- **C** : Langage principal.
- **MiniLibX** : Bibliothèque graphique légère.
- **X11** : Système de fenêtrage Unix.
- **Makefile** : Automatisation de la compilation.

## Ce que j'ai appris

- Manipulation des fenêtres avec MiniLibX et X11.
- Gestion des textures et des images.
- Capture des événements clavier et souris.
- Allocation dynamique de mémoire et gestion des fuites.
- Structuration du code pour un projet de taille moyenne.

## Conclusion

Le projet **so\_long** m'a permis de mieux comprendre les bases de la programmation graphique et de renforcer mes compétences en gestion d'événements et en manipulation de bibliothèques externes. C'était un défi passionnant qui m'a préparé pour des projets plus complexes avec des interactions graphiques encore plus riches ! 🚀

---



