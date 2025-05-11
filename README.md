# 🐾 Gestionnaire d'Animaux (Projet C)

Ce projet est une application en C qui permet de gérer une base de données simple d'animaux via des fichiers `.txt`. Chaque animal est représenté par un fichier, et l'utilisateur peut ajouter, supprimer, rechercher et trier les animaux à partir d'une interface console.

---

## 📁 Structure du projet

```
.
├── animals/              # Dossier contenant les fichiers des animaux
├── animal.h              # Structure de l'animal
├── utils.h / utils.c     # Fonctions utilitaires (tri, affichage, etc.)
├── search.h / search.c   # Fonctions de recherche
├── variantes.h / variantes.c # Fonctions avancées (ex: tri par âge, nettoyage)
├── main.c                # Point d'entrée du programme
├── menu.c                # Menu principal
├── Makefile              # Script de compilation
└── README.md             # Ce fichier
```

---

## ⚙️ Compilation

Assurez-vous d’avoir un compilateur C (comme `gcc`) installé sur votre machine.
Pour compiler le projet, utilisez simplement :

```bash
make
```

Cela générera un exécutable nommé `projet`.

Pour supprimer l'éxecutable, utilisez :
```bash
make clean
```

---

## 🚀 Lancement

Assurez-vous que le dossier `animals/`

---

## 🧩 Fonctionnalités

* Affichage de tous les animaux (vue courte ou détaillée)
* Ajout et suppression d’un animal
* Recherche par nom, espèce ou tranche d’âge (jeune/senior)
* Tri par âge (croissant)
* Calcul du temps de nettoyage hebdomadaire
* Menu interactif dans le terminal

---

## ✅ Espèces supportées

* Chien
* Chat
* Hamster
* Autruche

---

## 📌 Notes

* Le nombre d’animaux est limité à 50.
* Les fichiers d’animaux sont stockés dans le dossier `animals/` sous forme de `id.txt`.
* Le programme vide et recharge en mémoire les animaux à chaque modification.
