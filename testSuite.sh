#! /usr/bin/env bash

export BINARY="$(readlink -f "./Debug/FirstVu")"
TESTDIR="./tests"
export GLOBAL_UAO="$TESTDIR""/glob_account.inp"
export GLOBAL_ATO="$TESTDIR""/glob_available_tickets.inp"

function clean() {
    find "$TESTDIR" -type f | grep ".dtf." | xargs rm 2> /dev/null
    find "$TESTDIR" -type f | grep "\.out\." | xargs rm 2> /dev/null
}

function testCase() {
    cd "$1"
    case="$(basename $PWD)"

    #Input
    #GLOBAL_UAO
    #GLOBAL_ATO
    inp="$case"".inp"

    #Output
    dtf="$(mktemp "$case"".dtf.XXX")"
    out="$(mktemp "$case"".out.XXX")"
    etf="$case"".etf"

    #Expected
    uao="$case"".uao"
    ato="$case"".ato"

    echo "$case"
    "$BINARY" "$GLOBAL_UAO" "$GLOBAL_ATO" "$dtf" < "$inp" > "$out"

    rm "$dtf"
    rm "$out"
}

export -f clean
export -f testCase

clean
find "$TESTDIR" -mindepth 2 -type d | sort | xargs -I {} bash -c 'testCase "$@"' "testCase" {}
