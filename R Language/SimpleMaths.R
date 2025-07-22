num1 <- as.numeric(readline("Enter your first number: "))
num2 <- as.numeric(readline("Enter your second number: "))

cat(num1+num2, "\n")
cat(num1-num2, "\n")
cat(num1*num2, "\n")
if(num2!=0){
  cat(num1/num2, "\n")
} else {
  cat("Not Defined!\n")
}
