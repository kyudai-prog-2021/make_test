#!/bin/sh
gcc main.c -o test4

function func(){
input=$(<data4/input.txt)
./test4 << EOF
$input
EOF
}


echo $(func)> ./data4/result.txt
check=`diff ./data4/output.txt ./data4/result.txt`

if test $check -z
then
    echo "test4 success"
    exit 0
else
    echo 'test4 failed'
    exit 1
fi
