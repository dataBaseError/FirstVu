#! /usr/bin/env bash

export BINARY="$(readlink -f "./Debug/FirstVu")"
TESTDIR="$(readlink -f ./tests)"
export GLOBAL_UAO="$TESTDIR""/global/glob_account.inp"
export GLOBAL_ATO="$TESTDIR""/global/glob_available_tickets.inp"

function clean() {
    find "$TESTDIR" -type f | grep ".dtf" | xargs rm 2> /dev/null
    find "$TESTDIR" -type f | grep "\.out\." | xargs rm 2> /dev/null
}

function testCase() {
    cd "$1"
    case="$(basename "$1")"

    #Input
    #GLOBAL_UAO
    #GLOBAL_ATO
    inp="$case"".inp"

    #Output
    dtf="$(mktemp "$case"".dtf.XXX")"
    out="$(mktemp "$case"".out.XXX")"

    #Expected
    etf="$case"".etf"
    bto="$case"".bto"

    echo "$case"
    "$BINARY" "$GLOBAL_UAO" "$GLOBAL_ATO" "$dtf" < "$inp" > "$out"

    echo "TEST: DTF"
    diff "$dtf" "$etf"
    echo ""
    echo "TEST: Output"
    diff "$out" "$bto"
    echo ""

    rm "$dtf"
    rm "$out"
}

export -f clean
export -f testCase

clean

if test $# -lt 1; then
    find "$TESTDIR" -mindepth 2 -type d | sort | xargs -I {} bash -c 'testCase "$@"' "testCase" {}
elif test $# -eq 1; then
    testCase "$1"
fi
