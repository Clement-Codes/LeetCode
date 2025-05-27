func differenceOfSums(n int, m int) int {
    var num1, num2 int
    for i:= 1; i <= n; i++{
        if (i % m == 0){
            num2 += i
        } else {
            num1 += i
        }
    }
    return (num1 - num2)
}