#! /usr/bin/env bash

export BINARY="$(readlink -f "./Debug/FirstVu")"
TESTDIR="$(readlink -f ./tests)"
export GLOBAL_UAO="$TESTDIR""/global/glob_account.inp"
export GLOBAL_ATO="$TESTDIR""/global/glob_available_tickets.inp"

# Colours
export RED='\e[1;31m'
export GREEN='\e[1;32m'
export WHITE='\e[1;37m'
export RESET='\e[m'

function clean() {
    find "$TESTDIR" -type f | grep ".dtf" | xargs rm 2> /dev/null
    find "$TESTDIR" -type f | grep "\.out\." | xargs rm 2> /dev/null
}

function testCase() {
    cd "$1"
    case="$(basename "$1")"

    # Input
    #GLOBAL_UAO
    #GLOBAL_ATO
    inp="$case"".inp"

    # Output
    dtf="$(mktemp "$case"".dtf.XXX")"
    out="$(mktemp "$case"".out.XXX")"

    # Expected
    etf="$case"".etf"
    bto="$case"".bto"

    "$BINARY" "$GLOBAL_UAO" "$GLOBAL_ATO" "$dtf" < "$inp" &> "$out"

    dtfTest="$(sdiff -st "$dtf" "$etf")"
    outTest="$(sdiff -st "$out" "$bto")"

    if [ -n "$difTest" -o -n "$outTest" ]; then
        echo -ne "$RED"
    else
        echo -ne "$GREEN"
    fi

    echo "$case"
    echo -ne "$WHITE"

    if [ -n "$difTest" ]; then
        echo "TEST: DTF"
        echo "$difTest"
    fi

    if [ -n "$difTest" -a -n "$outTest" ]; then
        echo ""
    fi

    if [ -n "$outTest" ]; then
        echo "TEST: Output"
        echo "$outTest"
    fi

    echo ""

    rm "$dtf"
    rm "$out"
}

export -f clean
export -f testCase

clean

echo -ne "$WHITE"

if test $# -lt 1; then
    find "$TESTDIR" -mindepth 2 -type d | sed 's/\([a-z]\)\([0-9]\)$/\10\2/' | sort | sed 's/0\([0-9]\)$/\1/' | xargs -I {} bash -c 'testCase "$@"' "testCase" {}
elif test $# -eq 1; then
    testCase "$1"
fi

echo -ne "$RESET"
