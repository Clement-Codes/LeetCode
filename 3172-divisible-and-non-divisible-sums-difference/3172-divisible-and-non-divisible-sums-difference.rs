impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let mut num1:i32 = 0;
        let mut num2:i32 = 0;
        for i in 1..n+1{
            if i % m == 0{
                num2 += i;
            }
            else{
                num1 += i;
            }
        }
        return num1 - num2;
    }
}