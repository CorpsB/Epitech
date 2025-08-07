##
## EPITECH PROJECT, 2025
## B-DOP-400-STG-4-1-mymarvin-noe.carabin
## File description:
## run
##

docker build -t mon-jenkins-epitech -f tests/Dockerfile tests
docker run -d -p 8080:8080 mon-jenkins-epitech
