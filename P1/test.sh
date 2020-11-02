nums=$1
set -x -e
echo "| " $1 >> result.txt
./main ${nums} 1 >>  result.txt
./main ${nums} 2 >> result.txt
./main ${nums} 3 >> result.txt
./main ${nums} 4 >> result.txt
./main ${nums} 5 >> result.txt
./main ${nums} 6 >> result.txt
./main ${nums} 7 >> result.txt
echo "" >> result.txt
