#!/bin/sh
gcc main.c -o test5

function func(){
input=$(<data5/input.txt)
./test5 << EOF
$input
EOF
}


echo $(func)> ./data5/result.txt
check=`diff ./data5/output.txt ./data5/result.txt`

if test $check -z
then
    echo "test5 success"
    exit 0
else
    echo 'test5 failed'
    exit 1
fi
