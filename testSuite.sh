#! /usr/bin/env bash

export BINARY="$(readlink -f "./Debug/FirstVu")"
TESTDIR="./tests"

function clean() {
    find "$TESTDIR" -type f | grep ".dtf." | xargs rm 2> /dev/null
    find "$TESTDIR" -type f | grep "\.out\." | xargs rm 2> /dev/null
}

function testCase() {
    cd "$1"
    case="$(basename $PWD)"

    uao="$case"".uao"
    ato="$case"".ato"
    inp="$case"".inp"
    dtf="$(mktemp "$case"".dtf.XXX")"
    out="$(mktemp "$case"".out.XXX")"

    echo "$case"
    "$BINARY" "$uao" "$ato" "$dtf" < "$inp" > "$out"

    rm "$dtf"
    rm "$out"
}

export -f clean
export -f testCase

clean
find "$TESTDIR" -mindepth 2 -type d | sort | xargs -I {} bash -c 'testCase "$@"' "testCase" {}
