factorial <- function(num){
  if(num == 1 || num == 0){
    return(1)
  } else {
    return (num*factorial(num-1))
  }
}
nCr <- function(n, r){
  if(r == 0||r == n){
    return(1)
  } else {
    return(factorial(n)/factorial(r)*factorial(n-r))
  }
}
main <- function(){

n <- as.numeric(readline("Enter your n value: "))

r <- as.numeric(readline("Enter your r value: "))

if(n %% 1 !=0 || r %% 1 !=0 || n < 0 || r < 0){
  print("n and r must be non-negative integers\n")
  return()
}

factn <- factorial(n)
factr <- factorial(r)
result <- nCr(n, r)

cat("Factorial of", n, "is :",factn, "\n")
cat("Factorial of", r, "is :",factr, "\n")

cat(n,"C",r,"=", result, "\n")
}
main()
