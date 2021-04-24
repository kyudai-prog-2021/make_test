#!/bin/sh
gcc main.c -o test1

function func(){
input=$(<data1/input.txt)
./test1 << EOF
$input
EOF
}

echo $(func)> ./data1/result.txt
check=`diff ./data1/output.txt ./data1/result.txt`

if test $check -z
then
    echo "test1 success"
    exit 0
else
    echo 'test1 failed'
    exit 1
fi

    