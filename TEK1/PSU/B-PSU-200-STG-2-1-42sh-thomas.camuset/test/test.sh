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
        echo "Executable tcsh is missing or not executable."
        exit 1
    else
        echo "Executable tcsh found and is executable."
    fi
}

check_tcsh_executable

check_42sh_executable() {
    if ! command -v ./42sh > /dev/null || ! test -x ./42sh; then
        echo "Executable 42sh is missing or not executable."
        exit 1
    else
        echo "Executable 42sh found and is executable."
    fi
}

check_42sh_executable
echo ""
echo ""
echo ""

################################################################################
###################################TEST_VALUE###################################
################################################################################

# declare -A cmd2= ( [titre]="" [commande]="" [comment]="")

declare -A cmd1=( [titre]="Basic test" [commande]="" [comment]="Empty")
declare -A cmd2=( [titre]="Basic test" [commande]="ls -l" [comment]="Simple exec")
declare -A cmd3=( [titre]="Basic test" [commande]="ls imaginaire" [comment]="Wrong simple command")

# Path handling
declare -A cmd4=( [titre]="Path handling" [commande]="ls" [comment]="Executing normal binari")
declare -A cmd5=( [titre]="Path handling" [commande]="./test/test5.sh" [comment]="Using a local exectable")
declare -A cmd6=( [titre]="Path handling" [commande]="/bin/ls" [comment]="Using binary without the PATH value")

declare -A cmd7=( [titre]="Path handling - Nonexistent Path" [commande]="ls /un/dossier/non/existant" [comment]="Testing command execution from a nonexistent path")
declare -A cmd8=( [titre]="Path handling - Protected Path" [commande]="ls /root" [comment]="Testing access to a protected path to check permission handling")

# SETENV UNSETENV 
declare -A cmd9=( [titre]="SETENV UNSETENV" [commande]="setenv something true\nenv | grep something" [comment]="Setenv / Env / PrintEnv")
declare -A cmd10=( [titre]="SETENV UNSETENV" [commande]="setenv something true\nunsetenv someting\nenv|grep someting\nunsetenv" [comment]="Unsetenv")

declare -A cmd11=( [titre]="SETENV UNSETENV" [commande]="unsetenv nonexistentvariable\nenv | grep nonexistentvariable" [comment]="Trying to unset a non-existent variable to ensure proper error handling")
declare -A cmd12=( [titre]="SETENV UNSETENV" [commande]="setenv 123name true\nenv | grep 123name" [comment]="Setting a variable with a potentially invalid name to test name validation")
declare -A cmd13=( [titre]="SETENV UNSETENV" [commande]="setenv something true\nsetenv something false\nenv | grep something" [comment]="Setting the same variable multiple times to check last write wins behavior")
declare -A cmd14=( [titre]="SETENV UNSETENV" [commande]="setenv emptyvar\nenv | grep emptyvar" [comment]="Setting a variable without a value to see if it is handled as empty or ignored")


# CD
declare -A cmd15=( [titre]="CD" [commande]="cd src" [comment]="standar cd")
declare -A cmd16=( [titre]="CD" [commande]="cd imaginaire" [comment]="cd inside bad folder")
declare -A cmd17=( [titre]="CD" [commande]="cd src; cd -" [comment]="cd -")

declare -A cmd18=( [titre]="CD" [commande]="cd ~" [comment]="Changing to the home directory")
declare -A cmd19=( [titre]="CD" [commande]="cd /" [comment]="Changing to the root directory")
declare -A cmd20=( [titre]="CD" [commande]="cd" [comment]="Changing to the home directory by using cd without any argument")
declare -A cmd21=( [titre]="CD" [commande]="cd /root" [comment]="Trying to change to a directory with restricted permissions")


# Line formating
declare -A cmd22=( [titre]="Line formating" [commande]="ls " [comment]="Space before")
declare -A cmd23=( [titre]="Line formating" [commande]=" ls" [comment]="Space after")
declare -A cmd24=( [titre]="Line formating" [commande]=" ls " [comment]="Space before and after")
declare -A cmd25=( [titre]="Line formating" [commande]="                    ls                   ;      pwd     " [comment]="Space with separator")
declare -A cmd26=( [titre]="Line formating" [commande]="            ls           ; pwd       " [comment]="Space and tab")
declare -A cmd27=( [titre]="Line formating" [commande]="    ls" [comment]="Tab before")
declare -A cmd28=( [titre]="Line formating" [commande]="ls  " [comment]="Tab after")
declare -A cmd29=( [titre]="Line formating" [commande]="    ls  " [comment]="Tab before and after")

# separator
declare -A cmd30=( [titre]="separator" [commande]="ls ; pwd" [comment]="Separator (;)")

# Pipe
declare -A cmd31=( [titre]="Pipe" [commande]="setenv COUCOU_LES_COUPAINS true\nenv | grep COUCOU_LES_COUPAINS" [comment]="Pipe with buildin")
declare -A cmd32=( [titre]="Pipe" [commande]="ls -R ./src | grep .c" [comment]="Notmal pipe")
declare -A cmd33=( [titre]="Pipe" [commande]="cat test24.txt | grep e" [comment]="Big inpout pipe")
declare -A cmd34=( [titre]="Pipe" [commande]="ls -R ./src | grep .c | grep main" [comment]="Multi pipe")
declare -A cmd35=( [titre]="Pipe" [commande]="cat nonexistentfile.txt | grep 'data'" [comment]="Little wrong pipe" )
declare -A cmd36=( [titre]="Pipe" [commande]="echo 'Test data' | grepp 'data'" [comment]="Little wrong pipe 2")
declare -A cmd37=( [titre]="Pipe" [commande]="ps aux | head -n 5" [comment]="Process")
declare -A cmd38=( [titre]="Pipe" [commande]="ps aux | grep root | grep ssh" [comment]="Search SSH")
declare -A cmd39=( [titre]="Pipe" [commande]="find . -name '*.log' | xargs cat | grep 'ERROR'" [comment]="Search error into .log file")

# Redirection
declare -A cmd40=( [titre]="Redirection d'entrée" [commande]="cat < fichier.txt" [comment]="Lit le contenu de fichier.txt via la commande cat.")
declare -A cmd41=( [titre]="Redirection de sortie" [commande]="echo 'Hello, world!' > sortie.txt\n cat sortie.txt ; rm sortie.txt" [comment]="Écrit 'Hello, world!' dans sortie.txt, en écrasant le contenu existant.")
declare -A cmd42=( [titre]="Redirection de sortie avec ajout" [commande]="echo 'Ajoutons cette ligne' >> sortie.txt\n cat sortie.txt ; rm sortie.txt" [comment]="Ajoute 'Ajoutons cette ligne' à la fin de sortie.txt.")
declare -A cmd43=( [titre]="Redirection d'entrée avec here-doc" [commande]="grep e << test34.txt" [comment]="Utilise 'cat' pour afficher les lignes fournies jusqu'à ce qu'il rencontre EOF.")
declare -A cmd44=( [titre]="Combinaison de redirections erronée" [commande]="cat < sortie.txt > sortie.txt" [comment]="Tente de lire et d'écrire sur le même fichier en même temps, ce qui peut causer des comportements indéfinis ou une erreur.")

# Advenced manipulation
declare -A cmd45=( [titre]="Advenced manipulation" [commande]="cat ./test/chat/chat.txt ./test/chbt/chbt.txt ./test/chot/chot.txt | sort | uniq > sorted_uniq.txt\ncat sorted_uniq.txt ; rm sorted_uniq.txt" [comment]="Read and sort different file")
declare -A cmd46=( [titre]="Advenced manipulation" [commande]="grep error ./test/chat/chat.txt ./test/chbt/chbt.txt ./test/chot/chot.txt | wc -l > error_count.txt\ncat error_count.txt ; rm error_count.txt" [comment]="Count the ocurence of ERROR word")
declare -A cmd47=( [titre]="Advenced manipulation" [commande]="cut -d':' -f1,3 ./test/chat/chat.txt ./test/chbt/chbt.txt ./test/chot/chot.txt | grep 'admin' > admins.txt\ncat admins.txt ; rm admins.txt" [comment]="Show one part of admin sentence.")

# && and || tests
declare -A cmd48=( [titre]="Test avec l'opérateur &&" [commande]="ls && ls -l \n ls && MOI && LE_CHAT && pwd'" [comment]="Test with &&")
declare -A cmd49=( [titre]="Test avec l'opérateur ||" [commande]="Le_chat || ls'" [comment]="Test with ||")
declare -A cmd50=( [titre]="Combinaison de && et ||" [commande]="ls imaginaire || pwd && ls ; ls imaginaire && pwd || ls -l" [comment]="Test with && and ||")

declare -A cmd51=( [titre]="Test avec l'opérateur &&" [commande]="ls && false && pwd" [comment]="Test with && where the middle command fails")
declare -A cmd52=( [titre]="Test avec l'opérateur ||" [commande]="false || ls || pwd" [comment]="Test with || where the middle command succeeds")
declare -A cmd53=( [titre]="Combinaison de && et ||" [commande]="false && echo 'This should not print' || echo 'This should print'" [comment]="Testing short-circuit evaluation in && and || combination")
declare -A cmd54=( [titre]="Test avec && et || avec des commandes d'état" [commande]="cd false && pwd || cd / && pwd" [comment]="Testing && and || with state-changing commands")


# Globings
declare -A cmd55=( [titre]="Globings" [commande]="ls test/ch*\nls test/ch?t\nls test/ch[a-d]t" [comment]="Using all globings")
declare -A cmd56=( [titre]="Globings" [commande]="ls test/?h*?" [comment]="Using ? and *")
declare -A cmd57=( [titre]="Globings" [commande]="ls -R *" [comment]="Using only *")

declare -A cmd58=( [titre]="Globings" [commande]="ls 'test/ch*'" [comment]="Testing globings with escape to check if globbing is skipped")
declare -A cmd59=( [titre]="Globings" [commande]="ls test/!(ch*)" [comment]="Using extended globbing for exclusion")
declare -A cmd60=( [titre]="Globings" [commande]="ls test/?h[a-c]*.txt" [comment]="Using complex combination of ? and character ranges")


# Var interpreter (echo)
declare -A cmd61=( [titre]="Var interpreter (echo)" [commande]="set something true \n echo $something \n set something \n set | grep something" [comment]="Change value of a parameter")
declare -A cmd62=( [titre]="Var interpreter (echo)" [commande]="set something \n set | grep something\n unset something \n set | grep something" [comment]="Set and unset")
declare -A cmd63=( [titre]="Var interpreter (echo)" [commande]="set something = true bleu = vert blabla=bloblo blibli =" [comment]="Multiple definition of different value")

declare -A cmd64=( [titre]="Var interpreter (echo)" [commande]="echo $PATH" [comment]="Check inherited environment variable")
declare -A cmd65=( [titre]="Var interpreter (echo)" [commande]="set dir=src\n cd $dir \n pwd" [comment]="Use variable in complex command sequence")
declare -A cmd66=( [titre]="Var interpreter (echo)" [commande]="set name=world\n echo Hello $name!" [comment]="Variable interpolation in string")
declare -A cmd67=( [titre]="Var interpreter (echo)" [commande]="set my-variable=123 \n echo $my-variable" [comment]="Handling variables with complex names")
declare -A cmd68=( [titre]="Var interpreter (echo)" [commande]="echo $undefined" [comment]="Echo a variable that is not defined")
declare -A cmd69=( [titre]="Var interpreter (echo)" [commande]="set tempvar=tempvalue\n unset tempvar \n echo $tempvar" [comment]="Ensure variable is cleared after unset")
# PENSER A CREER LE FOLDER
declare -A cmd70=( [titre]="Inhibitor" [commande]="ls 'my file.txt'" [comment]="Using quotes to handle file names with spaces")
declare -A cmd71=( [titre]="Inhibitor" [commande]="ls \"*.txt\"" [comment]="Using double quotes to allow globing expansion for filenames")
declare -A cmd72=( [titre]="Inhibitor" [commande]="echo \"Value: \$VALUE, Path: \$PATH\"" [comment]="Using double quotes in complex commands to check proper handling of multiple expansions")


# Inhibitor
declare -A cmd73=( [titre]="Inhibitor" [commande]="echo '$HOME'" [comment]="")
declare -A cmd74=( [titre]="Inhibitor" [commande]="echo '*'" [comment]="")

declare -A cmd75=( [titre]="Inhibitor" [commande]="echo \"$HOME\"" [comment]="Using double quotes to allow variable expansion")
declare -A cmd76=( [titre]="Inhibitor" [commande]="echo \"\$HOME is where the heart is\"" [comment]="Combining double quotes and escape to mix literal and variable content")
declare -A cmd77=( [titre]="//Inhibitor" [commande]="echo 'Special characters \$*\\'" [comment]="Using single quotes to ensure special characters are treated as literals")
declare -A cmd78=( [titre]="Inhibitor" [commande]="echo 'It\'s easy to use single quotes inside single quotes if you know how.'" [comment]="Escaping single quotes inside single quotes")


# Magic quote
declare -A cmd79=( [titre]="//Magic quote" [commande]="echo 'Le chemin actuel est \$HOME'" [comment]="Simple quote" )
declare -A cmd80=( [titre]="//Magic quote" [commande]="echo \"Le chemin actuel est \$HOME\"" [comment]="Cette commande utilise des guillemets doubles pour permettre l'expansion de la variable HOME, affichant ainsi le chemin du répertoire personnel de l'utilisateur." )
declare -A cmd81=( [titre]="//Magic quote" [commande]="echo \"Nous sommes le \$(date +%Y-%m-%d)\"" [comment]="Cette commande utilise des guillemets doubles et des backticks pour exécuter la commande date et afficher la date actuelle au format YYYY-MM-DD." )

declare -A cmd82=( [titre]="//Magic quote" [commande]="echo \"Le serveur fonctionne depuis \$(uptime)\"" [comment]="Utilisation de backticks pour exécuter la commande uptime et intégrer son résultat dans un message.")
declare -A cmd83=( [titre]="Magic quote" [commande]="echo \"L'utilisateur est \$USER et la date est \$(date +%Y-%m-%d)\"" [comment]="Combinaison de l'expansion de variables et de l'exécution de commandes dans une citation double pour afficher à la fois l'utilisateur et la date.")
declare -A cmd84=( [titre]="Magic quote" [commande]="echo \"La recherche donne : \$(grep 'motif' file.txt)\"" [comment]="Utilisation de guillemets imbriqués pour des commandes complexes intégrées.")
declare -A cmd85=( [titre]="//Magic quote" [commande]="echo \"Chemin d'accès : \$HOME et date : \\\$(date +%Y-%m-%d)\"" [comment]="Test des séquences d'échappement dans des citations doubles pour vérifier le traitement correct des caractères spéciaux.")
declare -A cmd86=( [titre]="//Magic quote" [commande]="echo \"Infos: \$(whoami), \$(hostname), \$(pwd)\"" [comment]="Exécution de multiples commandes shell dans une seule citation pour évaluer la gestion des subshells imbriqués.")


# Alias
declare -A cmd87=( [titre]="Alias" [commande]="alias BOB ls\nalias | grep BOB\nalias ls" [comment]="Normal alias")
declare -A cmd88=( [titre]="Alias" [commande]="alias BOB ls\nBOB" [comment]="Alias execution")
declare -A cmd89=( [titre]="Alias" [commande]="alias A B\nalias B A\nA" [comment]="Alias loop")
declare -A cmd90=( [titre]="Alias" [commande]="alias TRAIN ls\nTRAIN -l" [comment]="Alias with flags")
declare -A cmd91=( [titre]="Alias" [commande]="alias TRAIN ls; TRAIN" [comment]="On the same line")

declare -A cmd92=( [titre]="Alias" [commande]="alias BOB ls\nunalias BOB\nalias | grep BOB" [comment]="Removing an alias and checking if it's effectively removed")
declare -A cmd93=( [titre]="Alias" [commande]="alias ls='ls -l'\nls" [comment]="Redefining an existing command to include options")
declare -A cmd94=( [titre]="Alias" [commande]="alias LIST='ls -l'\nalias SHOW=LIST\nSHOW" [comment]="Alias that includes another alias for execution")
declare -A cmd95=( [titre]="Alias" [commande]="alias PREP='cd /var; ls'\nPREP" [comment]="Alias with multiple commands")
declare -A cmd96=( [titre]="Alias" [commande]="alias TODAY='echo Today is \$(date +%A)'\nTODAY" [comment]="Alias that includes command substitution")


# History
declare -A cmd97=( [titre]="History" [commande]="ls -l\npwd\nls\nhistory 2" [comment]="n history")
declare -A cmd98=( [titre]="History" [commande]="history azerty" [comment]="Wrong history command")
declare -A cmd99=( [titre]="History" [commande]="!" [comment]="Just !")
declare -A cmd100=( [titre]="History" [commande]="ls\n!ls" [comment]="!ls")
declare -A cmd101=( [titre]="History" [commande]="ls\npwd\nls -l\nls -R test\n!2" [comment]="!n")
declare -A cmd102=( [titre]="History" [commande]="ls\npwd\nls -l\nls -R test\n! 2" [comment]="! n")
declare -A cmd103=( [titre]="History" [commande]="ls\npwd\nls -l\nls -R test\n!azerty" [comment]="!n")

declare -A cmd104=( [titre]="History" [commande]="history -c\nhistory" [comment]="Clearing the history and then displaying to confirm it's empty")
declare -A cmd105=( [titre]="History" [commande]="echo 'Hello world!'\n!echo" [comment]="Executing last command starting with 'echo' that includes special characters")


# Parenthesis
declare -A cmd106=( [titre]="Parenthesis" [commande]="pwd; (ls -R ./src | grep .c); echo $?" [comment]="Basic parentheses")
declare -A cmd107=( [titre]="Parenthesis" [commande]="(ls);ls" [comment]="Basic parentheses")
declare -A cmd108=( [titre]="Parenthesis" [commande]="ls;(ls)" [comment]="Basic parentheses")
declare -A cmd109=( [titre]="Parenthesis" [commande]="((ls)ls)" [comment]="Wrong parenthesis")
declare -A cmd110=( [titre]="Parenthesis" [commande]="(ls;)ls" [comment]="Wrong")

declare -A cmd111=( [titre]="Parenthesis" [commande]="(cd /tmp; pwd); pwd" [comment]="Testing directory change inside parentheses does not affect the outer shell")
declare -A cmd112=( [titre]="Parenthesis" [commande]="(cd /tmp; (ls -l); pwd); pwd" [comment]="Using nested parentheses to manage scope of changes and commands")
declare -A cmd113=( [titre]="Parenthesis" [commande]="(exit 1); echo $?" [comment]="Testing if exit status from a subshell is propagated to the parent shell")


# Backticks
declare -A cmd114=( [titre]="//Backticks" [commande]="echo \`date\`" [comment]="Outputs the current date by substituting the command output.")
declare -A cmd115=( [titre]="//Backticks" [commande]="echo \`cat non_existant_file\`; echo \$?" [comment]="Tries to display the contents of a non-existent file and prints the exit status.")
declare -A cmd116=( [titre]="//Backticks" [commande]="echo \`echo \\\`whoami\\\`\`" [comment]="Demonstrates nested command substitution by printing the username of the current user.")
declare -A cmd117=( [titre]="//Backticks" [commande]="user=\`whoami\`; echo \$user" [comment]="Assigns the output of 'whoami' to a variable and displays it.")
declare -A cmd118=( [titre]="//Backticks" [commande]="ls -l \`which bash\`" [comment]="Lists the details of the binary file for bash.")
declare -A cmd119=( [titre]="//Backticks" [commande]="file_size=\`wc -l non_existent_file 2> /dev/null\` || echo 'Failed to calculate file size'" [comment]="Attempts to calculate the line count of a file that doesn't exist, suppressing error and showing a fail message.")
declare -A cmd120=( [titre]="//Backticks" [commande]="echo \`[ -d /tmp ] && echo 'Tmp directory exists'\`" [comment]="Checks if the /tmp directory exists and outputs a message accordingly.")
declare -A cmd121=( [titre]="//Backticks" [commande]="\`mkdir new_dir; cd new_dir; pwd\`" [comment]="Creates a new directory, changes to it, and then prints the current working directory.")
declare -A cmd122=( [titre]="//Backticks" [commande]="\`ls -l /non_existent_directory 2>&1\`" [comment]="Tries to list a non-existent directory, redirecting both output and error.")
declare -A cmd123=( [titre]="//Backticks" [commande]="time \`\`sleep 2\`\`" [comment]="Measures the time taken to execute a sleep command within backticks.")




test=( cmd1 cmd2 cmd3 cmd4 cmd5 cmd6 cmd7 cmd8 cmd9 cmd10 cmd11 cmd12 cmd13  cmd14 cmd15 cmd16 cmd17 cmd18 cmd19 cmd20 cmd21 cmd22 cmd23 cmd24 cmd25 cmd26 cmd27 cmd28 cmd29 cmd30 cmd31 cmd32 cmd33 cmd34 cmd35 cmd36 cmd37 cmd38 cmd39 cmd40 cmd41 cmd42 cmd43 cmd44 cmd45 cmd46 cmd47 cmd48 cmd49 cmd50 cmd51 cmd52 cmd53 cmd54 cmd55 cmd56 cmd57 cmd58 cmd59 cmd60 cmd61 cmd62 cmd63 cmd64 cmd65 cmd66 cmd67 cmd68 cmd69 cmd70 cmd71 cmd72 cmd73 cmd74 cmd75 cmd76 cmd77 cmd78 cmd79 cmd80 cmd81 cmd82 cmd83 cmd84 cmd85 cmd86 cmd87 cmd88 cmd89 cmd90 cmd91 cmd92 cmd93 cmd94 cmd95 cmd96 cmd97 cmd98 cmd99 cmd100 cmd101 cmd102 cmd103 cmd104 cmd105 cmd106 cmd107 cmd108 cmd109 cmd110 cmd111 cmd112 cmd113 cmd114 cmd115 cmd116 cmd117 cmd118 cmd119 cmd120 cmd121 cmd122 cmd123 )
################################################################################
###################################TEST_FUNC####################################
################################################################################

declare -i total=0
declare -i count=0

lunch_test() {
    local -n test=$1
    total+=1
    touch "test/tcsh_1.txt"
    touch "test/tcsh_2.txt"
    touch "test/tcsh_exit.txt"
    touch "test/42sh_1.txt"
    touch "test/42sh_2.txt"
    touch "test/42sh_exit.txt"
    # TCSH COMMANDE
    echo -e "${test[commande]}" | tcsh > "test/tcsh_1.txt" 2> "test/tcsh_2.txt"
    echo "$?" > "test/tcsh_exit.txt"
    # 42SH COMMANDE
    echo -e "${test[commande]}" | ./42sh > "test/42sh_1.txt" 2> "test/42sh_2.txt"
    echo "$?" > "test/42sh_exit.txt"
    rm .history 2> /dev/null

    # Comparaison
    echo "------------------------------------------------------------"
    echo "${test[titre]}"
    echo "COMMAND: ${test[commande]}"
    echo "COMMENT: ${test[comment]}"
    if diff -q test/tcsh_1.txt "test/42sh_1.txt" > /dev/null && diff -q test/tcsh_2.txt "test/42sh_2.txt" > /dev/null && diff -q test/tcsh_exit.txt "test/42sh_exit.txt" > /dev/null; then
        echo -e "\e[32mTEST RESULT : OK\e[0m"
        count+=1
    else
        echo -e "\e[31mTEST RESULT : KO :(\e[0m"
        if diff -q test/tcsh_1.txt "test/42sh_1.txt" > /dev/null; then
            echo "---"
            echo -e "\e[32mSTANDAR OUTPUT : OK\e[0m"
        else
            echo "---"
            echo -e "\e[31mSTANDAR OUTPUT : KO\e[0m"
            echo ""
            echo -e "\e[31m42SH STANDAR OUTPUT :\e[0m"
            cat "test/42sh_1.txt"
            echo ""
            echo -e "\e[32mTCSH STANDAR OUTPUT :\e[0m"
            cat test/tcsh_1.txt
            echo ""
            echo -e "\e[33mDIFFERENCE :\e[0m"
            diff test/tcsh_1.txt "test/42sh_1.txt"
        fi
        if diff -q test/tcsh_2.txt "test/42sh_2.txt" > /dev/null; then
            echo "---"
            echo -e "\e[32mERROR OUTPUT : OK\e[0m"
        else
            echo "---"
            echo -e "\e[31mERROR OUTPUT : KO\e[0m"
            echo -e "\e[31m42SH ERROR OUTPUT :\e[0m"
            cat "test/42sh_2.txt"
            echo -e "\e[32mTCSH ERROR OUTPUT :\e[0m"
            cat test/tcsh_2.txt
            echo -e "\e[33mDIFFERENCE :\e[0m"
            diff test/tcsh_2.txt "test/42sh_2.txt"
        fi
        if diff -q test/tcsh_exit.txt "test/42sh_exit.txt" > /dev/null; then
            echo "---"
            echo -e "\e[32mEXIT_CODE OUTPUT : OK\e[0m"
        else
            echo "---"
            echo -e "\e[31mEXIT_CODE OUTPUT : KO\e[0m"
            echo -e "\e[31m42SH EXIT_CODE OUTPUT :\e[0m"
            cat "test/42sh_exit.txt"
            echo -e "\e[32mTCSH EXIT_CODE OUTPUT :\e[0m"
            cat test/tcsh_exit.txt
            echo -e "\e[33mDIFFERENCE :\e[0m"
            diff test/tcsh_exit.txt "test/42sh_exit.txt"
        fi
    fi
    echo "------------------------------------------------------------"
    rm test/tcsh_1.txt
    rm test/tcsh_2.txt
    rm test/tcsh_exit.txt
    rm "test/42sh_1.txt"
    rm "test/42sh_2.txt"
    rm "test/42sh_exit.txt"
    echo ""
}

for test_name in "${!test[@]}"; do
    lunch_test "${test[$test_name]}"
done

declare -i fail=$((total - count))
declare -i pourcent=$((count * 100 / total))

echo -e "\e[32mOK: $count\e[0m"
echo -e "\e[31mKO: $fail\e[0m"
echo -e "\e[36mTOTAL: $pourcent%\e[0m"
rm sortie.txt
