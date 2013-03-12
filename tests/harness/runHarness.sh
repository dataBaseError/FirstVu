#! /usr/bin/env bash

export BINARY="$(readlink -f "../../Debug/FirstVu")"
export TESTDIR="$(readlink -f "..")"
export GLOBAL_UAO="$TESTDIR""/global/glob_account.inp"
export GLOBAL_ATO="$TESTDIR""/global/glob_available_tickets.inp"

# Log File
export LOGFILE='all.log'

# Colours
export RED='\e[1;31m'
export GREEN='\e[1;32m'
export WHITE='\e[1;37m'
export RESET='\e[m'

export PATH='/usr/bin/':$PATH

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

    time=$(time -p ("$BINARY" "$GLOBAL_UAO" "$GLOBAL_ATO" "$dtf" < "$inp" &> "$out") 2>&1 > '/dev/null')

    dtfTest="$(sdiff -st "$dtf" "$etf")"
    outTest="$(sdiff -st "$out" "$bto")"

    if [ -n "$difTest" -o -n "$outTest" ]; then
        echo -ne "$RED"
    else
        echo -ne "$GREEN"
    fi

    echo "$case"
    echo -ne "$WHITE"

    if [ -z "$difTest" -a -z "$outTest" ]; then
        echo "Test Success"
    fi

    if [ -n "$difTest" ]; then
        echo "Test Failure: DTF"
        echo ""
        echo "Difference Between Actual and Expected DTF"
        echo ""
        echo "$difTest"
    fi

    if [ -n "$difTest" -a -n "$outTest" ]; then
        echo ""
    fi

    if [ -n "$outTest" ]; then
        echo "Test Failure: Output"
        echo ""
        echo "Difference Between Actual and Expected Output"
        echo ""
        echo "$outTest"
    fi

    echo ""
    echo "Time"
    echo ""
    echo "$time"
    echo ""

    rm "$dtf"
    rm "$out"
}

# Proposed Test Category Order:
#   - login
#   - logout
#   - create
#   - addcredit
#   - sell
#   - buy
#   - delete
#   - refund

function testSuite() {
    #allCases="$(find "$TESTDIR" -mindepth 2 -type d)"
    #sorted="$(sed 's/\([a-z]\)\([0-9]\)$/\10\2/' <<< "$allCases" | sort | sed 's/0\([0-9]\)$/\1/')"

    rm "$LOGFILE"

    for i in 'login' 'logout' 'create' 'addcredit' 'sell' 'buy' 'delete' 'refund'; do
        case="$(find "$TESTDIR"/"$i" -mindepth 1 -type d)"
        sorted="$(sed 's/\(.\)\([0-9]\)$/\10\2/' <<< "$case" | sort | sed 's/0\([0-9]\)$/\1/')"

        echo "$sorted" | xargs -I {} bash -c 'testCase "$1"' 'testCase' {} | tee -a "$LOGFILE"
    done

    decolour "$LOGFILE"
}

# Remove characters which are used to show colours in bash from the log file
# http://www.commandlinefu.com/commands/view/3584/remove-color-codes-special-characters-with-sed
function decolour() {
    sed -ri "s/\x1B\[([0-9]{1,2}(;[0-9]{1,2})?)?[m|K]//g" "$1"
}

export -f clean
export -f testCase
export -f testSuite
export -f decolour

clean

echo -ne "$WHITE"

testSuite

echo -ne "$RESET"
