#!/bin/sh
echo "Building Cress..."
bash build.sh
search_dir="../data/"
red=" tput setaf 1 "
green=" tput setaf 2 "
reset=" tput sgr0 "
for entry in "$search_dir"/*
do
    printf "\n"
    echo "--------------------------------------------------------------"
    printf "\n"
    echo "$(tput setaf 3)Current File: $entry$(tput sgr 0)"
    entropy=$(./../bin/cress -e "$entry")
    echo "$entropy"
    echo "$(tput setaf 3)Compressing$(tput sgr 0)"
    time ./../bin/cress -c $entry
    echo "$(tput setaf 3)Decompressing$(tput sgr 0)"
    time ./../bin/cress -d "$entry.c"
    sizeOrig=$(stat -c%s $entry)
    sizeComp=$(stat -c%s "$entry.c")
    sizeDecomp=$(stat -c%s "$entry.d")
    printf "\n"

    echo "Test [diff]"
    diffResult=&(diff $entry "$entry.d")
    if [ -z "$diffResult" ]
    then
        echo "$(tput setaf 2)Comparison with diff succesfull$(tput sgr 0)"
    else
        echo "$(tput setaf 1)$diffResult$(tput sgr 0)"
    fi
    echo "Test [filesize]"
    if [[ $sizeOrig != $sizeDecomp ]]
    then
        echo "$(tput setaf 1)Filesize does not match the original$(tput sgr 0)"
    else
        echo "$sizeOrig == $sizeDecomp"
        echo "$(tput setaf 2)File decompressed succesfully!$(tput sgr 0)"
    fi
    printf "\n"
    echo "$(tput setaf 3)Original Size: $sizeOrig$(tput sgr 0)"
    echo "$(tput setaf 3)Size after Compression $sizeComp$(tput sgr 0)"
    echo Size reduction by $((100 -  100 * $sizeComp/$sizeOrig ))%
done

printf "\n"
echo "Clearing up"
rm ../bin/*
rm ../data/*.c
rm ../data/*.d
echo "Done"

#Sources
#https://www.shell-tips.com/bash/performing-math-calculation-in-bash/
#https://stackoverflow.com/questions/5920333/how-to-check-size-of-a-file-using-bash
#https://stackoverflow.com/questions/2437452/how-to-get-the-list-of-files-in-a-directory-in-a-shell-script
#http://www.fibel.org/linux/lfo-0.6.0/node420.html
#https://www.cyberciti.biz/faq/unix-linux-bash-script-check-if-variable-is-empty/