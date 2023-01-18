# El-Wasmi_Lab3
# Lab 3 : Accelerometer ADXL345

# Introduction :

Le but de ce laboratoire était de réaliser une interface entre un accéléromètre ADXL345 et un microcontrôleur Altera Cyclone IV en utilisant un bus I2C. Le projet devait permettre de mesurer les accélérations sur les trois axes X, Y et Z, et de les afficher sur un afficheur 7 segments.

# Architecture du système
L'architecture du système comprend les composants suivants :

- Microcontrôleur Altera Cyclone IV
- Accéléromètre ADXL345
- Afficheur 7 segments
- Interfaces I2C et PIO pour la communication et l'affichage

L'architecture du système est représentée par le schéma ci-dessous :

![image](https://user-images.githubusercontent.com/75042681/213180568-d1fff51e-73fe-4040-a011-3cdba18f8443.png)

La communication entre le microcontrôleur et l'accéléromètre se fait via l'interface I2C. Le microcontrôleur envoie des commandes de lecture et d'écriture pour configurer l'accéléromètre et lire les données d'accélération. Les données sont ensuite utilisées pour mettre à jour les affichages sur l'afficheur 7 segments via l'interface PIO.

Pour controler les afficheurs 7 segments, j'ai utilisé un PIO programmé en sortie de 24 bits, chaque afficheur prenant 4 bits. Cela nous a permis de contrôler 6 afficheurs au total.

# Progression et résultat :

> Comit 1 : Création de l'environnement de base pour le lab3
> Comit 2 : Ajout de l'IP I2C et lecture de l'accélération sur l'axe X
- Ajout de l'IP de communication I2C dans l'architecture Qsys
- Affectation des broches pour relier les composants entre eux
- Création d'un fichier d'entête pour initialiser le processeur Nios II
- Création de fonctions write_register et read_register pour lire et écrire dans les registres de capteur
- Organisation du code sous forme des fichiers de code : main.c, lab_definition.h et lab3_definition.c pour gérer les données de l'accélération.
- Ajout de la fonctionnalité de lecture de l'axe X du capteur d'accélération
- Tests pour s'assurer que la lecture du capteur fonctionne correctement
- Validation de la lecture de l'axe X, cependant les valeurs ne sont pas calibrées, donc il reste à calibrer le capteur et à améliorer le code

voici architecture dans Qsys

![image](https://user-images.githubusercontent.com/75042681/213188279-f169dd92-0550-44a3-b70b-9a72d2ae0a05.png)


> Comit 3 : Amélioration du code
- Lecture et affichage de tous les axes dans le terminal et sur les afficheurs à 7 segments
- Ajout de switchs pour sélectionner quel axe afficher sur les afficheurs à 7 segments
- Intégration d'un timer en interruption qui démarre chaque seconde pour lire les valeurs de l'accéléromètre
- Calibration des valeurs de l'accéléromètre en utilisant les registres d'offset du capteur
> Comit 4 : Commentaire des codes et validation finale du lab3

Les résultats obtenus montrent que le capteur d'accélération est capable de lire les valeurs d'accélération sur les trois axes (X, Y, Z) et de les afficher sur les afficheurs à 7 segments. Les switchs permettent de sélectionner quel axe afficher sur les afficheurs. La calibration des valeurs avec les registres d'offset a permis d'obtenir des valeurs plus précises. Enfin, l'utilisation d'un timer en interruption a permis de lire les valeurs de l'accéléromètre de manière régulière et automatique.




https://user-images.githubusercontent.com/75042681/213187821-2e44d76e-adcf-4600-85bc-72706a3e05eb.mp4

# Conclusion:

En conclusion, ce laboratoire a permis de mettre en pratique les concepts de communication I2C et de gestion des interruptions pour réaliser lire les données d'un accéléromètre . Nous avons pu comprendre comment calibrer les valeurs de l'accéléromètre et les afficher sur des afficheurs à 7 segments en utilisant des switchs pour sélectionner l'axe à afficher. Ce laboratoire a également renforcé nos compétences en programmation . On a  bien validé que les concepts théoriques étudiés peuvent être mis en pratique pour réaliser des projets concrets.
