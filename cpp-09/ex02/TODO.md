# TODO List - PmergeMe (ex02)

## 1. Algorithme : Implémenter la Suite de Jacobsthal (Critique)
- [ ] Dans `insertPendingElements`, remplacer l'itération linéaire basique par un parcours basé sur l'ordre de la suite de Jacobsthal (1, 3, 5, 11, 21...).
- [ ] (Optionnel mais recommandé pour du vrai Ford-Johnson) Optimiser `std::lower_bound` pour chercher la position d'insertion uniquement de `mainChain.begin()` jusqu'à l'index du "Gagnant" associé (son ancien partenaire dans les paires), au lieu d'aller systématiquement jusqu'à `mainChain.end()`.

## 2. Contraintes du Sujet : Ajouter un deuxième conteneur (Obligatoire)
- [ ] Le sujet impose d'utiliser au moins 2 conteneurs différents (`std::vector` + `std::list` ou `std::deque`).
- [ ] Dupliquer la logique, créer un `template` ou faire une surcharge de fonction pour que l'algorithme complet puisse s'exécuter sur le second conteneur.

## 3. Sortie Standard (Output) : Format et Chronomètres (Obligatoire)
- [ ] Dans `main.cpp`, s'assurer de précéder l'affichage original de `"Before: "`.
- [ ] Précéder l'affichage final de `"After: "`.
- [ ] Implémenter un système de chronomètre (`gettimeofday()` ou `clock()`) avant/après l'exécution de l'algorithme sur le conteneur 1.
- [ ] Implémenter le même chronomètre pour le conteneur 2.
- [ ] Afficher le temps pris par le conteneur 1 au format strict : `Time to process a range of X elements with std::[container1] : TIME us`.
- [ ] Afficher le temps pris par le conteneur 2 au format strict : `Time to process a range of X elements with std::[container2] : TIME us`.

## Notes supplémentaires
- L'intrus (struggler) inséré à la toute fin doit utiliser `std::lower_bound` sur toute la longueur de la `mainChain` finale.
- Assure-toi que la gestion d'erreur affiche bien "Error" proprement si l'utilisateur donne de mauvaises entrées.
