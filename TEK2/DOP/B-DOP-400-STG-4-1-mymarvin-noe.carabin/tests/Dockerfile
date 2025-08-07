##
## EPITECH PROJECT, 2024
## B-DOP-400-STG-4-1-mymarvin-noe.carabin
## File description:
## Dockerfile
##

# Utilisation de l'image Jenkins officielle
FROM jenkins/jenkins:lts

# Passer en mode root pour installer les dépendances
USER root

# Installer les dépendances et le JDK
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    openjdk-17-jdk curl wget git && \
    rm -rf /var/lib/apt/lists/*

# Copier le fichier de configuration Jenkins Configuration as Code (JCasC)
COPY my_marvin.yml /var/jenkins_home/my_marvin.yml
COPY job_dsl.groovy /var/jenkins_home/job_dsl.groovy
# COPY init.groovy $JENKINS_HOME/init.groovy.d/job-dsl-init.groovy

# Définir les variables d'environnement
ENV CASC_JENKINS_CONFIG=/var/jenkins_home/my_marvin.yml
ENV USER_CHOCOLATEEN_PASSWORD=LeChat
ENV USER_VAUGIE_G_PASSWORD=LeChat
ENV USER_I_DONT_KNOW_PASSWORD=LeChat
ENV USER_NASSO_PASSWORD=LeChat
ENV JAVA_OPTS="-Djenkins.install.runSetupWizard=false"

# Installation des plugins avec jenkins-plugin-cli
RUN jenkins-plugin-cli --plugins \
    cloudbees-folder \
    configuration-as-code \
    credentials \
    github \
    instance-identity \
    job-dsl \
    script-security \
    structs \
    role-strategy \
    ws-cleanup

# Réattribuer Jenkins en tant qu'utilisateur
USER jenkins

# Exposer le port de Jenkins
EXPOSE 8080

# Démarrer Jenkins
CMD ["jenkins.sh"]
