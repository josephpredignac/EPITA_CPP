# ATTENTION NDIM is expected to be equal to 2,
# value is ecpected to be int

# Expects the executable called "main" to be in the same directory
# Needs the tool diff
# Will create a temporary file called tmpCartVecParam.a7d371 and tmpCartVecParam.a7d372

# Expected result
echo "{0}
{1}
{0,0,0,0,0}
{1,2,3,4,5}
{1}
{1,2,3,4,5}
{0}
{4,7}
{900,919,938,957}
1480" > tmpCartVecParam.a7d371

# Your solution
./main 2 1 testInit > tmpCartVecParam.a7d372
./main 1 1 testAdd >> tmpCartVecParam.a7d372
./main 2 2 testAdd >> tmpCartVecParam.a7d372
./main 10 4 testAdd >> tmpCartVecParam.a7d372
./main 4 3 scale 2 >> tmpCartVecParam.a7d372

# Compare
rr=$(diff tmpCartVecParam.a7d371 tmpCartVecParam.a7d372)

if [[ -z $rr ]]
then
    echo "Passed simple test"
else
    echo "Failed for one of"
    echo "./main 2 1 testInit > tmpCartVecParam.a7d372
./main 1 1 testAdd >> tmpCartVecParam.a7d372
./main 2 2 testAdd >> tmpCartVecParam.a7d372
./main 10 4 testAdd >> tmpCartVecParam.a7d372
./main 4 3 scale 2 >> tmpCartVecParam.a7d372"
    echo "Diff is"
    echo $rr
fi

