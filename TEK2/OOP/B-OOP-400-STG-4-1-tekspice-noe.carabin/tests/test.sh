#!/bin/bash
##
## EPITECH PROJECT, 2024
## B-PDG-300-STG-3-1-PDGRUSH1-noe.carabin
## File description:
## test.sh
##

# Définition des couleurs ANSI
RED="\e[31m"
GREEN="\e[32m"
BLUE="\e[34m"
RESET="\e[0m"
#make re

ERROR=0
SUCCES=0
TOTAL=0
RESULT=0

################################################################################
###################################TABLEAUX DE TESTS############################
################################################################################

declare -A test_table_1
declare -A test_table_2
declare -A test_table_3
declare -A test_table_4
declare -A test_table_5
declare -A test_table_6
declare -A test_table_7
declare -A test_table_8
declare -A test_table_9
declare -A test_table_10
declare -A test_table_11
declare -A test_table_12
declare -A test_table_13
declare -A test_table_14
declare -A test_table_15
declare -A test_table_16
declare -A test_table_17
declare -A test_table_18
declare -A test_table_19
declare -A test_table_20
declare -A test_table_21
declare -A test_table_22
declare -A test_table_23
declare -A test_table_24
declare -A test_table_25
declare -A test_table_26
declare -A test_table_27
declare -A test_table_28
declare -A test_table_29
declare -A test_table_30
declare -A test_table_31
declare -A test_table_32
declare -A test_table_33
declare -A test_table_34

##############################################################################
# 1) Test simple input/output valide
##############################################################################
test_table_1=(
    [Titre]="Test 1 : Simple input -> output"
    [Command]="echo -e 'simulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_simple_in_out.nts"
    [Comment]="Vérifie un input relié directement à un output (tous deux Undefined au départ)."
    [NormalOutput]="> > tick: 1
input(s):
  i0: U
output(s):
  out: U
>"
    [NormalExitCode]="0"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 2) Extension invalide => "ERROR - Unknown extension file."
##############################################################################
test_table_2=(
    [Titre]="Test 2 : Fichier avec extension invalide"
    [Command]="echo -e 'display\nexit' | ./nanotekspice tests/test_file/test_invalid_extension.nt"
    [Comment]="Provoque l'erreur d'extension inconnue."
    [NormalOutput]="ERROR - Unknown extension file."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 3) Fichier .nts inexistant => "ERROR - No such file or directory."
##############################################################################
test_table_3=(
    [Titre]="Test 3 : Fichier inexistant"
    [Command]="echo -e 'display\nexit' | ./nanotekspice tests/test_file/test_dont_exist.nts"
    [Comment]="Le fichier n'existe pas du tout."
    [NormalOutput]="ERROR - No such file or directory."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 4) Pas de section .chipsets => "ERROR - No .chipset section found."
##############################################################################
test_table_4=(
    [Titre]="Test 4 : Pas de .chipsets"
    [Command]="echo -e 'display\nexit' | ./nanotekspice tests/test_file/test_missing_chipset.nts"
    [Comment]="Manque complètement la section .chipsets."
    [NormalOutput]="ERROR - Sections are in the wrong order."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 5) Trop d’arguments composant => "ERROR - Too many arguments on a component declaration."
##############################################################################
test_table_5=(
    [Titre]="Test 5 : Trop d’arguments"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_too_many_args.nts"
    [Comment]="Exemple : 'input i0 i1' sur une seule ligne."
    [NormalOutput]="ERROR - Too many arguments on a component declaration."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 6) Pas assez d’arguments => "ERROR - Not enough arguments on a component declaration."
##############################################################################
test_table_6=(
    [Titre]="Test 6 : Pas assez d’arguments"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_not_enough_args.nts"
    [Comment]="Exemple : 'input' sans nom de composant."
    [NormalOutput]="ERROR - Not enough arguments on a component declaration."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 7) Deux mêmes noms => "ERROR - Two components cannot have the same Name."
##############################################################################
test_table_7=(
    [Titre]="Test 7 : Noms en double"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_same_name.nts"
    [Comment]="Déclare deux fois 'input i0'."
    [NormalOutput]="ERROR - Two components cannot have the same Name."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 8) Link vers un composant non déclaré => "ERROR - Link error : You used an uninitialized entity."
##############################################################################
test_table_8=(
    [Titre]="Test 8 : Link composant inconnu"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_link_uninitialized.nts"
    [Comment]="links: unknown:1 out:1 -> composant 'unknown' non déclaré."
    [NormalOutput]="ERROR - Link error : You used an uninitialized entity."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 9) Déclaration d’un composant inconnu => "ERROR - Unknown component type."
##############################################################################
test_table_9=(
    [Titre]="Test 9 : Composant inconnu"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_unknown_component.nts"
    [Comment]="Déclare un composant qui n'existe pas."
    [NormalOutput]="ERROR - Unknown component type."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 10) Lien dupliqué vers un même composant => "ERROR - Duplicate link detected."
##############################################################################
declare -A test_table_10
test_table_10=(
    [Titre]="Test 10 : Lien dupliqué"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_duplicate_link.nts"
    [Comment]="Test pour vérifier si un même lien entre composants est dupliqué."
    [NormalOutput]="> >"
    [NormalExitCode]="0"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 11) Syntaxe incorrecte dans le fichier => "ERROR - Invalid syntax in file."
##############################################################################
declare -A test_table_11
test_table_11=(
    [Titre]="Test 11 : Syntaxe incorrecte"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_incorrect_syntax.nts"
    [Comment]="Test pour voir si une erreur de syntaxe dans le fichier est bien détectée."
    [NormalOutput]="ERROR - Not enough arguments on a component declaration."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)


##############################################################################
# 12) Fichier vide => "ERROR - Empty file."
##############################################################################
test_table_12=(
    [Titre]="Test 12 : Fichier vide"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_empty_file.nts"
    [Comment]="Le fichier est complètement vide."
    [NormalOutput]="ERROR - No .chipset section found."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 13) Mauvais ordre des sections => "ERROR - Sections are in the wrong order."
##############################################################################
test_table_13=(
    [Titre]="Test 13 : Sections dans le mauvais ordre"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_wrong_section_order.nts"
    [Comment]="La section .links est placée avant .chipsets."
    [NormalOutput]="ERROR - Sections are in the wrong order."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 14) Déclaration invalide d'un lien => "ERROR - Invalid link declaration."
##############################################################################
test_table_14=(
    [Titre]="Test 14 : Déclaration de lien invalide"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_invalid_link.nts"
    [Comment]="Lien mal déclaré entre deux composants."
    [NormalOutput]="ERROR - Link error : You used an uninitialized entity."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 15) Déclaration incorrecte d’un input => "ERROR - Invalid input declaration."
##############################################################################
test_table_15=(
    [Titre]="Test 15 : Déclaration d’input incorrecte"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_invalid_input.nts"
    [Comment]="Déclare un input avec une syntaxe erronée."
    [NormalOutput]="ERROR - Unknown component type."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 16) Déclaration incorrecte d’un output => "ERROR - Invalid output declaration."
##############################################################################
test_table_16=(
    [Titre]="Test 16 : Déclaration d’output incorrecte"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_invalid_output.nts"
    [Comment]="Déclare un output avec une syntaxe erronée."
    [NormalOutput]="ERROR - Too many arguments on a component declaration."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 17) Fichier trop gros => "ERROR - File size exceeds limit."
##############################################################################
test_table_17=(
    [Titre]="Test 17 : Fichier trop gros"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_large_file.nts"
    [Comment]="Fichier dépassant la taille maximale autorisée."
    [NormalOutput]="> >"
    [NormalExitCode]="0"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 18) Trop de composants => "ERROR - Too many components declared."
##############################################################################
test_table_18=(
    [Titre]="Test 18 : Trop de composants"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_too_many_components.nts"
    [Comment]="Trop de composants sont déclarés dans le fichier."
    [NormalOutput]="> >"
    [NormalExitCode]="0"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 19) Mauvaise déclaration d’un clock => "ERROR - Invalid clock declaration."
##############################################################################
test_table_19=(
    [Titre]="Test 19 : Déclaration de clock incorrecte"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_invalid_clock.nts"
    [Comment]="Déclaration incorrecte d'un clock."
    [NormalOutput]="ERROR - Too many arguments on a component declaration."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# 20) Composant déjà utilisé ailleurs => "ERROR - Component is already in use."
##############################################################################
test_table_20=(
    [Titre]="Test 20 : Lien en dehors des limites"
    [Command]="echo -e 'simulate\nexit' | ./nanotekspice tests/test_file/test_component_bounds.nts"
    [Comment]="Un composant est connecté avec des connexions incohérentes."
    [NormalOutput]="ERROR - out is out of bounds."
    [NormalExitCode]="84"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# TESTS POUR LE COMPOSANT "INPUT"
##############################################################################

# Test 21 : Input qui modifie un signal
test_table_21=(
    [Titre]="Test 21 : Input modifie un signal"
    [Command]="echo -e 'i0=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_input_signal.nts"
    [Comment]="Teste si un input modifie correctement un signal."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  i0: 1\noutput(s):\n  out: 1\n>"
    [NormalExitCode]="0"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# TESTS POUR LE COMPOSANT "OUTPUT"
##############################################################################

# Test 22 : Output relié à un input qui change
test_table_22=(
    [Titre]="Test 22 : Output réactif"
    [Command]="echo -e 'i0=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_output_reactive.nts"
    [Comment]="Teste si un output suit bien un input modifié."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  i0: 1\noutput(s):\n  out: 1\n>"
    [NormalExitCode]="0"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)


##############################################################################
# TESTS POUR LE COMPOSANT "CLOCK"
##############################################################################

# Test 23 : Clock qui oscille après initialisation
test_table_23=(
    [Titre]="Test 23 : Clock oscillant après initialisation"
    [Command]="echo -e 'display\nc0=0\nsimulate\ndisplay\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_clock.nts"
    [Comment]="Teste un clock qui change de valeur après initialisation et simulation."
    [NormalOutput]="> tick: 0\ninput(s):\n  c0: U\noutput(s):\n  out: U\n\
> > > tick: 1\ninput(s):\n  c0: 0\noutput(s):\n  out: 0\n\
> > tick: 2\ninput(s):\n  c0: 1\noutput(s):\n  out: 1\n>"
    [NormalExitCode]="0"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)


##############################################################################
# TESTS POUR LE COMPOSANT "TRUE" ET "FALSE"
##############################################################################

# Test 24 : TRUE relié à un output (FORCE PROPAGATION)
test_table_24=(
    [Titre]="Test 24 : TRUE relié à un output"
    [Command]="echo -e 'display\nexit' | ./nanotekspice tests/test_file/test_true_linked.nts"
    [Comment]="Teste si TRUE transmet bien 1 à un output après propagation du signal."
    [NormalOutput]="> tick: 0\ninput(s):\noutput(s):\n  out: 1\n>"
    [NormalExitCode]="0"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

# Test 25 : FALSE relié à un output (FORCE PROPAGATION)
test_table_25=(
    [Titre]="Test 25 : FALSE relié à un output"
    [Command]="echo -e 'display\nexit' | ./nanotekspice tests/test_file/test_false_linked.nts"
    [Comment]="Teste si FALSE transmet bien 0 à un output après propagation du signal."
    [NormalOutput]="> tick: 0\ninput(s):\noutput(s):\n  out: 0\n>"
    [NormalExitCode]="0"
    [PreCommand]=""
    [SpecificTimeoutOnSec]="-1"
)

##############################################################################
# TESTS POUR LA PORTE AND (A ⋅ B)
##############################################################################

# Test 26 : AND (0 & 0 = 0)
test_table_26=(
    [Titre]="Test 26 : AND (0 & 0 = 0)"
    [Command]="echo -e 'a=0\nb=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_and.nts"
    [Comment]="Test de la porte AND avec 0 & 0."
    [NormalOutput]="> > > > tick: 1\ninput(s):\n  a: 0\n  b: 0\noutput(s):\n  out: 0\n>"
    [NormalExitCode]="0"
)

# Test 27 : AND (0 & 1 = 0)
test_table_27=(
    [Titre]="Test 27 : AND (0 & 1 = 0)"
    [Command]="echo -e 'a=0\nb=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_and.nts"
    [Comment]="Test de la porte AND avec 0 & 1."
    [NormalOutput]="> > > > tick: 1\ninput(s):\n  a: 0\n  b: 1\noutput(s):\n  out: 0\n>"
    [NormalExitCode]="0"
)

# Test 28 : AND (0 & U = 0)
test_table_28=(
    [Titre]="Test 28 : AND (0 & U = 0)"
    [Command]="echo -e 'a=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_and.nts"
    [Comment]="Test de la porte AND avec 0 & U."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: 0\n  b: U\noutput(s):\n  out: 0\n>"
    [NormalExitCode]="0"
)

# Test 29 : AND (1 & 0 = 0)
test_table_29=(
    [Titre]="Test 29 : AND (1 & 0 = 0)"
    [Command]="echo -e 'a=1\nb=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_and.nts"
    [Comment]="Test de la porte AND avec 1 & 0."
    [NormalOutput]="> > > > tick: 1\ninput(s):\n  a: 1\n  b: 0\noutput(s):\n  out: 0\n>"
    [NormalExitCode]="0"
)

# Test 30 : AND (1 & 1 = 1)
test_table_30=(
    [Titre]="Test 30 : AND (1 & 1 = 1)"
    [Command]="echo -e 'a=1\nb=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_and.nts"
    [Comment]="Test de la porte AND avec 1 & 1."
    [NormalOutput]="> > > > tick: 1\ninput(s):\n  a: 1\n  b: 1\noutput(s):\n  out: 1\n>"
    [NormalExitCode]="0"
)

# Test 31 : AND (1 & U = U)
test_table_31=(
    [Titre]="Test 31 : AND (1 & U = U)"
    [Command]="echo -e 'a=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_and.nts"
    [Comment]="Test de la porte AND avec 1 & U."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: 1\n  b: U\noutput(s):\n  out: U\n>"
    [NormalExitCode]="0"
)

# Test 32 : AND (U & 0 = 0)
test_table_32=(
    [Titre]="Test 32 : AND (U & 0 = 0)"
    [Command]="echo -e 'b=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_and.nts"
    [Comment]="Test de la porte AND avec U & 0."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: U\n  b: 0\noutput(s):\n  out: 0\n>"
    [NormalExitCode]="0"
)

# Test 33 : AND (U & 1 = U)
test_table_33=(
    [Titre]="Test 33 : AND (U & 1 = U)"
    [Command]="echo -e 'b=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_and.nts"
    [Comment]="Test de la porte AND avec U & 1."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: U\n  b: 1\noutput(s):\n  out: U\n>"
    [NormalExitCode]="0"
)

# Test 34 : AND (U & U = U)
test_table_34=(
    [Titre]="Test 34 : AND (U & U = U)"
    [Command]="echo -e 'simulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_and.nts"
    [Comment]="Test de la porte AND avec U & U."
    [NormalOutput]="> > tick: 1\ninput(s):\n  a: U\n  b: U\noutput(s):\n  out: U\n>"
    [NormalExitCode]="0"
)

# Déclarations des tests
declare -A test_table_35
declare -A test_table_36
declare -A test_table_37
declare -A test_table_38
declare -A test_table_39
declare -A test_table_40
declare -A test_table_41
declare -A test_table_42
declare -A test_table_43

# Test 35 : OR (0 | 0 = 0)
test_table_35=(
    [Titre]="Test 35 : OR (0 | 0 = 0)"
    [Command]="echo -e 'a=0\nb=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_or.nts"
    [Comment]="Test de la porte OR avec 0 | 0."
    [NormalOutput]="> > > > tick: 1\ninput(s):\n  a: 0\n  b: 0\noutput(s):\n  out: 0\n>"
    [NormalExitCode]="0"
)

# Test 36 : OR (0 | 1 = 1)
test_table_36=(
    [Titre]="Test 36 : OR (0 | 1 = 1)"
    [Command]="echo -e 'a=0\nb=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_or.nts"
    [Comment]="Test de la porte OR avec 0 | 1."
    [NormalOutput]="> > > > tick: 1\ninput(s):\n  a: 0\n  b: 1\noutput(s):\n  out: 1\n>"
    [NormalExitCode]="0"
)

# Test 37 : OR (0 | U = U)
test_table_37=(
    [Titre]="Test 37 : OR (0 | U = U)"
    [Command]="echo -e 'a=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_or.nts"
    [Comment]="Test de la porte OR avec 0 | U."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: 0\n  b: U\noutput(s):\n  out: U\n>"
    [NormalExitCode]="0"
)

# Test 38 : OR (1 | 0 = 1)
test_table_38=(
    [Titre]="Test 38 : OR (1 | 0 = 1)"
    [Command]="echo -e 'a=1\nb=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_or.nts"
    [Comment]="Test de la porte OR avec 1 | 0."
    [NormalOutput]="> > > > tick: 1\ninput(s):\n  a: 1\n  b: 0\noutput(s):\n  out: 1\n>"
    [NormalExitCode]="0"
)

# Test 39 : OR (1 | 1 = 1)
test_table_39=(
    [Titre]="Test 39 : OR (1 | 1 = 1)"
    [Command]="echo -e 'a=1\nb=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_or.nts"
    [Comment]="Test de la porte OR avec 1 | 1."
    [NormalOutput]="> > > > tick: 1\ninput(s):\n  a: 1\n  b: 1\noutput(s):\n  out: 1\n>"
    [NormalExitCode]="0"
)

# Test 40 : OR (1 | U = 1)
test_table_40=(
    [Titre]="Test 40 : OR (1 | U = 1)"
    [Command]="echo -e 'a=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_or.nts"
    [Comment]="Test de la porte OR avec 1 | U."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: 1\n  b: U\noutput(s):\n  out: 1\n>"
    [NormalExitCode]="0"
)

# Test 41 : OR (U | 0 = U)
test_table_41=(
    [Titre]="Test 41 : OR (U | 0 = U)"
    [Command]="echo -e 'b=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_or.nts"
    [Comment]="Test de la porte OR avec U | 0."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: U\n  b: 0\noutput(s):\n  out: U\n>"
    [NormalExitCode]="0"
)

# Test 42 : OR (U | 1 = 1)
test_table_42=(
    [Titre]="Test 42 : OR (U | 1 = 1)"
    [Command]="echo -e 'b=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_or.nts"
    [Comment]="Test de la porte OR avec U | 1."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: U\n  b: 1\noutput(s):\n  out: 1\n>"
    [NormalExitCode]="0"
)

# Test 43 : OR (U | U = U)
test_table_43=(
    [Titre]="Test 43 : OR (U | U = U)"
    [Command]="echo -e 'simulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_or.nts"
    [Comment]="Test de la porte OR avec U | U."
    [NormalOutput]="> > tick: 1\ninput(s):\n  a: U\n  b: U\noutput(s):\n  out: U\n>"
    [NormalExitCode]="0"
)

# Déclarations des tests
declare -A test_table_44
declare -A test_table_45
declare -A test_table_46
declare -A test_table_47
declare -A test_table_48
declare -A test_table_49
declare -A test_table_50
declare -A test_table_51
declare -A test_table_52

# Test 44 : XOR (0 ⊕ 0 = 0)
test_table_44=(
    [Titre]="Test 44 : XOR (0 ⊕ 0 = 0)"
    [Command]="echo -e 'a=0\nb=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_xor.nts"
    [Comment]="Test de la porte XOR avec 0 ⊕ 0."
    [NormalOutput]="> > > > tick: 1\ninput(s):\n  a: 0\n  b: 0\noutput(s):\n  out: 0\n>"
    [NormalExitCode]="0"
)

# Test 45 : XOR (0 ⊕ 1 = 1)
test_table_45=(
    [Titre]="Test 45 : XOR (0 ⊕ 1 = 1)"
    [Command]="echo -e 'a=0\nb=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_xor.nts"
    [Comment]="Test de la porte XOR avec 0 ⊕ 1."
    [NormalOutput]="> > > > tick: 1\ninput(s):\n  a: 0\n  b: 1\noutput(s):\n  out: 1\n>"
    [NormalExitCode]="0"
)

# Test 46 : XOR (0 ⊕ U = U)
test_table_46=(
    [Titre]="Test 46 : XOR (0 ⊕ U = U)"
    [Command]="echo -e 'a=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_xor.nts"
    [Comment]="Test de la porte XOR avec 0 ⊕ U."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: 0\n  b: U\noutput(s):\n  out: U\n>"
    [NormalExitCode]="0"
)

# Test 47 : XOR (1 ⊕ 0 = 1)
test_table_47=(
    [Titre]="Test 47 : XOR (1 ⊕ 0 = 1)"
    [Command]="echo -e 'a=1\nb=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_xor.nts"
    [Comment]="Test de la porte XOR avec 1 ⊕ 0."
    [NormalOutput]="> > > > tick: 1\ninput(s):\n  a: 1\n  b: 0\noutput(s):\n  out: 1\n>"
    [NormalExitCode]="0"
)

# Test 48 : XOR (1 ⊕ 1 = 0)
test_table_48=(
    [Titre]="Test 48 : XOR (1 ⊕ 1 = 0)"
    [Command]="echo -e 'a=1\nb=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_xor.nts"
    [Comment]="Test de la porte XOR avec 1 ⊕ 1."
    [NormalOutput]="> > > > tick: 1\ninput(s):\n  a: 1\n  b: 1\noutput(s):\n  out: 0\n>"
    [NormalExitCode]="0"
)

# Test 49 : XOR (1 ⊕ U = U)
test_table_49=(
    [Titre]="Test 49 : XOR (1 ⊕ U = U)"
    [Command]="echo -e 'a=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_xor.nts"
    [Comment]="Test de la porte XOR avec 1 ⊕ U."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: 1\n  b: U\noutput(s):\n  out: U\n>"
    [NormalExitCode]="0"
)

# Test 50 : XOR (U ⊕ 0 = U)
test_table_50=(
    [Titre]="Test 50 : XOR (U ⊕ 0 = U)"
    [Command]="echo -e 'b=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_xor.nts"
    [Comment]="Test de la porte XOR avec U ⊕ 0."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: U\n  b: 0\noutput(s):\n  out: U\n>"
    [NormalExitCode]="0"
)

# Test 51 : XOR (U ⊕ 1 = U)
test_table_51=(
    [Titre]="Test 51 : XOR (U ⊕ 1 = U)"
    [Command]="echo -e 'b=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_xor.nts"
    [Comment]="Test de la porte XOR avec U ⊕ 1."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: U\n  b: 1\noutput(s):\n  out: U\n>"
    [NormalExitCode]="0"
)

# Test 52 : XOR (U ⊕ U = U)
test_table_52=(
    [Titre]="Test 52 : XOR (U ⊕ U = U)"
    [Command]="echo -e 'simulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_xor.nts"
    [Comment]="Test de la porte XOR avec U ⊕ U."
    [NormalOutput]="> > tick: 1\ninput(s):\n  a: U\n  b: U\noutput(s):\n  out: U\n>"
    [NormalExitCode]="0"
)

# Déclarations des tests
declare -A test_table_53
declare -A test_table_54
declare -A test_table_55

# Test 53 : NOT (0 → 1)
test_table_53=(
    [Titre]="Test 53 : NOT (0 → 1)"
    [Command]="echo -e 'a=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_not.nts"
    [Comment]="Test de la porte NOT avec 0."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: 0\noutput(s):\n  out: 1\n>"
    [NormalExitCode]="0"
)

# Test 54 : NOT (1 → 0)
test_table_54=(
    [Titre]="Test 54 : NOT (1 → 0)"
    [Command]="echo -e 'a=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_not.nts"
    [Comment]="Test de la porte NOT avec 1."
    [NormalOutput]="> > > tick: 1\ninput(s):\n  a: 1\noutput(s):\n  out: 0\n>"
    [NormalExitCode]="0"
)

# Test 55 : NOT (U → U)
test_table_55=(
    [Titre]="Test 55 : NOT (U → U)"
    [Command]="echo -e 'simulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_not.nts"
    [Comment]="Test de la porte NOT avec U (Undefined)."
    [NormalOutput]="> > tick: 1\ninput(s):\n  a: U\noutput(s):\n  out: U\n>"
    [NormalExitCode]="0"
)

################################################################################
############################GATES###############################################
################################################################################

# Déclarations des tests
declare -A test_table_56
declare -A test_table_57
declare -A test_table_58
declare -A test_table_59
declare -A test_table_60
declare -A test_table_61
declare -A test_table_62
declare -A test_table_63
declare -A test_table_64
declare -A test_table_65

# Test 56 : NOR(0,0) → 1
test_table_56=(
    [Titre]="Test 56 : NOR(0,0) → 1"
    [Command]="echo -e 'a=0\nb=0\nc=0\nd=0\ne=0\nf=0\ng=0\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4001.nts"
    [Comment]="Test de toutes les portes NOR avec les entrées 0,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: 0\n  c: 0\n  d: 0\n  e: 0\n  f: 0\n  g: 0\n  h: 0\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

# Test 57 : NOR(0,1) → 0
test_table_57=(
    [Titre]="Test 57 : NOR(0,1) → 0"
    [Command]="echo -e 'a=0\nb=1\nc=0\nd=1\ne=0\nf=1\ng=0\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4001.nts"
    [Comment]="Test de toutes les portes NOR avec les entrées 0,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: 1\n  c: 0\n  d: 1\n  e: 0\n  f: 1\n  g: 0\n  h: 1\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n>"
    [NormalExitCode]="0"
)

# Test 58 : NOR(0,U) → U
test_table_58=(
    [Titre]="Test 58 : NOR(0,U) → U"
    [Command]="echo -e 'a=0\nb=U\nc=0\nd=U\ne=0\nf=U\ng=0\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4001.nts"
    [Comment]="Test de toutes les portes NOR avec les entrées 0,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: U\n  c: 0\n  d: U\n  e: 0\n  f: U\n  g: 0\n  h: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Test 59 : NOR(1,0) → 0
test_table_59=(
    [Titre]="Test 59 : NOR(1,0) → 0"
    [Command]="echo -e 'a=1\nb=0\nc=1\nd=0\ne=1\nf=0\ng=1\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4001.nts"
    [Comment]="Test de toutes les portes NOR avec les entrées 1,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: 0\n  c: 1\n  d: 0\n  e: 1\n  f: 0\n  g: 1\n  h: 0\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n>"
    [NormalExitCode]="0"
)

# Test 60 : NOR(1,1) → 0
test_table_60=(
    [Titre]="Test 60 : NOR(1,1) → 0"
    [Command]="echo -e 'a=1\nb=1\nc=1\nd=1\ne=1\nf=1\ng=1\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4001.nts"
    [Comment]="Test de toutes les portes NOR avec les entrées 1,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: 1\n  c: 1\n  d: 1\n  e: 1\n  f: 1\n  g: 1\n  h: 1\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n>"
    [NormalExitCode]="0"
)

# Test 61 : NOR(U, U) → U
test_table_61=(
    [Titre]="Test 61 : NOR(U,U) → U"
    [Command]="echo -e 'a=U\nb=U\nc=U\nd=U\ne=U\nf=U\ng=U\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4001.nts"
    [Comment]="Test de toutes les portes NOR avec les entrées U,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: U\n  c: U\n  d: U\n  e: U\n  f: U\n  g: U\n  h: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Test 62 : NOR(U, 0) → U
test_table_62=(
    [Titre]="Test 62 : NOR(U,0) → U"
    [Command]="echo -e 'a=U\nb=0\nc=U\nd=0\ne=U\nf=0\ng=U\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4001.nts"
    [Comment]="Test de toutes les portes NOR avec les entrées U,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: 0\n  c: U\n  d: 0\n  e: U\n  f: 0\n  g: U\n  h: 0\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Test 63 : NOR(U, 1) → 0
test_table_63=(
    [Titre]="Test 63 : NOR(U,1) → 0"
    [Command]="echo -e 'a=U\nb=1\nc=U\nd=1\ne=U\nf=1\ng=U\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4001.nts"
    [Comment]="Test de toutes les portes NOR avec les entrées U,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: 1\n  c: U\n  d: 1\n  e: U\n  f: 1\n  g: U\n  h: 1\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n>"
    [NormalExitCode]="0"
)

# Test 64 : NOR(U,U) → U
test_table_64=(
    [Titre]="Test 64 : NOR(U,U) → U"
    [Command]="echo -e 'a=U\nb=U\nc=U\nd=U\ne=U\nf=U\ng=U\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4001.nts"
    [Comment]="Test de toutes les portes NOR avec les entrées U,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: U\n  c: U\n  d: U\n  e: U\n  f: U\n  g: U\n  h: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Test 65 : NOR(U,U) avec alternance → U
test_table_65=(
    [Titre]="Test 65 : NOR(U,U) avec alternance → U"
    [Command]="echo -e 'a=U\nb=U\nc=0\nd=1\ne=1\nf=0\ng=U\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4001.nts"
    [Comment]="Test de toutes les portes NOR avec certaines entrées en U, d'autres en 0 ou 1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: U\n  c: 0\n  d: 1\n  e: 1\n  f: 0\n  g: U\n  h: U\noutput(s):\n  out1: U\n  out2: 0\n  out3: 0\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Déclarations des tests

# Déclarations des tests

declare -A test_table_66
declare -A test_table_67
declare -A test_table_68
declare -A test_table_69
declare -A test_table_70
declare -A test_table_71
declare -A test_table_72
declare -A test_table_73
declare -A test_table_74

# Test 66 : NAND(0,0) → 1
test_table_66=(
    [Titre]="Test 66 : NAND(0,0) → 1"
    [Command]="echo -e 'a=0\nb=0\nc=0\nd=0\ne=0\nf=0\ng=0\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4011.nts"
    [Comment]="Test de toutes les portes NAND avec les entrées 0,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: 0\n  c: 0\n  d: 0\n  e: 0\n  f: 0\n  g: 0\n  h: 0\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

# Test 67 : NAND(0,1) → 1
test_table_67=(
    [Titre]="Test 67 : NAND(0,1) → 1"
    [Command]="echo -e 'a=0\nb=1\nc=0\nd=1\ne=0\nf=1\ng=0\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4011.nts"
    [Comment]="Test de toutes les portes NAND avec les entrées 0,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: 1\n  c: 0\n  d: 1\n  e: 0\n  f: 1\n  g: 0\n  h: 1\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

# Test 68 : NAND(0,U) → 1
test_table_68=(
    [Titre]="Test 68 : NAND(0,U) → 1"
    [Command]="echo -e 'a=0\nb=U\nc=0\nd=U\ne=0\nf=U\ng=0\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4011.nts"
    [Comment]="Test de toutes les portes NAND avec les entrées 0,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: U\n  c: 0\n  d: U\n  e: 0\n  f: U\n  g: 0\n  h: U\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

# Test 69 : NAND(1,0) → 1
test_table_69=(
    [Titre]="Test 69 : NAND(1,0) → 1"
    [Command]="echo -e 'a=1\nb=0\nc=1\nd=0\ne=1\nf=0\ng=1\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4011.nts"
    [Comment]="Test de toutes les portes NAND avec les entrées 1,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: 0\n  c: 1\n  d: 0\n  e: 1\n  f: 0\n  g: 1\n  h: 0\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

# Test 70 : NAND(1,1) → 0
test_table_70=(
    [Titre]="Test 70 : NAND(1,1) → 0"
    [Command]="echo -e 'a=1\nb=1\nc=1\nd=1\ne=1\nf=1\ng=1\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4011.nts"
    [Comment]="Test de toutes les portes NAND avec les entrées 1,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: 1\n  c: 1\n  d: 1\n  e: 1\n  f: 1\n  g: 1\n  h: 1\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n>"
    [NormalExitCode]="0"
)

# Test 71 : NAND(1,U) → U
test_table_71=(
    [Titre]="Test 71 : NAND(1,U) → U"
    [Command]="echo -e 'a=1\nb=U\nc=1\nd=U\ne=1\nf=U\ng=1\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4011.nts"
    [Comment]="Test de toutes les portes NAND avec les entrées 1,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: U\n  c: 1\n  d: U\n  e: 1\n  f: U\n  g: 1\n  h: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Test 72 : NAND(U,0) → 1
test_table_72=(
    [Titre]="Test 72 : NAND(U,0) → 1"
    [Command]="echo -e 'a=U\nb=0\nc=U\nd=0\ne=U\nf=0\ng=U\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4011.nts"
    [Comment]="Test de toutes les portes NAND avec les entrées U,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: 0\n  c: U\n  d: 0\n  e: U\n  f: 0\n  g: U\n  h: 0\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

# Test 73 : NAND(U,1) → U
test_table_73=(
    [Titre]="Test 73 : NAND(U,1) → U"
    [Command]="echo -e 'a=U\nb=1\nc=U\nd=1\ne=U\nf=1\ng=U\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4011.nts"
    [Comment]="Test de toutes les portes NAND avec les entrées U,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: 1\n  c: U\n  d: 1\n  e: U\n  f: 1\n  g: U\n  h: 1\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Test 74 : NAND(U,U) → U
test_table_74=(
    [Titre]="Test 74 : NAND(U,U) → U"
    [Command]="echo -e 'a=U\nb=U\nc=U\nd=U\ne=U\nf=U\ng=U\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4011.nts"
    [Comment]="Test de toutes les portes NAND avec les entrées U,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: U\n  c: U\n  d: U\n  e: U\n  f: U\n  g: U\n  h: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Déclarations des tests

declare -A test_table_75
declare -A test_table_76
declare -A test_table_77
declare -A test_table_78
declare -A test_table_79
declare -A test_table_80
declare -A test_table_81
declare -A test_table_82
declare -A test_table_83

# Test 75 : XOR(0,0) → 0
test_table_75=(
    [Titre]="Test 75 : XOR(0,0) → 0"
    [Command]="echo -e 'a=0\nb=0\nc=0\nd=0\ne=0\nf=0\ng=0\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4030.nts"
    [Comment]="Test de toutes les portes XOR avec les entrées 0,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: 0\n  c: 0\n  d: 0\n  e: 0\n  f: 0\n  g: 0\n  h: 0\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n>"
    [NormalExitCode]="0"
)

# Test 76 : XOR(0,1) → 1
test_table_76=(
    [Titre]="Test 76 : XOR(0,1) → 1"
    [Command]="echo -e 'a=0\nb=1\nc=0\nd=1\ne=0\nf=1\ng=0\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4030.nts"
    [Comment]="Test de toutes les portes XOR avec les entrées 0,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: 1\n  c: 0\n  d: 1\n  e: 0\n  f: 1\n  g: 0\n  h: 1\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

# Test 77 : XOR(0,U) → U
test_table_77=(
    [Titre]="Test 77 : XOR(0,U) → U"
    [Command]="echo -e 'a=0\nb=U\nc=0\nd=U\ne=0\nf=U\ng=0\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4030.nts"
    [Comment]="Test de toutes les portes XOR avec les entrées 0,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: U\n  c: 0\n  d: U\n  e: 0\n  f: U\n  g: 0\n  h: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Test 78 : XOR(1,0) → 1
test_table_78=(
    [Titre]="Test 78 : XOR(1,0) → 1"
    [Command]="echo -e 'a=1\nb=0\nc=1\nd=0\ne=1\nf=0\ng=1\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4030.nts"
    [Comment]="Test de toutes les portes XOR avec les entrées 1,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: 0\n  c: 1\n  d: 0\n  e: 1\n  f: 0\n  g: 1\n  h: 0\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

# Test 79 : XOR(1,1) → 0
test_table_79=(
    [Titre]="Test 79 : XOR(1,1) → 0"
    [Command]="echo -e 'a=1\nb=1\nc=1\nd=1\ne=1\nf=1\ng=1\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4030.nts"
    [Comment]="Test de toutes les portes XOR avec les entrées 1,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: 1\n  c: 1\n  d: 1\n  e: 1\n  f: 1\n  g: 1\n  h: 1\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n>"
    [NormalExitCode]="0"
)

# Test 80 : XOR(1,U) → U
test_table_80=(
    [Titre]="Test 80 : XOR(1,U) → U"
    [Command]="echo -e 'a=1\nb=U\nc=1\nd=U\ne=1\nf=U\ng=1\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4030.nts"
    [Comment]="Test de toutes les portes XOR avec les entrées 1,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: U\n  c: 1\n  d: U\n  e: 1\n  f: U\n  g: 1\n  h: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Test 81 : XOR(U,0) → U
test_table_81=(
    [Titre]="Test 81 : XOR(U,0) → U"
    [Command]="echo -e 'a=U\nb=0\nc=U\nd=0\ne=U\nf=0\ng=U\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4030.nts"
    [Comment]="Test de toutes les portes XOR avec les entrées U,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: 0\n  c: U\n  d: 0\n  e: U\n  f: 0\n  g: U\n  h: 0\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Test 82 : XOR(U,1) → U
test_table_82=(
    [Titre]="Test 82 : XOR(U,1) → U"
    [Command]="echo -e 'a=U\nb=1\nc=U\nd=1\ne=U\nf=1\ng=U\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4030.nts"
    [Comment]="Test de toutes les portes XOR avec les entrées U,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: 1\n  c: U\n  d: 1\n  e: U\n  f: 1\n  g: U\n  h: 1\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

declare -A test_table_83

# Test 83 : XOR(U,U) → U
test_table_83=(
    [Titre]="Test 83 : XOR(U,U) → U"
    [Command]="echo -e 'a=U\nb=U\nc=U\nd=U\ne=U\nf=U\ng=U\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4030.nts"
    [Comment]="Test de toutes les portes XOR avec les entrées U,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: U\n  c: U\n  d: U\n  e: U\n  f: U\n  g: U\n  h: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Déclarations des tests

declare -A test_table_84
declare -A test_table_85
declare -A test_table_86
declare -A test_table_87
declare -A test_table_88
declare -A test_table_89
declare -A test_table_90
declare -A test_table_91
declare -A test_table_92

# Test 84 : OR(0,0) → 0
test_table_84=(
    [Titre]="Test 84 : OR(0,0) → 0"
    [Command]="echo -e 'a=0\nb=0\nc=0\nd=0\ne=0\nf=0\ng=0\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4071.nts"
    [Comment]="Test de toutes les portes OR avec les entrées 0,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: 0\n  c: 0\n  d: 0\n  e: 0\n  f: 0\n  g: 0\n  h: 0\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n>"
    [NormalExitCode]="0"
)

# Test 85 : OR(0,1) → 1
test_table_85=(
    [Titre]="Test 85 : OR(0,1) → 1"
    [Command]="echo -e 'a=0\nb=1\nc=0\nd=1\ne=0\nf=1\ng=0\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4071.nts"
    [Comment]="Test de toutes les portes OR avec les entrées 0,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: 1\n  c: 0\n  d: 1\n  e: 0\n  f: 1\n  g: 0\n  h: 1\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

# Test 86 : OR(0,U) → U
test_table_86=(
    [Titre]="Test 86 : OR(0,U) → U"
    [Command]="echo -e 'a=0\nb=U\nc=0\nd=U\ne=0\nf=U\ng=0\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4071.nts"
    [Comment]="Test de toutes les portes OR avec les entrées 0,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: U\n  c: 0\n  d: U\n  e: 0\n  f: U\n  g: 0\n  h: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Test 87 : OR(1,0) → 1
test_table_87=(
    [Titre]="Test 87 : OR(1,0) → 1"
    [Command]="echo -e 'a=1\nb=0\nc=1\nd=0\ne=1\nf=0\ng=1\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4071.nts"
    [Comment]="Test de toutes les portes OR avec les entrées 1,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: 0\n  c: 1\n  d: 0\n  e: 1\n  f: 0\n  g: 1\n  h: 0\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

# Test 88 : OR(1,1) → 1
test_table_88=(
    [Titre]="Test 88 : OR(1,1) → 1"
    [Command]="echo -e 'a=1\nb=1\nc=1\nd=1\ne=1\nf=1\ng=1\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4071.nts"
    [Comment]="Test de toutes les portes OR avec les entrées 1,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: 1\n  c: 1\n  d: 1\n  e: 1\n  f: 1\n  g: 1\n  h: 1\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

# Test 89 : OR(1,U) → 1
test_table_89=(
    [Titre]="Test 89 : OR(1,U) → 1"
    [Command]="echo -e 'a=1\nb=U\nc=1\nd=U\ne=1\nf=U\ng=1\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4071.nts"
    [Comment]="Test de toutes les portes OR avec les entrées 1,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: U\n  c: 1\n  d: U\n  e: 1\n  f: U\n  g: 1\n  h: U\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

# Test 90 : OR(U,0) → U
test_table_90=(
    [Titre]="Test 90 : OR(U,0) → U"
    [Command]="echo -e 'a=U\nb=0\nc=U\nd=0\ne=U\nf=0\ng=U\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4071.nts"
    [Comment]="Test de toutes les portes OR avec les entrées U,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: 0\n  c: U\n  d: 0\n  e: U\n  f: 0\n  g: U\n  h: 0\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Test 91 : OR(U,1) → 1
test_table_91=(
    [Titre]="Test 91 : OR(U,1) → 1"
    [Command]="echo -e 'a=U\nb=1\nc=U\nd=1\ne=U\nf=1\ng=U\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4071.nts"
    [Comment]="Test de toutes les portes OR avec les entrées U,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: 1\n  c: U\n  d: 1\n  e: U\n  f: 1\n  g: U\n  h: 1\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

declare -A test_table_92

# Test 92 : OR(U,U) → U
test_table_92=(
    [Titre]="Test 92 : OR(U,U) → U"
    [Command]="echo -e 'a=U\nb=U\nc=U\nd=U\ne=U\nf=U\ng=U\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4071.nts"
    [Comment]="Test de toutes les portes OR avec les entrées U,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: U\n  c: U\n  d: U\n  e: U\n  f: U\n  g: U\n  h: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Déclarations des tests

declare -A test_table_93
declare -A test_table_94
declare -A test_table_95
declare -A test_table_96
declare -A test_table_97
declare -A test_table_98
declare -A test_table_99
declare -A test_table_100
declare -A test_table_101

# Test 93 : AND(0,0) → 0
test_table_93=(
    [Titre]="Test 93 : AND(0,0) → 0"
    [Command]="echo -e 'a=0\nb=0\nc=0\nd=0\ne=0\nf=0\ng=0\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4081.nts"
    [Comment]="Test de toutes les portes AND avec les entrées 0,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: 0\n  c: 0\n  d: 0\n  e: 0\n  f: 0\n  g: 0\n  h: 0\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n>"
    [NormalExitCode]="0"
)

# Test 94 : AND(0,1) → 0
test_table_94=(
    [Titre]="Test 94 : AND(0,1) → 0"
    [Command]="echo -e 'a=0\nb=1\nc=0\nd=1\ne=0\nf=1\ng=0\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4081.nts"
    [Comment]="Test de toutes les portes AND avec les entrées 0,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: 1\n  c: 0\n  d: 1\n  e: 0\n  f: 1\n  g: 0\n  h: 1\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n>"
    [NormalExitCode]="0"
)

# Test 95 : AND(0,U) → 0
test_table_95=(
    [Titre]="Test 95 : AND(0,U) → 0"
    [Command]="echo -e 'a=0\nb=U\nc=0\nd=U\ne=0\nf=U\ng=0\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4081.nts"
    [Comment]="Test de toutes les portes AND avec les entrées 0,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: U\n  c: 0\n  d: U\n  e: 0\n  f: U\n  g: 0\n  h: U\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n>"
    [NormalExitCode]="0"
)

# Test 96 : AND(1,0) → 0
test_table_96=(
    [Titre]="Test 96 : AND(1,0) → 0"
    [Command]="echo -e 'a=1\nb=0\nc=1\nd=0\ne=1\nf=0\ng=1\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4081.nts"
    [Comment]="Test de toutes les portes AND avec les entrées 1,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: 0\n  c: 1\n  d: 0\n  e: 1\n  f: 0\n  g: 1\n  h: 0\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n>"
    [NormalExitCode]="0"
)

# Test 97 : AND(1,1) → 1
test_table_97=(
    [Titre]="Test 97 : AND(1,1) → 1"
    [Command]="echo -e 'a=1\nb=1\nc=1\nd=1\ne=1\nf=1\ng=1\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4081.nts"
    [Comment]="Test de toutes les portes AND avec les entrées 1,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: 1\n  c: 1\n  d: 1\n  e: 1\n  f: 1\n  g: 1\n  h: 1\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n>"
    [NormalExitCode]="0"
)

# Test 98 : AND(1,U) → U
test_table_98=(
    [Titre]="Test 98 : AND(1,U) → U"
    [Command]="echo -e 'a=1\nb=U\nc=1\nd=U\ne=1\nf=U\ng=1\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4081.nts"
    [Comment]="Test de toutes les portes AND avec les entrées 1,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: U\n  c: 1\n  d: U\n  e: 1\n  f: U\n  g: 1\n  h: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Test 99 : AND(U,0) → 0
test_table_99=(
    [Titre]="Test 99 : AND(U,0) → 0"
    [Command]="echo -e 'a=U\nb=0\nc=U\nd=0\ne=U\nf=0\ng=U\nh=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4081.nts"
    [Comment]="Test de toutes les portes AND avec les entrées U,0."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: 0\n  c: U\n  d: 0\n  e: U\n  f: 0\n  g: U\n  h: 0\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n>"
    [NormalExitCode]="0"
)

test_table_100=(
    [Titre]="Test 100 : AND(U,1) → U"
    [Command]="echo -e 'a=U\nb=1\nc=U\nd=1\ne=U\nf=1\ng=U\nh=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4081.nts"
    [Comment]="Test de toutes les portes AND avec les entrées U,1."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: 1\n  c: U\n  d: 1\n  e: U\n  f: 1\n  g: U\n  h: 1\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

test_table_101=(
    [Titre]="Test 101 : AND(U,U) → U"
    [Command]="echo -e 'a=U\nb=U\nc=U\nd=U\ne=U\nf=U\ng=U\nh=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4081.nts"
    [Comment]="Test de toutes les portes AND avec les entrées U,U."
    [NormalOutput]="> > > > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: U\n  c: U\n  d: U\n  e: U\n  f: U\n  g: U\n  h: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n>"
    [NormalExitCode]="0"
)

# Déclarations des tests

declare -A test_table_102
declare -A test_table_103
declare -A test_table_104
declare -A test_table_105
declare -A test_table_106
declare -A test_table_107
declare -A test_table_108
declare -A test_table_109
declare -A test_table_110
declare -A test_table_111
declare -A test_table_112
declare -A test_table_113


# Test 102 : NOT(0) → 1
test_table_102=(
    [Titre]="Test 102 : NOT(0) → 1"
    [Command]="echo -e 'a=0\nb=0\nc=0\nd=0\ne=0\nf=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4069.nts"
    [Comment]="Test de toutes les portes NOT avec les entrées 0."
    [NormalOutput]="> > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: 0\n  c: 0\n  d: 0\n  e: 0\n  f: 0\noutput(s):\n  out1: 1\n  out2: 1\n  out3: 1\n  out4: 1\n  out5: 1\n  out6: 1\n>"
    [NormalExitCode]="0"
)

# Test 103 : NOT(1) → 0
test_table_103=(
    [Titre]="Test 103 : NOT(1) → 0"
    [Command]="echo -e 'a=1\nb=1\nc=1\nd=1\ne=1\nf=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4069.nts"
    [Comment]="Test de toutes les portes NOT avec les entrées 1."
    [NormalOutput]="> > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: 1\n  c: 1\n  d: 1\n  e: 1\n  f: 1\noutput(s):\n  out1: 0\n  out2: 0\n  out3: 0\n  out4: 0\n  out5: 0\n  out6: 0\n>"
    [NormalExitCode]="0"
)

# Test 104 : NOT(U) → U
test_table_104=(
    [Titre]="Test 104 : NOT(U) → U"
    [Command]="echo -e 'a=U\nb=U\nc=U\nd=U\ne=U\nf=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4069.nts"
    [Comment]="Test de toutes les portes NOT avec les entrées U."
    [NormalOutput]="> > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: U\n  c: U\n  d: U\n  e: U\n  f: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n  out5: U\n  out6: U\n>"
    [NormalExitCode]="0"
)

# Test 105 : Alternance (0,1,0,1,0,1) → (1,0,1,0,1,0)
test_table_105=(
    [Titre]="Test 105 : Alternance (0,1,0,1,0,1) → (1,0,1,0,1,0)"
    [Command]="echo -e 'a=0\nb=1\nc=0\nd=1\ne=0\nf=1\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4069.nts"
    [Comment]="Test de toutes les portes NOT avec une alternance d'entrées 0 et 1."
    [NormalOutput]="> > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: 1\n  c: 0\n  d: 1\n  e: 0\n  f: 1\noutput(s):\n  out1: 1\n  out2: 0\n  out3: 1\n  out4: 0\n  out5: 1\n  out6: 0\n>"
    [NormalExitCode]="0"
)

# Test 106 : Alternance (1,0,1,0,1,0) → (0,1,0,1,0,1)
test_table_106=(
    [Titre]="Test 106 : Alternance (1,0,1,0,1,0) → (0,1,0,1,0,1)"
    [Command]="echo -e 'a=1\nb=0\nc=1\nd=0\ne=1\nf=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4069.nts"
    [Comment]="Test de toutes les portes NOT avec une alternance d'entrées 1 et 0."
    [NormalOutput]="> > > > > > > > tick: 1\ninput(s):\n  a: 1\n  b: 0\n  c: 1\n  d: 0\n  e: 1\n  f: 0\noutput(s):\n  out1: 0\n  out2: 1\n  out3: 0\n  out4: 1\n  out5: 0\n  out6: 1\n>"
    [NormalExitCode]="0"
)

# Test 107 : Mélange de 0, 1 et U
test_table_107=(
    [Titre]="Test 107 : Mélange de 0, 1 et U"
    [Command]="echo -e 'a=0\nb=1\nc=U\nd=0\ne=1\nf=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4069.nts"
    [Comment]="Test de toutes les portes NOT avec un mélange de valeurs."
    [NormalOutput]="> > > > > > > > tick: 1\ninput(s):\n  a: 0\n  b: 1\n  c: U\n  d: 0\n  e: 1\n  f: U\noutput(s):\n  out1: 1\n  out2: 0\n  out3: U\n  out4: 1\n  out5: 0\n  out6: U\n>"
    [NormalExitCode]="0"
)

test_table_108=(
    [Titre]="Test 108 : Mélange de valeurs avec plus d'U"
    [Command]="echo -e 'a=U\nb=U\nc=0\nd=1\ne=U\nf=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4069.nts"
    [Comment]="Test de toutes les portes NOT avec un mélange où U est plus fréquent."
    [NormalOutput]="> > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: U\n  c: 0\n  d: 1\n  e: U\n  f: U\noutput(s):\n  out1: U\n  out2: U\n  out3: 1\n  out4: 0\n  out5: U\n  out6: U\n>"
    [NormalExitCode]="0"
)

test_table_109=(
    [Titre]="Test 109 : Tous les NOT gates en Undefined"
    [Command]="echo -e 'a=U\nb=U\nc=U\nd=U\ne=U\nf=U\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/test_4069.nts"
    [Comment]="Test de toutes les portes NOT avec uniquement des entrées U."
    [NormalOutput]="> > > > > > > > tick: 1\ninput(s):\n  a: U\n  b: U\n  c: U\n  d: U\n  e: U\n  f: U\noutput(s):\n  out1: U\n  out2: U\n  out3: U\n  out4: U\n  out5: U\n  out6: U\n>"
    [NormalExitCode]="0"
)

test_table_110=(
    [Titre]="Test 110 : Parse space empty line"
    [Command]="echo -e 'exit' | ./nanotekspice tests/test_file/TEST_SPACE.nts"
    [Comment]="Test de toutes les portes NOT avec uniquement des entrées U."
    [NormalOutput]="> \n"
    [NormalExitCode]="0"
)

test_table_111=(
    [Titre]="Test 111 : Parse space empty line II"
    [Command]="echo -e 'exit' | ./nanotekspice tests/test_file/test_space2.nts"
    [Comment]="Test de toutes les portes NOT avec uniquement des entrées U."
    [NormalOutput]="> \n"
    [NormalExitCode]="0"
)

test_table_112=(
    [Titre]="Clock test"
    [Command]="echo -e 'display\ncl=1\nsimulate\ndisplay\nsimulate\ndisplay\ncl=0\nsimulate\ndisplay\nexit' | ./nanotekspice tests/test_file/clock.nts"
    [Comment]="Test de toutes les portes NOT avec uniquement des entrées U."
    [NormalOutput]="> tick: 0
input(s):
  cl: U
output(s):
  out: U
> > > tick: 1
input(s):
  cl: 1
output(s):
  out: 1
> > tick: 2
input(s):
  cl: 0
output(s):
  out: 0
> > > tick: 3
input(s):
  cl: 0
output(s):
  out: 0
>"
    [NormalExitCode]="0"
)

test_table_113=(
    [Titre]="Loger test"
    [Command]="echo -e 'clock=0
inhibit=0
in_128=0
in_064=1
in_032=0
in_016=0
in_008=0
in_004=1
in_002=0
in_001=1
simulate
simulate
in_128=0
in_064=1
in_032=1
in_016=1
in_008=0
in_004=0
in_002=0
in_001=0
simulate
simulate
in_128=0
in_064=0
in_032=1
in_016=1
in_008=0
in_004=0
in_002=0
in_001=1
simulate
simulate
in_128=0
in_064=1
in_032=1
in_016=1
in_008=0
in_004=1
in_002=0
in_001=0
simulate
simulate
in_128=0
in_064=0
in_032=1
in_016=1
in_008=0
in_004=0
in_002=1
in_001=1
simulate
simulate
in_128=0
in_064=1
in_032=1
in_016=0
in_008=0
in_004=0
in_002=1
in_001=1
simulate
simulate
in_128=0
in_064=1
in_032=1
in_016=0
in_008=1
in_004=0
in_002=0
in_001=0
simulate
simulate
in_128=0
in_064=0
in_032=1
in_016=0
in_008=0
in_004=0
in_002=0
in_001=1
simulate
simulate
inhibit=1
simulate
simulate
inhibit=0
in_008=U
simulate
simulate
in_008=0
clock=U
simulate
simulate' | ./nanotekspice tests/test_file/loggeer.nts ; cat log.bin"
    [Comment]="Test de toutes les portes NOT avec uniquement des entrées U."
    [NormalOutput]="> > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > Ep1t3ch!"
    [NormalExitCode]="0"
)

################################################################################
###################################CONFIGURATION FILE###########################
################################################################################

EXECUTABLE="nanotekspice"
COMPARAISON_EXECUTABLE=""
#Laissez -1 pour ne pas lancer de temps de timeout
DefaultTimeOutOnSec=(60)

FLAG1=$1
FLAG2=$2

clear
echo -e "Bienvenu(e) dans mon super programme de test !"
echo -e ""
echo -e "Pour utiliser correctement ce petit executable fort sympathique, merci de pré-remplir le nom de l'executable à vérifier, les tests à effectuer et optionnelement un autre executable avec lequel vous voulez le comparer."
echo -e ""
echo -e "FLAGS"
echo -e "-c: Permet de lancer la comparaison avec un autre executable"
echo -e "-g: Modifie les sorties pour être conforme à GitHub action."
echo -e "-t: Modifie les sorties pour un terminal."
echo -e ""
echo -e "Merci d'utiliser cette executable dévelopé par CorpsB dans le cadre de sa scolarité à Epitech (Strasbourg)"
echo -e ""
echo -e ""

rm log.bin

################################################################################
###################################LANCEMENT DES TESTS##########################
################################################################################


# Fonction pour le mode "-g -c" (GitHub Actions + Comparaison)
RunGitHubComparisonTest() {
    echo "==> Exécution des tests avec comparaison + GitHub Actions"
    for key in $(seq 0 113); do
        test_name="test_table_$key"
        declare -n current_test="$test_name" 2>/dev/null || continue

        if [[ -n "${current_test[Command]}" ]]; then
            LunchGitHubComparisonTest "$test_name"
        fi
    done
}

# Fonction pour le mode "-g" (GitHub Actions seul)
RunGitHubTest() {
    echo "==> Exécution des tests avec format GitHub Actions"
    for key in $(seq 0 113); do
        test_name="test_table_$key"
        declare -n current_test="$test_name" 2>/dev/null || continue

        if [[ -n "${current_test[Command]}" ]];  then
            LunchGitHubTest "$test_name"
        fi
    done
    echo "::notice title=SUCCES:: $SUCCES tests are succesfuly runing on the $TOTAL tests."
    if [[ $ERROR -gt 0 ]]; then
        echo "::error title=ERROR:: $ERROR test failed on the $TOTAL tests."
    fi
    RESULT=$(( (SUCCES * 100) / TOTAL ))
    echo "::notice title=RESULT:: You passed $RESULT% tests."
}

# Fonction pour le mode "-c" (Comparaison seule)
RunComparisonTest() {
    echo "==> Exécution des tests en mode comparaison"
    for key in $(seq 1 20); do
        test_name="test_table_$key"
        declare -n current_test="$test_name" 2>/dev/null || continue

        if [[ -n "${current_test[Command]}" ]]; then
            LunchComparisonTest "$test_name"
        fi
    done
}

# Fonction pour le mode "normal" (sans GitHub, sans comparaison)
RunNormalTest() {
    echo -e "${BLUE}==> Exécution des tests en mode normal${RESET}"
    for key in $(seq 0 113); do
        test_name="test_table_$key"
        declare -n current_test="$test_name" 2>/dev/null || continue

        if [[ -n "${current_test[Command]}" ]]; then
            LunchNormalTest "$test_name"
        fi
    done
}

# Fonction pour tester un exécutable en mode GitHub Actions
LunchGitHubTest() {
    local key=$1
    declare -n current_test="$key"

    local command="${current_test[Command]}"
    local expected_output="${current_test[NormalOutput]}"
    local title="${current_test[Titre]}"

    if [[ -z "$command" || "$command" == "-1" ]]; then
        echo "::warning title=ERROR::$title - La commande est vide ou invalide"
        return
    fi

    local output
    output=$(eval -- "$command" 2>&1)

    # Nettoyage des espaces et des caractères invisibles
    output=$(echo -e "$output" | sed 's/[[:space:]]*$//')
    expected_output=$(echo -e "$expected_output" | sed 's/[[:space:]]*$//')

    ((TOTAL++))
    if [[ "$output" == "$expected_output" ]]; then
        ((SUCCES++))
    else
        ((ERROR++))
    fi
}

# Fonction pour comparer l'exécutable avec un autre
LunchComparisonTest() {
    local key=$1
    declare -n current_test="$key"

    local command="${current_test[Command]}"
    local title="${current_test[Titre]}"

    if [[ -z "$command" || "$command" == "-1" ]]; then
        echo -e "${RED}⚠ ERREUR : La commande est vide ou invalide pour \"$title\"${RESET}"
        return
    fi

    local output1 output2
    output1=$(eval -- "$command" | "$EXECUTABLE" 2>&1)
    output2=$(eval -- "$command" | "$COMPARAISON_EXECUTABLE" 2>&1)

    # Nettoyage des espaces et des caractères invisibles
    output1=$(echo -e "$output1" | sed 's/[[:space:]]*$//')
    output2=$(echo -e "$output2" | sed 's/[[:space:]]*$//')

    if [[ "$output1" == "$output2" ]]; then
        echo -e "${GREEN}✔ SUCCÈS${RESET} : $title"
    else
        echo -e "${RED}✘ ERREUR${RESET} : $title"
        echo -e "${BLUE}Sortie exécutée :${RESET}\n$output1"
        echo -e "${RED}Sortie attendue :${RESET}\n$output2"
    fi
}

# Fonction pour tester un exécutable en mode normal avec le titre du test
LunchNormalTest() {
    local key=$1
    declare -n current_test="$key"

    local command="${current_test[Command]}"
    local expected_output="${current_test[NormalOutput]}"
    local title="${current_test[Titre]}"

    # Vérifier si la commande est vide
    if [[ -z "$command" || "$command" == "-1" ]]; then
        echo -e "${RED}⚠ ERREUR : La commande est vide ou invalide pour \"$title\"${RESET}"
        return
    fi

    local output
    output=$(eval -- "$command" 2>&1)

    # Supprime les espaces et retours à la ligne inutiles
    output=$(echo -e "$output" | sed 's/[[:space:]]*$//')
    expected_output=$(echo -e "$expected_output" | sed 's/[[:space:]]*$//')

    if [[ "$output" == "$expected_output" ]]; then
        echo -e "${GREEN}✔ SUCCÈS${RESET} : $title"
    else
        echo -e "${RED}✘ ERREUR${RESET} : $title"
        echo -e "${BLUE}Attendu :${RESET}\n$(echo -e "$expected_output")"
        echo -e "${RED}Obtenu  :${RESET}\n$output"

        # Comparaison avec diff pour voir les différences
        echo -e "${BLUE}Différences détectées (attendu vs obtenu) :${RESET}"
        diff <(echo -e "$expected_output") <(echo -e "$output") || echo -e "${RED}Aucune différence visible... peut-être un espace ou un retour à la ligne en trop.${RESET}"

        # Affichage détaillé avec cat -A pour voir les caractères invisibles
        echo -e "${BLUE}Caractères invisibles dans l'attendu :${RESET}"
        echo -e "$expected_output" | cat -A
        echo -e "${RED}Caractères invisibles dans l'obtenu :${RESET}"
        echo -e "$output" | cat -A
    fi
}


################################################################################
###################################FLAG DETECTOR################################
################################################################################


if [[ ($FLAG1 == "-g" && $FLAG2 == "-c") || ($FLAG1 == "-c" && $FLAG2 == "-g") ]]; then
    RunGitHubComparisonTest
elif [[ $FLAG1 == "-g" && -z "$FLAG2" ]]; then
    RunGitHubTest
elif [[ $FLAG1 == "-c" && -z "$FLAG2" ]]; then
    RunComparisonTest
elif [[ -z "$FLAG1" && -z "$FLAG2" ]]; then
    RunNormalTest  # Exécution correcte une seule fois
else
    echo "WARNING: FLAG(S) ERROR"
    echo -e ""
    echo -e "ACCEPTED FLAGS"
    echo -e "-c: Permet de lancer la comparaison avec un autre exécutable"
    echo -e "-g: Modifie les sorties pour être conforme à GitHub Actions."
    echo -e ""
    exit 84
fi


################################################################################
###################################INITIALISATION TESTS#########################
################################################################################

if [[ $EXECUTABLE == "" ]]; then
    echo "ERROR: Executable name is missing, please complete and retry."
    exit 84
fi

if [[ -z "$COMPARAISON_EXECUTABLE" && ($FLAG1 == "-c" || $FLAG2 == "-c") ]]; then
    echo "ERROR: Comparaison executable is missing, please complete and retry."
    exit 84
fi

rm log.bin
