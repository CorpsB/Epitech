##
## EPITECH PROJECT, 2023
## New
## File description:
## push.sh
##

files_modified=$(git status | grep ".c" | awk '{print $3}')
files_h=$(git status | grep ".h" | awk '{print $3}')
makefile=$(git status | grep "Makefile" | awk '{print $3}')
clear
make fclean
rm 
/coding-style-checker-main/coding-style.sh . .
clear
file="coding-style-reports.log"
if [ -s "$file" ]; then    
    echo "\e[31m/!\ WARNING : CODING-STYLE ERROR(S) DETECTED : WARNING /!\ \e[0m"
    cat "$file"
    echo ""
    echo "Do you want push ? (y/n) ?"
    read response
    if [ "$response" == "n" ]; then
        echo "Push canceled ..."
        exit
    fi
else
    echo "No coding-style error detected ..."
fi
rm coding-style-reports.log
while true; do
    echo ""
    echo "Qu'avez vous fait ?"
    echo ""
    echo "1) Ajout de nouvelles fonctionnalités"
    echo "2) Correction de bugs ?"
    echo "3) Reecriture sans changements de fonctionnalités / optimisation"
    echo "4) Changement de style"
    echo "5) Bonus"
    read type
    if [ "$type" == "1" ]; then
        comm_type="feat : "
        break
    fi
    if [ "$type" == "2" ]; then
        comm_type="fix : "
        break
    fi
    if [ "$type" == "3" ]; then
        comm_type="refactor : "
        break
    fi
    if [ "$type" == "4" ]; then
        comm_type="style : "
        break
    fi
        if [ "$type" == "4" ]; then
        comm_type="feat/fix BONUS : "
        break
    fi
    echo "Unrecognized format..."
    continue
done
echo "Please enter a desctiption (in english) :"
read description
git add *.c
git add *.h
git add Makefile
git commit -m "$comm_type$description"
clear
git push
echo "Commit message : $comm_type$description"
exit