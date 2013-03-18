#! /usr/bin/env bash

## Runs the test harness
##
## @author          Khalil Fazal
## @studentNumber   100425046
## @author          Joseph Heron
## @studentNumber   100425488
## @author          Ryan Crawford
## @studoentNumber  100425694
## @author          Carly Marshall
## @author          100426654

export BINARY="$(readlink -f "../../Debug/FirstVu_frontend")"
export TESTDIR="$(readlink -f "..")"
export GLOBAL_UAO="$TESTDIR""/global/glob_account.inp"
export GLOBAL_ATO="$TESTDIR""/global/glob_available_tickets.inp"

# Colour Your World
export RED='\e[1;31m'
export GREEN='\e[1;32m'
export WHITE='\e[1;37m'
export RESET='\e[m'

export PATH='/usr/bin/':$PATH

## Clean the test directory tree of any stale or extraneous files
function clean() {
    find "$TESTDIR" -type f | grep ".dtf" | xargs rm 2> /dev/null
    find "$TESTDIR" -type f | grep "\.out\." | xargs rm 2> /dev/null
}

## Runs a test on a test case. Each test case contains the following:
##      - an input file
##      - an expected output file
##      - and an expected daily transaction file
##
## The FirstVu Ticket Retailer is tested by using these files.
##
## @param $1 Directory containing the test case
function testCase() {

    # Change directory to the test case.
    cd "$1"

    # The name of the test case is the name of the current directory.
    case="$(basename "$1")"

    # Input
    # GLOBAL_UAO
    # GLOBAL_ATO
    inp="$case"".inp"

    # Actual Output Files
    dtf="$(mktemp "$case"".dtf.XXX")"
    out="$(mktemp "$case"".out.XXX")"

    # Expected Output Files
    etf="$case"".etf"
    bto="$case"".bto"

    # - Run the binary against the input files
    # - STDOUT and STDERR are redirected to the actual output file
    # - The output from the time command is stored,
    #   it will be echoed back to the output stream later
    timeElapsed=$(time -p ("$BINARY" "$GLOBAL_UAO" "$GLOBAL_ATO" "$dtf" < "$inp" &> "$out") 2>&1)

    # Compare the actual files with the expected files and store the results
    dtfTest="$(sdiff -st "$dtf" "$etf")"
    outTest="$(sdiff -st "$out" "$bto")"

    # If there is at least one different between the actual files and the expected files,
    # change the font colour to red, else change it to green.
    if [ -n "$dtfTest" -o -n "$outTest" ]; then
        echo -ne "$RED"
    else
        echo -ne "$GREEN"
    fi

    # Display the test case's name
    echo "$case"

    # Change the font colour to white
    echo -ne "$WHITE"

    # Notify if there is no difference between the actual and expected output
    if [ -z "$dtfTest" -a -z "$outTest" ]; then
        echo "Test Success"
    fi

    # If the daily transaction files don't match, show the difference between
    # the actual and expected daily transaction files.
    if [ -n "$dtfTest" ]; then
        echo "Test Failure: DTF"
        echo ""
        echo "Difference Between Actual and Expected DTF"
        echo ""
        echo "$dtfTest"
    fi

    # Add spacing if there is an error in both the actual output file
    # and the actual daily transaction file
    if [ -n "$dtfTest" -a -n "$outTest" ]; then
        echo ""
    fi

    # If the output files don't match, show the difference between
    # the actual and expected output files.
    if [ -n "$outTest" ]; then
        echo "Test Failure: Output"
        echo ""
        echo "Difference Between Actual and Expected Output"
        echo ""
        echo "$outTest"
    fi

    # Show the program's run time
    echo ""
    echo "Time"
    echo ""
    echo "$timeElapsed"
    echo ""

    # Delete the test files
    rm "$dtf"
    rm "$out"
}

## Run the test suite in order.
##
## The test suite will run in order of dependancies, based off of dependancies.txt
##   1. login
##   2. logout
##   3. create
##   4. addcredit
##   5. sell
##   6. buy
##   7. delete
##   8. refund
function testSuite() {

    # Loop through each category
    for i in 'login' 'logout' 'create' 'addcredit' 'sell' 'buy' 'delete' 'refund'; do

        # Find all test cases in a category
        category="$(find "$TESTDIR"/"$i" -mindepth 1 -type d)"

        # Sort the test cases in numerical order
        # login3 comes after login2 but login10 comes after login1

        # This is done buy prepending the trailing single-digit numbers with a zero,
        # sorting the result, then removing the place-holding zeros.
        sorted="$(sed 's/\(.\)\([0-9]\)$/\10\2/' <<< "$category" | sort | sed 's/0\([0-9]\)$/\1/')"

        # Test each member of the test category
        echo "$sorted" | xargs -I {} bash -c 'testCase "$1"' 'testCase' {}
    done
}

export -f clean
export -f testCase
export -f testSuite

clean

testSuite

# Reset the font colour back to default
echo -ne "$RESET"
