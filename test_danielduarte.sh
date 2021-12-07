#!/bin/bash

l=$(echo "ps" | ./hsh);
sh=$(echo "ps" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check 0 ✔️
else
    echo Check 0 ❌
fi

l=$(echo "which ls" | ./hsh);
sh=$(echo "which ls" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check 1 ✔️
else
    echo Check 1 ❌
fi

l=$(echo "du" | ./hsh);
sh=$(echo "du" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check 2 ✔️
else
    echo Check 2 ❌
fi

l=$(echo "pwd" | ./hsh);
sh=$(echo "pwd" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check 3 ✔️
else
    echo Check 3 ❌
fi

l=$(echo "env" | ./hsh);
sh=$(echo "env" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check 4 ✔️
else
    echo Check 4 ❌
fi

l=$(echo "/usr/bin/ls" | ./hsh);
sh=$(echo "/usr/bin/ls" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check 5 ✔️
else
    echo Check 5 ❌
fi

l=$(echo "/usr/bin/ls" | ./hsh);
sh=$(echo "/usr/bin/ls" | sh);
if [ "${l}" == "${sh}" ]
then
    echo Check 6 ✔️
else
    echo Check 6 ❌
fi

