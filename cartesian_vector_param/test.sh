# ATTENTION NDIM is expected to be equal to 2,
# value is ecpected to be int

# Expects the executable called "main" to be in the same directory
# Needs the tool diff
# Will create a temporary file called tmpCartVecParam.a7d371 and tmpCartVecParam.a7d372

# Expected result
echo "{4,7}
{1,8}
{-2,-2}
{-6,-6}
60
{0,1}
{2,5}
80" > tmpCartVecParam.a7d371

# Your solution
./main 2 testInit > tmpCartVecParam.a7d372
./main 1 testAdd >> tmpCartVecParam.a7d372
./main 2 testAdd >> tmpCartVecParam.a7d372
./main 4 scale 2 >> tmpCartVecParam.a7d372

# Compare
rr=$(diff tmpCartVecParam.a7d371 tmpCartVecParam.a7d372)

if [[ -z $rr ]]
then
    echo "Passed simple test"
else
    echo "Failed for one of"
    echo "./main 2 testInit > tmpCartVecParam.a7d372
./main 1 testAdd >> tmpCartVecParam.a7d372
./main 2 testAdd >> tmpCartVecParam.a7d372
./main 4 scale >> tmpCartVecParam.a7d372"
    echo "Diff is"
    echo $rr
fi

