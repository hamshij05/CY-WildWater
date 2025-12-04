<h1 align="center"> C-WILD WATER </h1>

<a href="https://cytech.cyu.fr">
  <img src="https://upload.wikimedia.org/wikipedia/commons/4/4a/CY_Tech.png" alt="CY Tech" width="120">
</a>
<a href="https://cytech.cyu.fr">
  <img src="https://img.shields.io/badge/CY%20Tech-blue?style=for-the-badge&logo=https://upload.wikimedia.org/wikipedia/commons/4/4a/CY_Tech.png" alt="CY Badge">
</a>

## **Bienvenue dans notre programme**

## Sommaire
1. [Description du projet](#description-du-projet)  
2. [Structure](#structure)  
3. [Installation](#installation)  
4. [Utilisation](#utilisation)
5. [Arborescence du projet](#arborescence-du-projet)
6. [Auteurs](#auteurs)  

## Description du projet     
Le **projet WildWater** consiste à développer une application permettant de traiter un fichier de données de plusieurs millions de lignes concernant la distribution d’eau potable en France permettent de : 
generer des histogrammmes des usines de traitement
calculer les fuites d'eau d'une usine donnée
Ce fichier CSV décrit les relations entre les différentes entités du réseau (sources, usines, stockages, jonctions, raccordements, usagers), ainsi que les volumes d’eau et les pertes observées dans chaque tronçon. Le système est composé de :
- **Un script Shell** :
  point d’entrée du programme, responsable des commandes utilisateur, de la gestion des traitements et de l’appel au programme C. 
-  **Un programme C** :  
 responsable des calculs lourds (histogrammes, volumes traités, pertes d’eau).

## Structure 
  - **`biblio.h`** : contient tous les bibliothèques utilisées, les définitions de les structures et les déclarations des fonctions.  
  - **`Makefile`** : permet d'automatiser la compilation  

## Installation
 **Prerequis**  
Avant de commencer, assurez-vous les outils suivants sont installes sur votre système :   
- **`GnuPlot`** : pour la génération de graphiques
- **`Bash`** : pour exécuter le script Shell
- **`grep et awk`** : pour des fonctions utiles pour le traitement de données
  

## Utilisation

## Arborescence du projet

## Auteurs    
- **Hamshigaa JEKUMAR** - hamshij05  
