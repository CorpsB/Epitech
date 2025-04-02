#!/bin/bash
##
## EPITECH PROJECT, 2023
## B-PSU-200-STG-2-1-42sh-thomas.camuset
## File description:
## test.sh
##

clear
echo "Bienvenu(e) dans mon super programme de test pour le 42SH by MOI et le CHAT"

check_tcsh_executable() {
    tcsh -c ls > /dev/null
    if [ $? -ne 0 ]; then
        echo "::error ::Executable tcsh is missing or not executable."
        exit 1
    else
        echo "::notice:: Executable tcsh found and is executable."
    fi
}

check_tcsh_executable

check_42sh_executable() {
    if ! command -v ./42sh > /dev/null || ! test -x ./42sh; then
        echo "::error::Executable 42sh is missing or not executable."
        exit 1
    else
        echo "::notice::Executable 42sh found and is executable."
    fi
}

check_42sh_executable
echo ""
echo ""
echo ""

################################################################################
###################################TEST_VALUE###################################
################################################################################

# declare -A cmd2=( [titre]="" [commande]="" [comment]="")

declare -A cmd1=( [titre]="Basic test" [commande]="" [comment]="Empty")
declare -A cmd2=( [titre]="Basic test" [commande]="ls -l" [comment]="Simple exec")
declare -A cmd3=( [titre]="Basic test" [commande]="ls imaginaire" [comment]="Wrong simple command")

# Path handling
declare -A cmd4=( [titre]="Path handling" [commande]="ls" [comment]="Executing normal binari")
declare -A cmd5=( [titre]="Path handling" [commande]="./test/test5.sh" [comment]="Using a local exectable")
declare -A cmd6=( [titre]="Path handling" [commande]="/bin/ls" [comment]="Using binary without the PATH value")
declare -A cmd7=( [titre]="Path handling" [commande]="" [comment]="")

# SETENV UNSETENV 
declare -A cmd8=( [titre]="SETENV UNSETENV" [commande]="setenv something true\nenv | grep something" [comment]="Setenv / Env / PrintEnv")
declare -A cmd9=( [titre]="SETENV UNSETENV" [commande]="setenv something true\nunsetenv someting\nenv|grep someting\nunsetenv" [comment]="Unsetenv")

# CD
declare -A cmd10=( [titre]="CD" [commande]="cd src" [comment]="standar cd")
declare -A cmd11=( [titre]="CD" [commande]="cd imaginaire" [comment]="cd inside bad folder")
declare -A cmd12=( [titre]="CD" [commande]="cd src; cd -" [comment]="cd -")

# Line formating
declare -A cmd13=( [titre]="Line formating" [commande]="ls " [comment]="Space before")
declare -A cmd14=( [titre]="Line formating" [commande]=" ls" [comment]="Space after")
declare -A cmd15=( [titre]="Line formating" [commande]=" ls " [comment]="Space before and after")
declare -A cmd16=( [titre]="Line formating" [commande]="                    ls                   ;      pwd     " [comment]="Space with separator")
declare -A cmd17=( [titre]="Line formating" [commande]="            ls           ; pwd       " [comment]="Space and tab")
declare -A cmd18=( [titre]="Line formating" [commande]="    ls" [comment]="Tab before")
declare -A cmd19=( [titre]="Line formating" [commande]="ls  " [comment]="Tab after")
declare -A cmd20=( [titre]="Line formating" [commande]="    ls  " [comment]="Tab before and after")

# separator
declare -A cmd21=( [titre]="separator" [commande]="ls ; pwd" [comment]="Separator (;)")

# Pipe
declare -A cmd22=( [titre]="Pipe" [commande]="setenv COUCOU_LES_COUPAINS true\nenv | grep COUCOU_LES_COUPAINS" [comment]="Pipe with buildin")
declare -A cmd23=( [titre]="Pipe" [commande]="ls -R ./src | grep .c" [comment]="Notmal pipe")
declare -A cmd24=( [titre]="Pipe" [commande]="cat test24.txt | grep e" [comment]="Big inpout pipe")
declare -A cmd25=( [titre]="Pipe" [commande]="ls -R ./src | grep .c | grep main" [comment]="Multi pipe")
declare -A cmd26=( [titre]="Pipe" [commande]="cat nonexistentfile.txt | grep 'data'" [comment]="Little wrong pipe" )
declare -A cmd27=( [titre]="Pipe" [commande]="echo 'Test data' | grepp 'data'" [comment]="Little wrong pipe 2")
declare -A cmd28=( [titre]="Pipe" [commande]="ps aux | head -n 5" [comment]="Process")
declare -A cmd29=( [titre]="Pipe" [commande]="ps aux | grep root | grep ssh" [comment]="Search SSH")
declare -A cmd30=( [titre]="Pipe" [commande]="find . -name '*.log' | xargs cat | grep 'ERROR'" [comment]="Search error into .log file")

# Redirection
declare -A cmd31=( [titre]="Redirection d'entrée" [commande]="cat < fichier.txt" [comment]="Lit le contenu de fichier.txt via la commande cat.")
declare -A cmd32=( [titre]="Redirection de sortie" [commande]="echo 'Hello, world!' > sortie.txt\n cat sortie.txt ; rm sortie.txt" [comment]="Écrit 'Hello, world!' dans sortie.txt, en écrasant le contenu existant.")
declare -A cmd33=( [titre]="Redirection de sortie avec ajout" [commande]="echo 'Ajoutons cette ligne' >> sortie.txt\n cat sortie.txt ; rm sortie.txt" [comment]="Ajoute 'Ajoutons cette ligne' à la fin de sortie.txt.")
declare -A cmd34=( [titre]="Redirection d'entrée avec here-doc" [commande]="grep e << test34.txt" [comment]="Utilise 'cat' pour afficher les lignes fournies jusqu'à ce qu'il rencontre EOF.")
declare -A cmd35=( [titre]="Combinaison de redirections erronée" [commande]="cat < sortie.txt > sortie.txt" [comment]="Tente de lire et d'écrire sur le même fichier en même temps, ce qui peut causer des comportements indéfinis ou une erreur.")

# Advenced manipulation
declare -A cmd36=( [titre]="Advenced manipulation" [commande]="cat ./test/chat/chat.txt ./test/chbt/chbt.txt ./test/chot/chot.txt | sort | uniq > sorted_uniq.txt\ncat sorted_uniq.txt ; rm sorted_uniq.txt" [comment]="Read and sort different file")
declare -A cmd37=( [titre]="Advenced manipulation" [commande]="grep error ./test/chat/chat.txt ./test/chbt/chbt.txt ./test/chot/chot.txt | wc -l > error_count.txt\ncat error_count.txt ; rm error_count.txt" [comment]="Count the ocurence of ERROR word")
declare -A cmd38=( [titre]="Advenced manipulation" [commande]="cut -d':' -f1,3 ./test/chat/chat.txt ./test/chbt/chbt.txt ./test/chot/chot.txt | grep 'admin' > admins.txt\ncat admins.txt ; rm admins.txt" [comment]="Show one part of admin sentence.")

# && and || tests
declare -A cmd39=( [titre]="Test avec l'opérateur &&" [commande]="ls && ls -l \n ls && MOI && LE_CHAT && pwd'" [comment]="Test with &&")
declare -A cmd40=( [titre]="Test avec l'opérateur ||" [commande]="Le_chat || ls'" [comment]="Test with ||")
declare -A cmd41=( [titre]="Combinaison de && et ||" [commande]="ls imaginaire || pwd && ls ; ls imaginaire && pwd || ls -l" [comment]="Test with && and ||")

# Globings
declare -A cmd42=( [titre]="Globings" [commande]="ls test/ch*\nls test/ch?t\nls test/ch[a-d]t" [comment]="Using all globings")

# Var interpreter (echo)
declare -A cmd43=( [titre]="Var interpreter (echo)" [commande]="set something true \n echo $something \n set something \n set | grep something" [comment]="Change value of a parameter")
declare -A cmd44=( [titre]="Var interpreter (echo)" [commande]="set something \n set | grep something\n unset something \n set | grep something" [comment]="Set and unset")
declare -A cmd45=( [titre]="Var interpreter (echo)" [commande]="set something = true bleu = vert blabla=bloblo blibli =" [comment]="Multiple definition of different value")

# Inhibitor
declare -A cmd46=( [titre]="Inhibitor" [commande]="echo '$HOME'" [comment]="")
declare -A cmd47=( [titre]="Inhibitor" [commande]="echo '*'" [comment]="")

# Magic quote
declare -A cmd48=( [titre]="Magic quote" [commande]="echo 'Le chemin actuel est \$HOME'" [comment]="Simple quote" )
declare -A cmd49=( [titre]="Magic quote" [commande]="echo \"Le chemin actuel est \$HOME\"" [comment]="Cette commande utilise des guillemets doubles pour permettre l'expansion de la variable HOME, affichant ainsi le chemin du répertoire personnel de l'utilisateur." )
declare -A cmd50=( [titre]="Magic quote" [commande]="echo \"Nous sommes le \$(date +%Y-%m-%d)\"" [comment]="Cette commande utilise des guillemets doubles et des backticks pour exécuter la commande date et afficher la date actuelle au format YYYY-MM-DD." )

# Alias
declare -A cmd51=( [titre]="Alias" [commande]="alias BOB ls\nalias | grep BOB\nalias ls" [comment]="Normal alias")
declare -A cmd52=( [titre]="Alias" [commande]="alias BOB ls\nBOB" [comment]="Alias execution")
declare -A cmd53=( [titre]="Alias" [commande]="alias A B\nalias B A\nA" [comment]="Alias loop")
declare -A cmd54=( [titre]="Alias" [commande]="alias TRAIN ls\nTRAIN -l" [comment]="Alias with flags")
declare -A cmd55=( [titre]="Alias" [commande]="alias TRAIN ls; TRAIN" [comment]="On the same line")

# History
declare -A cmd56=( [titre]="Inhibitor" [commande]="rm .history\nls -l\npwd\nls\nhistory 2" [comment]="n history")
declare -A cmd57=( [titre]="Inhibitor" [commande]="history azerty" [comment]="Wrong history command")
declare -A cmd58=( [titre]="Inhibitor" [commande]="!" [comment]="Just !")
declare -A cmd59=( [titre]="Inhibitor" [commande]="ls\n!ls" [comment]="!ls")

# Parenthesis
declare -A cmd56=( [titre]="Parenthesis" [commande]="pwd; (ls -R ./src | grep .c); echo $?" [comment]="Basic parentheses")

test=( cmd1 cmd2 cmd3 cmd4 cmd5 cmd6 cmd7 cmd8 cmd9 cmd10 cmd11 cmd12 cmd13  cmd14 cmd15 cmd16 cmd17 cmd18 cmd19 cmd20 cmd21 cmd22 cmd23 cmd24 cmd25 cmd26 cmd27 cmd28 cmd29 cmd30 cmd31 cmd32 cmd33 cmd34 cmd35 cmd36 cmd37 cmd38 cmd39 cmd40 cmd41 cmd42 cmd43 cmd44 cmd45 cmd46 cmd47 cmd48 cmd49 cmd50 cmd51 cmd52 cmd53 cmd54 cmd55 cmd56 )

################################################################################
###################################TEST_FUNC####################################
################################################################################

declare -i total=0
declare -i count=0

lunch_test() {
    local -n test=$1
    total+=1
    # TCSH COMMANDE
    echo -e "${test[commande]}" | tcsh > "test/tcsh_1.txt" 2> "test/tcsh_2.txt"
    echo "$?" > "test/tcsh_exit.txt"
    # 42SH COMMANDE
    echo -e "${test[commande]}" | ./42sh > "test/42sh_1.txt" 2> "test/42sh_2.txt"
    echo "$?" > "test/42sh_exit.txt"
    # Comparaison
    # echo "------------------------------------------------------------"
    if diff -q test/tcsh_1.txt "test/42sh_1.txt" > /dev/null && diff -q test/tcsh_2.txt "test/42sh_2.txt" > /dev/null && diff -q test/tcsh_exit.txt "test/42sh_exit.txt" > /dev/null; then
        count+=1
    else
        echo -e "::error::${test[titre]}\nCOMMAND: ${test[commande]}\nCOMMENT: ${test[comment]}"
    fi
    # echo "------------------------------------------------------------"
    rm test/tcsh_1.txt
    rm test/tcsh_2.txt
    rm test/tcsh_exit.txt
    rm "test/42sh_1.txt"
    rm "test/42sh_2.txt"
    rm "test/42sh_exit.txt"
    # echo ""
}

for test_name in "${!test[@]}"; do
    lunch_test "${test[$test_name]}"
done

declare -i fail=$((total - count))
declare -i pourcent=$((count * 100 / total))

echo -e "::notice::\e[32mOK: $count\e[0m"
echo -e "::warning::\e[31mKO: $fail\e[0m"
echo -e "::notice::\e[36mTOTAL: $pourcent%\e[0m"
rm sortie.txt
