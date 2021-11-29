echo "Run help";
time ../code/cmake-build-debug/homework_2;

echo "\nRun test #0"
time ../code/cmake-build-debug/homework_2 -f test00.txt out00_1.txt out00_2.txt

echo "\nRun test #1"
time ../code/cmake-build-debug/homework_2 -f test01.txt out01_1.txt out01_2.txt

echo "\nRun test #2"
time ../code/cmake-build-debug/homework_2 -f test02.txt out02_1.txt out02_2.txt

echo "\nRun test #3"
time ../code/cmake-build-debug/homework_2 -f test03.txt out03_1.txt out03_2.txt

echo "\nRun test #4"
time ../code/cmake-build-debug/homework_2 -f test04.txt out04_1.txt out04_2.txt

echo "\nRun test #5"
time ../code/cmake-build-debug/homework_2 -f test05.txt out05_1.txt out05_2.txt

echo "\nRun test #6 (random)"
time ../code/cmake-build-debug/homework_2 -n 10000 outrnd_1.txt outrnd_2.txt
