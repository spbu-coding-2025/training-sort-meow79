#!/bin/sh -e

BASEDIR=$(realpath "$(dirname "$0")")
ROOTDIR=$(realpath "$BASEDIR/..")
SORTER="$ROOTDIR/build/src/sorter"
TESTDIR="$ROOTDIR/test"

START=1
END=10
RC=0
for i in $(seq $START $END); do
	echo "TEST $i RUNNING"
	if "$SORTER" < "$TESTDIR/${i}.in" | diff -B -Z - "$TESTDIR/${i}.out"; then
		echo "TEST $i OK"
	else
		echo "TEST $i FAILED"
		RC=1
	fi
done

exit $RC
