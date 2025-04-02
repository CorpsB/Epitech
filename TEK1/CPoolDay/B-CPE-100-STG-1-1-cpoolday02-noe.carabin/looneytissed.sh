#!/bin/bash
#sed  "s/theo1/Wile E. Coyote/" | grep "Wile E. Coyote" | sed "s/steven1/Daffy Duck/" | grep "Daffy Duck" | sed "s/arnaud1/Porky Pig/" | grep "Porky Pig" | sed "s/pierre-jean/Marvin the Martian/"
    #| grep "Marvin the Martian"
sed -e "s/theo1/Wile E. Coyote/" -e "s/steven1/Daffy Duck/" -e     "s/arnaud1/Porky Pig/" -e "s/pierre-jean/Marvin the Martian/" | grep -E "Wile E. Coyote|Daffy Duck|Porky Pig|Marvin the Martian"
