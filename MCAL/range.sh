#! /bin/bash

ls=`ls`

for i in ${ls}
do 
    if [ ${i} != "range.sh" ]
    then
        sed -e 's/..\..\LIB\/./g' ${i}/${i}_program.c
    fi
done


#sed 's/foo/bar/g' hello.txt